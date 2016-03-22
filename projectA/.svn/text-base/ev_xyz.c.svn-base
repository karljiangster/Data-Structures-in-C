/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 

/* test the xyz structs and its functions */ 
void evidence_xyz() { 

    printf("TESTING XYZ\n\n"); 

    xyz test_a = xyz_expr(1, 1, 1); 
    printf("z: %f\n", test_a.z); 
    xyz test_b = xyz_expr(-1, 1, 1); 
    xyz test_c = xyz_expr(0, 0, 0); 

    printf("expected: (1, 1, 1) \t| actual: "); 
    xyz_show(stdout, test_a);
    puts(" "); 

    xyz c_dup = xyz_dup(test_c); 
    printf("expected: (0, 0, 0) \t| actual: "); 
    xyz_show(stdout, c_dup); 
    puts(" "); 
    
    xyz a_b = xyz_add(test_a, test_b); 
    printf("expected: (0, 2, 2) \t| actual: "); 
    xyz_show(stdout, a_b); 
    puts(" "); 

    xyz a_b_sub = xyz_sub(test_a, test_b); 
    printf("expected: (2, 0, 0) \t| actual: "); 
    xyz_show(stdout, a_b_sub); 
    puts(" "); 

    xyz b_neg = xyz_neg(test_b); 
    printf("expected: (1, -1, -1) \t| actual: "); 
    xyz_show(stdout, b_neg); 
    puts(" "); 

    double dot_ab = xyz_dot(test_a, test_b); 
    double dot_bc = xyz_dot(test_b, test_c); 
    printf("expected: A dot B = 1, B dot C = 0\t actual: %3f | %3f)",
	dot_ab, dot_bc); 
    puts(" "); 

    double mag_a = xyz_mag(test_a); 
    printf("expected: %3f \t| actual: %3f", sqrt(3), mag_a);   
    puts(" "); 

    xyz norm_a = xyz_norm(test_a); 
    xyz norm_c = xyz_norm(test_c); 
    xyz_show(stdout, norm_a); 
    puts(" "); 
    xyz_show(stdout, norm_c); //just do a visual inspection here 

    xyz test_d = xyz_expr(-1, -1, -1); 
    double dist = xyz_dist(test_a, test_d); 
    printf("dist: %f\n", dist); 
} 


int main() { 
    evidence_xyz(); 
    return 0; 
} 
