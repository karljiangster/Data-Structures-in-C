/* Karl Jiang, karljiang  
 * HW5 WIN 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "hw5.h" 

/* helper functions for testing intlist remove nth */ 
intlist* intlist_con(int val, intlist* next) { 

    intlist* rv = malloc(sizeof(rv)); 
    rv -> val = val; 
    rv -> next = next; 
    return rv; 
} 


/* print for checking */ 
void print_intlist(intlist* ll, int len) { 

    intlist* tmp = ll; 

    for(int i = 0; i < len; ++i) { 
	printf("%d ", tmp -> val); 
	tmp = tmp -> next; 
    } 
    puts(" "); 
} 


/* test intlist remove */ 
void evidence_intlist_remove_nth() { 
    
    printf("TESTING INTLIST REMOVE NTH\n\n"); 

    intlist* test = intlist_con(0, NULL); 
    for(int i = 1; i < 4; ++i) { 
	test = intlist_con(i, test); 
    } 
    
    printf("test: "); 
    print_intlist(test, 4); 
    
    
    //zero element 
    intlist* zero = intlist_remove_nth(test, 0); 
    printf("expected: 2 1 0\t|actual: "); 
    print_intlist(zero, 3);
       
    //middle 
    intlist* mid = intlist_remove_nth(zero, 1); 
    printf("expected: 2 0\t|actual: "); 
    print_intlist(mid, 2); 
  
    //end 
    intlist* end = intlist_remove_nth(mid, 1); 
    printf("expected: 2 \t|actual: "); 
    print_intlist(end, 1); 

    /*     
    //outside 
    intlist* outside = intlist_remove_nth(end, 3); 
    print_intlist(outside, 2); //this should NOT run 
      
    //empty case 
    intlist* empty = NULL; 
    intlist* still_empty = intlist_remove_nth(empty, 0);   
    print_intlist(still_empty, 0);
    */ 
    puts(" "); 
} 


/* helper for inttree order show - constructs tree */ 
inttree* inttree_cons(int val, inttree* left, inttree* right) { 

    inttree* tr = (inttree*) malloc(sizeof(inttree)); 
    tr -> val = val; 
    tr -> left = left; 
    tr -> right = right; 
    return tr; 
} 

/* function to be used in testing apply */ 
int increment(int val) { 

    return val + 1; 
} 


/* test for inttree functions
 * case1: NULL, case2: both left and right, case3: left only 
 * case4: right only, case5: leaf 
 */ 
void evidence_inttree() { 

    printf("TESTING INTTREE FUNCTIONS\n\n"); 
    //left hand example from problem description 
    //covers left only, both left an right, leaf
    inttree* one = inttree_cons(1, NULL, NULL); 
    inttree* seven = inttree_cons(7, NULL, NULL); 
    inttree* three = inttree_cons(3, one, seven);  
    inttree* two = inttree_cons(2, NULL, NULL); 
    inttree* left = inttree_cons(1, three, two); 
    inttree* right = inttree_cons(7, NULL, NULL); 
    inttree* tr = inttree_cons(2, left, right); 

    //below tree covers right only 
    inttree* rightnode = inttree_cons(5, NULL, NULL); 
    inttree* righttr = inttree_cons(7, NULL, rightnode); 
    
    printf("expected: 1 3 7 1 2 2 7\nactual: "); 
    inttree_inorder_show(tr); 
    puts(" "); 

    printf("expected: 7 5\nactual: "); 
    inttree_inorder_show(righttr); 
    puts(" "); 

    int aggregate = inttree_aggregate(tr); 
    printf("expected: 23\t|actual:  %d\n", aggregate);
    printf("expected: 1 11 7 14 2 23 7\nactual: "); 
    inttree_inorder_show(tr); 
    puts(" ");  

    int agr_righttr = inttree_aggregate(righttr); 
    printf("expected: 12\t|actual: %d\n", agr_righttr); 
    printf("expected: 12 5\nactual: "); 
    inttree_inorder_show(righttr); 
    puts(" ");

    //test apply 
    inttree_apply(tr, increment); 
    printf("expected: 2 12 8 15 3 24 8\nactual: "); 
    inttree_inorder_show(tr); 
    puts(" "); 

    inttree_apply(righttr, increment); 
    printf("expected: 13 6\nactual: "); 
    inttree_inorder_show(righttr); 
    puts(" "); 

} 


