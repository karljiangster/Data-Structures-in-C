/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * object list operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* constructs a object list the heap */
obj_list *ol_cons(object o, obj_list *os) { 

    obj_list* ol = (obj_list*) malloc(sizeof(obj_list) ); 
    ol -> obj = o; 
    ol -> next = os; 
    return ol; 
} 

/* returns obj_list with object s and null pointer */
obj_list *ol_singleton(object s) { 

    return ol_cons(s, NULL); 
} 

/* returns num of objects ib obj_list */ 
int _ol_size(obj_list* os) { 


    int size = 0; 
    obj_list* tmp; 
    for(tmp = os; tmp != NULL; tmp = tmp -> next) { 
	size++; 
    } 
    return size; 
} 
/* to string for obj_list */
char *ol_tos(obj_list *os) { 
 
    int len = _ol_size(os);     
    char buf [100 * len]; 
    sprintf(buf, "OBJECTLIST:\n"); 

    obj_list* tmp = os; 
    for(int i = 0; i < len; ++i) { 
	char header [20]; 
	sprintf(header, "\tObject %d\n", i); 
	strcat(buf, header); 
	strcat(buf, object_tos(tmp -> obj) );
		
	tmp = tmp -> next; 
    }
    return strdup(buf);  
} 

/* prints contents to file */
void ol_show(FILE *f, obj_list *os) { 

    fprintf(f, "%s", ol_tos(os) ); 
} 

/* frees the object and its contents */
void ol_free(obj_list *ss) { 

    obj_list* tmp = ss; 
    while(tmp != NULL) { 
	
	obj_list* willdie = tmp; 
	tmp = tmp -> next; 
	free(willdie); 
    } 
} 

