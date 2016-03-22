#include <stdio.h> 
#include <stdlib.h> 
#include "final.h" 
#include <string.h> 

intlist* make_intlist(int size) { 

    intlist* test = intlist_cons(0, NULL);
    for(int i = 1; i < size; ++i) { 
	test = intlist_cons(i, test); 
    }
    return test;  
} 

intlist* make_dups(int size, int interval, int start_val) { 

    int dup_count = 1; 
    int cur_val = 0; 
    intlist* test = intlist_cons(start_val, NULL); 
    
    for(int i = 0; i < size; ++i) { 
	if(dup_count >= interval) { 
	    cur_val++; 
	    dup_count = 0; 
	}
	test = intlist_cons(cur_val, test); 
	dup_count++; 
    } 
    return test; 
} 


void evidence_reverse() { 

    intlist* test = make_intlist(10); 
    intlist_show(test);
    intlist* reversed = reverse(test);  
    intlist_show(reversed);

    intlist* snub = NULL; 
    intlist* snub_rev = reverse(snub); 
    intlist_show(snub_rev);  
   
} 

void evidence_rem_dupes() { 

    intlist* test = make_dups(9, 4, 0); 
    intlist_show(test); 
    rem_dupes(test); 
    intlist_show(test);

    intlist* no_dups = make_intlist(10); 
    rem_dupes(no_dups); 
    intlist_show(no_dups); 
}

void evidence_rem_runs() { 

    intlist* dups = make_dups(10, 3, 0); 
    intlist_show(dups); 
    rem_runs(dups); 
    intlist_show(dups); 
} 


void show_code(unsigned short* code, unsigned int alen) { 

    printf("code: [ "); 
    for(int i = 0; i < alen; ++i) { 
	printf("%hu , ", code[i] ); 
    } 
    printf(" }\n"); 
} 

void evidence_code() { 

    printf("CODE\n\n"); 
    unsigned short a[] = {20960, 2208, 15936, 14836, 655, 69, 648, 1664, 9824,
	                      20741, 565, 5748, 9710, 27648};
    unsigned int alen = 14;

    char* decoded = decode(a, alen); 
    printf("%s\n", decoded);
    unsigned int tobe = strlen(decoded);  
    unsigned short* encoded = encode(decoded, &tobe ); 
    show_code(encoded, tobe); 
    
    char* decoded_again = decode(encoded, alen); 
    printf("%s\n", decoded_again); 
    /* 
    char* simple = "test"; 
    unsigned int simple_alen = 0;  
    unsigned short* simple_code = encode(simple, &simple_alen); 
    show_code(simple_code, simple_alen); */ 
    
} 
 

exptree* cons_op(exptree* left, exptree* right, optype operator) { 

    exptree* tree = (exptree*) malloc(sizeof(exptree)); 
    tree -> type = OP; 
    tree -> u.op.op = operator; 
    tree -> u.op.left = left; 
    tree -> u.op.right = right; 
    return tree; 


} 

exptree* cons_lit(double literal) { 

    exptree* tree = (exptree*) malloc(sizeof(exptree)); 
    tree -> type = LIT; 
    tree -> u.lit = literal; 
    return tree; 
} 

exptree* make_example() { 
    
    exptree* four = cons_lit(4); 
    exptree* two = cons_lit(2); 
    exptree* minus = cons_op(four, two, MINUS); 

    exptree* three = cons_lit(3); 
    exptree* times = cons_op(minus, three, TIMES); 

    exptree* one = cons_lit(1); 
    exptree* plus = cons_op(times, one, PLUS); 

    return plus; 
} 

void evidence_eval() { 
    
    exptree* ex_tree = make_example(); 
    exptree_show(ex_tree);
    puts(" ");  

    printf("result: %f\n", evaluate(ex_tree) ); 

    exptree* easy = cons_lit(4); 
    exptree_show(easy); 
}

void evidence_matrix() { 

    printf("\nMATRIX TIME\n\n");  
    matrix* m = matrix_new(2, 4); 
    matrix_show(m); 
    puts(" "); 

    matrix* m_trans = matrix_transpose(m); 
    matrix_show(m_trans); 
    puts(" ");

    matrix* sum = matrix_add(m, m); 
    matrix_show(sum);
    puts(" ");   

    matrix* trans_sum = matrix_transpose(sum); 
    matrix* product = matrix_multiply(sum, trans_sum); 
    matrix_show(product); 
    puts(" ");  
} 

int main() { 

    evidence_reverse();
    evidence_rem_dupes();  
//  evidence_rem_runs(); 
    evidence_eval();
    evidence_matrix();  
    evidence_code(); 
    return 0; 
} 
