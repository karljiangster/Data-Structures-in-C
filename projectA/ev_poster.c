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
/* test the poster struct and its functions */ 
void evidence_poster() { 

    printf("TESTING POSTER\n\n");
    xyz ulc = xyz_expr(0, 0, 0); 
    double w = 1.5, h = 1; 
    color shine = color_expr(0.1, 0.1, 0.1); 
    color (*surface_color)(object*, location) = &sc; 
    
    poster p = poster_expr(ulc, w, h, surface_color, shine); 
    poster_show(stdout, p); 

} 


int main() { 
    evidence_poster(); 
    return 0; 
} 
