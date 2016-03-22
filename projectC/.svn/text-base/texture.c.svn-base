#include <stdio.h> 
#include <stdlib.h> 
#include "raytracer.h"
#include <math.h>

/* =================================== */ 
/* === texture operations => texture.c === */ 
/* =================================== */ 

/* coloring functions specified on web page */

/* _dist : compute Euclidean distance in 3-space */
double _dist(xyz a, xyz b)
{
  double dx = a.x-b.x;
  double dy = a.y-b.y;
  double dz = a.z-b.z;
  return sqrt(dx*dx+dy*dy+dz*dz);
}

/* poster_red_distance - calculate distance from upper-left-corner, use to 
 * scale from black at upper-left to red at lower-right
 */
color poster_red_distance(object *o, location loc)
{
  if (o->tag!=POSTER) {
    fprintf(stderr,"error (poster_red_distance): not a poster\n");
    exit(1);
  }
  location ulc = o->o.p.upper_left;
  /* compute lower right corner */
  location lrc = {ulc.x+o->o.p.w,ulc.y+o->o.p.h,ulc.z}; 
  /* take the distance from between loc and ulc, and divide by total distance
   * from the ulc to rlc. place that result as the red in a color.
   */
  return color_expr(_dist(ulc,loc)/_dist(ulc,lrc),0,0);
}

/* poster_rgb_distance - calculate distance from upper-left-corner, use to 
 * scale from all red at upper-left to all blue at lower-left, with 
 * green in the middle, and gradations between them.
 */
color poster_rgb_distance(object *o, location loc)
{
  if (o->tag!=POSTER) {
    fprintf(stderr,"error (poster_rgb_distance): not a poster\n");
    exit(1);
  }
  location ulc = o->o.p.upper_left;
  /* compute lower right corner */
  location lrc = {ulc.x+o->o.p.w,ulc.y+o->o.p.h,ulc.z}; 
  /* relative ratio within poster */
  double ratio = _dist(ulc,loc)/_dist(ulc,lrc);
  /* for the first half, we blend from red to green */
  if (ratio<=0.5)
    return color_expr(1-ratio*2,ratio*2,0);
  /* for the first half, we blend from green to blue */
  else 
    return color_expr(0,2*(1-ratio),2*ratio-1);
}


/* sphere_loc_to_rgb - scale the location so that it maps x, y, z onto r, g, b in 
 * a way that shows gradations in the sphere. You are being given flexibility to 
 * do this in a way that looks interesting to you.
 */
/* Note: Yours does NOT need to be exactly like this - this is one solution */
color sphere_loc_to_rgb(object *o, location loc)
{
  // separately find relative x, y, z (relative to sphere),                                           
  // then map onto 0->1 or r, g, b                                                                    
  sphere *s = &(o->o.s);

  // 0 to 1 - where are x and y within poster?                                                        
  double x_within_sphere = (s->center.x+s->radius - loc.x)/
    (s->radius*2);
  double y_within_sphere = (s->center.y+s->radius - loc.y)/
    (s->radius*2);
  double z_within_sphere = (s->center.z+s->radius - loc.z)/
    (s->radius*2);

  return color_expr(x_within_sphere, y_within_sphere, z_within_sphere);

}


/* sphere_stripes - color the sphere with 4 blue stripes on a white background.
 * the pattern is: WBWBWBWBW. The stripes and background are roughly equal height.
 */
color sphere_horiz_stripes(object *o, location loc)
{
  if (o->tag!=SPHERE) {
    fprintf(stderr,"error (sphere_horiz_stripes): not a sphere\n");
    exit(1);
  }    
  location ctr = o->o.s.center;
  double rad = o->o.s.radius;
  double dy = loc.y-ctr.y;
  double s = (dy+rad)/(2*rad); /* s is on [0,1] */
  int n = (int)floor(s*9);     /* n is on [0,9] */
  if (n==9) n--;               /* n is on [0,8] */
  return n%2?color_expr(0,0,1):color_expr(1,1,1);
}


/* map_texture_on_sphere takes an object. Uses polar coordinates 
 * to scale on vertical (phi) on [-pi/2, pi/2] and horizontal (theta) 
 * on [-pi, pi]. Then scales to width and height of texture bitmap 
 * returns the color at location loc 
 */
