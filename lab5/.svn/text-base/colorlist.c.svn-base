/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "colorlist.h" 
#include "color.h" 

/* note: must allocate a new struct on the heap */
colorlist *cl_cons(color *c, colorlist *cs) { 

    colorlist* new = (colorlist*) malloc( sizeof(colorlist) ); 
    new -> c = *c; 
    new -> next = cs; 
    return new; 
} 


/* returns the length of the entire colorlist */ 
unsigned int cl_length(colorlist *cs) { 
    
    unsigned int length = 0; 
    colorlist* tmp; 

    for(tmp = cs; tmp != NULL; tmp = tmp -> next) { 
	length++; 
    } 
    return length; 
}


/* return the maximum red component of all colors */
double cl_max_red(colorlist *cs) { 

    colorlist* tmp = cs; 
    if(!tmp) { 
	fprintf(stderr, "Empty colorlist"); 
	exit(1); 
    } 

    double max_red = tmp -> c.r; 

    for(tmp = cs; tmp != NULL; tmp = tmp -> next) { 
	if(tmp -> c.r > max_red) 
	    max_red = tmp -> c.r; 
    } 

    return max_red; 
        
} 


/* prints contents of colorlist */ 
void cl_print(colorlist *cs) { 

    colorlist* tmp; 
    for(tmp = cs; tmp != NULL; tmp = tmp -> next) { 
	color_print( &(tmp -> c) ); 
	puts(" "); 
    } 
}

/* frees the colorlist */
void cl_free(colorlist *cs) { 
    
    colorlist* tmp = cs; 
    while(tmp) { 
	colorlist* will_die = tmp; 
	tmp = tmp -> next; 
	free(will_die); 
    } 
    	
} 



