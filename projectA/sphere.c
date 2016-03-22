/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * sphere operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* constructs a sphere */
sphere sphere_expr(location v, double r, color(*sc)(object *,location), 
	        color sh) { 

    sphere s; 
    s.center = v; 
    s.radius = r; 
    s.surface_color = sc; 
    s.shine = sh; 
    return s; 
} 

/* tostring for sphere */
char *sphere_tos(sphere s) { 
    
    char buf[75]; 
    sprintf(buf, "SPHERE\n\tcenter: %s\n\tradius: %f\n", 
		xyz_tos(s.center), s.radius); 
    return strdup(buf); 
} 

/* display for sphere */
void sphere_show(FILE *f, sphere s) { 
//only going to use stderr for this, 
//fprintf(f, ..); 0 in any show file. 
//file *x  = fopen("f.ppm", "w"); 
    
    fprintf(f, "%s", sphere_tos(s) ); 
} 