color map_texture_on_sphere(object *o, location loc) { 
    double phi =  -asin(  (loc.y - o -> o.s.center.y) /  o -> o.s.radius ); 
    double theta = atan2( (loc.x - o -> o.s.center.x) / (o -> o.s.radius * cos(phi) ),
			 -(loc.z - o -> o.s.center.z) / (o -> o.s.radius * cos(phi) ) ); 

    int a = (0.5 + phi /        M_PI)   * o -> t -> height; 
    int b = (0.5 + theta / (2 * M_PI) ) * o -> t -> width; 

    if(a == o -> t -> height)
	a--; 
    if(b == o -> t -> width) 
	b--; 
    
    return o -> t -> pixels[a][b]; 
} 

/* general function for mapping on cube faces */ 
color _map_texture_on_face(object* o, 
	location corner, location loc, double length, face f) { 

    int a, b; 
    double dif_a, dif_b;  
    if(f == FRONT) { 
	dif_a = ( fabs(loc.y - corner.y) ); 	
	dif_b = ( fabs(loc.x - corner.x) ); 
    } 
    else if(f == LEFT || f == RIGHT) { 
	dif_a = ( fabs(loc.y - corner.y) ); 
	dif_b = ( fabs(loc.z - corner.z) ); 	
    }
    else if(f == UP || f == DOWN) { 
	dif_a = ( fabs(loc.z - corner.z) ); 	
	dif_b = ( fabs(loc.x - corner.x) ); 
    } 
    else { 
	fprintf(stderr, "invalid face value in _map_texture_on_poster\n"); 
	exit(1); 
    } 
    a = dif_a * o -> t -> height / length; 
    b = dif_b * o -> t -> width  / length; 

    if(a == o -> t -> height) 
	a--; 	
    if(b == o -> t -> width) 
	b--;
    return o -> t -> pixels[a][b];
}

/* map_texture_on_poster takes an object (which is assumed to have
 * tag == POSTER) and an intersection point. It uses the bitmap contained
 * in the object, the attributes of the poster, and the intersection
 * point to determine the color at that intersection point. It scales the 
 * height and width, stretching or shrinking the bitmap to match the 
 * poster.
 */
color map_texture_on_poster(object *o, location loc) { 

    int a = ( fabs(loc.y - o -> o.p.upper_left.y) ) * o -> t -> height / o -> o.p.h; 
    int b = ( fabs(loc.x - o -> o.p.upper_left.x) ) * o -> t -> width  / o -> o.p.w; 

    if(a == o -> t -> height) 
	a--; 
    if(b == o -> t -> width) 
	b--;
    return o -> t -> pixels[a][b]; 
} 

/* assuming o is a cube, determines the face that intersection is on */ 
face determine_face(object *o, location intersection) { 
    location ftl = o -> o.c.front_top_left;
    face f; 
    if( fabs(intersection.z - ftl.z) <= 0.01) 
	f = FRONT; 
    else if( fabs(intersection.x - ftl.x ) <= 0.01) 
	f = LEFT; 
    else if( fabs(intersection.x - (ftl.x + o -> o.c.length) ) <= 0.01) 
	f = RIGHT; 
    else if( fabs(intersection.y - ftl.y) <= 0.01) 
	f = UP; 
    else if( fabs(intersection.y - (ftl.y - o -> o.c.length) ) <= 0.01) 
	f = DOWN;
    else { 
	fprintf(stderr, "intersection is not on any face of the cube\n"); 
	exit(1);
    } 
    return f;     
}

/* maps texture onto each of the cube faces. First finds which face 
 * the intersection is on, and then returns the coordinate on that bitmap
 */ 
color map_texture_on_cube_faces(object *o, location intersection) { 
    face on = determine_face(o, intersection);
    
    direction norm_sub; 
    double d_sub;
    direction corner;  
    
    cube_face_int_params(on, o -> o.c, &norm_sub, &d_sub, &corner);  
    return _map_texture_on_face(o, corner, intersection, o -> o.c.length, on);

}

/* returns a 3 by 3 coordinate of given location based on face. 
 * used for map_texture_around_cube 
 */
