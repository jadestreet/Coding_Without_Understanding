#include <stdio.h>
#include <stdlib.h>
struct vector_t {
    int *data;
    int index, size;
};
void vector_init(struct vector_t*);
void vector_destroy(struct vector_t*);
int vector_get_size(struct vector_t);
int vector_resize(struct vector_t*);
int vector_at(struct vector_t, int index);
void vector_push_back(struct vector_t*, int value);
int vector_pop_back(struct vector_t*);
void vector_copy(struct vector_t* from, struct vector_t* to);
int main() {
    struct vector_t vector;
    vector_init(&vector);
    printf("FIRST VECTOR: \n\n\n");
    printf("Before push back: ");
    int i;
    for (i = 0; i < vector_get_size(vector); i++)
    {
        printf("%d ", vector_at(vector, i));
    }
    printf("\n");
    vector_push_back(&vector, 1);
    vector_push_back(&vector, 2);
    vector_push_back(&vector, 3);
    vector_push_back(&vector, 4);
    printf("After push back: ");
    for (i = 0; i < vector_get_size(vector); i++)
    {
        printf("%d ", vector_at(vector, i));
    }
    printf("\nVector size: %d\n", vector.size);
    printf("\nAfter 2 pops: ");
    vector_pop_back(&vector);
    vector_pop_back(&vector);
    for (i = 0; i < vector_get_size(vector); i++)
    {
        printf("%d ", vector_at(vector, i));
    }
    printf("\nVector size: %d\n", vector.size);
    struct vector_t vector_to;
    vector_copy(&vector, &vector_to);
    printf("\n\n\nCOPIED VECTOR: \n\n\n");
    printf("Before push back: ");
    for (i = 0; i < vector_get_size(vector_to); i++)
    {
        printf("%d ", vector_at(vector_to, i));
    }
    printf("\n");
    vector_push_back(&vector_to, 1);
    vector_push_back(&vector_to, 2);
    vector_push_back(&vector_to, 3);
    vector_push_back(&vector_to, 4);
    printf("After push back: ");
    for (i = 0; i < vector_get_size(vector_to); i++)
    {
        printf("%d ", vector_at(vector_to, i));
    }
    printf("\nVector size: %d\n", vector_to.size);
    printf("\nAfter 2 pops: ");
    vector_pop_back(&vector_to);
    vector_pop_back(&vector_to);
    for (i = 0; i < vector_get_size(vector_to); i++)
    {
        printf("%d ", vector_at(vector_to, i));
    }
    printf("\nVector size: %d\n", vector_to.size);
    vector_destroy(&vector);
    vector_destroy(&vector_to);
    return 0;
}
void vector_init(struct vector_t* v) {
    v->size = 5;
    v->index = 0;
    v->data = (int*) malloc(v->size * sizeof(int));
}
void vector_destroy(struct vector_t* v){
    if (v->data != NULL)
    {
        free(v->data);
        v->data = NULL;
    }
    v->size = 0;
    v->index = 0;
}
int vector_get_size(struct vector_t v) {
    return v.index;
}
void vector_push_back(struct vector_t* v, int value) {
    if (v->index == v->size)
    {
        vector_resize(v);
    }
    v->data[v->index++] = value;
}
int vector_at(struct vector_t v, int index) {
    if (v.index >= 0 ||
        v.index <= v.size)
    {
        return v.data[index];
    }
	else
    {
        return -1; 
    }
}
int vector_pop_back(struct vector_t* v) {
    if (v-> index < 0)
    {
        return -1; 
    }
    else
    {
        vector_resize(v);
        return v->data[--v->index];
    }
}
int vector_resize(struct vector_t* v) {
    if (v->index >= v->size)
    {
        return v->size *= 2;
    }
    else if (v->index <= v->size/2 + 1)
    {
        return v->size /= 2;
    }
    else
    {
        return -1; 
    }
    return 0; 
}
void vector_copy(struct vector_t* from, struct vector_t* to)
{
    to->size = from->size;
    to->index = 0;
    to->data = (int*) malloc(from->size * sizeof(int));
    int i;
    for (i = 0; i < from->size; i++)
    {
	vector_push_back(to, from->data[i]);
    }
}