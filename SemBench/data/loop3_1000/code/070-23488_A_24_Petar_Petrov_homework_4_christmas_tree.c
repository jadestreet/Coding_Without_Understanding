#include<stdio.h>
int christmas_tree(int height)
{
    int counter, print_counter, space_counter;
    char symbol = 42, space = 32;
    for(counter = 1; counter <= height; counter++)
    {
       for(space_counter = 1; space_counter <= (height - counter); space_counter++)
       {
           printf("%c",space);
       }
       for(print_counter = 1; print_counter <= (counter + counter-1); print_counter++)
       {
           printf("%c",symbol);
       }
       printf("\n");
    }          
    return 0;
}
int main()
{
   christmas_tree(4);
   christmas_tree(7);
   christmas_tree(11);
   return 0;
}