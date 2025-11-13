#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>  
struct node { 
	void  *data;    
    struct node *next;   
} ;
struct node *mylist = NULL; 
void list_append(void *data)
{  
   struct node *ptr = NULL; 
   struct node *newnode = NULL; 
   newnode = malloc(sizeof(struct node));  
   newnode->data = data; 
   newnode->next = NULL;  
   if(mylist == NULL) 
     {  
		mylist = newnode; 		
     }  		   
   else 
     {  
	     for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 
	       { 
	       } 	    
	   ptr->next = newnode; 
	 }     
}    
void free_list(void) 
{ 
   struct node *ptr, *tmp = NULL;  	  
   if(mylist != NULL) 
     {  
	     for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 
	       { 
			  printf( "Freeing %s\n",  (char *) (ptr->data) );  
			  tmp = ptr; 			 
		      free(tmp); 			      
	       } 	    
	    printf( "Freeing %s\n",  (char *) (ptr->data) ); 
	    free(ptr);   
	 }     
} 	
void print_list(void)
{ 
   struct node *ptr	= NULL;  
    for( ptr = mylist; ptr->next != NULL; ptr = ptr->next ) 	
	   { 
		  printf( "mylist->data = %s\n",  (char *) (ptr->data) );   		 		
	   } 	    
	printf( "mylist->data = %s\n",  (char *) (ptr->data) ); 
}
int main() 
{ 
list_append("foo");  
list_append("bar");  
list_append("baz");   
list_append("one");   
list_append("two");   
list_append("three");   
print_list(); 
free_list();  
return 0;  
} 