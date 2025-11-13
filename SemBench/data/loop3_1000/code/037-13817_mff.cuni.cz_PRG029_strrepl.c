#include "stdio.h"
#include "string.h" 
char *strxcpy(char *kam, char *start, int p) {   
 char *dest = kam;
 if (kam != start) {
    if (kam < start) {
        while (p > 0) {
            *kam++ = *start++;
            p--;
        }
    } else {
        kam+=p-1;
        start+=p-1;
        while (p > 0) {
            *kam-- = *start--;
            p--;
        }
    }
 }
 return dest;
}
typedef struct tagSTRREPDATA {
 char   *co;
 char   *cim;
 int    delta;
 int    l_co;
 int    l_cim;
} STRREPDATA, *PSTRREPDATA;
void strrep(char *kde, char *kam, PSTRREPDATA data) 
{
   char *src;
   char *dest;
   char *start = kde;
   int p = 0;
   while (*kde) {  
     src = kde;    
     dest = data->co; 
     while ((*src == *dest) && *src) {  
       src++;           
       dest++; 
     }
     if ((*src == *dest) || !(*dest)) {   
       if ((data->delta >= 0))  
         strrep(src, kam + p + data->l_cim, data); 
       strxcpy(kam, start, p);            
       strxcpy(kam + p, data->cim, data->l_cim); 
       if ((data->delta < 0))   
         strrep(src, kam + p + data->l_cim, data);
       return;
     }
     kde++;
     p++;
   }
   p++;                    
   strxcpy(kam, start, p); 
   return;
}
char *strreplace(char *kde, char *co, char *cim) 
{
  STRREPDATA data;              
  data.cim = cim;
  data.co = co;
  data.l_cim = strlen(cim);
  data.l_co = strlen(co);
  data.delta = data.l_cim - data.l_co;
  if (*co) strrep(kde, kde, &data); 
  return kde;
}
char buffer[100] = "abcdefghijcdAAABBBcdZZZcd";
int main(int argc, char* argv[])
{
  printf("%s\n\n", buffer);
  printf("%s\n", strreplace(buffer,"cd","XXX"));
  printf("%s\n", strreplace(buffer,"X","cd"));
  getc(stdin);
  return 0;
}