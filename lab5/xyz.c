/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "xyz.h" 

/* create new vector with given parameters */ 
xyz *xyz_new(double x, double y, double z) { 
    
    xyz* new = (xyz*) malloc( sizeof(xyz) ); 
    new -> x = x; 
    new -> y = y; 
    new -> z = z; 
    return new; 

} 

/* create a fresh vector with same components as argument */
xyz *xyz_dup(xyz *v) { 
   return xyz_new(v -> x, v -> y, v -> z);  
} 

/* add two vectors */
xyz *xyz_add(xyz *v1, xyz *v2) { 

    return xyz_new(v1 -> x + v2 -> x, v1 -> y + v2 -> y, 
	    v1 -> z + v2 -> z); 
} 

/* subtract the second vector from the first */
xyz *xyz_sub(xyz *v1, xyz *v2) { 
    
     return xyz_new(v1 -> x - v2 -> x, v1 -> y - v2 -> y, 
	    v1 -> z - v2 -> z); 
}

/* scale the components of a vector by scalar s */
xyz *xyz_scale(double s, xyz *v) { 

    return xyz_new(s * v -> x, s * v -> y, s * v -> z);  
} 

/* negate a vector */
xyz *xyz_neg(xyz *v) { 	

    return xyz_scale(-1, v);  
}

/* compute the dot product of two vectors */
double xyz_dot(xyz *v1, xyz *v2) { 

    int sum_x = v1 -> x * v2 -> x; 
    int sum_y = v1 -> y * v2 -> y; 
    int sum_z = v1 -> z * v2 -> z; 
    return sum_x + sum_y + sum_z;  

} 


/* compute the magnitude of a vector */
double xyz_mag(xyz *v) { 

    double dot = xyz_dot(v, v);
    return sqrt(dot);  
}

/* normalize the vector */
xyz *xyz_norm(xyz *v) { 
    
    double mag = xyz_mag(v); 
    if(mag == 0) 
	return v; 
    return xyz_scale(1/mag, v); 
} 

/* produce a string representation of a vector */
char *xyz_tos(xyz *v) { 
    
    char buf[50]; 
    sprintf(buf, "(%.3f, %.3f, %.3f)", v -> x, v -> y, v -> z); 
    return strdup(buf);  
} 

/* print the string representation of a vector */
void xyz_print(xyz *v) { 

    printf("%s", xyz_tos(v) ); 
}
