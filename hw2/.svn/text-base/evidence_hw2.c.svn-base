/* Karl Jiang, karljiang 
* CS 152, Winter 2016
* HW2
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include "hw2.h" 


void evidence_nth_harmonic() { 

    printf("\nTesting nth harmonic \n"); 

    int nths [] = {0, 1, 5, 100, 35635645}; 
    double expt [] = {0.0, 1.0, 2.28333333333, 5.187377517639621, 17.966072637866933}; 
    
    int cases = 5; 
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %f \t| actual: %f \t| \n", expt[i], nth_harmonic( nths [i] ) );	
    } 
} 


void evidence_harmonic_solve() { 
    
    printf("\nTesting harmonic_solve \n"); 

    double inputs [] = {-57.8, 0.0, 1.0, 2.283333331, 5.1873775176391, 17.96607263701}; 
    unsigned int expt [] = {0, 0, 1, 5, 100, 35635645}; 
    
    int cases = 6; 
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %u \t| actual: %u \t| \n", expt[i], harmonic_solve( inputs [i] ) );	
    } 

}


void evidence_pi_approx() { 

    printf("\nTesting pi_approx \n"); 

    unsigned int inputs [] = {0, 1, 4, 100}; 
    double expt [] = {0.0, 4.0, 3.49570907, 3.16041703178}; 
     
    int cases = 4; 
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %f \t| actual: %f \t| \n", expt[i], pi_approx( inputs [i] ) );	
    }    
}


void evidence_circle() { 
    
    printf("\nTesting pi_approx \n"); 

    unsigned int inputs [] = {0, 1, 5}; 
    char* expt [] = {"*", " *\n***\n *", "     *\n  *******  \n ********* \
\n ********* \n ********* \n***********\n ********* \n ********* \
\n ********* \n  *******  \n     *     "};     
    int cases = 3; 
    for(int i = 0; i < cases; ++i) { 
	printf("expected: \n%s \nactual: \n", expt[i]); 
	circle(inputs[i]); 
	printf("\n");
    } 
     
} 

void evidence_triangles() { 

    printf("\nTesting triangles \n"); 

    unsigned int rows [] = {2, 0, 1};
    unsigned int cols [] = {3, 1, 1}; 
    unsigned int heights [] = {4, 0, 1};   
    char* expt [] = { 
    "*   *   *\n**  **  **\n*** *** ***\n************\n*   *  \
 *   \n**  **  **  \n*** *** *** \n************", "", "*"};   
     
    int cases = 3; 
    for(int i = 0; i < cases; ++i) { 
	printf("expected: \n%s \nactual: \n", expt[i]); 
	triangles(rows[i], cols[i], heights[i]);
	printf("\n");
	 
    }     
} 
 

void evidence_int_div() { 
 
    printf("\nTesting int_div \n"); 

    unsigned int ns [] = {0, 1, 4, 10, 15, 21, 33, 48493, 4294967295, 12, 7}; 
    unsigned int ds [] = {1, 3, 5, 2, 3, 8, 16, 17, 35345, 4294967295, 0};
    unsigned int qs [] = {0, 0, 0, 5, 5, 2, 2, 2852, 121515, 0, 0}; 
    unsigned int rs [] = {0, 1, 4, 0, 0, 5, 1, 9, 19620, 12, 0};    
     
    int cases = 11; 
    
    unsigned int q = 0, r = 0; 
    unsigned int *qp = &q, *rp = &r;  
 
    for(int i = 0; i < cases; ++i) { 
	printf("expected (q, r) : (%u, %u) \t| actual: ", qs[i], rs[i]); 
	int_div(ns[i], ds[i], qp, rp); 
	printf("(%u, %u) \n", q, r);     
    } 
} 
 
int main() { 
    
    evidence_nth_harmonic(); 
    evidence_harmonic_solve(); 
    evidence_pi_approx();
    evidence_triangles();
    evidence_circle();
    evidence_int_div(); 
    return 0; 
} 
