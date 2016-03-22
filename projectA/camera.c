/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * camera operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* makes new camera with height and width of physical plane, location */ 
camera camera_expr(unsigned int w, unsigned int h, location loc) { 

    camera cm; 
    cm.h = h;
    cm.w = w; 
    cm.loc = loc; 
    return cm; 
} 


/* to string for camera */ 
char *camera_tos(camera cm) { 
    
    char buf [75];
    sprintf(buf, "CAMERA:\nheight: %u\t|width: %u\t|loc: %s\n", 
	   cm.h, cm.w, xyz_tos(cm.loc) );  
    return strdup(buf); 
} 

/* print contents to file f */ 
void camera_show(FILE *f, camera cm) { 
    fprintf(f, "%s", camera_tos(cm) ); 
} 
