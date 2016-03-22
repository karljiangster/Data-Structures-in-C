/* takes in a string s and a delimiter d and splits the string into
 * "words", starting a new word each time the delimiter character occurs.
 * The words are returned in an array of strings.
 */ 
 char** split_at(char* s, char d);

/* represent a measurement that consists of a numeric value and a unit
 * (such * as 56.5 in). 
 */ 
struct measurement{
    double value;
    char* units;
    unsigned int exponent;
}; 
typedef struct measurement measurement; 

/* represents a conversion. For measurements. */ 
struct conversion {
    char *from, *to;
    double mult_by;
}; 
typedef struct conversion conversion; 

/* constructor for measurement */ 
measurement new_m(double v, char* u, unsigned exp);

/* constructor for conversion */  
conversion new_conv(char *fm, char *t, double mult); 

/* simply adds two numbers. Cannot run if they are of different measurements. */ 
 measurement add_measurements(measurement m1, measurement m2);

/* returns a copy of the measurement scaled by the provided factor. */ 
measurement scale_measurement(measurement m, double lambda);

/* multiplies two measurements, must be of same units, but of different exponent.*/ 
measurement multiply_measurements(measurement m1, measurement m2);

/* toString() function for the measurement. Uses the fprintf function to write into 
* the returned string value and strdup to make a heap allocated copy. 
*/ 
char* measurement_tos( measurement m);

/* takes in a list of known conversion factors and its length, a particular measurement,
 * and the units to which we want it to be converted to. Returns propertly converted 
 * and labeled value. 
 */ 
measurement convert_units(conversion* conversions, unsigned int n_conversions,
                        measurement m, char* to);

/* the following data structures allow us to represent a list of 
 * integers either as an array, or as a linked list. 
 */ 
struct int_arraylist {
    int* a;
    unsigned int alen;
}; 
typedef struct int_arraylist int_arraylist; 

typedef struct int_linkedlist int_linkedlist;
struct int_linkedlist {
    int val;
    int_linkedlist* next;
}; 

union int_listunion {
    int_arraylist array;
    int_linkedlist* linked;
};
typedef union int_listunion int_listunion; 

enum int_listtag {
    ARRAY, LINKED
};
typedef enum int_listtag int_listtag; 

struct int_list{
    enum int_listtag tag;
    union int_listunion u;
};
typedef struct int_list int_list;

/* makes new, empty lists in array_list format. */ 
int_list int_array_new();

/* makes new, empty list in linked list format. */ 
int_list int_linked_new();

/* returns the nth value in the provided list, using zero based indexing. */ 
int int_list_nth(struct int_list xs, unsigned int n);

/* ovrewrites the value in the list at the nth index with the specified value. */ 
void int_list_set(struct int_list xs, unsigned int n, int val);

/* appends the given value to the end of the specified list. Note that in the array 
 * case, a new array must be created that is one element longer and free old arr. 
 */ 
void int_list_append(struct int_list* xs, int val);

/* appends the given value to the beggining of the specified list. Note that in the array 
 * case, a new array must be created that is one element longer and free old arr. 
 */ 
void int_list_prepend(struct int_list* xs, int val);

/* prints the contents of the list on the screen, seperated by spaces. */ 
void int_list_show(struct int_list xs);

/* reclaims memory used by the array or by the linked list cells */ 
void int_list_free(struct int_list xs);

/* struct for digitlist, a linked list starting with the ones digit. */ 
typedef struct digitlist digitlist;

struct digitlist {
    unsigned char digit;
    digitlist* next;
};

/* constructor for digitlist - make the first node */ 
digitlist* _new_dlist(unsigned char digit, digitlist* next); 

/* frees the digitlist from the heap. */ 
void _free_digitlist(digitlist* digits); 

/* to string function for digitlist */ 
void _print_digits(digitlist* digits); 

/* adds two digitlists together by adding each node value. */ 
digitlist* add_digits(unsigned char base, digitlist* ds1, digitlist* ds2);


/* The following declarations were automatically added by add-stubs.sh at
 * Thu, Feb 18, 2016  9:48:30 PM, so that the automated tests can compile.
 */

