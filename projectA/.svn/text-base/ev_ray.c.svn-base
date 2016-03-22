/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "raytracer.h" 

/* test the ray struct and its functions */ 
void evidence_ray() { 

    printf("TESTING RAY\n\n"); 
    location origin = xyz_expr(0, 0, 0); 
    direction dir = xyz_expr(1, 1, 1); 
    ray r = ray_expr(origin, dir); 
    printf("%s\n", ray_tos(r) ); 

    printf("%s\n", xyz_tos(ray_position(r, 1) ) ); 
    ray_show(stdout, r); 
} 


int main() { 
    evidence_ray(); 
    return 0; 
} 
