/* Karl Jiang, karljiang
 * CS 152, Winter 2016
 * HW4 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "hw4.h" 


/* constructor for measurement. */ 
measurement new_m(double v, char* u, unsigned exp) { 
    measurement m; 
    m.value = v; 
    m.units = u; 
    m.exponent = exp;
    return m; 
} 


/* constructor for conversion */  
conversion new_conv(char *fm, char *t, double mult) { 
    conversion c; 
    c.from = fm; 
    c.to = t; 
    c.mult_by = mult; 
    return c; 
} 


/* returns an unsigned int of the number of elements needed in the 
* output of split_at. 
*/ 
unsigned int num_splits(char *s, char d) { 

	int count = 1; 
	
	char *cur_char = s + 1; 
	while(*cur_char != '\0') { 
	    if(*cur_char == d) { 
		    ++count; 
		}
	    cur_char++; 
	} 
	if(*cur_char - 1 == d) 
	    count--; 
	return count; 
} 


/* takes in a string s and a delimiter d and splits the string into
 * "words", starting a new word each time the delimiter character occurs.
 * The words are returned in an array of strings.
 */ 
char** split_at(char* s, char d) { 	
	    
    int num_s = num_splits(s, d); 
    char ** splits = malloc( ( num_s + 1) * sizeof(char*)); //+1 for NULL 
 
    int index = 0; //tracking the number of elements 
    int str_len = 0; //tracks the length of each string   
    char* cur_char = s; //iterates through s 
 
    if(*s != d) 
	str_len++;
    cur_char++; 


    while(*cur_char != '\0') { 
	if(*cur_char == d) {  
	    splits[index] = malloc((str_len + 1) * sizeof(char));
	    strncpy(splits[index], cur_char - str_len, str_len);
	    str_len = 0;  
	    ++index; 
	} 
	else 
	    ++str_len; 
	cur_char++; 
    }  
    
    if(index + 1 < num_s) { //implying last char was not a delim 
	splits[index] = malloc((str_len + 1) * sizeof(char));
	strncpy(splits[index], cur_char - str_len, str_len); 
    }
    
    splits[num_s] = NULL; 
    return splits; 
 }
 

/* simply adds two numbers. Cannot run if they are of different measurements. */ 
measurement add_measurements(measurement m1,  measurement m2) { 

    if(strcmp(m1.units, m2.units) || m1.exponent != m2.exponent) { 
	fprintf(stderr, "Units or exp do not match."); 
	exit(1); 
    } 
    
    return new_m(m1.value + m2.value, strdup(m1.units), m1.exponent); 
} 

/* returns a copy of the measurement scaled by the provided factor. */ 
measurement scale_measurement(measurement m, double lambda) { 
    return new_m(m.value * lambda, strdup(m.units), m.exponent); 
}  

/* multiplies two measurements, must be of same units, but can be of 
* different exponent.
*/ 
measurement multiply_measurements(measurement m1,  measurement m2) { 
 
    if( strcmp(m1.units, m2.units) ) { 
	fprintf(stderr, "Units do not match."); 
	exit(1); 
    } 
    return new_m(m1.value * m2.value, strdup(m1.units), m1.exponent + m2.exponent); 
}  

/* toString() function for the measurement. Uses the fprintf function to write into 
 * the returned string value and strdup to make a heap allocated copy. 
 */ 
char* measurement_tos( measurement m) { 
    
    char buf [30];
    if (m.exponent != 1) 
        sprintf(buf, "%.2lf %s^%u\n", m.value, m.units, m.exponent);  
    else 
        sprintf(buf, "%.2lf %s\n", m.value, m.units);    
    return strdup(buf); 
}


