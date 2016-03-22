/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "color.h" 

/* test the color structs and its functions */ 
void evidence_color() { 

    printf("TESTING COLOR\n\n"); 
    
    /* out of bound test 
     * color* bad = color_new(1.1, 0.5, 0.2);  
     * color* bad2 = color_new(-0.2, 0.5, 0.2);    
     */ 

    color* colors [3]; 
    colors[0] = color_new(0, 0, 0); 
    colors[1] = color_new(0.5, 0.5, 0.5); 
    colors[2] = color_new(1, 1, 1); 

    for(int i = 0; i < 3; ++i) { 
	color_print( colors[i] ); //tests tostring at same time
	puts(" "); 	
    }
    puts(" "); 

    color* dups [3]; 
    for(int i = 0; i < 3; ++i) { 
	dups[i] = color_dup( colors[i] ); 
	color_print( dups[i] ); 
	puts(" "); 
    }

    color* mod = color_modulate(colors[0], colors[1] ); 
    color_print(mod); 
    puts(" "); 

    color* s1 = color_scale(-2.5, colors[1] ); 
    printf("expected: (0, 0, 0) \t| actual: "); 
    color_print(s1);
    puts(" ");  
    color* s2 = color_scale(100, colors[2] ); 
    printf("expected: (1, 1, 1) \t| actual: "); 
    color_print(s2);
    puts(" ");  
    color* s3 = color_scale(0.5, colors[1] ); 
    printf("expected: (0.25, 0.25, 0.25) \t| actual: "); 
    color_print(s3);
    puts(" "); 

    color* add1 = color_add(colors[0], colors[1]); 
    printf("expected: (0.5, 0.5, 0.5) \t| actual: "); 
    color_print(add1); 
    puts(" ");     
    color* add2 = color_add(colors[1], colors[2]); 
    printf("expected: (1, 1, 1) \t| actual: "); 
    color_print(add2); 
    puts(" ");    

    for(int i = 0; i < 3; ++i) { 
	color_print_bytes( colors[i] ); 
	puts(" "); 	
    } 
} 


int main() { 
    evidence_color(); 
    return 0; 
} 
