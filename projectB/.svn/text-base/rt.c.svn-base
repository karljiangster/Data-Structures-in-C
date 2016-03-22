#include "raytracer.h"

int main(int argc, char *argv[])
{
  unsigned sel = argc>1 ? atoi(argv[1]) : 0;
  stage stg = get_stage(sel);
  
  FILE *f = fopen("evidence.ppm", "w"); 

  render(f,stg);

  printf("Object has been created...\n"); 

  ol_free(stg.s.objects);

  return 0;
}

