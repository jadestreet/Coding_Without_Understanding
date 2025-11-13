#include <stdio.h>  
#include <stdlib.h> 
typedef struct _vector2 {
    int x, y;
} vector2;                   
char    buffer[128];         
int     intArray[10];        
vector2 vectorArray[4];      
void swap(int* a, int* b);
void part1()
{
    int* iptr;
    int *ptr1, *ptr2;
    int var1 = 5, var2 = 10; 
    iptr = &var1;         
    iptr = &intArray[0];  
    iptr = intArray;      
    printf("value   = %d\n", *iptr);  
    printf("address = %d\n", (int)iptr);   
    printf("address = %p\n", iptr);   
    *iptr = 5;
    printf("var1 = %2d    var2 = %2d\n", var1, var2);
    swap(&var1, &var2);   
    printf("var1 = %2d    var2 = %2d\n", var1, var2);
}
void swap(int* a, int* b) 
{
    int temp = *a;   
    *a = *b;         
    *b = temp;       
}
void printArray() 
{
    int i, size;
    size = sizeof(intArray) / sizeof(int); 
    printf("int[%d] { ", size);
    for (i = 0; i < size; i++)
        printf("%d, ", intArray[i]);
    printf("}\n");
}
void part2()
{
    int *iptr;
    int i = 0;
    iptr = intArray; 
    while (i < 5)     
    {
        *iptr = i;    
        iptr += 1;    
        i++;          
    }
    printArray();
    while (i < 10)      
    {
        *iptr++ = i++;  
    }
    printArray();
}
void my_strcpy1(char* dst, const char* src)
{
    while (*src != 0)
    {
        *dst = *src;  
        ++dst, ++src; 
    }
}
void my_strcpy2(char* dst, const char* src)
{
    while (*dst = *src) 
    {
        ++dst, ++src; 
    }
}
void my_strcpy3(char* dst, const char* src)
{
    while (*dst++ = *src++) 
        ;
}
void printVectors() 
{
    int i, size;
    vector2* vp = vectorArray;
    size = sizeof(vectorArray) / sizeof(vector2); 
    printf("vec2[%d] { ", size);
    for (i = 0; i < 4; i++) { 
        printf("[%d,%d] ", vp->x, vp->y);   
        vp++;                               
    }
    printf("}\n");
}
void part3()
{
    int *iptr, *eptr, i;
    iptr = intArray;                         
    eptr = (char*)iptr + sizeof(intArray);  
    i = 0;
    while (iptr != eptr)  
        *iptr++ = i++;    
    iptr = vectorArray;                        
    eptr = (char*)iptr + sizeof(vectorArray); 
    i = 0;
    while (iptr != eptr)
        *iptr++ = i++; 
    printVectors(); 
}
void part4()
{
    vector2 *vptr, v;
    vptr = vectorArray + 1;  
    vptr = &vectorArray[1];  
    vptr = &1[vectorArray];  
    v = vectorArray[1];      
    v = *(vectorArray + 1);  
    vptr = ((int*) vectorArray) + 1; 
    vptr->x = 100;    
    vptr->y = 200;    
    vptr = (vector2*)buffer;
    printVectors(); 
    return;
}
int myIntFunction(int arg) 
{
    static int sint = 0;
    printf("myIntFunction() => %d\n", sint);
    return sint += arg;
}
void part5()
{
    int(*func)(int);              
    typedef int(*int_func)(int);  
    int_func tdfunc;              
    func = &myIntFunction;        
    tdfunc = &myIntFunction;
    func(2);                      
    tdfunc(3);
}
void part6()
{
    int a[10];              
    int marr[10][10];       
    int(*ptr2arr[10])[10];  
    int* arr2ptr[10][10];   
    int i, *iptr;
    for (i = 0; i < 10; i++) 
        ptr2arr[i] = &marr[i];
    iptr = (int*) ptr2arr[0]; 
}
typedef struct _ivector { 
    int  size;            
    int  capacity;
	int* data;
} ivector;
ivector* iv_new() 
{
    ivector* iv = malloc(sizeof(ivector));
    iv->size     = 0;   
    iv->capacity = 0;   
	iv->data     = NULL;
    return iv;
}
void iv_free(ivector* iv) 
{
	if (iv) 
	{
		if (iv->data) 
			free(iv->data); 
		free(iv);           
	}
}
void iv_add(ivector* iv, int item) 
{
    if (iv->size == iv->capacity) 
    {
        iv->capacity += 4 + iv->capacity / 2; 
        iv->data = realloc(iv->data, sizeof(int) * iv->capacity);
    }
    iv->data[iv->size++] = item; 
}
void part7()
{
    printf("--------------------------\n");
    printf("ivector test:\n");
    ivector* iv = iv_new();  
    iv_add(iv, 10);          
    iv_add(iv, 20);
    iv_add(iv, 30);
    for (int i = 0; i < iv->size; ++i) 
        printf("ivec[%d] = %d\n", i, iv->data[i]);
    iv_free(iv); 
}
int main(int argc, char** argv)
{
    part1();
    part2();
    part3();
    part4();
    part5();
    part6();
    part7();
	#if _MSC_VER
		system("pause");
	#endif
    return 0;
}