/* takes in a list of known conversion factors and its length, a particular measurement,
 * and the units to which we want it to be converted to. Returns propertly converted 
 * and labeled value. 
 */ 
 measurement convert_units(conversion* conversions, unsigned int n_conversions,
                        measurement m, char* to) { 
   for(int i = 0; i < n_conversions; ++i) {
	if( !(strcmp(conversions[i].from, m.units) ) && 
		!( strcmp(conversions[i].to, to) ) ) { 
	    measurement c_m = new_m(m.value, conversions[i].to, m.exponent); 
	    for(int j = 0; j < m.exponent; ++j) { 
		c_m.value *= conversions[i].mult_by; 
	    }
	    return c_m; 
	} 
    }  
    fprintf(stderr, "No direct conversions avaliable in conversions array."); 
    exit(1); 
}


/* makes new, empty lists in array_list format. */
int_list int_array_new() { 
    int_list a_list; 
    a_list.tag = ARRAY; 
    a_list.u.array.alen = 0; 
    a_list.u.array.a = NULL; 
    return a_list; 
}


/* makes new, empty list in linked list format. */ 
int_list int_linked_new() { 
    int_list i_list;
    i_list.tag = LINKED; 
    i_list.u.linked = NULL; 
    return i_list; 
} 


/* returns the nth value POINTER in the provided list, using zero based indexing. */ 
int * _int_list_nth(int_list xs, unsigned int n) { 
    if(xs.tag == ARRAY) { 
	if(xs.u.array.alen <= n) { 
	    fprintf(stderr, "Requested index beyond size of arraylist"); 
	    exit(1);  
	} 
	return xs.u.array.a + n; 
    }
    
    int_linkedlist* tmp = xs.u.linked; 
    while(n-- && tmp) { 
	tmp = tmp->next; 
    } 
    if(tmp) 
	return &(tmp->val); 
    fprintf(stderr, "Requested index beyond size of linked list.");  
    exit(1);  
}

//* returns the nth value POINTER in the provided list, using zero based indexing. */ 
int int_list_nth(int_list xs, unsigned int n) { 
    return *_int_list_nth(xs, n); 
} 


/* ovrewrites the value in the list at the nth index with the specified value. */ 
void int_list_set(struct int_list xs, unsigned int n, int val) { 
     *_int_list_nth(xs, n) = val;  
}  

/* contructor for a list node */ 
int_linkedlist * _new_ll(int val, int_linkedlist * next) { 
    int_linkedlist* new = (int_linkedlist*) malloc(sizeof(*new));  
    new -> val = val; 
    new -> next = next; 
    return new;  
} 

/* appends the given value to the end of the specified list. Note that in the array 
 * case, a new array must be created that is one element longer and free old arr. 
 */ 
void int_list_append(struct int_list* xs, int val) { 
    if(xs->tag == ARRAY) { 
	xs->u.array.alen++;
	xs->u.array.a = (int *) realloc(xs->u.array.a, xs->u.array.alen * sizeof(int)); 
	xs->u.array.a[xs->u.array.alen - 1] = val; 
	return; 
    }
   
    if(!xs -> u.linked) { 
	xs -> u.linked = _new_ll(val, NULL);
	return; 
    }  
    
    int_linkedlist * cur = xs -> u.linked;
    while(cur -> next != NULL) { 
	cur = cur -> next; 
    } 
    cur -> next = _new_ll(val, NULL); 
} 


/* appends the given value to the beggining of the specified list. Note that in the array 
 * case, a new array must be created that is one element longer and free old arr. 
 */
void int_list_prepend(int_list* xs, int val) { 
    if(xs->tag == ARRAY) { 
	int_arraylist* A = &(xs -> u.array);
	A -> a = realloc(A -> a, ( A -> alen + 1 ) * sizeof(int) );
	for(int i = A -> alen; i; --i) { 
	    A -> a[i] = A -> a[i - 1]; 
	} 
	A -> a[0] = val; 
	A -> alen++; 
	return; 
    }
     xs -> u.linked = _new_ll(val, xs -> u.linked);  
}


