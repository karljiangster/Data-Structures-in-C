/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* test the logical loc  and its functions */ 
void evidence_logical_loc() { 

    printf("TESTING LOGICAL LOC\n\n"); 
    
    camera cm0 = camera_expr(10, 10, xyz_expr(0, 0, -5) ); 
    location ulc_0 = logical_loc(cm0, 0, 0); 
    location lrc_0 = logical_loc(cm0, 9, 9); 
    xyz_show(stderr, ulc_0); 
    xyz_show(stderr, lrc_0); 
    puts(" "); 
    
    camera cm1 = camera_expr(30, 20, xyz_expr(0, 0, -5) ); 
    location ulc_1 = logical_loc(cm1, 0, 0); 
    location ulc1_1 = logical_loc(cm1, 1, 0); 
    location lrc_1 = logical_loc(cm1, 29, 19); 
    xyz_show(stderr, ulc_1); 
    xyz_show(stderr, ulc1_1); 
    xyz_show(stderr, lrc_1); 
    puts(" "); 

    camera cm2 = camera_expr(10, 14, xyz_expr(0, 0, -5) ); 
    location ulc_2 = logical_loc(cm2, 0, 0); 
    location lrc_2 = logical_loc(cm2, 9, 13); 
    location llc_2 = logical_loc(cm2, 0, 13); 
    xyz_show(stderr, ulc_2); 
    xyz_show(stderr, lrc_2); 
    xyz_show(stderr, llc_2); 
    puts(" "); 

}


/* sc_blue : surface color function that returns blue, always */
color sc_blue(object *o, location loc)
{
    return color_expr(0,0,1);
}


int main(int argc, char *argv[]) { 

    //evidence_logical_loc(); 
    stage g; 
    g.c = camera_expr(300, 300, xyz_expr(0, 0, -5) ); 
    sphere s = sphere_expr(xyz_expr(0, 0, 3), 1, sc_blue, 
	   color_expr(0, 0, 0) );  
 
    obj_list* objs = ol_singleton(obj_sphere(s) );  
    g.s.objects = objs; 
    g.s.bg = color_expr(0, 0, 0);  

    FILE *f = fopen("evidence.ppm", "w"); 
    render(f, g); 
    return 0; 
} 
