/* struct for a vector in 3d space */ 
typedef struct xyz {
    double x;
    double y;
    double z;
} xyz;

/* === vector operations === */

/* create new vector with given parameters */ 
xyz *xyz_new(double x, double y, double z);

/* create a fresh vector with same components as argument */
xyz *xyz_dup(xyz *v);

/* add two vectors */
xyz *xyz_add(xyz *v1, xyz *v2);

/* subtract the second vector from the first */
xyz *xyz_sub(xyz *v1, xyz *v2);

/* negate a vector */
xyz *xyz_neg(xyz *v);

/* scale the components of a vector by scalar s */
xyz *xyz_scale(double s, xyz *v);

/* compute the dot product of two vectors */
double xyz_dot(xyz *v1, xyz *v2);

/* compute the magnitude of a vector */
double xyz_mag(xyz *v);

/* normalize the vector */
xyz *xyz_norm(xyz *v);

/* produce a string representation of a vector */
char *xyz_tos(xyz *v);

/* print the string representation of a vector */
void xyz_print(xyz *v); 

