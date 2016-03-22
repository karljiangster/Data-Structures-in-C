/* Karl Jiang, karljiang 
 * CMSC 152, Winter 2016 
 * Texture operations 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include "raytracer.h" 


/* sc_blue : surface color function that returns blue, always */
color sc_blue(object *o, location loc)
{
      return color_expr(0,0,1);
}

/* poster_red_distance - calculate distance from upper-left-corner, use to 
 * scale from black at upper-left to red at lower-right
 */
color poster_red_distance(object *o, location loc) { 
    
    poster p = o -> o.p; 
    xyz ul = p.upper_left; 
    xyz lr = xyz_expr(ul.x + p.w, ul.y - p.h, ul.z); 
   
    double dist = xyz_dist(loc, ul); 
    double total_dist = xyz_dist(ul, lr);  
    return color_expr(dist / total_dist, 0, 0);  
} 
 
 
/* poster_rgb_distance - calculate distance from upper-left-corner, use to 
 * scale from all red at upper-left to all blue at lower-right, with 
 * green in the middle, and gradations between them.
 */
color poster_rgb_distance(object *o, location loc); 
 
 
/* sphere_loc_to_rgb - scale the location so that it maps x, y, z onto r, g, b in 
 * a way that shows gradations in the sphere. You are being given flexibility to 
 * do this in a way that looks interesting to you.
 */
color sphere_loc_to_rgb(object *o, location loc); 
 
 
/* sphere_stripes - color the sphere with 4 blue stripes on a white background.
 * the pattern is: WBWBWBWBW. The stripes and background are roughly equal height.
 */
color sphere_horiz_stripes(object *o, location loc); 


