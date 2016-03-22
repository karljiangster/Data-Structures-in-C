typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

intlist* intlist_cons(int val, intlist* xs); 

intlist* reverse(intlist* xs);

void rem_dupes(intlist* xs);

void rem_runs(intlist* xs);

void intlist_show(intlist* xs); 

unsigned short* encode(char* s, unsigned int* alen);

char* decode(unsigned short* a, unsigned int alen);

enum optype {
        PLUS, MINUS, TIMES, DIVIDE
};

typedef struct tagged_exptree exptree;

typedef enum optype optype; 
typedef enum nodetype nodetype; 
typedef struct operation operation; 

struct operation {
        enum optype op;
	    exptree *left, *right;
};

union op_or_lit {
        struct operation op;
	    double lit;
};

enum nodetype {
        OP, LIT
};

struct tagged_exptree {
        enum nodetype type;
	    union op_or_lit u;
};

double evaluate(exptree* t);

void exptree_show(exptree* t); 

typedef struct matrix matrix; 

struct matrix {
        unsigned int nrows, ncols;
	    double** m;
};

struct matrix* matrix_new(unsigned int nrows, unsigned int ncols);
/* all values initialized to 0 */
void matrix_show(struct matrix* m);
struct matrix* matrix_transpose(struct matrix* m);
struct matrix* matrix_add(struct matrix* m1, struct matrix* m2);
/* element-wise addition */
struct matrix* matrix_multiply(struct matrix* m1, struct matrix* m2);
/* standard matrix multiplication, not element-wise */

unsigned int htbl_suggested_size(unsigned int expected_num_entries);


