/* Karl Jiang, karljiang 
* CS 152, Winter 2016
* HW2
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

/* Given n, returns the nth harmonic number as a double. */ 
double nth_harmonic(unsigned int n){ 
    
    double sum = 0; 
    for(int i = 1; i <= n; ++i) { 
	sum += 1.0 / i;  
    }  
    return sum; 
}  

/* Returns the least value n s.t. nth harmonic number is at least x. */ 
unsigned int harmonic_solve(double x) { 
    
    double sum = 0.0;
    int n = 0;  
    while(sum < x) {
	n++;  
	sum += 1.0 / n;  
    }   
    return n; 
}  

/* integrates sqrt(1- x^2) with x: [0,1] to calculate pi. Uses reimann sums. */  
double pi_approx(unsigned int n) { 
    
    if(!n) 
	return 0; 
    double area = 0; 
    double width = 1.0 / n; 
    double x = 0; 
    
    while(x < 1.0) {
	double height = sqrt(1 - x * x);  
	area += (width * height); 
	x += width; 	
    } 
    return 4 * area; 
}  

/* prints the circle s.t. x^2 + y^2 <= radius^2.*/ 
void circle(unsigned int radius) { 
 
    int area = radius * radius; 
    int rminus = -1 * radius;  
    
    for(int y = radius; y >= rminus; --y) { 
	for(int x = radius; x >= rminus; --x) { 
	    if(y * y + x * x <= area) 
		printf("*");
	    else
		printf(" "); 
	} 
	printf("\n");
    }
} 

/* prints a matrix of triangles given their height, num of rows and cols in matrix. */ 
void triangles(unsigned int rows, unsigned int cols, 
unsigned int tri_height) {
    
    for(int r = 0; r < rows; ++r) { 
	for(int y = 0; y < tri_height; ++y) {
	    for(int c = 0; c < cols; ++c) { 
		for(int x = 0; x < tri_height; ++x) { 
		    if(x <= y) 
			printf("*");
		    else 
			printf(" "); 
		}   
	    }
	    printf("\n");
	}  
    }      
} 

/* Given numerator n and denominator d, gives the quotient q
* and remainder r as out parameters. 
*/ 
void int_div(unsigned int n, unsigned int d, unsigned int* q, unsigned int* r) { 

    if(!d) { 
	fprintf(stderr, "Can't divide by negative number."); 
	exit(1); 
    } 

    unsigned int quotient = 0; 
    while(n >= d) { 
	n = n - d; 
	quotient++; 
    }     
    
    *q = quotient; 
    *r = n; 
} 
