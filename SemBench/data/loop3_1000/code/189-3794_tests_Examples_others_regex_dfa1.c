#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char*
re2post(char *re)
{
	int nalt, natom;
	static char buf[8000];
	char *dst;
	struct {
		int nalt;
		int natom;
	} paren[100], *p;
	p = paren;
	dst = buf;
	nalt = 0;
	natom = 0;
	if(strlen(re) >= sizeof buf/2)
		return NULL;
	for(; *re; re++){
		switch(*re){
		case '(':
			if(natom > 1){
				--natom;
				*dst++ = '.';
			}
			if(p >= paren+100)
				return NULL;
			p->nalt = nalt;
			p->natom = natom;
			p++;
			nalt = 0;
			natom = 0;
			break;
		case '|':
			if(natom == 0)
				return NULL;
			while(--natom > 0)
				*dst++ = '.';
			nalt++;
			break;
		case ')':
			if(p == paren)
				return NULL;
			if(natom == 0)
				return NULL;
			while(--natom > 0)
				*dst++ = '.';
			for(; nalt > 0; nalt--)
				*dst++ = '|';
			--p;
			nalt = p->nalt;
			natom = p->natom;
			natom++;
			break;
		case '*':
		case '+':
		case '?':
			if(natom == 0)
				return NULL;
			*dst++ = *re;
			break;
		default:
			if(natom > 1){
				--natom;
				*dst++ = '.';
			}
			*dst++ = *re;
			natom++;
			break;
		}
	}
	if(p != paren)
		return NULL;
	while(--natom > 0)
		*dst++ = '.';
	for(; nalt > 0; nalt--)
		*dst++ = '|';
	*dst = 0;
	return buf;
}
enum
{
	Match = 256,
	Split = 257
};
typedef struct State State;
struct State
{
	int c;
	State *out;
	State *out1;
	int lastlist;
};
State matchstate = { Match };	
int nstate;
State*
state(int c, State *out, State *out1)
{
	State *s;
	nstate++;
	s = malloc(sizeof *s);
	s->lastlist = 0;
	s->c = c;
	s->out = out;
	s->out1 = out1;
	return s;
}
typedef struct Frag Frag;
typedef union Ptrlist Ptrlist;
struct Frag
{
	State *start;
	Ptrlist *out;
};
Frag
frag(State *start, Ptrlist *out)
{
	Frag n = { start, out };
	return n;
}
union Ptrlist
{
	Ptrlist *next;
	State *s;
};
Ptrlist*
list1(State **outp)
{
	Ptrlist *l;
	l = (Ptrlist*)outp;
	l->next = NULL;
	return l;
}
void
patch(Ptrlist *l, State *s)
{
	Ptrlist *next;
	for(; l; l=next){
		next = l->next;
		l->s = s;
	}
}
Ptrlist*
append(Ptrlist *l1, Ptrlist *l2)
{
	Ptrlist *oldl1;
	oldl1 = l1;
	while(l1->next)
		l1 = l1->next;
	l1->next = l2;
	return oldl1;
}
State*
post2nfa(char *postfix)
{
	char *p;
	Frag stack[1000], *stackp, e1, e2, e;
	State *s;
	if(postfix == NULL)
		return NULL;
	#define push(s) *stackp++ = s
	#define pop() *--stackp
	stackp = stack;
	for(p=postfix; *p; p++){
		switch(*p){
		default:
			s = state(*p, NULL, NULL);
			push(frag(s, list1(&s->out)));
			break;
		case '.':	
			e2 = pop();
			e1 = pop();
			patch(e1.out, e2.start);
			push(frag(e1.start, e2.out));
			break;
		case '|':	
			e2 = pop();
			e1 = pop();
			s = state(Split, e1.start, e2.start);
			push(frag(s, append(e1.out, e2.out)));
			break;
		case '?':	
			e = pop();
			s = state(Split, e.start, NULL);
			push(frag(s, append(e.out, list1(&s->out1))));
			break;
		case '*':	
			e = pop();
			s = state(Split, e.start, NULL);
			patch(e.out, s);
			push(frag(s, list1(&s->out1)));
			break;
		case '+':	
			e = pop();
			s = state(Split, e.start, NULL);
			patch(e.out, s);
			push(frag(e.start, list1(&s->out1)));
			break;
		}
	}
	e = pop();
	if(stackp != stack)
		return NULL;
	patch(e.out, &matchstate);
	return e.start;
#undef pop
#undef push
}
typedef struct List List;
struct List
{
	State **s;
	int n;
};
List l1, l2;
static int listid;
void addstate(List*, State*);
void step(List*, int, List*);
List*
startlist(State *start, List *l)
{
	l->n = 0;
	listid++;
	addstate(l, start);
	return l;
}
int
ismatch(List *l)
{
	int i;
	for(i=0; i<l->n; i++)
		if(l->s[i] == &matchstate)
			return 1;
	return 0;
}
void
addstate(List *l, State *s)
{
	if(s == NULL || s->lastlist == listid)
		return;
	s->lastlist = listid;
	if(s->c == Split){
		addstate(l, s->out);
		addstate(l, s->out1);
		return;
	}
	l->s[l->n++] = s;
}
void
step(List *clist, int c, List *nlist)
{
	int i;
	State *s;
	listid++;
	nlist->n = 0;
	for(i=0; i<clist->n; i++){
		s = clist->s[i];
		if(s->c == c)
			addstate(nlist, s->out);
	}
}
typedef struct DState DState;
struct DState
{
	List l;
	DState *next[256];
	DState *left;
	DState *right;
};
static int
listcmp(List *l1, List *l2)
{
	int i;
	if(l1->n < l2->n)
		return -1;
	if(l1->n > l2->n)
		return 1;
	for(i=0; i<l1->n; i++)
		if(l1->s[i] < l2->s[i])
			return -1;
		else if(l1->s[i] > l2->s[i])
			return 1;
	return 0;
}
static int
ptrcmp(const void *a, const void *b)
{
	if(a < b)
		return -1;
	if(a > b)
		return 1;
	return 0;
}
DState *freelist;
DState*
allocdstate(void)
{
	DState *d;
	if((d = freelist) != NULL)
		freelist = d->left;
	else{
		d = malloc(sizeof *d + nstate*sizeof(State*));
		d->l.s = (State**)(d+1);
	}
	d->left = NULL;
	d->right = NULL;
	memset(d->next, 0, sizeof d->next);
	return d;
}
void
freestates(DState *d)
{
	if(d == NULL)
		return;
	freestates(d->left);
	freestates(d->right);
	d->left = freelist;
	freelist = d;
}
static DState *alldstates;
static int nstates;
void
freecache(void)
{
	freestates(alldstates);
	alldstates = NULL;
	nstates = 0;
}
int maxstates = 32;
DState*
dstate(List *l, DState **nextp)
{
	int i;
	DState **dp, *d;
	qsort(l->s, l->n, sizeof l->s[0], ptrcmp);
	dp = &alldstates;
	while((d = *dp) != NULL){
		i = listcmp(l, &d->l);
		if(i < 0)
			dp = &d->left;
		else if(i > 0)
			dp = &d->right;
		else
			return d;
	}
	if(nstates >= maxstates){
		freecache();
		dp = &alldstates;
		nextp = NULL;
	}
	d = allocdstate();
	memmove(d->l.s, l->s, l->n*sizeof l->s[0]);
	d->l.n = l->n;
	*dp = d;
	nstates++;
	if(nextp != NULL)
		*nextp = d;
	return d;
}
void
startnfa(State *start, List *l)
{
	l->n = 0;
	listid++;
	addstate(l, start);
}
DState*
startdstate(State *start)
{
	return dstate(startlist(start, &l1), NULL);
}
DState*
nextstate(DState *d, int c)
{
	step(&d->l, c, &l1);
	return dstate(&l1, &d->next[c]);
}
int
match(DState *start, char *s)
{
	DState *d, *next;
	int c;
	d = start;
	for(; *s; s++){
		c = *s & 0xFF;
		if((next = d->next[c]) == NULL)
			next = nextstate(d, c);
		d = next;
	}
	return ismatch(&d->l);
}
int
main(int argc, char **argv)
{
	int i;
	char* post;
	State* start;
    char* regexp = argv[1];
    int testRepCount = atoi(argv[2]);
    int totalRepCount = atoi(argv[3]);
    char* testStr = argv[4];
    for (i = 0; i < totalRepCount; ++i)
    {
    	post = re2post(regexp);
    	start = post2nfa(post);
    	l1.s = malloc(nstate*sizeof l1.s[0]);
    	l2.s = malloc(nstate*sizeof l2.s[0]);
        	if (!match(startdstate(start), testStr))
    			printf("%s\n", argv[i]);
	free(l1.s);
	free(l2.s);
    }
	return 0;
}