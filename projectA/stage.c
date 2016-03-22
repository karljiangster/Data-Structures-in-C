/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * stage operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* to string for stage */ 
char *stage_tos(stage stg) { 
    
    char* scene_str = scene_tos(stg.s); 
    char* cam_str = camera_tos(stg.c); 

    int buf_size = strlen(scene_str) + strlen(cam_str); 
    char buf [buf_size + 50];  
    sprintf(buf, "STAGE DATA:\n\n"); 
    strcat(buf, scene_str);
    strcat(buf, "\n"); 
    strcat(buf, cam_str);    
   
    return strdup(buf);  
} 

/* print contents to file f */ 
void stage_show(FILE *f, stage stg) { 
    fprintf(f, "%s", stage_tos(stg) ); 
} 
