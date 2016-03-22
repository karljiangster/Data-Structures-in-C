# Makefile (starter)
# CS152 Winter 2016
# Project A

.PHONY: clean

xyz: raytracer.h xyz.c ev_xyz.c
		clang -lm -g -Wall -o ev_xyz xyz.c ev_xyz.c

color: raytracer.h color.c ev_color.c
		clang -lm -g -Wall -o ev_color color.c ev_color.c

ray: raytracer.h xyz.c ray.c ev_ray.c 
		clang -lm -g -Wall -o ev_ray xyz.c ray.c ev_ray.c 

sphere: raytracer.h xyz.c color.c sphere.c ev_sphere.c 
		clang -lm -g -Wall -o ev_sphere xyz.c color.c sphere.c ev_sphere.c 

poster: raytracer.h xyz.c color.c poster.c ev_poster.c 
		clang -lm -g -Wall -o ev_poster xyz.c color.c poster.c ev_poster.c 

object: raytracer.h xyz.c color.c poster.c sphere.c object.c ev_object.c 
		clang -lm -g -Wall -o ev_object xyz.c color.c poster.c sphere.c object.c ev_object.c 

obj_list: raytracer.h xyz.c color.c poster.c sphere.c object.c obj_list.c ev_objlist.c 
	clang -lm -g -Wall -o ev_obj_list xyz.c color.c poster.c sphere.c object.c obj_list.c ev_objlist.c 

scene: raytracer.h xyz.c color.c poster.c sphere.c object.c obj_list.c scene.c ev_scene.c 
	clang -lm -g -Wall -o ev_scene xyz.c color.c poster.c sphere.c object.c obj_list.c scene.c ev_scene.c 

hit_test: raytracer.h xyz.c color.c hit_test.c ev_hit_test.c
	clang -lm -g -Wall -o ev_hit_test xyz.c color.c hit_test.c ev_hit_test.c 

camera: raytracer.h xyz.c camera.c ev_camera.c 
	clang -lm -g -Wall -o ev_camera xyz.c camera.c ev_camera.c 

stage: raytracer.h xyz.c color.c poster.c sphere.c object.c obj_list.c scene.c camera.c stage.c ev_stage.c  
	clang -lm -g -Wall -o ev_stage xyz.c color.c poster.c sphere.c object.c obj_list.c scene.c camera.c stage.c ev_stage.c 

intersect: raytracer.h xyz.c color.c ray.c poster.c sphere.c object.c hit_test.c intersect.c ev_intersect.c 
	clang -lm -g -Wall -o ev_intersect xyz.c color.c ray.c poster.c sphere.c object.c hit_test.c intersect.c ev_intersect.c 

texture: raytracer.h xyz.c color.c ray.c poster.c sphere.c object.c texture.c ev_texture.c  
	clang -lm -g -Wall -o ev_texture xyz.c color.c ray.c poster.c sphere.c object.c texture.c ev_texture.c  

raytracer: raytracer.h xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c camera.c hit_test.c stage.c intersect.c raytracer.c rt.c
	clang -lm -g -Wall -o ev_rt xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c camera.c hit_test.c stage.c intersect.c raytracer.c rt.c

SRC = xyz.c color.c ray.c sphere.c poster.c object.c obj_list.c scene.c light.c camera.c hit_test.c stage.c intersect.c raytracer.c rt.c texture.c

trace: raytracer.h $(SRC)
	clang -g -O3 -Wall -o rt $(SRC) -lm

clean:
	rm -rf rt *.dSYM *.ppm
