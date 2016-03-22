/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* some random function to test object pointer */ 
color sc(object* o, location intersection) { 

       return color_expr(0, 0, 0); 
} 


/* test the sphere struct and its functions */ 
void evidence_sphere() { 

    printf("TESTING SPHERE\n\n");
    location v = xyz_expr(0, 0, 0); 
    double r = 3; 
    color shine = color_expr(0, 0, 0); 
    color (*surface_color)(object*, location) = &sc; 

    sphere s = sphere_expr(v, r, surface_color, shine); 
    sphere_show(stderr, s); 

} 


int main() { 
    evidence_sphere(); 
    return 0; 
} 
