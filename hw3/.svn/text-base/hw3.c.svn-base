/* Karl Jiang 
* CMSC 152, Winter 2016
* Lab 3
*/ 

#include <stdio.h> 
#include <stdlib.h> 

/* returns a pseudo-boolean int representing true if and only if all
* elements of the array a with length alen are positive.
*/
int all_positive(int a[], unsigned int alen) { 

    for(int i = 0; i < alen; ++i) { 
	if(a[i] <= 0) 
	    return 0; 
    } 
    return 1; 
} 

/* returns a pseudo-boolean int representing true if and only if all
* elements of the array a with length alen are positive.
*/
int exists_positive(int a[], unsigned int alen) { 

    for(int i = 0; i < alen; ++i) { 
	if(a[i] > 0) 
	    return 1; 
    } 
    return 0; 
} 

/* returns the index of the first (i.e., with the smallest index)
* element in the array that is positive. If no element is positive,
* returns -1.
*/
int first_positive(int a[], unsigned int alen) { 

    for(int i = 0; i < alen; ++i) { 
	if(a[i] > 0) 
	    return i; 
    } 
    return -1;
} 

/* returns the number of positive numbers in the array. */
unsigned int number_positives(int a[], unsigned int alen) { 
    
    int count = 0; 
    for(int i = 0; i < alen; ++i) { 
	if(a[i] > 0) 
	    count++; 
    } 
    return count;  
} 

/* changes the sign of every element in the array */
void negate(int a[], unsigned int alen) { 
    
    for(int i = 0; i < alen; ++i) { 
	a[i] = -1 * a[i]; 
    }  
} 

/* returns a new array containing partial sums over the provided array */
int* partial_sums(int a[], unsigned int alen) { 
    
    int* partials = (int*) malloc( sizeof(int) * (alen + 1) ); 
    partials[0] = 0; 
    int sum = 0; 

    for(int i = 0; i < alen; ++i) { 
	sum += a[i]; 
	partials[i + 1] = sum; 
    }  
    return partials;   
} 

/* modifies the passed-in array such that each value appears,
* in the updated array, one more spot to the "right" than before
*/
void rotate_right(int a[], int alen) { 

    if(!alen) 
	return; 
    int last  = a[alen - 1]; 
    for(int i = alen - 1; i > 0; --i) { 
	a[i] = a[i - 1]; 
    } 
    a[0] = last; 
} 

  
/* Given int n, updates aray factors [] that contains the factors of n in
ncreasing order of index. Updates flen as well, the number of factors.
* Note that if flen is not large enough, an error will occur.
*/
void factorization(unsigned int n, unsigned int factors[],
unsigned int* flen) { 

    if(n == 0 || n == 1) { 
	*flen = 0;  
	return; 
    } 
    unsigned int div  = 2, num_fact = 0;
    while(num_fact + 1 < *flen && div * div <= n) {  
	if(n % div == 0) { 
	    factors[num_fact] = div;
	    num_fact++;
	    n = n / div;  
	}  
	else if(div != 2)  
	    div += 2; 
	else //should only run if div = 2, the first value it takes. 
	    div ++; 	   
    } 
    if(div * div > n) { 
	factors[num_fact] = n; 
	num_fact++;  
	*flen = num_fact;  
    } 
    else { 
    	fprintf(stderr, "flen is not large enough."); 
	exit(1); 
    }
    
	 
} 


/* Takes in an array of code numbers and its length and returns
* a string with the decoded message.
*/
char* decode(unsigned int a[], unsigned int alen) { 

    char *code = (char*) malloc( sizeof(char) * (alen + 1) );     
    for(int i = 0; i < alen; ++i) {
	if(!a[i]) 
	    code[i] = ' ';  
	else if(a[i] > 26) { 
	    fprintf(stderr, "code goes beyond standard alpha numerics."); 
	    exit(1); 
	} 
	else 
	    code[i] = 'A' + (a[i] - 1);  
    }
    code[alen] = '\0'; 
    return code;  
} 
