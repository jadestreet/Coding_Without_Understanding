#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 30
typedef struct n {
	int top;
	int array[STACK_SIZE];
}Stack;
void init_stack(Stack *S)
{
	S->top = STACK_SIZE;
}
void push(Stack *S,char ch)
{
	S->top--;
	S->array[S->top] = ch;
}
char pop(Stack *S)
{
	return S->array[S->top++];
}
int isempty(Stack *S)
{
	if(S->top == STACK_SIZE)
		return 0;
	else 
		return 1;
}
void suffix(Stack *DS,Stack *CS,char *string)
{
	char ch;
	char per_ch;
	while(*string != '\0')
	{
		if(isempty(CS))
			per_ch = CS->array[CS->top];
		else
			per_ch = '\0';
		ch = *string;
		if(ch >= '0' && ch <= '9')
			push(DS,ch);
		else if(ch == '(')
			push(CS,ch);
		else if(ch == ')')
		{
			do{
				if(isempty(CS))
					ch = pop(CS);
				if(ch != '(')
					push(DS,ch);
			}
			while(ch != '(');
		}
		else
		{
			if(isempty(CS))
			{
				do{
					per_ch = pop(CS);
					if(per_ch == '(')
					{
						push(CS,per_ch);
						break;
					}
					else if(per_ch == '+' || per_ch == '-')
					{
						if(ch == '+' || ch == '-')
						{
							push(DS,per_ch);
						} else
						{
							push(CS,per_ch);
							break;
						}
					}else if(per_ch == '*' || per_ch == '/')
					{
						if(ch == '+' || ch == '-')
						{
							push(DS,per_ch);
						}else
						{
							push(CS,per_ch);
							break;
						}
					}
				}while(isempty(CS));
			} 
			push(CS,ch);
		}
	string++;	
	}
	while(isempty(CS))
	{
		ch = pop(CS);
		push(DS,ch);	
	}
}
int calc(Stack *S)
{
	Stack T;
	char ch;
	int d1,d2;
	int total = 0;
	init_stack(&T);
	while(isempty(S))
	{
		ch = pop(S);
		printf("%c",ch);
		if(ch >= '0' && ch <= '9')
			ch = ch - '0';
		push(&T,ch);
	}
	printf("\n");
	while(isempty(&T))
	{
		ch = pop(&T);
		if(ch >= 0 && ch <= 9)
			push(S,ch);
		else {
			if(isempty(S))
			{
				d1 = (char)pop(S);
				d1 = d1 & 0xff;
				if(isempty(S))
				{
					d2 = (char)pop(S);	
					d2 = d2 &0xff;
					if(ch == '+')
					{
						total = d1 + d2;
					}else if(ch == '-')
						total = d2 - d1;
					else if(ch == '*')
						total = d2 * d1;
					else
						total = d2 / d1;
					push(S,total);
					printf("The d1 = %d,d2 = %d,total = %d\n",d1,d2,total);
				}
				else 
					push(S,d1);
			}
		}
	}
	return total;
}
int main()
{
	Stack DS,CS;
	char ch;
	int total;
	char *string = "100+9";
	init_stack(&DS);
	init_stack(&CS);
	suffix(&DS,&CS,string);
	total = calc(&DS);
	printf("The %s = %d\n",string,total);
	return 0;
}