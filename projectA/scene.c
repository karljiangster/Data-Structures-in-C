/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * scene operations
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* to string for scene */ 
char *scene_tos(scene sc) { 
    
    char* ol_str = ol_tos(sc.objects); 
    char* col_str = color_tos(sc.bg); 

    int buf_size = strlen(ol_str) + strlen(col_str); 
    char buf [buf_size + 50];  
    sprintf(buf, "SCENE DATA:\n\n"); 
    strcat(buf, col_str);
    strcat(buf, "\n"); 
    strcat(buf, ol_str);    
   
    return strdup(buf);  
} 

/* print contents to file f */ 
void scene_show(FILE *f, scene sc) { 
    fprintf(f, "%s", scene_tos(sc) ); 
} 
