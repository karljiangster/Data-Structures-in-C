/* Karl Jiang, karljiang 
* CS 152, Winter 2016
* Lab 3 
*/ 

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

/* Returns the distance between (x0, y0) and (x1, y1) */ 
double dist(double x0, double y0, double x1, double y1) { 

    double x = x1 - x0; 
    double y = y1 - y0; 
    
    return sqrt(x * x + y * y); 
}

 
/* Prints the proper RGB value for draw_waves. */ 
void rgb_print(int x, int y, int xc, int yc) { 

    double sin_res = sin( dist(x, y, xc, yc) ); 
    int col_b = (int) ( (sin_res + 1) * 255 / 2);  	
    printf("0 0 %d", col_b); 
}

 
/* Generates a side_length x side_length image in ppm text
* to the console. The ppm should resemble a wave where colors
* are based off its distance from the offset center.
*/
void draw_waves(int side_length, int x_offset, int y_offset) { 

    if(side_length <= 0) { 
	fprintf(stderr, "Please input a side length that is more than 0."); 
	exit(1); 
    } 
 
    printf("P3\n"); 
    printf("%d %d\n", side_length, side_length); 
    printf("255\n"); 
    
    int center_x = side_length / 2 + x_offset; 
    int center_y = side_length / 2 + y_offset; 
    
    for(int i = 0; i < side_length; ++i) { 
	for(int j = 0; j < side_length; ++j) { 
	    rgb_print(i, j, center_x, center_y); 
	    printf("\n"); 
	} 
    } 

} 


