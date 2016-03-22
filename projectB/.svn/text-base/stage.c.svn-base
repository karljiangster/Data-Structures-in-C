#include "raytracer.h"

/* =================================== */ 
/* === stage operations => stage.c === */ 
/* =================================== */ 

const char *_stage_fmt = "*** begin stage\n\n%s\n\n%s\n*** end stage\n";

char *stage_tos(stage stg)
{
  char buf[1024];
  memset(buf,0,1024);
  char *c = camera_tos(stg.c);
  char *s = scene_tos(stg.s);
  snprintf(buf,1024,_stage_fmt,c,s);
  free(c);
  free(s);
  return strdup(buf);
}

void stage_show(FILE *f, stage stg)
{
  char *s = stage_tos(stg);
  fprintf(f,"%s",s);
  free(s);
}

/* constant coloring functions for easy testing */

color sc_red(object *o, location loc)
{
  return color_expr(1,0,0);
}

color sc_green(object *o, location loc)
{
  return color_expr(0,1,0);
}

/* sc_blue : surface color function that returns blue, always */
color sc_blue(object *o, location loc)
{
  return color_expr(0,0,1);
}

/* sc_maroon : surface color function that returns maroon, always */
color sc_maroon(object *o, location loc)
{
  return color_expr(0.5,0,0);
}

color sc_purple(object *o, location loc)
{
  return color_expr(0.5,0,0.5);
}

color sc_gray(object *o, location loc)
{
  return color_expr(0.5,0.5,0.5);
}

/* object constructors */

object *sphere_obj(location v, double r, color(*sc)(object*,location), color sh)
{
  object *new_obj = (object*)malloc(sizeof(object));
  if (new_obj==NULL) {
    fprintf(stderr,"error (sphere_obj): malloc failed\n");
    exit(1);
  }
  new_obj->tag = SPHERE;
  new_obj->o.s.center = v;
  new_obj->o.s.radius = r;
  new_obj->o.s.surface_color = sc;
  new_obj->o.s.shine = sh;
  new_obj->o.s.o = NULL;
  new_obj->t = NULL;
  return new_obj;
}

object *poster_obj(location ulc, 
		   double w,
		   double h, 
		   color(*sc)(object*,location), 
		   color sh)
{
  object *new_obj = (object*)malloc(sizeof(object));
  if (new_obj==NULL) {
    fprintf(stderr,"error (poster_obj): malloc failed\n");
    exit(1);
  }
  new_obj->tag = POSTER;
  new_obj->o.p.upper_left = ulc;
  new_obj->o.p.w = w;
  new_obj->o.p.h = h;
  new_obj->o.p.surface_color = sc;
  new_obj->o.p.shine = sh;
  new_obj->o.s.o = NULL;
  new_obj->t = NULL;
  return new_obj;
}

