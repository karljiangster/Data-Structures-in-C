#include <stdio.h> 
#include <stdlib.h> 
#include "final.h" 
#include <string.h> 

intlist* intlist_cons(int val, intlist* l) { 

    intlist* new = malloc(sizeof(intlist) ); 
    new -> val = val; 
    new -> next = l; 
    return new; 
} 

void intlist_show(intlist* xs) { 
    
    for(intlist* tmp = xs; tmp != NULL; tmp = tmp -> next) { 
	printf("%d ", tmp -> val); 
    } 
    puts(" "); 
} 

intlist* reverse(intlist* xs) { 

    intlist* reverse; 
    for(intlist* tmp = xs; tmp != NULL; tmp = tmp -> next) { 

	reverse = intlist_cons(tmp -> val, reverse); 
    }
    return reverse;  
} 

void rem_dupes(intlist* xs) { 

    for(intlist* tmp = xs; tmp != NULL; tmp = tmp -> next) { 
	intlist* cur = tmp -> next; 
	while(cur != NULL && cur -> val == tmp -> val) { 
	    intlist* willdie = cur; 
	    cur = cur -> next; 
	    free(willdie); 
	} 
	tmp -> next = cur; 
    } 
    
} 

void rem_runs(intlist* xs) { 
    intlist* tmp = xs; 
    while(tmp != NULL) { 
	intlist* cur = tmp -> next; 
	while(cur != NULL && cur -> val == tmp -> val) { 
	    intlist* willdie = cur; 
	    cur = cur -> next; 
	    free(willdie); 
	} 
	tmp = cur;
		
    } 
} 

 
unsigned short cencode(char c) { 
    if(c  == '.')  
	return 27; 
    if(c == ' ')  
	return 0; 
    if(c >= 'A' && c <= 'Z')  
	return c - 'A' + 1; 
    if(c >= 'a' && c <= 'z')  
	return c - 'a' + 1; 
    fprintf(stderr, "Invalid. s: %c\n", c); 
    exit(1);  
}


void print_in_binary(unsigned short x) { 

        if(!x) 
	    return; 
	print_in_binary(x >> 1); 
	printf("%d ", x & 1); 
		    
} 


int add_value(int val, int pack, int offset) { 
    //short val to desired length, 5. shift val by push. erase all vals in pack in range. 
    val = (val & 0x1f) << offset;
    pack = pack & ~((0x1f) << offset); 
    return pack | val;  
    
} 

unsigned short* encode(char* s, unsigned int* alen) { 

    unsigned int length = strlen(s); 
    *alen = length / 3 + ( (length % 3) ? 1 : 0); 
    unsigned short* coded = malloc(sizeof(unsigned short) * (*alen) ); 
    //added +1 for /0 and leftovers  

    char* cur = s;
    int index = 0;  
    while(*cur != '\0') { 
	
	coded[index] = ( cencode(*cur) << 10); 
	if(cur[1] == '\0') { 
	    break;
	}

	//coded[index] = coded[index] | ( cencode( cur[1] ) << 5); 
	coded[index] = add_value(cencode( *(cur + 1) ), coded[index], 5); 
	if(cur[2] == '\0') {  
	    break;
	} 

	//coded[index] = coded[index] | cencode( cur[2] ); 
    	coded[index] = add_value(cencode( *(cur + 2 ) ), coded[index], 0); 

	index++;
	cur += 3; 	
    } 

    return coded; 
} 

char cdecode(unsigned char b) { 

    if(b == 0) 
	return ' '; 
    if(b == 27)
	return '.'; 
    else if(b < 27)
	return 'a' - 1 + b; 
    else 
	fprintf(stderr, "b exceed 27: %c\n", b); 
	exit(1); 
} 


char* decode(unsigned short* a, unsigned int alen) { 

    int code_len = alen * 3 + 1; 
    char* code = (char*) malloc(sizeof(char) * code_len);
    for(int i = 0; i < alen; ++i) { 

	unsigned short msg = a[i];	
	code[3 * i + 2] = cdecode(msg & 0x1f); 	
	code[3 * i + 1] = cdecode( (msg >> 5) & 0x1f); 
	code[3 * i] = cdecode( (a[i] >> 10) & 0x1f); 
    } 	
    code[code_len - 1] = '\0'; 
    return code; 
} 
 

