#include <math.h>
#include "raytracer.h"

/* === intersect.c === */

/* to fill in slots not used in project A */
color _c0 = {0,0,0};
xyz _v0 = {0,0,0}; 

hit_test sph_int(ray r, object obj, sphere s)
{
  xyz A = xyz_sub(r.origin,s.center);
  double B = xyz_dot(A,r.dir);
  double C = xyz_dot(A,A)-s.radius*s.radius;
  double D = B*B-C;
  double t = (-B)-sqrt(D);
  if (D>0&&t>0) {
    location pos = ray_position(r, t); 
    direction surf_dir = xyz_sub(pos, s.center);
    color surf = s.surface_color(&obj, pos); 
    hit_test ht = {HIT, t, pos, surf,_c0, xyz_norm(surf_dir) };
    return ht;
  } else {
    // if it doesn't hit, then it's a miss, and nothing else in the struct matters
    hit_test ht = {MISS,0,_v0,_c0,_c0,_v0};
    return ht;
  }
}

/* based on the face f, returns surface normal and distance
 * and pseudo poster corner as out parameters
 */ 
void cube_face_int_params(face f, cube c, 
	    direction* s_norm, double* d, location* corner)
{     
    double length = c.length; 
    location ftl = c.front_top_left; 

    switch(f) { 	
	case FRONT: 	
	    *s_norm = xyz_expr(0, 0, -1); 	
	    *corner = ftl; //wont nessecarily be ulc, just ref point
	    *d = corner -> z; 
	    break; 
	case LEFT: 
	    *s_norm = xyz_expr(-1, 0, 0); 
	    *corner = ftl; 
	    *d = corner -> x;
	    break;  
	case RIGHT: 	
	    *s_norm = xyz_expr(1, 0, 0); 	
	    *corner = xyz_add(ftl, xyz_expr(length, 0, 0) );  
	    *d = - (corner -> x);
	    break;  
	case UP: 
	    *s_norm = xyz_expr(0, 1, 0); 	
	    *corner = ftl; 
	    *d = - (corner -> y);
	    break;  
	case DOWN: 	
	    *s_norm = xyz_expr(0, -1, 0); 	
	    *corner = xyz_add(ftl, xyz_expr(0, -length, 0) ); 
	    *d = corner -> y;
	    break; 
	default: 
	    fprintf(stderr, "face not any value\n"); 
	    exit(1); 
    }  
}

/* like on_poster, but for a cube face. Given the face corner, determines 
 * if loc is on the face
 */ 
int on_face(cube c, location corner, location loc, face f) { 

    if(f == FRONT) 
	 return (loc.x >= corner.x) &&
         (loc.x <= (corner.x + c.length)) &&
         (loc.y <= corner.y) &&
         (loc.y >= (corner.y - c.length));

    else if(f == LEFT || f == RIGHT) //yz plane  
    	 return (loc.z >= corner.z) &&
         (loc.z <= (corner.z + c.length)) &&
         (loc.y <= corner.y) &&
         (loc.y >= (corner.y - c.length));
    
    return (loc.x >= corner.x) &&
    (loc.x <= (corner.x + c.length)) &&
    (loc.z >= corner.z) &&
    (loc.z <= (corner.z + c.length));
} 

/* general function for poster intersect */ 
hit_test face_int(ray r, object obj_cube, face f) { 
    double d;
    location corner; 
    direction n; 
    cube_face_int_params(f, obj_cube.o.c, &n, &d, &corner);  
    
    double t = -(xyz_dot(r.origin,n)+d)/xyz_dot(r.dir,n);
    location hp = ray_position(r,t);

    if (t > 0 && on_face(obj_cube.o.c, corner, hp, f)) {
	color surf = obj_cube.o.c.surface_color(&obj_cube, hp); //if cube face, then we set to this  
	hit_test ht = {HIT, t, hp, surf, {0,0,0}, n};
	return ht;
    } 
    hit_test ht = {MISS,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    return ht;
} 

/* pre: the location's z matches the poster's 
 * this is outcome of math given haha
 */ 
int on_poster(poster *p, location loc)
{
    return (loc.x>=p->upper_left.x) &&
    (loc.x<=(p->upper_left.x+p->w)) &&
    (loc.y<=p->upper_left.y) &&
    (loc.y>=(p->upper_left.y-p->h));
}


hit_test pst_int(ray r, object obj, poster p)
{
    xyz n = xyz_expr(0,0,-1);
    double d = p.upper_left.z;
    double t = -(xyz_dot(r.origin,n)+d)/xyz_dot(r.dir,n);
    location hp = ray_position(r,t);
    if (t>0&&on_poster(&p,hp)) {
	color surf = p.surface_color(&obj, hp); 
	hit_test ht = {HIT, t, hp, surf, {0,0,0}, n}; 
	return ht; 
    }   
    hit_test ht = {MISS,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    return ht; 

}

hit_test cube_int(ray r, object obj, cube c) {  

    hit_test front = face_int(r, obj, FRONT); 
    hit_test up = face_int(r, obj, UP); 
    hit_test down = face_int(r, obj, DOWN); 
    hit_test left = face_int(r, obj, LEFT); 
    hit_test right = face_int(r, obj, RIGHT);

    if(front.miss == HIT && (xyz_dot(r.dir, front.surf_norm) < 0 ) ) 
	return front; 
    if(up.miss == HIT && (xyz_dot(r.dir, up.surf_norm) < 0) ) 
	return up; 
    if(down.miss == HIT && (xyz_dot(r.dir, down.surf_norm) < 0) )
	return down; 
    if(left.miss == HIT && (xyz_dot(r.dir, left.surf_norm) < 0) )
	return left; 
    if(right.miss == HIT && (xyz_dot(r.dir, right.surf_norm) < 0) )
	return right;
    hit_test nothing = {MISS,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    return nothing; 
}
 
hit_test intersect(ray r, object obj)
{
    switch (obj.tag) {
	case SPHERE:
	return sph_int(r, obj, obj.o.s); 
    case POSTER:
	return pst_int(r, obj, obj.o.p);
    case CUBE: 
	return cube_int(r, obj, obj.o.c); 
    default:
    fprintf(stderr,"error (intersect): unknown object tag %d\n",obj.tag);
    exit(1);
  }
}
