#include <stdio.h>
void count_array_elements_times(int *p,int size_p,int (*q)[6]);
int is_num_in_array(int *p,int array_size,int n);
int count_number_in_array(int *p,int array_size,int n);
int main()
{
    int array[6]={22,23,22,23,5,6};
    int array_count[2][6]={};
    count_array_elements_times(array,6,array_count);
}
void count_array_elements_times(int *p,int size_p,int (*q)[6])
{
    int i,j,k;
    k=0;
    for (i=0;i<size_p;i++)
    {
        if(-1 == is_num_in_array(q[0],6,p[i]))
        {
            q[0][k]=p[i];
            k++;
        }
    }
    for (i=0; i<size_p; i++)
    {
        q[1][i]=count_number_in_array(p, size_p, q[0][i]);
    }
    for(j=0;j<6;j++)
    {
        if (q[0][j]!=0)
        {
            printf("number %d occured %d times \n",q[0][j],q[1][j]);
        }
    }
    printf("\n");
}
int is_num_in_array(int *p,int array_size,int n)
{
    int i;
    for(i=0; i<array_size; i++)
    {
        if(p[i]==n)
        {
            return 1;
        }
    }
    return -1;
}
int count_number_in_array(int *p,int array_size,int n)
{
    int i,count=0;
    for (i=0; i<array_size; i++)
    {
        if (p[i]==n)
        {
            count++;
        }
    }
    return count;
}