/* Returns the distance between the points (x0, y0) and (x1, y1) */
double dist(double x0, double y0, double x1, double y1);

/* Generates a side_length x side_length image in ppm text 
* to the console. The ppm should resemble a wave where colors 
* are based off its distance from the offset center. 
*/ 
void draw_waves(int side_length, int x_offset, int y_offset);
