/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * ray operations 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* constructor for ray */ 
ray ray_expr(location origin, direction dir) { 

    ray r; 
    r.origin = origin; 
    r.dir = dir; 
    return r; 
} 


/* ray_position: interpreting direction as velocity, calculate position
 * of ray r after time t. 
 */
xyz ray_position(ray r, double t) { 
    
    return xyz_add(r.origin, xyz_scale(t, r.dir) ); 
} 


/* to string for ray */ 
char *ray_tos(ray r) { 
    
    char buf [75]; 
    sprintf(buf, "RAY: %s + t * %s\n", xyz_tos(r.origin), xyz_tos(r.dir) ); 
    return strdup(buf); 
} 

/* prints contents of ray to file f */ 
void ray_show(FILE *f, ray r) { 

    fprintf(f, "%s", ray_tos(r) ); 
} 
