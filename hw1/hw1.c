/* Karl Jiang, karljiang 
 * CS 152, win 2016 
 * hw1 
 */ 

#include <stdio.h> 
#include <stdlib.h> 

//array used in digit_letters, contains counts of single digit nums
int digit_counts[10] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

 /* area_box : Returns the outside surface area of the box
  * given dimensions. If any of the parameters are invalid, returns -1  
  */
double area_box(double width, double height, double depth) { 

    if(width <= 0 || height <= 0 || depth <= 0) {  
	fprintf(stderr, "At least one of the parameters are not valid."); 
    } 
    return 2 * (width * height + width * depth + height * depth);  

}

/* digit_letters : returns num of letters in english word of
 * given single digit
 */
unsigned int digit_letters(unsigned int digit) { 

    if(digit > 10) { 
	fprintf(stderr, "%u is more than one digit.", digit); 
	exit(1); 
    } 
    return digit_counts[digit]; 
} 


/* valid_room : determines if room number is valid */
int valid_room(unsigned int room) { 
    
    if(room <= 100) 
	return 0;
    int room_num = room % 100;
    if(room <= 4836) 
	return room_num >= 1 && room_num <= 36;  
    if(room <= 9924) 
	return room_num >= 12 && room_num <= 24; 
    return 0; 
} 


/* rotary_pulses: returns num of pulses of the given telephone number */
unsigned int rotary_pulses(unsigned long long int phone_num) { 

    if(!phone_num) 
	return 0; 
    int curr_digit = phone_num % 10; 
    if(!curr_digit)    
	return 10 + rotary_pulses(phone_num / 10);  
    return curr_digit + rotary_pulses(phone_num / 10); 
} 

 
 
