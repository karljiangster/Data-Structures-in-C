#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* ===================================== */ 
/* === light operations => light.c === */ 
/* ===================================== */ 


const char *_light_fmt = "light(\n direction: %s\n color:%s\n)"; 

char *light_tos(light l) { 

    char buf [50]; 
    sprintf(buf, _light_fmt, xyz_tos(l.dir), color_tos(l.c) ); 
    return strdup(buf); 
} 


void light_show(FILE *f, light l) {

   fprintf(f, "%s", light_tos(l) );  

} 


