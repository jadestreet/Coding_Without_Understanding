#include <stdio.h>
#include <stdlib.h>
void print_array(int *a,int len){
for (int i= 0;i<len;i++){
int p = a[i];
int j = i;
while(j>=1 & a[j-1]>p){
a[j] = a[j-1];
j = j-1 ;
}
a[j] = p;}
for(int i = 0;i<len;i++){
printf("%d\n",a[i]);}
}
int main(){
int g[11] = {6,4,2,15,68,8,6,2,7,0,3};
print_array(&*g,11);}