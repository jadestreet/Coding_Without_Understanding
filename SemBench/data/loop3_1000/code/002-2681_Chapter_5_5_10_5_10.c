#include <stdio.h>
#include <ctype.h>                      
#include <stdlib.h>                     
#define MAXOP                           
#define NUMBER '0'                      
#define WRONGNUM '1'                    
int getop (char *);
void push(double);
double pop(void);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s arguments\n", argv[0]);
        return 1;
    }
    int type, ar = 1;
    double op2;
    while (ar < argc) {
        type = getop(argv[ar]);
        switch (type) {
            case NUMBER:
                push(atof(argv[ar]));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            default:
                printf("error: unknown command %s\n", argv[ar]);
                break;
        }
        ar++;
    }
    printf("\t%.8g\n", pop());
    return 0;
}
int getop(char *s)
{
    char *tmp = s;
    while (*tmp == ' ' || *tmp == '\t')     
        tmp++;
    if (!isdigit(*tmp) && *tmp != '.') 
        return *tmp;                        
    int point = 0;
    while (*tmp) {
        if (*tmp == '.')
            if (point)
                return WRONGNUM;
            else
                point = 1;
        else
            if (!isdigit(*tmp))
                return WRONGNUM;
        tmp++;
    }
    return NUMBER;
}
#define MAXVAL 100                      
int sp = 0;                             
double val[MAXVAL];                     
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}