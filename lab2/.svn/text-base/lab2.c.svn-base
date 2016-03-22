#include <stdio.h>
#include <stdlib.h> 


/* Turns the input unsigned int - which should be less 
than whatever -ecimal form, and converts it accordingingly. 
Covers the hex, octal, binary
*/ 
void print_type_digit(unsigned int bit, unsigned int divisor) {
 
    if(bit > 10) {  
	switch(bit) { 
    	    case 15: 
		printf("F");
		break;  
	    case 14: 
		printf("E"); 
		break;  
	    case 13: 
		printf("D"); 
		break;  
	    case 12: 
		printf("C"); 
		break;  
	    case 11: 
		printf("B");
		break;  
	    case 10: 
		printf("A");
		break;  
	    }  
    } 
    else 
	printf("%u", bit); 
} 


/* General function to print out the changed base from 
* base 10 to 2, 8, 16. 
* Inputs: 
* byte: base 10 number to be converted 
* count: Integer representing number of digits to print  
* divisor: new base (ie. base 16 would be divisor = 16) 
*/ 
void convert(unsigned int byte, unsigned int count, 
    unsigned int divisor) { 

    if(count <= 0) 
	return; 
    count--; 
    if(byte) {  
	convert(byte / divisor, count, divisor); 
	print_type_digit(byte % divisor, divisor);    
    } 
    else { 
	printf("0"); 
	convert(byte, count, divisor);  
    } 	   
 }     
 

/* Changes from decimal to hexadecimal. 8 bits -> 2 digits. */  
void hex_char(unsigned char byte) {
     convert(byte, 2, 16); 
}


/* Changes from decimal to hexadecimal. 32 bits -> 8 digits*/ 
void hex_int(unsigned int n) { 
    convert(n, 8, 16); 
}

/* Changes from decimal to octal. 8 bits -> 3 digits. */ 
void octal_char(unsigned char byte) { 
    convert(byte, 3, 8); 
}   

/* Changes from decimal to octal. 32 bits -> 11 digits */   
void octal_int(unsigned int n) { 
    convert(n, 11, 8); 
} 

/* Changes from decimal to binary. 8  digits*/ 
void binary_char(unsigned char byte) { 
    convert(byte, 8, 2);  
}
 
/* Changes from decimal to binary. 32 digits */ 
void binary_int(unsigned int n) { 
    convert(n, 32, 2); 
} 
