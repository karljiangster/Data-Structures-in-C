/*Karl Jiang, karljiang
CS 152, Winter 2016
Lab 1
*/ 

#include <stdio.h> 
#include <stdlib.h> 


/* expt : linear time recursive exponentiation */
long int expt(int a, unsigned int n){
	
    if(n == 0)
	return 1;  	  
    else 
	return a * expt(a, n - 1); 
}


/* ss : exponentiation by successive squaring */
long int ss(int a, unsigned int n) { 
    
    if(n == 0)
	return 1; 
    if(n % 2 == 1) 
	return a * ss(a, n - 1); 
    long int split = ss(a, n/2); 
    return split * split;  
}
 

/* _ssm : exponentiation modulo m by successive squaring
 * this is the helper function for ssm  
 */
int ssm(int a, unsigned int n, unsigned int m) { 
    
    if(m == 0) { 
	fprintf(stderr, "error: cannot use mod 0.\n"); 
	exit(1); 
    }  
    if(n == 0)  
	return 1;  
    if(n % 2) 
	return (a % m) * ssm(a, n-1, m); 
    int split = ssm(a, n/2, m); 
    return (split * split) % m;     
} 