/* The function get_stage just needs to return a valid stage. */
/* The argument may be used, or not, at your discretion. */
stage get_stage(unsigned int selection)
{
  if (selection==1) {
    /* gallery image foo5.ppm */
    camera cam = {{0,0,-5},1280,1280};
    location ulc = {-1, 4, 1.5};
    object *pst = poster_obj(ulc, 0.5, 6, 
			map_texture_on_poster,color_expr(0,0,0) );
    pst -> t = make_vert_stripes(color_expr(0.5, 0.5, 0.8), 
			color_expr(0.9, 0, 0), 7); 
    light l = { xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1) }; 
    scene scn = {{0,0,0.25},ol_singleton(*pst), l, color_expr(0.1, 0.1, 0.1) };
    /* valgrind caught this -- it's because the poster is copied into
     * the object list, as opposed to its pointer being copied
     */
    free(pst);
    stage stg = {cam,scn};
    return stg;
  }
  if (selection==2) {
    /* gallery image foo6.ppm */
    camera cam = {{0,0,-5},1280,1280};
    location ulc = {-1.5,1.5,4.5};
	object *pst = poster_obj(ulc, 3, 3, map_texture_on_poster, 
			color_expr(0,0,0));
	pst -> t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8),
		   	color_expr(0.9, 0, 0), 5); 
	light l = { xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1) }; 
	scene scn = {{0,0,0.25},ol_singleton(*pst), l,
	   	color_expr(0.1, 0.1, 0.1) };
    free(pst);
    stage stg = {cam,scn};
    return stg;
  }
  if (selection==3) {
	/* foo7.ppm */ 
    camera cam = {{0,0,-5},1280,1280};
    location ulc = {-1.5,1.5,4.5};
	object *pst = poster_obj(ulc, 3, 3, map_texture_on_poster, 
			color_expr(0,0,0));
	pst -> t = make_waves(100, 0, 0, color_expr(1, 0, 0));  
	light l = { xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1) }; 
	scene scn = {{0,0,0.25},ol_singleton(*pst), l,
	   	color_expr(0.1, 0.1, 0.1) };
    free(pst);
    stage stg = {cam,scn};
    return stg;

  }
  if (selection==4) {
    /* gallery image foo9.ppm */
    camera cam = {{0,0,-5},1280,1280};
    location ulc = {-1,4,1.5};
	object *pst = poster_obj(ulc, 0.5, 6, map_texture_on_poster, 
			color_expr(0,0,0));
	texture *stripes = make_vert_stripes(color_expr(0.5, 0.5, 0.8), 
			color_expr(0.9, 0, 0), 7); 
	pst -> t = stripes; 
	object *sphere = sphere_obj(xyz_expr(0, 0, 3), 1, map_texture_on_sphere, 
			color_expr(0, 0, 0) ); 
	sphere -> t = stripes; 
	object *sphere_small = sphere_obj(xyz_expr(0.5, -0.7, 2), 0.5, 
			map_texture_on_sphere, color_expr(0, 0, 0) ); 
	sphere_small -> t = make_waves(100, 0, 0, color_expr(1, 0, 0) ); 
	light l = {xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1) };
	
	obj_list* objs = ol_singleton(*pst); 
	objs = ol_cons(*sphere, objs); 
	objs = ol_cons(*sphere_small, objs); 
	scene scn = { {0,0,0.25}, objs, l,
	   	color_expr(0.1, 0.1, 0.1) };
    free(pst);
    stage stg = {cam,scn};
    return stg;
  } 
  if (selection==100) {
    /* striped sphere */
    camera c = {{0,0,-5},1280,720};
    light l = { xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1) }; 
    //texture* tex = make_vert_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 7); 
    texture* tex = make_waves(600, 0, 0, color_expr(1.0, 0, 0) ); 
    object *sph = sphere_obj(xyz_expr(0,0,3),1,&map_texture_on_sphere,color_expr(0,0,0));
    sph -> t = tex;  
    scene s = {{0,0,0.25},NULL, l, color_expr(0.1, 0.1, 0.1) };
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==101) {
    /* let's get a better look at the striped sphere... */
    camera c = {{0,0,-5},500,800};
    object *sph = sphere_obj(xyz_expr(0,0,4),1,&sphere_horiz_stripes,color_expr(0,0,0));
    scene s = {{0,0,0.25},NULL};
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==103) {
    /* based on gallery image 3 */
    camera c = {{0,0,-5},120,120};
    object *sph = sphere_obj(xyz_expr(1,0,4),1,&sc_red,color_expr(0,0,0));
    scene s = {{0,0,0.25},NULL};
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==104) {
    /* based on gallery image 4 */
    camera c = {{0,0,-5},120,120};
    object *sph0 = sphere_obj(xyz_expr(0,0,3),1,&sc_blue,color_expr(0,0,0));
    object *sph1 = sphere_obj(xyz_expr(-0.5,0.7,3),0.5,&sc_red,color_expr(0,0,0));
    scene s = {{0,0,0.25},NULL};
    s.objects = ol_cons(*sph0,ol_singleton(*sph1));    
    free(sph0);
    free(sph1);
    stage g = {c,s};
    return g;
  }

  /* some simple examples for students */
  if (selection==15200) {
    camera c = {{0,0,-5},300,300};
    object *sph = sphere_obj(xyz_expr(0,0,3),1,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==15201) {
    camera c = {{0,0,-5},600,300};
    object *sph = sphere_obj(xyz_expr(0,0,3),1,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==15202) {
    camera c = {{0,0,-5},300,600};
    object *sph = sphere_obj(xyz_expr(0,0,3),1,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*sph);
    free(sph);
    stage g = {c,s};
    return g;
  } 
  if (selection==15203) {
    camera c = {{0,0,-5},300,300};
    object *pst = poster_obj(xyz_expr(-1,1,3),1,1,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*pst);
    free(pst);
    stage g = {c,s};
    return g;
  } 
  if (selection==15204) {
    camera c = {{0,0,-5},300,300};
    object *pst = poster_obj(xyz_expr(-1,1,3),2,1,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*pst);
    free(pst);
    stage g = {c,s};
    return g;
  } 
  if (selection==15205) {
    camera c = {{0,0,-5},300,300};
    object *pst = poster_obj(xyz_expr(-1,1,3),1,2,&sc_blue,color_expr(0,0,0));
    scene s = {{0,0,0},NULL};
    s.objects = ol_singleton(*pst);
    free(pst);
    stage g = {c,s};
    return g;
  } 
  if (selection==15206) {
    camera c = {{0,0,-5},200,400};
    object *sph0 = sphere_obj(xyz_expr(-1,0,3),0.3,&sc_blue,color_expr(0,0,0));
    object *sph1 = sphere_obj(xyz_expr(1,0,3),0.3,&sc_maroon,color_expr(0,0,0));    
    scene s = {{0,0,0},NULL};
    s.objects = ol_cons(*sph0,ol_singleton(*sph1));
    free(sph0);
    free(sph1);
    stage g = {c,s};
    return g;
  }
	fprintf(stderr,"error (get_stage): undefined selection %u\n"
                 "(see get_stage in stage.c for available selections)\n",selection);
	exit(1);
} 