location flatten_cube_loc(location loc, face f, object* o) {
    double c_l = o -> o.c.length; 
    location ftl = o -> o.c.front_top_left; 
    double x_add; 
    double y_add;

    switch(f) { 
	case FRONT:
	    x_add = (loc.x - ftl.x) / c_l; 
	    y_add = (ftl.y - loc.y) / c_l; 
	    return xyz_expr(1 + x_add, 1 + y_add, 0); 
	case LEFT:
	    x_add = (loc.z - ftl.z) / c_l; 
	    y_add = (ftl.y - loc.y) / c_l; 
	    return xyz_expr(x_add, 1 + y_add, 0); 
	case RIGHT:
	    x_add = (loc.z - ftl.z) / c_l; 
	    y_add = (ftl.y - loc.y) / c_l; 
	    return xyz_expr(2 + x_add, 1 + y_add, 0); 
	case UP:
	    x_add = (loc.x - ftl.x) / c_l; 
	    y_add = (loc.z - ftl.z) / c_l; 
	    return xyz_expr(1 + x_add, y_add, 0); 
	case DOWN:
	    x_add = (loc.x - ftl.x) / c_l; 
	    y_add = (loc.z - ftl.z) / c_l; 
	    return xyz_expr(1 + x_add, 2 + y_add, 0); 
	default: 
	    fprintf(stderr, "No valid face.\n"); 
	    exit(1); 
    } 
} 

/* maps bitmap using 2d representation of cube */ 
color map_texture_around_cube(object *o, location intersection) { 
    face loc_face = determine_face(o, intersection);
    location flat = flatten_cube_loc(intersection, loc_face, o); 
    return _map_texture_on_face(o, xyz_expr(0, 0, 0), flat,
	    3, FRONT); 
} 

/* general function for making texture */ 
texture* make_texture(color c1, color c2, int N, int M){
    color** pixel = malloc( N * sizeof(*pixel) );
    for (int i = 0; i < N; i++){
	pixel[i] = malloc( M * sizeof(color) );
	for (int j = 0; j < M; j++)
	    pixel[i][j] = (i ^ j) & 1 ? c2 : c1;
    }

    texture* t = malloc( sizeof(*t) );
    t -> height = N;
    t -> width  = M;
    t -> pixels = pixel;
    return t;
}

/* makes horizontal stripes texture */ 
texture *make_horiz_stripes(color c1, color c2, int num_stripes) { 
    return make_texture(c1, c2, num_stripes, 1);
} 

/* makes vertical stripes texture */ 
texture *make_vert_stripes(color c1, color c2, int num_stripes) { 
    return make_texture(c1, c2, 1, num_stripes); 
} 

/* Returns the distance between (x0, y0) and (x1, y1) */
double _dist_points(double x0, double y0, double x1, double y1) {

    double x = x1 - x0;
    double y = y1 - y0;

    return sqrt(x * x + y * y);
}

/* helper for waves, gives color at certain point */ 
color _wave_color(int x, int y, int xc, int yc, color c) { 

    double sin_res = sin( _dist_points(x, y, xc, yc) );
    double col_b = (sin_res + 1) / 2;
    return color_scale(col_b, c); 
}  

/* makes wave type texture */ 
texture *make_waves(int length, int x_offset, int y_offset, color col) { 

    texture *t = malloc(sizeof(texture) ); 
    t -> width = length; 
    t -> height = length; 

    int xc = length / 2; 
    int yc = length / 2; 
    if(length & 1) {
	xc += x_offset; 
	yc += y_offset; 
    } 
    
    color** pixels_table = malloc(sizeof(color) * length * length); 
    for(int i = 0; i < length; ++i) { 
	pixels_table[i] = malloc(sizeof(color) * length); 
	for(int j = 0; j < length; ++j) { 
	    pixels_table[i][j] = _wave_color(j, i, xc, yc, col);
	} 
    } 
    t -> pixels = pixels_table; 
    return t; 
} 

/* opens file, reads info, and returns the texture */ 
texture *make_bitmap_from_file(char *filename) { 

    FILE *fp = fopen(filename, "r"); 
    if(fp == NULL) { 
	fprintf(stderr, "file does not exist.\n"); 
	exit(1); 
    } 
    char magic [3]; 
    int wt, ht; 
    double max_rgb; 
    fscanf(fp, "%s\n", magic); 
    fscanf(fp, "%d %d\n", &wt, &ht); 
    fscanf(fp, "%lf\n", &max_rgb);

    texture *map = malloc(sizeof(texture) ); 
    map -> height = ht; 
    map -> width = wt;
    color** pixels = malloc(sizeof(color*) * ht); 

    double r; 
    double g;
    double b; 

    //now read the rbg vals 
    for(int i = 0; i < ht; ++i) { 
	pixels[i] = malloc(sizeof(color) * wt); 
	for(int j = 0; j < wt; ++j) { 
	    fscanf(fp, "%lf %lf %lf", &r, &g, &b);
	    pixels[i][j] = color_expr(r / max_rgb, g / max_rgb, b / max_rgb);   
	} 	
    } 	
    fclose(fp); 
    map -> pixels = pixels; 
    return map; 
} 


