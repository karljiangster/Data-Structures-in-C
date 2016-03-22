/* Karl Jiang, karljing
 * CS152, Winter 2016
 * Lab 1 
 */


#include <stdio.h> 
#include <stdlib.h> 
#include "expt.h" 

/* evidence_expt: test expt */ 
void evidence_expt() { 
    
    printf("*** testing expt\n");
    printf("-expecting 1: %ld\n", expt(2, 0) ); 
    printf("-expecting 256: %ld\n", expt(2, 8) ); 
    printf("-expecting 2: %ld\n", expt(2, 1) ); 
    printf("-expecting 1: %ld\n", expt(1, 0) ); 
    printf("-expecting 1: %ld\n", expt(1, 10) ); 
    printf("-expecting 0: %ld\n", expt(0, 3) ); 
    printf("-expecting 1: %ld\n", expt(0, 0) ); 
    printf("-expecting -3: %ld\n", expt(-3, 1) ); 
    printf("-expecting 9: %ld\n", expt(-3, 2) ); 

}

/* evidence_expt: test ss */ 
void evidence_ss() { 

    printf("*** testing ss\n");
    printf("-expecting 1: %ld\n", ss(2, 0) ); 
    printf("-expecting 256: %ld\n", ss(2, 8) ); 
    printf("-expecting 2: %ld\n", ss(2, 1) ); 
    printf("-expecting 1: %ld\n", ss(1, 0) ); 
    printf("-expecting 1: %ld\n", ss(1, 10) ); 
    printf("-expecting 0: %ld\n", ss(0, 3) ); 
    printf("-expecting 1: %ld\n", ss(0, 0) ); 
    printf("-expecting -3: %ld\n", ss(-3, 1) ); 
    printf("-expecting 9: %ld\n", ss(-3, 2) ); 

} 

/* evidence_expt: test ssm */ 
void evidence_ssm() { 

    printf("*** testing ssm\n");
    printf("-expecting 24: %d\n", ssm(2, 10, 1000) ); 
    printf("-expecting 0: %d\n", ssm(0, 8, 7) ); 
    printf("-expecting 2: %d\n", ssm(2, 9, 3) ); 
    printf("-expecting 1: %d\n", ssm(3, 0, 1000) ); 
    printf("-expecting 1: %d\n", ssm(0, 0, 100) ); 
    printf("-expecting 1: %d\n", ssm(2, 60, 0) ); //throw error here 
} 


int main(int argc, char *argv[]) { 
    
    printf("CS 152 Lab1\n"); 
    evidence_expt(); 
    evidence_ss(); 
    evidence_ssm(); 
    return 0; 
} 
