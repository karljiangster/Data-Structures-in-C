#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

/* raytracer.h
 * CS152 Winter 2015
 * Project A
 * Feb 2015
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/* ====================================== */ 
/* ====================================== */ 
/* === STRUCTURE AND TYPE DEFINITIONS === */ 
/* ====================================== */ 
/* ====================================== */ 

typedef unsigned char byte;

typedef struct {
  double x;
  double y;
  double z;
} xyz;

/* Note: Because xyz can be used for both a particular location
 * and a directional vector, we can use the same struct and 
 * typedef for clarity. We may use the three names interchangeably.
 * This allows us to share the basic operations (add, sub, mag, scale).
 * We are not required to use location and direction, it is merely a 
 * tool to help us understand what our (or someone else's) code is doing.
 */

typedef xyz location;
typedef xyz direction;

typedef struct {
  /* each value must be on interval [0,1] */
  double r;
  double g;
  double b;
} color;

typedef struct {
  location origin;
  direction dir;
} ray;

typedef struct _object object;

typedef struct {
  location center;
  double radius;
  color(*surface_color)(object *o, location loc);
  color shine; // not used in project A
  object *o;
} sphere;

typedef struct {
  xyz upper_left;
  double w;
  double h;
  color(*surface_color)(object *poster, location intersection);
  color shine; // not used in project A
  object *o;
} poster;

union object_union {
  sphere s;
  poster p;
};

/* texture used in project B */
typedef struct {
        color **pixels;
        int height;
        int width;
} texture;

struct _object{
  enum  { SPHERE, POSTER } tag;
  union object_union o;
  texture *t; // NULL in project A
};

typedef struct obj_list obj_list;
/* convention: NULL is the empty object list */
struct obj_list {
  object obj;
  obj_list *next;
};

/* not used in project A */
typedef struct {
  direction dir; /* note: the vector points AT the light */
  color c;
} light;

typedef struct {
  color bg;
  obj_list *objects;
  light light; // not used in project A
  color amb; // not used in project A
} scene;

typedef struct {
  enum {MISS=0,HIT=1} miss;
  double t;
  location hit_point;
  color surf; // not used in project A
  color shine; // not used in project A
  direction surf_norm; // not used in project A
} hit_test;

typedef struct {
  location loc;
  unsigned int h;
  unsigned int w;
} camera;

typedef struct {
  camera c;
  scene s;
} stage;

/* ================== */ 
/* ================== */ 
/* === OPERATIONS === */ 
/* ================== */ 
/* ================== */ 

/* Please note: the following is not necessarily every operation you
 * will need, nor will you necessarily use every operation in your
 * implementation.  Add and implement additional operations as you
 * require them.
 */

/* ================================== */ 
/* === vector operations => xyz.c === */ 
/* ================================== */ 

xyz xyz_expr(double x, double y, double z);


/* create a fresh vector with same components as argument */
xyz xyz_dup(xyz v); 

/* xyz_add : add two vectors */
/* (x,y,z) + (X,Y,Z) = (x+X,y+Y,z+Z) */
xyz xyz_add(xyz v1, xyz v2);

/* xyz_sub : subtract the second vector from the first */
/* (x,y,z) - (X,Y,Z) = (x-X,y-Y,z-Z) */
xyz xyz_sub(xyz v1, xyz v2);

/* xyz_neg : negate a vector */
/* -(x,y,z) = (-x,-y,-z) */
xyz xyz_neg(xyz v);

/* xyz_scale : scale the components of a vector by scalar s */
/* s(x,y,z) = (sx,sy,sz) */
xyz xyz_scale(double s, xyz v);

/* computer the distance between two vetors */ 
double xyz_dist(xyz v1, xyz v2); 

/* xyz_dot : compute the dot product of two vectors */
/* (x,y,z) dot (X,Y,Z) = xX+yY+zZ */
double xyz_dot(xyz v1, xyz v2);

/* xyz_mag : compute the magnitude of a vector */
/* the square root of the sum of the squares of the components */
double xyz_mag(xyz v);

/* xyz_norm : normalize the vector */
/* i.e., a vector pointing in the same direction whose magnitude is 1 */
/* - normalize a vector by scaling by 1 over its magnitude */
/* - if a vector's magnitude is zero, it can't be normalized; return it */
xyz xyz_norm(xyz v);

char *xyz_tos(xyz v);

void xyz_show(FILE *f, xyz v);

/* =================================== */ 
/* === color operations => color.c === */ 
/* =================================== */ 

/* reject if any component is outside [0.0,1.0] */
color color_expr(double r, double g, double b);

/* creates a duplicate of the given color */
color color_dup(color c); 

/* color_modulate : multiply the components or two colors */
/* (r,g,b) * (R,G,B) = (rR,gG,bB) */
color color_modulate(color c1, color c2);

/* color_scale : scale each component by given scalar, but */
/* don't allow any component in the result to fall outside [0,1] */
color color_scale(double s, color c);

/* add components of colors, but */
/* don't allow any component in the result to exceed 1 */
color color_add(color c1, color c2);

