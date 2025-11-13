#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
typedef struct QUEEN {
    int x,y;
} queen;
typedef struct STACK {
    int size;
    int capacity;
    queen data[STACK_SIZE];
} stack;
int equal_queen(queen *q1, queen *q2);
int find_queen(stack *s, queen *q);
int queens(int n);
stack *init_stack();
void free_stack(stack *s);
queen *pop(stack *s);
queen *top(stack *s);
int push(stack *s, queen *q);
int size(stack *s);
int empty(stack *s);
int main()
{
    printf("%d\n", queens(8));
    return 0;
}
int queens(int n)
{
    if (n < 4)
    {
        return 0;
    }
    else
    {
        int count = 0;
        stack *s = init_stack();
        queen *p =  (queen *)malloc(sizeof(queen));
        queen *q = p;
        p->x = 0;
        p->y = 0;
        while (size(s) < n) 
        {
            count ++;
            if (q->x >= n)
            {
                if ((p = pop(s)) == NULL) 
                {   
                    break;
                }
                q->x = p->x;
                q->y = p->y;
                q->x++;
                if (q->x >= n)
                {   
                    continue;
                }
            }
            if (find_queen(s, q) >= 0)
            {
                q->x++;
            }
            else
            {
                push(s, q);
                q->x = 0;
                q->y ++;
            }
        }
        if (size(s) == n)
        {
            while (!empty(s))
            {
                q = pop(s);
                if (!q)
                {
                    fputs("pop", stderr);
                }
                printf("(%d, %d)\n", q->x, q->y);
            }
            free_stack(s);
            return count;
        }
        else
        {
            free_stack(s);
            return 0;
        }
    }
}
int equal_queen(queen *q1, queen *q2)
{
    if (q1->x == q2->x || q1->y == q2->y || q1->x + q1->y == q2->x + q2->y
            || q1->x - q1->y == q2->x - q2->y)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
stack *init_stack()
{
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL)
    {
        return NULL;
    }
    else
    {
        s->size = 0;
        s->capacity = STACK_SIZE;
        return s;
    }
}
void free_stack(stack *s)
{
    if (s != NULL)
    {
        free(s);
    }
}
queen *pop(stack *s)
{
    if (s == NULL || s->size <= 0)
    {
        return NULL;
    }
    else
    {
        return &s->data[--(s->size)];
    }
}
queen *top(stack *s)
{
    if (s == NULL || s->size <= 0)
    {
        return NULL;
    }
    else
    {
        return &s->data[s->size];
    }
}
int push(stack *s, queen *q)
{
    if (s == NULL)
    {
        return 1;
    }
    else if (s->size >= s->capacity)
    {
        return 2;
    }
    else
    {
        s->data[s->size++] = *q;
        return 0;
    }
}
int size(stack *s)
{
    if (s == NULL)
    {
        return -1;
    }
    else
    {
        return s->size;
    }
}
int empty(stack *s)
{
    if (s == NULL || s->size <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int find_queen(stack *s, queen *q)
{
    int index, pos;
    pos = -1;
    if (!empty(s))
    {
        index = 0;
        while (index < size(s))
        {
            if (equal_queen(&s->data[index], q))
            {
                pos = index;
                break;
            }
            index++;
        }
    }
    return pos;
}