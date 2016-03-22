/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * hit_test operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/*expr for hit_test if a miss */ 
hit_test miss_expr() { 

    hit_test miss; 
    miss.miss = MISS; 
    return miss; 
} 

/* expr for hit_test, provided it hits. Refine in Proj B */ 
hit_test hit_test_expr(double t, location hit_point) { 

    hit_test ht; 
    ht.miss = HIT; 
    ht.t = t; 
    ht.hit_point = hit_point; 
    return ht; 

}  

/* to string for hit_test */ 
char *hit_test_tos(hit_test t) { 
    
    if(t.miss == MISS) 
	return strdup("HIT TEST:\nNO HIT\n\n"); 	
    char buf [50 * 4]; //2 colors, 2 xyz, all apprx 50 char 
    sprintf(buf, "HIT TEST:\ntime: %f\t|hit point: %s\n\n", 
	    t.t, xyz_tos(t.hit_point) );

    return strdup(buf); 
} 

/* print contents to file f */ 
void hit_test_show(FILE *f, hit_test t) { 
    fprintf(f, "%s", hit_test_tos(t) ); 
} 
