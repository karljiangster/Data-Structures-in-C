/* Karl Jiang
* CMSC 152, Winter 2016
* Lab 3
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw3.h" 

void evidence_all_positive() { 

    printf("Testing all_positive: \n"); 

    int cases = 4; 
    int alen = 3; 
    
    int test [4][3] = {  {1, 2, 8},  {-6, 7, 5}, {0, 6, -1}, 
    {0, 4, 8} }; 
    
    int expt [4] = {1, 0, 0, 0}; 

    for(int i = 0; i < cases; ++i) { 
	printf("expected: %d \t| actual: %d \n", expt[i],
	     all_positive( test[i], alen ) );
    }  
    int corner_one [] = {};
    printf("expected: %d \t| actual: %d \n", 1,
	 all_positive( corner_one, 0 ) );
 
} 


void evidence_exists_positive() { 

    printf("\nTesting exists_positive \n"); 
    
    int test [5][3] = { {-1, -2, -8},  {-6, 7, 5}, {0, 6, -1}, 
    {0, 4, 8}, {0, 0, 0} } ; 
    
    int expt [5] = {0, 1, 1, 1, 0}; 
    
    int cases = 5; 
    int alen = 3; 
    
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %d \t| actual: %d \n", expt[i],
	     exists_positive( test[i], alen ) );
    }  
    int corner_one [] = {};
    printf("expected: %d \t| actual: %d \n", 0,
	 exists_positive( corner_one, 0 ) );
} 


void evidence_first_positive() { 
   
    printf("\nTesting first_positive \n"); 
    
    int test [5][3] = { {-1, -2, -8},  {-6, 7, 5}, {0, 6, -1}, 
    {0, -3, 8}, {0, 0, 0} }; 
    
    int expt [5] = {-1, 1, 1, 2, -1}; 
    
    int cases = 5; 
    int alen = 3; 
    
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %d \t| actual: %d \n", expt[i],
	     first_positive( test[i], alen ) );
    }  
    int corner_one [] = {};
    printf("expected: %d \t| actual: %d \n", -1,
	 first_positive( corner_one, 0 ) );

} 


void evidence_number_positives() { 
   
    printf("\nTesting number_positives \n"); 
    
    int test [5][3] = { {-1, -2, -8},  {-6, 7, 5}, {0, 6, -1}, 
    {2, 6, 5}, {0, 0, 0} }; 
    
    int expt [5] = {0, 2, 1, 3, 0}; 
    
    int cases = 5; 
    int alen = 3; 
    
    for(int i = 0; i < cases; ++i) { 
	printf("expected: %d \t| actual: %d \n", expt[i],
	     number_positives( test[i], alen ) );
    } 
 
    int corner_one [] = {};
    printf("expected: %d \t| actual: %d \n", 0,
	 number_positives( corner_one, 0 ) );

}    
    
void evidence_negate() { 
    
    printf("\nTesting negate \n"); 
    
    int test [5][3] = { {-1, -2, -8},  {-6, 7, 5}, {0, 6, -1}, 
    {0, 0, 0} }; 
    
    int expt [5][3] = { {1, 2, 8},  {6, -7, -5}, {0, -6, 1}, 
    {0, 0, 0} }; 
    
    int cases = 4; 
    int alen = 3; 
    
    for(int i = 0; i < cases; ++i) { 
	printf("expected: "); 
	for(int j = 0; j < alen; ++j) { 
	    printf("%d ", expt[i][j]); 
	} 
	printf("\t|actual: "); 
	negate(test[i], alen); 
	for(int j = 0; j < alen; ++j) { 
	    printf("%d ", test[i][j]); 
	}
	printf("\n");  
    }
} 


void evidence_partial_sums() { 

    printf("\nTesting partial_sums\n"); 
    
    int test [5][3] = { {-1, -2, -8},  {0, 0, 0}, {1, 2, 3}, 
    {-2, 4, -3} };
    
    int expt [5][4] = { {0, -1, -3, -11},  {0, 0, 0, 0}, {0, 1, 3, 6}, 
    {0, -2, 2, -1} }; 
    
    int cases = 4; 
    int alen = 3; 

    for(int i = 0; i < cases; ++i) { 
	printf("expected: "); 
	for(int j = 0; j < alen + 1; ++j) { 
	    printf("%d ", expt[i][j]); 
	} 
	printf("\t|actual: "); 
	int* p_sum = partial_sums(test[i], alen); 
	for(int j = 0; j < alen + 1; ++j) { 
	    printf("%d ", p_sum[j]); 
	}
	printf("\n");  
    } 
    
} 

void evidence_rotate_right() { 

    printf("\nTesting rotate_right \n"); 
    
    int test [5][3] = { {-1, -2, -8},  {-6, 7, 5}, {0, 6, -1}, 
    {0, 0, 0} }; 
    
    int expt [5][3] = { {-8, -1, -2},  {5, -6, 7}, {-1, 0, 6}, 
    {0, 0, 0} }; 
    
    int cases = 4; 
    int alen = 3; 
    
    for(int i = 0; i < cases; ++i) { 
	printf("expected: "); 
	for(int j = 0; j < alen; ++j) { 
	    printf("%d ", expt[i][j]); 
	} 
	printf("\t|actual: "); 
	rotate_right(test[i], alen); 
	for(int j = 0; j < alen; ++j) { 
	    printf("%d ", test[i][j]); 
	}
	printf("\n");  
    } 
} 


void evidence_factorization() { 

    printf("\nTesting factorization\n"); 
    
    unsigned int test [11] = {12, 1, 13, 100, 91, 0, 169, 65535, 14, 2, 3}; 
    char* expt [] = { "2 2 3", " ", "13", "2 2 5 5", "7 13", " ", 
	    "13 13", "3 5 17 257", "2 7", "2", "3"}; 
    int expt_flens [] = {3, 0, 1, 4, 2, 0, 2, 4, 2, 1, 1}; 
    

    for(int i = 0; i < 11; ++i) { //loops for number of tests 
	printf("n: %u \t| expt flens: %d \t| expected: %s \n", 
	    test[i], expt_flens[i], expt[i] ); 
    
	    unsigned int flens = 4; 
	    unsigned int *pflens = &flens; 
	    unsigned int f_input [] = {1, 2, 3, 4}; 

	    factorization(test[i], f_input, pflens);
	    
	    printf("actual flens: %d \t| actual: ", flens);   
	    for(int t = 0; t < flens; ++t) { 
		printf("%d ", f_input[t]); 
	    }
	printf("\n\n"); 
    }  
} 


void evidence_decode() { 
    
    printf("\nTesting decode\n"); 
 
    unsigned int test [4][4] = { {1, 0, 7, 8}, {2, 3, 0, 26},
	 {1, 5, 10, 25}, {28, 4, 7, 8} };       
    char* expt[] = {"A GH\0", "BC Z\0", "AEJY\0", "ERROR\0"};   

    unsigned int alen = 4;  

    for(int i = 0; i < 5; ++i) { 
	printf("expected: %s \t|", expt[i]); 
	printf("actual: "); 
	char *uncoded = decode(test[i], alen); 
	printf("%s\n", uncoded);   
    } 
} 

int main() { 
    
    evidence_all_positive(); 
    evidence_exists_positive();
    evidence_first_positive();  
    evidence_number_positives();
    evidence_negate();  
    evidence_partial_sums(); 
    evidence_rotate_right();
    
    evidence_factorization();  
    evidence_decode(); 
    return 0; 
} 
