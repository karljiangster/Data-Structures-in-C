#include <stdio.h> 
#include <stdlib.h> 
#include "lab2.h" 


void evidence_hex_char() { 
   
    printf("\nTesting hex_char\n");  
    unsigned char bytes [] = {0, 1, 5, 15, 16, 17, 100, 255}; 
    char *expected [] = {"00", "01", "05", "0F", "10", 
		    "11", "64", "FF"};
    for(int i = 0; i < 8; ++i) { 
	printf("input: %d \t| expected: %s \t| actual: ", 
	    bytes[i], expected[i]); 
	hex_char(bytes[i]); 
	printf("\n"); 
    } 
} 

void evidence_hex_int() { 
   
    printf("\nTesting hex_int \n");  
    unsigned int inputs [] = {0, 1, 5, 15, 16, 17, 
		254, 234535, 4294967295}; 
    char *expected[] = {"00000000","00000001", "00000005",
	    "0000000F", "00000010", "00000011", "000000FE",
	    "00039427", "FFFFFFFF"}; 
    int cases = 9;

    for(int i = 0; i < cases; i++) {
        printf("input %d: \t| expected: %s \t| actual: ",
		 inputs[i], expected[i]);
	hex_int(inputs[i]); 
	printf("\n");  
    }
} 


void evidence_octal_char() { 

    printf("\nTesting octal_char \n");  
    unsigned char inputs [] = {0, 1, 7, 8, 16, 64, 255}; 
    char *expected[] = {"000", "001", "007", "010", "020", "100", "377"}; 
    int cases = 7;

    for(int i = 0; i < cases; i++) {
        printf("input %d: \t| expected: %s \t| actual: ",
		 inputs[i], expected[i]);
	octal_char(inputs[i]); 
	printf("\n");  
    }

} 


void evidence_octal_int() { 
    
    printf("\nTesting octal_int \n");
  
    unsigned int inputs [] = {0, 1, 7, 8, 16, 254,
	 234535, 4294967295}; 
    char *expected[] = {"00000000000","00000000001", "00000000007",
	     "00000000010", "00000000020", "00000000376",
	    "00000712047", "37777777777"}; 
    int cases = 8;

    for(int i = 0; i < cases; i++) {
        printf("input %d: \t| expected: %s \t| actual: ",
		 inputs[i], expected[i]);
	octal_int(inputs[i]); 
	printf("\n");  
    }
} 


void evidence_binary_char() { 
    
    printf("\nTesting binary_char \n");  
    unsigned char inputs [] = {0, 1, 2, 8, 17, 64, 255}; 
    char *expected[] = {"00000000", "00000001", "00000010",
	 "00001000", "00010001", "01000000", "11111111"}; 
    int cases = 7;

    for(int i = 0; i < cases; i++) {
        printf("input %d: \t| expected: %s \t| actual: ",
		 inputs[i], expected[i]);
	binary_char(inputs[i]); 
	printf("\n");  
    }

} 

void evidence_binary_int() { 
    printf("\nTesting octal_int \n");
  
    unsigned int inputs [] = {0, 1, 7, 8, 16, 387,
	 234535, 4294967295}; 
    char *expected[] = { "00000000000000000000000000000000",
"00000000000000000000000000000001","00000000000000000000000000000111",
"00000000000000000000000000001000","00000000000000000000000000010000",
"00000000000000000000000110000011","00000000000000111001010000100111",
"11111111111111111111111111111111"}; 

    int cases = 8;

    for(int i = 0; i < cases; i++) {
        printf("input %d: \n| expected: \t %s \n| actual: \t ",
		 inputs[i], expected[i]);
	binary_int(inputs[i]); 
	printf("\n\n");  
    } 
} 


int main() { 
    
    printf("Test\n"); 
    
    evidence_hex_char();
    evidence_hex_int(); 

    evidence_octal_char(); 
    evidence_octal_int(); 

    evidence_binary_char(); 
    evidence_binary_int();          

    return 0; 
} 

