#include <stdio.h>
#include <stdlib.h>
struct string {
  char c;
  struct string* next;
};
struct queue {
  int poped;
  int distance;
  struct string string;
  struct queue* next;
};
struct queue head;
void print_string(const struct string* s) {
  struct string* p;
  for(p = s->next; p != NULL; p = p->next) {
    printf("%c", p->c);
  }
}
int length(const struct string* s) {
  struct string* p;
  int l;
  for(l = 0, p = s->next; p != NULL; p = p->next, l++);
  return l;
}
char value_at(const struct string* s, int d) {
  struct string* p;
  int i;
  p = s->next;
  for(i = 0; i < d; i++) {
    p = p->next;
  }
  return p->c;
}
void append(struct string* s, int d, char c) {
  struct string* p;
  struct string* q;
  struct string* new;
  int i;
  p = s->next;
  q = s;
  for(i = 0; i < d; i++) {
    p = p->next;
    q = q->next;
  }
  new = (struct string*) malloc(sizeof(struct string));
  new->c = c;
  new->next = q->next;
  q->next = new;
}
void delete(struct string* s, int d) {
  struct string* p;
  struct string* q;
  int i;
  p = s->next;
  q = s;
  for(i = 0; i < d; i++) {
    p = p->next;
    q = q->next;
  }
  q->next = p->next;
  free(p);
}
void replace(struct string* s, int d, char c) {
  struct string* p;
  int i;
  p = s->next;
  for(i = 0; i < d; i++) {
    p = p->next;
  }
  p->c = c;
}
void copy(struct string* d, const struct string* s) {
  struct string* p;
  struct string* q;
  struct string* new;
  d->next = NULL;
  for(p = d, q = s->next; q != NULL; p = p->next, q = q->next) {
    new = (struct string*) malloc(sizeof(struct string));
    new->c = q->c;
    new->next = NULL;
    p->next = new;
  }
}
int equal(const struct string *a, const struct string* b) {
  struct string* p;
  struct string* q;
  for(p = a->next, q = b->next; p != NULL && q != NULL && p->c == q->c; p = p->next, q = q->next);
  return p == NULL && q == NULL;
}
void print_queue() {
  struct queue* p;
  printf("queue = [\n");
  for(p = head.next; p != NULL; p = p->next) {
    printf("  { poped: %1d, distance: %2d, string: ", p->poped, p->distance);
    print_string(&p->string);
    printf(" },\n");
  }
  printf("]\n");
}
int push_if_unique(int distance, struct string* s) {
  struct queue* p;
  struct queue* q;
  struct queue* new;
  for(p = head.next, q = &head; p != NULL; p = p->next, q = q->next) {
    if(equal(&p->string, s)) {
      return 0;
    }
  }
  new = (struct queue*) malloc(sizeof(struct queue));
  new->poped = 0;
  new->distance = distance;
  copy(&new->string, s);
  new->next = NULL;
  q->next = new;
  return 1;
}
int pop(int* distance, struct string* s) {
  struct queue* p;
  for(p = head.next; p != NULL; p = p->next) {
    if(p->poped == 0) {
      p->poped = 1;
      *distance = p->distance;
      copy(s, &p->string);
      return 1;
    }
  }
  return 0;
}
void create_char_set(char** char_set, struct string* begin, struct string* end) {
  int chars[256];
  int l, n;
  int i, j;
  n = 0;
  for(i = 0; i < 256; i++) {
    if(chars[i] == 1) {
      n++;
    }
  }
  *char_set = (char*) malloc(sizeof(char) * n);
  j = 0;
  for(i = 0; i < 256; i++) {
    if(chars[i] == 1) {
      (*char_set)[j] = chars[i];
      j++;
    }
  }
}
int levenshtein_distance(struct string* begin, struct string* end) {
  struct string current;
  struct string next;
  int distance;
  int chars[256];
  int l, i;
  int c;
  for(i = 0; i < 256; i++) {
    chars[i] = 0;
  }
  for(l = length(begin), i = 0; i < l; i++) {
    chars[value_at(begin, i)] = 1;
  }
  for(l = length(end), i = 0; i < l; i++) {
    chars[value_at(end, i)] = 1;
  }
  push_if_unique(0, begin);
  while(pop(&distance, &current)) {
    printf("%d ", distance);
    print_string(&current);
    printf("\n");
    l = length(&current);
    for(i = 0; i <= l; i++) {
      for(c = 0; c < 256; c++) {
        if(chars[c] == 0) continue;
        copy(&next, &current);
        append(&next, i, c);
        if(equal(&next, end)) {
          return distance + 1;
        }
        push_if_unique(distance + 1, &next);
      }
    }
    for(i = 0; i < l; i++) {
      copy(&next, &current);
      delete(&next, i);
      if(equal(&next, end)) {
        return distance + 1;
      }
      push_if_unique(distance + 1, &next);
    }
    for(i = 0; i < l; i++) {
      for(c = 0; c < 256; c++) {
        if(chars[c] == 0) continue;
        copy(&next, &current);
        replace(&next, i, c);
        if(equal(&next, end)) {
          return distance + 1;
        }
        push_if_unique(distance + 1, &next);
      }
    }
  }
  return -1;
}
void input(struct string* begin, struct string* end) {
  int l;
  char c;
  l = 0;
  while(c = fgetc(stdin), c != EOF && c != '\n') {
    append(begin, l, c);
    l++;
  }
  l = 0;
  while(c = fgetc(stdin), c != EOF && c != '\n') {
    append(end, l, c);
    l++;
  }
}
int main(void) {
  struct string begin, end;
  int distance;
  begin.next = NULL;
  end.next = NULL;
  input(&begin, &end);
  distance = levenshtein_distance(&begin, &end);
  printf("%d\n", distance);
  return 0;
}