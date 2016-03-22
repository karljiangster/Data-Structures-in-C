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

/* testing intersect */ 
void evidence_intersect() { 

    printf("Testing Intersect\n"); 

    //going to make several types of vectors and objects
    xyz ulcs [5]; 
    location vs [5];
    poster posters[5];
    sphere spheres[5]; 
    object objects[10]; //will contain spheres and posters 
    int radius = 3; //just one type of radius 

    double w = 10, h = 15;  
    color shine = color_expr(0, 0, 0); 
    color (*surface_color)(object*, location) = &sc; 

    for(int i = 0; i < 5; ++i) { 
	xyz input = xyz_expr(i, i, 1 + i); 
	ulcs[i] = input; 
	vs[i] = input; 	
	
	posters[i] = poster_expr(ulcs[i], w, h, surface_color, shine);
	spheres[i] = sphere_expr(vs[i], radius, surface_color, shine); 	
	
	object op;
	op.tag = POSTER; 
	op.o.p = posters[i];
	objects[2 * i] = op; 

	object os; 
	os.tag = SPHERE; 
	os.o.s = spheres[i]; 
	objects[2 * i + 1] = os; 
    } 	
    
    location ray_origins [3]; 
    direction ray_dirs [3]; 
    ray rays [3]; 
    hit_test tests [10];

    for(int i = 0; i < 3; ++i) { 
	ray_origins[i] = xyz_expr(i - 1, i - 1, i - 1); 
	ray_dirs[i] = xyz_expr(i * i, i * i, i * i); 
	rays[i] = ray_expr(ray_origins[i], ray_dirs[i] ); 
	 	
	for(int j = 0; j < 10; ++j) { 
	    tests[i] = intersect(rays[i], objects[j] );
	    hit_test_show(stderr, tests[i]);   
	} 

	puts(" "); 
	 
    } 

} 

int main() { 

    evidence_intersect(); 
    return 0; 
} 

 
