#ifndef colorlist_h
#define colorlist_h
#include "color.h" 

/* struct for colorlist*/ 
typedef struct colorlist colorlist;
struct colorlist {
    color c;
    colorlist *next;
};

/* note: must allocate a new struct on the heap */
colorlist *cl_cons(color *c, colorlist *cs);

/* returns the length of the entire colorlist */ 
unsigned int cl_length(colorlist *cs);

/* return the maximum red component of all colors */
double cl_max_red(colorlist *cs);

/* prints contents of colorlist */ 
void cl_print(colorlist *cs);

/* frees the colorlist */ 
void cl_free(colorlist *cs);

#endif
