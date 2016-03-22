#include "raytracer.h"
#include "math.h" 

/* === raytracer.c === */

/* hit test utilities */

const hit_test _miss = {MISS,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}};

int hit(hit_test t)
{
  return t.miss==HIT;
}

int miss(hit_test t)
{
  return t.miss==MISS;
}

/* coordinate system transformation */

location logical_loc(camera c, unsigned int x, unsigned int y)
{
  double pixw, pixh;
  double lx, ly;
  if (c.h>c.w)
    pixh = pixw = 2.0 / c.h;
  else
    pixh = pixw = 2.0 / c.w;
  if (x>c.w || y>c.h) {
    fprintf(stderr, "error (logical_loc): out of bounds (%d, %d)\n", x, y);
    exit(1);
  }
  lx = -1.0 + (pixw * x) + (pixw / 2.0);
  ly =  1.0 - ((pixh * y) + (pixh / 2.0));
  if (c.w>c.h)
    ly -= (c.w-c.h) / 2.0 * pixh;
  else
    lx += (c.h-c.w) / 2.0 * pixw;
  location result = {lx, ly, 0};
  return result;
}

/* ray tracing */

color color_at(object *obj, location loc)
{
  color(*sc)(object*,location) = 
    obj->tag==SPHERE?
    obj->o.s.surface_color: 
    obj->o.p.surface_color;
  return (*sc)(obj,loc);
}

color trace_ray(scene s, ray r)
{
  obj_list *objs = s.objects;
  hit_test closest_hit = _miss;
  object *closest_obj = NULL;
  /* walk over object list, keep track of closest object if there is one */
  while (objs) {
    /* for each object, check for intersect */
    hit_test curr_hit = intersect(r,objs->obj);
    /* if it hits AND it's the first hit OR it's closer than closest hit */
    if (hit(curr_hit) && (miss(closest_hit) || (curr_hit.t<closest_hit.t))) {
      // update this to be the closest hit
      closest_hit = curr_hit;
      closest_obj = &(objs->obj);
    }
    // advance to next object
    objs = objs->next;
  }
  /* if there is a closest object, return its color, otherwise s.bg */
    return closest_obj?shining(s, r, closest_hit, *closest_obj):s.bg;  	
}

/* main loop and ppm creation */

void ppm_header(FILE *f, int height, int width)
{
  fprintf(f,"P3\n");
  fprintf(f,"%d %d\n", width, height);
  fprintf(f,"255\n");
}

void render(FILE *f, stage g)
{
  int row, col;
  camera c = g.c;
  scene sc = g.s;
  ppm_header(f,c.h,c.w);
  /* loop over all locations in the pixel field */
  for(row=0; row<c.h; row++) {
    for(col=0; col<c.w; col++) {
      /* 1: Translate from physical to logical */
      location loc = logical_loc(c,col,row);
      /* 2: Create a directional vector from camera to pixel */
      direction dir = xyz_sub(loc,c.loc);
      /* 3: Normalize this vector */
      direction normdir = xyz_norm(dir);
      /* 4: Create a ray starting at the camera in the direction of normdir */
      ray r = {c.loc,normdir};
      /* 5: trace the ray through the scene and obtain the color */
      color col = trace_ray(sc,r);
      /* 6: print that pixel to the screen (which can be redirected to a file) */
      color_show_bytes(f,col);
    }
  }
}


/* Given an intersection location p, light source, and object list,
 * check each object to see if it intersects the shadow ray. 
 * return nonzero if the location p is in shadow. Return 0 if not.
 */
int shadow(location p, light l, obj_list *objs) { 

    direction nudge = xyz_scale(1e-6, l.dir); 

    ray light_ray = { xyz_add(p, nudge), l.dir }; 

    obj_list* tmp = objs;
    while ( tmp != NULL && intersect(light_ray, tmp -> obj).miss != HIT )
	tmp = tmp -> next;
    //return 0;
    return tmp != NULL; 

}  


/* Given a scene, ray, and hit_test, determine the color of the pixel.
 * The hit_test already calculated the surface color of the shape in the 
 * absence of lighting. Here, you take into account shadow and ambient
 * light to adjust the color. */
color lighting(scene s, ray r, hit_test h) { 

    color surf = h.surf; //already computed color in intersect 
    if(h.miss == MISS) 
	return s.bg; 
    if( shadow(h.hit_point, s.light, s.objects) ) { 
	return color_modulate(surf, s.bg); 	
    } 
    else { 
	double beyond = xyz_dot(h.surf_norm, s.light.dir); 
	color diffuse = color_scale( (beyond > 0) ? beyond : 0,
	       	s.light.c); 
	return color_modulate(surf, color_add(s.bg, diffuse) ); 		
    } 
} 

/* returns max val in dbls */ 
double _max(double* dbls, int len) { 
    double max = *dbls; 
    for(int i = 0; i < len; ++i) { 
	if(dbls[i] > max) 
	    max = dbls[i]; 
    }
    return max; 
} 

/*gets the shine from obj */ 
color get_shine_from_obj(object o) { 
    switch(o.tag) { 
	case CUBE:
	    return o.o.c.shine; 
	case SPHERE: 
	    return o.o.s.shine; 
	case POSTER:
	    return o.o.p.shine;
	default: 
	    fprintf(stderr, "no tag specificed.\n"); 
	    exit(1);  
    } 
} 

/* includes shine to edit lighting */ 
color shining(scene scn, ray rey, hit_test h, object o) { 

    
    color k = lighting(scn, rey, h); 
    color S = get_shine_from_obj(o); 
    color s;
    direction n = h.surf_norm; 
    direction l = xyz_norm(scn.light.dir);
    double n_dot_l = xyz_dot(n, l);  

    if(n_dot_l > 0 ) { 
	direction r_scale = xyz_scale(2 * n_dot_l, n);	
	direction r = xyz_sub(r_scale, l); 
	direction v = xyz_neg(rey.dir);
	double dbls [] = {xyz_dot(r, v) , 0};
	s = color_scale(pow( _max(dbls, 2), 6), S );
	return color_add(s, k); 
    }
    return k; 
} 



