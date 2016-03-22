/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * sphere operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* Makes a poster */ 
poster poster_expr(location ulc, double w, double h, color(*sc)(object*,
	    location), color sh) { 

    poster l; 
    l.upper_left = ulc; 
    l.w = w; 
    l.h = h; 
    l.surface_color = sc; 
    l.shine = sh; 
    return l; 
} 

/* to string for poster */ 
char *poster_tos(poster s) { 

    char buf[75]; 
    sprintf(buf, "POSTER\n\tulc: %s\n\twidth: %f\n\theight: %f\n", 
	    xyz_tos(s.upper_left), s.w, s.h); 
    return strdup(buf); 
} 

/* print contents to file f */ 
void poster_show(FILE *f, poster s) { 
    fprintf(f, "%s", poster_tos(s) ); 
} 

