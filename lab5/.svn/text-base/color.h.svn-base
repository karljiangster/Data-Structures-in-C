#ifndef COLOR_H
#define COLOR_H

/* General struct for color */ 
typedef struct color {
        /* each value must be on interval [0,1] */
    double r;
    double g;
    double b;
} color;

/* === color operations === */

/* enforce that each value is on interval [0,1] */
color *color_new(double r, double g, double b);

/* creates a duplicate of the given color */
color *color_dup(color *c);

/* multiply the components of two colors */
color *color_modulate(color *c1, color *c2);

/* scale each component by given scalar */
color *color_scale(double s, color *c);

/* add components of colors */
color *color_add(color *c1, color *c2);

/* produce a string representation of a color */
char *color_tos(color *c);

/* prints the contents of color to the console. */
void color_print(color *c);

 /* print three integer values on [0,255]. */
void color_print_bytes(color *c);

#endif
