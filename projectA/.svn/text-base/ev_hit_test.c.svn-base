/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* test the hit test structs and its functions */ 
void evidence_hit_test() { 

    printf("TESTING HIT TEST\n\n"); 
    
    double t = 5.1; 
    location hit_point = xyz_expr(4, 7, 5); 

    hit_test hit; 
    hit.miss = 1; 
    hit.hit_point = hit_point; 
    hit.t = t; 
    hit_test_show(stderr, hit); 

    hit_test miss; 
    hit.miss = 0; 
    hit_test_show(stderr, miss); 

    hit_test exp_test = hit_test_expr(5, hit_point); 
    hit_test_show(stderr, exp_test); 

    hit_test_show(stderr, miss_expr() ); 
}


int main() { 
    evidence_hit_test(); 
    return 0; 
} 
