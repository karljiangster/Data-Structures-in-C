/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * intersect 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* helper for intersect of object is sphere */ 
hit_test _sphere_intersect(ray r, sphere s) { 

    location ro = r.origin; 
    direction rd = xyz_norm(r.dir); 
    location sc = s.center; 
    double sr = s.radius; 

    location A = xyz_sub(ro, sc); 
    double B = xyz_dot(A, rd);
    double C = xyz_dot(A, A) - sr * sr; 
    double D = B * B - C; 
    double t = -B - sqrt(D); 

    if(D <= 0 || t <= 0)  
	return miss_expr();
    return hit_test_expr(t, ray_position(r, t) ); 

} 

/* returns true (1) if the ray at time t is within the poster bounds. False otherwise */ 
int _within_poster_bounds(location position, poster p) { 

   
    double left_bound = p.upper_left.x; 
    double right_bound = p.upper_left.x + p.w; 
    double upper_bound = p.upper_left.y + p.h; 
    double lower_bound = p.upper_left.y;  
   
    if(position.x > left_bound && position.x < right_bound && 
	    position.y > lower_bound && position.y < upper_bound) { 
	return 1; 	
    }
    return 0; 
} 


/* helper function for hit_test when object is poster */ 
hit_test _poster_intersect(ray r, poster p) { 

    location ro = r.origin; 
    direction rd = xyz_norm(r.dir);
    direction n = xyz_expr(0, 0, -1); 
    double d = p.upper_left.z;  
    double t =(xyz_dot(ro, n) + d) / (xyz_dot(rd, n) );
 
    location position = ray_position(r, t);
  
    int in_bounds = _within_poster_bounds(position, p);  
    
    if(t > 0 && in_bounds == 1) 
	return hit_test_expr(t, position);  
    else  
	return miss_expr(); 
}  

/* returns hit_test on ray hitting object */ 
hit_test intersect(ray r, object obj) { 

    if(obj.tag == SPHERE) 
	return _sphere_intersect(r, obj.o.s) ; 
    return _poster_intersect(r, obj.o.p); 
} 
