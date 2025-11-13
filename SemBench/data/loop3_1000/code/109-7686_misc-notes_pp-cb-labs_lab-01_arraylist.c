#include <stdio.h>
#include <stdlib.h>
#define LIST_CAPACITY 42
struct arraylist {
        long storage[LIST_CAPACITY];
        unsigned n_elems;
};
#define ERROR ((struct arraylist *)(-1))
struct arraylist *arraylist_new(void)
{
        struct arraylist *l = malloc(sizeof(struct arraylist));
        l->n_elems = 0;
        return l;
}
struct arraylist *arraylist_cons(long n, struct arraylist *l)
{
        if (l->n_elems >= LIST_CAPACITY)
                return ERROR;
        l->storage[l->n_elems++] = n;
        return l;
}
long arraylist_head(struct arraylist *l)
{
        if (l->n_elems == 0)
                return (long) ERROR;
        return l->storage[l->n_elems - 1];
}
struct arraylist *arraylist_tail(struct arraylist *l)
{
        if (l->n_elems == 0)
                return ERROR;
        l->n_elems--;
        return l;
}
long arraylist_get(unsigned i, struct arraylist *l)
{
        if (i == 0)
                return arraylist_head(l);
        return arraylist_get(i - 1, arraylist_tail(l));
}
struct arraylist *arraylist_insert(long n, unsigned i, struct arraylist *l)
{
        long new_head;
        struct arraylist *rec;
        if (i == 0)
                return arraylist_cons(n, l);
        new_head = arraylist_head(l);
        rec = arraylist_insert(n, i - 1, arraylist_tail(l));
        return arraylist_cons(new_head, rec);
}
struct arraylist *arraylist_remove(unsigned i, struct arraylist *l)
{
        long new_head;
        struct arraylist *rec;
        if (i == 0)
                return arraylist_tail(l);
        new_head = arraylist_head(l);
        rec = arraylist_remove(i - 1, arraylist_tail(l));
        return arraylist_cons(new_head, rec);
}
# if 0
long arraylist_get(unsigned i, struct arraylist *l)
{
        if (l->n_elems <= i)
                return (long) ERROR;
        return l->storage[l->n_elems - i - 1];
}
struct arraylist *arraylist_insert(long n, unsigned i, struct arraylist *l)
{
        unsigned k;
        if (l->n_elems <= i)
                return ERROR;
        if (l->n_elems + 1 > LIST_CAPACITY)
                return ERROR;
        for (k = l->n_elems - 1; k > l->n_elems - i - 1; k--)
                l->storage[k + 1] = l->storage[k];
        l->n_elems++;
        l->storage[l->n_elems - i - 1] = n;
        return l;
}
struct arraylist *arraylist_remove(unsigned i, struct arraylist *l)
{
        int k;
        if (l->n_elems <= i)
                return ERROR;
        l->n_elems--;
        for (k = l->n_elems - i; k < l->n_elems; k++)
                l->storage[k] = l->storage[k + 1];
        return l;
}
#endif
void arraylist_print(struct arraylist *l)
{
        int i;
        for (i = l->n_elems - 1; i >= 0; i--)
                printf("%ld ", l->storage[i]);
        printf("\n");
}
int main(void)
{
        struct arraylist *l;
        l = arraylist_new();
        l = arraylist_cons(1, arraylist_cons(2, arraylist_cons(3, l)));
        l = arraylist_cons(4, l);
        printf("l = "); arraylist_print(l);
        l = arraylist_insert(5, 2, l);
        printf("after inserting at pos 2, l = "); arraylist_print(l);
        printf("head(l) = %ld\n", arraylist_head(l));
        l = arraylist_tail(l);
        printf("l = tail(l) = "); arraylist_print(l);
        l = arraylist_remove(2, l);
        printf("removed l[2]; l = "); arraylist_print(l);
        l = arraylist_remove(0, l);
        printf("removed l[0]; l = "); arraylist_print(l);
        free(l);
        return 0;
}