double evaluate(exptree* t) { 

    if(t == NULL) 
	return 0; 
    if(t -> type == LIT) 
	return t -> u.lit;  
    switch(t -> u.op.op) { 
	case PLUS: 
	    return evaluate(t -> u.op.left) + evaluate(t -> u.op.right); 
   	case MINUS: 
	    return evaluate(t -> u.op.left) - evaluate(t -> u.op.right); 
	case TIMES: 
	    return evaluate(t -> u.op.left) * evaluate(t -> u.op.right); 
	case DIVIDE:
	    return evaluate(t -> u.op.left) / evaluate(t -> u.op.right); 
	default: 
	    printf("This should not be happening. \n"); 
	    return 0; 
    }  
}

void exptree_show(exptree* t) { 

    if(t == NULL) 
	return;
    if(t -> type == LIT) { 
	printf("%f ", t -> u.lit); 
    } 
    
    else { 
	printf("( ");  
	exptree_show(t -> u.op.left); 
	switch(t -> u.op.op) { 
	    case PLUS: 
		printf("+ ");
		break; 	
	    case MINUS: 
		printf("- "); 
		break; 
	    case TIMES: 
		printf("* "); 
		break; 
	    case DIVIDE:
		printf("/ "); 
		break; 
	    default: 
		printf(" dur "); 
	} 
	exptree_show(t -> u.op.right); 
	printf(") "); 
    } 
}

struct matrix* matrix_new(unsigned int nrows, unsigned int ncols) { 

    matrix* m = (matrix*) malloc(sizeof(matrix) ); 
    m -> nrows = nrows; 
    m -> ncols = ncols; 
    m -> m = (double**) malloc(sizeof(double*) * nrows ); 
    for(int i = 0; i < nrows; ++i) { 
	m -> m[i] = (double*) malloc(sizeof(double) * ncols); 
	for(int j = 0; j < ncols; ++j) 
	    m -> m[i][j] = 1; 
    }  
    return m; 
}

void matrix_show(struct matrix* m) { 

    for(int i = 0; i < m -> nrows; ++i) { 
	printf("| "); 
	for(int j = 0; j < m -> ncols; ++j) { 
	    printf("%.1f ", m -> m[i][j]); 
	} 
	printf("|\n"); 
    } 
}

struct matrix* matrix_transpose(struct matrix* m) { 

    matrix* pose = malloc(sizeof(double*) * m -> ncols); 
    pose -> ncols = m -> nrows; 
    pose -> nrows = m -> ncols; 
    pose -> m = (double**) malloc(sizeof(double*) * pose -> nrows);
    
    for(int i = 0; i < pose -> nrows; ++i) { 
	pose -> m[i] = (double*) malloc(sizeof(double) * pose -> ncols); 
	for(int j = 0; j < pose -> ncols; ++j) 
	    pose -> m[i][j] = m -> m[j][i]; 
    }  
    return pose; 
}

void check_lengths(matrix *m1, matrix *m2) { 
    if(m1 -> nrows != m2 -> nrows || m1 -> ncols != m2 -> ncols) { 
	fprintf(stderr, "Matrix dimensions differ!\n"); 
	exit(1); 
    } 
} 
struct matrix* matrix_add(struct matrix* m1, struct matrix* m2) { 
    check_lengths(m1, m2); 
    matrix* sum = matrix_new(m1 -> nrows, m2 -> ncols); 

    for(int i = 0; i < m1 -> nrows; ++i) { 
	for(int j = 0; j < m2 -> ncols; ++j) { 
	    sum -> m[i][j] = m1 -> m[i][j] + m2 -> m[i][j]; 	    
	} 
    } 
    return sum; 
} 

void check_mult_lengths(matrix* m1, matrix* m2) { 
    if(m1 -> ncols != m2 -> nrows) { 
	fprintf(stderr, "m1 ncols and m2 nrows must match.\n"); 
	exit(1); 
    } 
} 

double dot_product(double* a1, double* a2, int len) { 

    int product = 0; 
    for(int i = 0; i < len; ++i)  
	product += a1[i] * a2[i];
    return product;  
} 

struct matrix* matrix_multiply(struct matrix* m1, struct matrix* m2) { 
    check_mult_lengths(m1, m2);
    matrix* p = matrix_new(m1 -> nrows, m2 -> ncols); 
    matrix* trans_m2 = matrix_transpose(m2); 

    for(int i = 0; i < p -> nrows; ++i) { 
	for(int j = 0; j < p -> ncols; ++j) { 
	    p -> m[i][j] = dot_product(m1 -> m[i], 
		    trans_m2 -> m[j], p -> ncols); 
	} 
    } 	
    return p; 
} 

unsigned int htbl_suggested_size(unsigned int expected_num_entries) { 

    //load factor = expected / n buckets 
    //min n buckets = 11 
    //iterate through prime numbers, starting with 11. Call this p 
    //If expected / p <= 0.7, then we good. 
    return 8; 
} 