char *color_tos(color c);

void color_show(FILE *f, color c);

/* color_show_bytes */
/* print three integers on [0,255] with spaces in between and a newline */
/* suitable for use in a PPM */
void color_show_bytes(FILE *f, color c);

/* =============================== */ 
/* === ray operations => ray.c === */ 
/* =============================== */ 

/* constructor for ray */ 
ray ray_expr(location origin, direction dir); 

/* ray_position: interpreting direction as velocity, calculate position
 * of ray r after time t. 
 */
xyz ray_position(ray r, double t);

/* to string function for ray */ 
char *ray_tos(ray r);

void ray_show(FILE *f, ray r);

/* ===================================== */ 
/* === sphere operations => sphere.c === */ 
/* ===================================== */ 

/* constructs a sphere */ 
sphere sphere_expr(location v, double r, color(*sc)(object *,location), 
	color sh);

/* tostring for sphere */ 
char *sphere_tos(sphere s);

/* display for sphere */ 
void sphere_show(FILE *f, sphere s);

/* ===================================== */ 
/* === slab operations => poster.c ===== */ 
/* ===================================== */ 

/* Makes a poster */ 
poster poster_expr(location ulc, double w, double h, color(*sc)(object*,location), color sh);

/* to string for poster */ 
char *poster_tos(poster s);

/* print contents to file f */ 
void poster_show(FILE *f, poster s);

/* ===================================== */ 
/* === object operations => object.c === */ 
/* ===================================== */ 

/* expr for object sphere */
object obj_sphere(sphere s); 

/* expr for object poster */
object obj_poster(poster p);

/* to string function for object */ 
char *object_tos(object o);

/* returns color of object at point */
color object_color(object obj, location loc); 

/* prints contents togiven file f */ 
void object_show(FILE *f, object o);

/* ======================================== */ 
/* === object list ops => obj_list.c === */ 
/* ======================================== */ 

/* constructs a object list the heap */ 
obj_list *ol_cons(object o, obj_list *os);

/* returns the object s in the given obj_list and null pointer */ 
obj_list *ol_singleton(object s);

/* to string for obj_list */ 
char *ol_tos(obj_list *os);

/* prints contents to file */ 
void ol_show(FILE *f, obj_list *os);

/* frees the object and its contents */ 
void ol_free(obj_list *ss);

/* =================================== */ 
/* === scene operations => scene.c === */ 
/* =================================== */ 

/* to string function for scene */ 
char *scene_tos(scene sc);

/* pirnts contents out to file f */ 
void scene_show(FILE *f, scene sc);

/* ========================================= */ 
/* === hit_test operations => hit_test.c === */ 
/* ========================================= */ 

/*expr for hit_test if a miss */ 
hit_test miss_expr(); 

/* expr for hit_test, provided it hits.  Refine in Proj B */ 
hit_test hit_test_expr(double t, location hit_point); 

/* to string for hit_test */ 
char *hit_test_tos(hit_test t);

/* prints contents of hit_test to given file */ 
void hit_test_show(FILE *f, hit_test t);

/* ===================================== */ 
/* === camera operations => camera.c === */ 
/* ===================================== */ 

/* makes new camera with height and width of physical plane, location */ 
camera camera_expr(unsigned int h, unsigned int w, location loc); 

/* to string for camera */ 
char *camera_tos(camera cm);

/* prints contents of camera to file f */ 
void camera_show(FILE *f, camera cm);

/* =================================== */ 
/* === stage operations => stage.c === */ 
/* =================================== */ 

char *stage_tos(stage stg);

void stage_show(FILE *f, stage stg);

/* The function get_stage just needs to return a valid stage. */
/* The argument may be used, or not, at your discretion. */
stage get_stage(unsigned int selection);

/* ======================================= */ 
/* === texture operations => texture.c === */ 
/* ======================================= */

/* poster_red_distance - calculate distance from upper-left-corner, use to 
 * scale from black at upper-left to red at lower-right
 */
color poster_red_distance(object *o, location loc); 

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

/* ================================================ */ 
/* ================================================ */ 
/* === RAY TRACER LOGIC and MAIN => raytracer.c === */ 
/* ================================================ */ 
/* ================================================ */ 

/* === project 1 operations === */

/* === intersect.c === */

/* returns hit_test on ray hitting object */ 
hit_test intersect(ray r, object obj);

/* === raytracer.c === */

/* given physical coordinates, converts to logical and returns */ 
location logical_loc(camera c, unsigned int x, unsigned int y);

/* follow a ray from the camera into a scene, test for intersections 
 * with any spheres objects and find either the closest intersection 
 * or miss, use the surface_color function to compute the color.
 */ 
color trace_ray(scene s, ray r);

/* run trace_ray over all rays though each pixel in the image, 
 * compute the color corresponding to each ray, and write an 
 * image, pixel by pixel, to the file pointed to by f.
 */ 
void render(FILE *f, stage g);

/* === rt.c === */

int main(int argc, char *argv[]);

#endif /* __RAYTRACER_H__ */