/* prints the contents of the list on the screen, seperated by spaces. */
void int_list_show(struct int_list xs) { 
    if(xs.tag == ARRAY) {
	int* a = xs.u.array.a, n = xs.u.array.alen;
	if (!n)
	    return;
	for (int i = 0; i < n - 1; i++)
	    printf("%d ", a[i]);
	printf("%d", a[n - 1]);
	return;
    } 
    int_linkedlist* tmp = xs.u.linked; 
    if (!tmp)
	return;
    for(tmp = xs.u.linked; tmp->next != NULL; tmp = tmp->next) { 
	printf("%d ", tmp->val); 
    } 
    printf("%d", tmp->val); 
} 


/* reclaims memory used by the array or by the linked list cells */ 
void int_list_free(struct int_list xs) { 
    if(xs.tag == ARRAY) { 
	free(xs.u.array.a);	
	return; 
    }  
    int_linkedlist* tmp = xs.u.linked; 
    while(tmp) { 
	int_linkedlist * will_die = tmp; 
	tmp = tmp -> next; 
	free(will_die); 
    }  
}


/* constructor for digitlist - make the first node */ 
digitlist* _new_dlist(unsigned char digit, digitlist* next) { 
    digitlist* new = (digitlist*) malloc(sizeof(*new) ); 
    new -> digit = digit; 
    new -> next = next; 
    return new; 
}   


/* frees the digitlist from the heap. */ 
void _free_digitlist(digitlist* digits) { 
    digitlist* cur = digits; 
    while(cur) { 
	digitlist* willdie = cur; 
	cur = cur -> next; 
	free(willdie); 	
    } 	     
} 


/* to string function for digitlist */ 
void _print_digits(digitlist* digits) { 

    digitlist* tmp = digits; 
    if(!tmp) 
	return;
    int count = 0; 
    for(tmp = digits; tmp != NULL; tmp = tmp -> next) { 
	printf("%d ", tmp -> digit); 
	count++; 
    } 
}


/* adds the remaning digitlist to the sum digitlist */ 
void add_one_digitlist(unsigned char base, digitlist* a, 
	digitlist* cur, unsigned char dig_b) {
   
    unsigned char temp_sum = (a -> digit) + dig_b; 
    
    while(a -> next) { 
	cur -> digit = temp_sum % base; 
	cur -> next = _new_dlist(temp_sum / base, NULL);
	cur = cur -> next; 
	a = a -> next;		
	temp_sum = (cur -> digit) + (a -> digit); 
    }	
    
    cur -> digit = temp_sum % base;
    if(temp_sum / base) { 
	cur -> next = _new_dlist(temp_sum / base, NULL); 
    } 
} 


/* adds two digitlists together by adding each node value. */ 
digitlist* add_digits(unsigned char base, digitlist* ds1, digitlist* ds2) { 
    
    digitlist* sum = _new_dlist(0, NULL); //this will be returned 
    digitlist* cur = sum; //add nodes to sum 
    digitlist* a = ds1; //parse through a 
    digitlist* b = ds2; //parse through b 

    while(a -> next != NULL && b -> next != NULL) { 
	unsigned char temp_sum = cur -> digit + a -> digit + b -> digit; 
	cur -> digit = temp_sum % base; 
	cur -> next = _new_dlist(temp_sum / base, NULL);
	cur = cur -> next; 
	a = a -> next; 
	b = b -> next; 	
    }
    
    if(a -> next) { 
	add_one_digitlist(base, a, cur, b -> digit); 
    } 
    else if(b -> next)
    	add_one_digitlist(base, b, cur, a -> digit); 
     
    else { 
	unsigned char temp_sum = (cur -> digit) + (a -> digit) + 
	    (b -> digit); 
	cur -> digit = temp_sum % base;      
	if(temp_sum / base) { 
	    cur -> next = _new_dlist(temp_sum / base, NULL); 
	} 
    }
    return sum;  
} 
