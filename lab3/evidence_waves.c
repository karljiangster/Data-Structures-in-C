/* Karl Jiang, karljiang
* CS 152 Winter 
* Lab 3 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include "waves.h" 

void evidence_dist() {

    double x0 [] = {-4.7, -2, 0, 1, 5.7};
    double y0 [] = {-8.7, 7.8, 8, 14, -8.6};  
    double x1 [] = {-4.7, -3, 9.5, 0.999, 6};  
    double y1 [] = {-8.7, 7.8, 8.001, 1, 5.7}; 

    double expt [] = {0, 1, 9.5000001, 13.000000038, 14.3031465}; 
    int cases = 5; 

    for(int i = 0; i < cases; ++i) { 
	printf("expected: %f \t\t| actual: %f \n", expt[i], 
	    dist( x0[i], y0[i], x1[i], y1[i] ) ); 
    }  

} 


int main() { 
    
    evidence_dist(); 
} 
