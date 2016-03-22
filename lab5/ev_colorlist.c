/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "colorlist.h" 

/* test the colorlist structs and its functions */ 
void evidence_colorlist() { 

    printf("TESTING COLORLIST\n\n"); 

    int size = 6; 
    color* colors [6]; 
    double param = 0.2; 
    for(int i = 0; i < size; ++i) { 
	colors[i] = color_new(i * param, i * param, i * param); 
    } 

    colorlist* cl = cl_cons( colors[0], NULL);
    colorlist* tmp = cl; 	
    for(int i = 1; i < 6; ++i) { 
	tmp -> next = cl_cons( colors[i], NULL); 
	tmp = tmp -> next; 
    }

    cl_print(cl); 

    printf("expected length: 6\t|actual: %d\n", cl_length(cl) );  
    printf("expected max red: 1.000\t|actual: %.3f\n", cl_max_red(cl) ); 
    
    //test null cl
    colorlist* nada = NULL; 
    printf("expected length: 0\t|actual: %d\n", cl_length(nada) ); 

    cl_max_red(nada);  

} 


int main() { 
    evidence_colorlist(); 
    return 0; 
} 
