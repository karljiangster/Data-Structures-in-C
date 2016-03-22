/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* checks if each input is in the interval [0, 1]. throws error */ 
void _in_range(double r, double g, double b) { 
    
    double inputs [] = {r, g, b}; 
    for(int i = 0; i < 3; ++i) { 
	if(inputs[i] < 0 || inputs[i] > 1) { 
	    fprintf(stderr, "Inputs outside interval"); 
	    exit(1);   
	} 	    
    } 
} 

/* enforce that each value is on interval [0,1] */
color color_expr(double r, double g, double b) { 

    _in_range(r, g, b); 
    color new = {r, g, b}; 
    return new; 
} 

/* creates a duplicate of the given color */
color color_dup(color c) { 
    return color_expr(c.r, c.g, c.b); 
} 

/* multiply the components of two colors */
color color_modulate(color c1, color c2) { 
    return color_expr(c1.r * c2.r, c1.g * c2.g, 
	    c1.b * c2.b);
} 

/* pushes the given double to 0 or 1 if ![0,1], whichever is closer */ 
double _force(double d) { 

    if(d < 0) 
	return 0; 
    if(d > 1) 
	return 1; 
    return d; 
} 

/* scale each component by given scalar */
color color_scale(double s, color c) {
     
    return color_expr(_force(s * c.r), 
	    _force(s * c.g), _force(s * c.b) ); 
} 

/* add components of colors */
color color_add(color c1, color c2) { 
    return color_expr(_force(c1.r + c2.r), 
		_force(c1.g + c2.g), 
		_force(c1.b + c2.b) ); 
} 

/* produce a string representation of a color */
char* color_tos(color c) { 

    char buf[50]; 
    sprintf(buf, "(%.3f, %.3f, %.3f)", c.r, c.g, c.b); 
    return strdup(buf); 
}

/* prints contents of color to file f */
void color_show(FILE *f, color c) { 
    
    fprintf(f, "%s", color_tos(c) ); 
} 


/* scales on interval [0, 255]. Assumes d is on [0, 1] */ 
int _byte_val(double d) { 
    return round(d * 255); 
} 

/* print three integer values on [0,255]. */
void color_show_bytes(FILE *f, color c) { 
    fprintf(f, "%d %d %d\n", _byte_val(c.r), 
		    _byte_val(c.g), 
		    _byte_val(c.b) ); 
} 

