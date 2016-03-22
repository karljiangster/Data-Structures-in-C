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

/* testing object functions */ 
void evidence_object() { 

    printf("Testing Object\n"); 
    xyz ulc = xyz_expr(0, 0, 0); 
    double w = 1.5, h = 1;  
    color shine = color_expr(0.1, 0.1, 0.1); 
    color (*surface_color)(object*, location) = &sc; 
    poster p = poster_expr(ulc, w, h, surface_color, shine); 
    
    object o; 
    o.tag = POSTER;
    o.o.p = p; 
    
    object_show(stderr, o); 

    location v = xyz_expr(0, 0, 0); 
    double r = 3;  
    sphere s = sphere_expr(v, r, surface_color, shine);    
    
    object os;
    os.tag = SPHERE; 
    os.o.s = s; 

    object_show(stderr, os); 
} 

int main() { 

    evidence_object(); 
    return 0; 
} 

 