/* evidence for make_tree function */ 
void evidence_make_tree() { 

    printf("\n\nTESTING MAKE TREE\n\n"); 

    //case 0: very simple case 
    char* case0 = "ABC "; 
    tree* simple = make_tree(case0);
    print_tree(simple); 
    puts(" "); 

    //case 1: from example - string works 
    char* case1 = "ABDEIKLSNORTUVY ";
    tree* example = make_tree(case1); 
    print_tree(example); 
    puts(" ");

    //case 1.5: only leaf
    char* single = "A"; 
    tree* tr_single = make_tree(single); 
    print_tree(tr_single); 
    puts(" ");  

    //case 2: rando non power of case
    /* char* case2 = "WONT WORK ";
    tree* nonpower = make_tree(case2); 
    print_tree(nonpower); 
    puts(" "); 
    */  
    
    //case 3: empty. Shouldn't run. 
    /* char* empty_case = ""; 
    tree* empty = make_tree(empty_case);
    print_tree(empty); 
    puts(" "); */ 

    //case 4: NULL 
    /* char* nullstr = NULL; 
    tree* death = make_tree(nullstr); 
    print_tree(death); 
    puts(" "); */  
}   


/* evidence for decode */ 
void evidence_decode() { 
   
    printf("\n\nTESTING DECODE\n\n"); 
    //declare trees  
    char* tree_ex = "ABDEIKLSNORTUVY ";
    tree* example = make_tree(tree_ex);

    char* smpl = "ABC "; 
    tree* simple = make_tree(smpl);
   
      
    //case 0: - using tree from before. Covers chars other than L, R 
    char* message = "LLLR LLRR RRRR LRRR RRLL RLRL LLRR RRRR RLRR RLLR RRRR\
    LLRL RLRL LRLL RLLL LRLR RRRR RRRL RLLR RRLL RLRL RRRR RLLR RRLR LLLL LRRL\
    RLRR LRLL RLLL LLRR";
    char* msg_example = decode(example, message); 
    printf("%s\n", msg_example);

    //case 1: event where we run out of characters, but not at leaf
    char* extra_cypher = "LLL "; 
    char* extra_cyph_code = decode(simple, extra_cypher);
    printf("expected: A\nactual: ");  
    printf("%s\n", extra_cyph_code);  
    
    //case 2: empty string 
    char* empty_string = ""; 
    char* empty_decode = decode(simple, empty_string); 
    printf("expected: \nactual: "); 
    printf("%s\n", empty_decode);     


    //case 3: jank tree - not evenly spread. 
    tree* jank = make_tree("ABC "); 
    jank -> u.node.left -> u.node.left = make_tree("ABC ");
    char* jank_msg = "L L L L | R L|LLRL"; 
    char* jank_code = decode(jank, jank_msg); 
    printf("expected: ACC\nactual: "); 
    printf("%s\n", jank_code);

    //case 4: impossible tree NULL 
    //tree* null = NULL; 
    //char* null_error = decode(null, extra_cypher); 

    //case 5: impossible with only one letter
    /* tree* one = malloc(sizeof(tree));
    one -> tag = LEAF; 
    one -> u.leaf = 'A'; 
    char* one_error = decode(one, extra_cypher);     
    */ 
}  


int main() { 

    evidence_intlist_remove_nth(); 
    evidence_inttree();
    evidence_make_tree();  
    evidence_decode(); 
} 


