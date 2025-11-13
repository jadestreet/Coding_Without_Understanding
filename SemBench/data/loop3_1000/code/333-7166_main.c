#include <stdio.h>
#include <stdlib.h>
typedef char * arr_t;
typedef int (*cmp_func)(const char *, const char *);
void swap(arr_t *a, arr_t *b)
{
	arr_t tmp = *a;
	*a = *b;
	*b = tmp;
}
void prints(const char *s)
{
	for (; *s != '\n'; ++s)
		{
			putc(*s, stdout);
		}
	putc('\n', stdout);
	return;
}
int lexCmp(const char *, const char *);
int intCmp(const int, const int);
void bubbleSort		(arr_t *const, arr_t *const, cmp_func);
void insertSort		(arr_t *const, arr_t *const, cmp_func);
void mergeSort		(arr_t *const, arr_t *const, cmp_func);
void quickSort		(arr_t *const, arr_t *const, cmp_func);
int main(int argc, char **argv)
{	
	if (argc < 3)
	{
		printf("not enough arguments\n");
		return 0;
	}
	if (argc > 3)
	{
		printf("too many arguments\n");
		return 0;
	}
	int n, bsize = 0, strc = 0;
	n = atoi(argv[1]);
	if (n <= 0)
	{
		return 0;
	}
	FILE *fin = fopen(argv[2], "r");
	if(!fin)
	{
		printf("ERROR: failed to open file\n");
		return 1;
	}
	int c = 0;
	for (; c != EOF && strc < n; ++bsize) 
	{
		c = fgetc(fin);
		if (c == '\n' || c == EOF) 
		{
			++strc;
		}
	}
	if (bsize <= 1) 
	{
		printf("Empty file - nothing to do here\n");
		return 0;
	}
	char **const arr = (char **const) malloc( strc * sizeof(char *) );
	char *const buf = (char *const) malloc( bsize * sizeof(char) );
	rewind(fin);
	int j = 0, k = 0;
	arr[j++] = buf;
	for (c = 0; c != EOF && j <= strc; ++k)
	{
		c = fgetc(fin);
		buf[k] = c;
		if (c == '\n')
		{
			if (j < strc) 
			{
				arr[j] = buf + k + 1;
			}
			++j;
		}
	}
	if (bsize > 1 && buf[k-2] == '\n' && buf[k-1] == EOF)
	{
		--strc;
	}
	bsize = k;
	buf[bsize-1] = '\n';
	quickSort(arr, arr+strc, lexCmp);
	for (int i = 0; i < strc; ++i)
	{
		prints(arr[i]);
	}	
	free(arr);
	free(buf);
	fclose(fin);
	return 0;
}
int lexCmp(const char *left, const char *right)
{
	const char endl = '\n';
	int i = 0;
	for ( ; left[i] != endl && right[i] != endl; ++i) 
	{
		if (left[i] != right[i]) 
		{
			return (left[i] < right[i]) ? 1 : -1;
		}
	}
	if (left[i] != endl || right[i] != endl)
	{
		return (left[i] == endl) ? 1 : -1;
	}
	return 0;
}
int intCmp(const int left, const int right)
{
	if (left != right)
	{
		return (left < right) ? 1 : -1;
	}
    return 0;
}
void bubbleSort(arr_t *const begin, arr_t *const end, cmp_func cmp) 
{
	for (arr_t *i = begin; i != end; ++i) 
	{
		for (arr_t *j = end - 1; j != i; --j)
		{
			if ( (*cmp)(*j, *(j-1)) == 1) 
			{
				swap(j, (j-1));
			}
		}
	}
}
void insertSort(arr_t *const begin, arr_t *const end, cmp_func cmp)
{
	for (arr_t *i = begin + 1; i != end; ++i)
	{
		for (arr_t *j = i; j != begin && (*cmp)(*j, *(j-1)) == 1; --j)
		{
			swap(j, (j-1));
		}
	}
}
void merge(arr_t *const _begin, arr_t *const _mid, arr_t *const _end, arr_t *const buf, cmp_func cmp)
{
	arr_t 	*b = buf,
		*f = _begin,
		*s = _mid;
	for(; f != _mid && s != _end; ++b)
	{
	    *b = (cmp(*f, *s) != -1) ? *f++ : *s++;
	}
	arr_t *cur = (f == _mid) ? s : f;
	arr_t *__end = (f == _mid) ? _end : _mid;
	for (; cur != __end; ++cur)
	{
		*b++ = *cur;
	}
	cur = _end;
	while (b != buf)
	{
		*--cur = *--b;
	}
}
void _sort(arr_t *const _begin, arr_t *const _end, arr_t *const buf, cmp_func cmp) 
{
	if (_end - _begin < 2)
	{
		return;
	}		
	arr_t *_mid = _begin + (_end - _begin)/2; 
	_sort(_begin, _mid, buf, cmp);
	_sort(_mid, _end, buf, cmp);
	merge(_begin, _mid, _end, buf, cmp);
}
void mergeSort(arr_t *const begin, arr_t *const end, cmp_func cmp)
{	
	arr_t *const buf = (arr_t*) malloc((end-begin)*sizeof(arr_t));
	_sort(begin, end, buf, cmp);
	free(buf);
}
void quickSort(arr_t *const begin, arr_t *const end, cmp_func cmp) 
{
	if (end - begin < 2) 
	{ 
		return;
	}	
	arr_t mid = *(begin + (end-begin)/2);
	arr_t *l = begin, *r = end - 1;
	while (l <= r) 
	{
		while (cmp(*l, mid) == 1)
		{
			++l;
		}
		while (cmp(*r, mid) == -1)
		{
			--r;
		}		
		if (l <= r)
		{
			swap(l++, r--);
		}
	}
	quickSort(begin, r+1, cmp);
	quickSort(l, end, cmp);
}