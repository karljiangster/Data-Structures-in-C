 /* Karl Jiang, karljiang 
 * CS 152, win 2016 
 * hw1 
 */  

#include <stdio.h> 
#include <stdlib.h> 
#include "hw1.h" 
 

void evidence_area_box() {

    printf("Testing Area Box. \n"); 
    double wid[] = {2, 4.5, 0.1, 0};  
    double heit[] = {1, 7.8, 0.7, 6};
    double dpth[] = {1, 9.5, 0.1, 7.6}; 
    double exptd[] = {10, 303.9, 0.3, -1};
    //-1 this shouldnt run anyways since the wid is 0      

    for(int i = 0; i < 4; ++i) { 
	printf("expected: %12f | actual: %12f \n", exptd[i], area_box( wid[i],
						 heit[i], dpth[i]) );   
    } 
} 

void evidence_digit_letters() { 

    printf("\nTesting digit_letters \n"); 
    // array of counts of each digit. Ie. 0: a[0] = 4 since "zero" has 4 letters 
    int digits[] = {0, 1, 5, 9}; 
    int expt[] = {4, 3, 4, 4}; 
    for(int i = 0; i < 4; ++i) { 
	printf("expected %8u | actual: %8u \n", expt[i], digit_letters(digits[i]) ); 
    }  
    // printf("expected: ERROR on %d", digit_letters(22) ); 
    
} 


void evidence_valid_room() { 
    
    printf("\nTesting valid_room \n"); 
    int floor_nums[] = {0, 100, 101, 233, 1000, 2033, 
			    4836, 4837, 4901, 4955, 9921, 
			    9924, 10000, 45345, -10}; 
    int expt[] = {0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0}; 
    
    for(int i = 0; i < 14; ++i) {  
	printf("expected %8d | actual: %8d \n", expt[i], valid_room( floor_nums[i] ) );   
    } 
} 


void evidence_rotary_pulses() { 

    printf("\nTesting rotary_pulses. \n"); 
    unsigned long long int numbers[] = {2039797408, 7737021234,
					 4540450434, 50000};
    int expt[] = {2 + 10 + 3 + 9 + 7 + 9 + 7 + 4 + 10 + 8, 46, 
		    4 + 5 + 4 + 10 + 4 + 5 + 10 + 4 + 3 + 4, 
		    5 + 10 * 4};
    for(int i = 0; i < 4; ++i) { 
    	printf("expected %8d | actual: %8d \n", expt[i], rotary_pulses( numbers[i] ) );   
    }     
} 

int main(int argc, char *argv[]) { 
    
    evidence_area_box(); 
    evidence_digit_letters(); 
    evidence_valid_room(); 
    evidence_rotary_pulses(); 
    return 0; 
} 
