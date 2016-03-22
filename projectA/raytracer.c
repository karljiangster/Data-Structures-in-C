/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * Raytracer logic
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <float.h> 
#include "raytracer.h" 


/* checks whether the given x and y points are within camera bounds */ 
void _check_bounds(camera c, unsigned int x, unsigned int y) {
    
    if(x < c.w && y < c.h) 
	return; 
    fprintf(stderr, "Parameters out of bounds of camera\n."); 
    exit(1); 
} 


/* given physical coordinates, converts to logical and returns */ 
location logical_loc(camera c, unsigned int x, unsigned int y) { 

    _check_bounds(c, x, y);
    double x_crd, y_crd;
    double width = c.w; 
    double height = c.h;     
    double x_w = x; 
    double y_h = y; 

    if(width > height) { 
	x_crd = -1 + 1 / width + 2 * x_w / width;
	y_crd = height / width - 1 / width - 2 * y_h / width; 
    }
    else {  	
	x_crd = -width / height + 1 / height + 2 * x_w / height; 
    	y_crd = 1 - 1 / height - 2 * y_h / height; 
    } 

    return xyz_expr(x_crd, y_crd, 0); 
} 


/* follow a ray from the camera into a scene, test for intersections 
 * with any spheres objects and find either the closest intersection 
 * or miss, use the surface_color function to compute the color.
 */ 
color trace_ray(scene s, ray r) { 
    color ans = s.bg;
    double t = DBL_MAX; //max double 1.7E+308 
    for(obj_list* objs = s.objects; objs != NULL; objs = objs -> next) { 
	
	hit_test hit = intersect(r, objs -> obj); 
	if(hit.miss == HIT && hit.t < t) { 
	    t = hit.t; 
	    ans = object_color(objs -> obj, hit.hit_point);  
	} 
    } 

    return ans; 

} 


/* run trace_ray over all rays though each pixel in the image, 
 * compute the color corresponding to each ray, and write an 
 * image, pixel by pixel, to the file pointed to by f.
 */ 
void render(FILE *f, stage g) { 

    fprintf(f, "P3\n%d %d\n255\n", g.c.h, g.c.w);
    for(unsigned int y = 0; y < g.c.h; ++y) { 
	for(unsigned int x = 0; x < g.c.w; ++x) { 
	    direction dir = xyz_sub(logical_loc(g.c, x, y),  g.c.loc); 
	    color col = trace_ray(g.s, ray_expr(g.c.loc, dir) ); 
	    color_show_bytes(f, col); 
	} 
    }
} 

