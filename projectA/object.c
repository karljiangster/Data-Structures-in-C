/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * object operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* returns color of object at point */ 
color object_color(object obj, location loc) { 
    
    if(obj.tag == SPHERE) 
	return obj.o.s.surface_color(&obj, loc); 
    return obj.o.p.surface_color(&obj, loc); 

} 


/* expr for object sphere */  
object obj_sphere(sphere s) { 

    object os; 
    os.tag = SPHERE; 
    os.o.s = s; 
    return os; 
} 

/* expr for object poster */ 
object obj_poster(poster p) { 

    object op; 
    op.tag = POSTER; 
    op.o.p = p; 
    return op; 
} 

/* to string for object */ 
char *object_tos(object o) { 
    if(o.tag == POSTER) 
	return poster_tos(o.o.p);
    return sphere_tos(o.o.s); 
} 

/* print contents to file f */ 
void object_show(FILE *f, object o) { 
    fprintf(f, "%s", object_tos(o) ); 
} 
