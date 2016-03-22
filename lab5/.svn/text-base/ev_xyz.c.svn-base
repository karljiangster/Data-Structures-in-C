/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "xyz.h" 

/* test the xyz structs and its functions */ 
void evidence_xyz() { 

    printf("TESTING XYZ\n\n"); 

    xyz* test_a = xyz_new(1, 1, 1); 
    xyz* test_b = xyz_new(-1, 1, 1); 
    xyz* test_c = xyz_new(0, 0, 0); 

    printf("expected: (1, 1, 1) \t| actual: "); 
    xyz_print(test_a); //used xyz_tos in xyz_print, so we test that too
    puts(" "); 

    xyz* c_dup = xyz_dup(test_c); 
    printf("expected: (0, 0, 0) \t| actual: "); 
    xyz_print(c_dup); 
    puts(" "); 
    
    xyz* a_b = xyz_add(test_a, test_b); 
    printf("expected: (0, 2, 2) \t| actual: "); 
    xyz_print(a_b); 
    puts(" "); 

    xyz* a_b_sub = xyz_sub(test_a, test_b); 
    printf("expected: (2, 0, 0) \t| actual: "); 
    xyz_print(a_b_sub); 
    puts(" "); 

    xyz* b_neg = xyz_neg(test_b); 
    printf("expected: (1, -1, -1) \t| actual: "); 
    xyz_print(b_neg); 
    puts(" "); 

    double dot_ab = xyz_dot(test_a, test_b); 
    double dot_bc = xyz_dot(test_b, test_c); 
    printf("expected: A dot B = 1, B dot C = 0\t actual: %3f | %3f)",
	dot_ab, dot_bc); 
    puts(" "); 

    double mag_a = xyz_mag(test_a); 
    printf("expected: %3f \t| actual: %3f", sqrt(3), mag_a);   
    puts(" "); 

    xyz* norm_a = xyz_norm(test_a); 
    xyz* norm_c = xyz_norm(test_c); 
    xyz_print(norm_a); 
    puts(" "); 
    xyz_print(norm_c); //just do a visual inspection here 

    puts(" "); 
} 


int main() { 
    evidence_xyz(); 
    return 0; 
} 
