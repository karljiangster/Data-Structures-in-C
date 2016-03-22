/* Karl Jiang, karljiang  
 * HW5 WIN 2016 
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "hw5.h" 

/* helper function for intlist_remove_n
 * changes pointer of tmp to next next. Frees skipped 
 */ 
void _rmv_intlist(intlist* tmp) { 
    
    intlist* willdie = tmp -> next; 
    tmp -> next = tmp -> next -> next;
    free(willdie);   
} 


/* removes the nth element from the linked list.
 * returns the head pointer for the resulting list
 * if index is beyond the end of the list, raise an error and exit.
 * free the list cell that held the now-removed element
 */  
intlist* intlist_remove_nth(intlist* xs, unsigned int n) { 

    intlist* tmp = xs; 
   
    if(tmp == NULL) { 
	fprintf(stderr, "Out of Bounds."); 
	exit(1);     
    } 
    if(n == 0) { 
	free(xs); 
	return tmp -> next;
    } 	

    int i = 1; //removing the ith element, i == n  
    while(tmp -> next != NULL) { 
	if(i == n) { 
	    _rmv_intlist(tmp); 
	    return xs;    
	} 
	tmp = tmp -> next; 
	i++; 
    }

    //printf("i: %d", i); 
    fprintf(stderr, "Out of Bounds."); 
    exit(1);     
	
    return xs; 

} 


/* in-order traversal. traverses its left subtree, 
 * then prints the node's value, then traverses the right subtree.
 * Seperate by single space
 */ 
void inttree_inorder_show(inttree* t) { 

    if(t == NULL) 
	return; 
    inttree_inorder_show(t -> left); 
    printf("%d ", t -> val); 
    inttree_inorder_show(t -> right); 

} 

/* modifies the tree to aggregate its values upwards. 
 * node's value is updated to be the sum of its original value 
 * and the aggregated values of its subtrees.
 * returns the aggregated value of the root node.
 */ 
int inttree_aggregate(inttree* t) { 
   
    if(t == NULL) 
       return 0; 
    int sum = t -> val; 
    if(t -> left != NULL) { 
	inttree_aggregate(t -> left); 
	sum += t -> left -> val;
    } 	
    if(t -> right != NULL) { 
	inttree_aggregate(t -> right); 
	sum += t -> right -> val; 
    } 
    t -> val = sum;     
    return sum; 
} 

/* modifies the provided tree by updating the value 
 * at each node to be the result obtained by calling 
 * the passed-in function (represented by a function pointer) 
 * on the original value for that node.
 */
void inttree_apply(inttree* t, int (*f)(int)) { 
    
    if(t == NULL) 
	return; 
    t -> val = f(t -> val);
    if(t -> left != NULL)
	inttree_apply(t -> left, f); 
    if(t -> right != NULL)
	inttree_apply(t -> right, f); 	  
    
} 


/* checks if a int a power of 2 */ 
void _is_power_two(int n) { 
    
    int original = n; 
    if(n == 0) { 
	fprintf(stderr, "string cannot be empty. \n");
	exit(1); 	
    } 

    while(n > 1) { 
	if(n % 2) { 
	    fprintf(stderr, "%d must be a power of 2. \n", original); 
	    exit(1); 
	} 
	n = n / 2; 
    } 
}


/* constructs a leaf tree */ 
tree* _tree_leaf_cons(char s) { 

    tree* leaf = (tree*) malloc(sizeof(tree)); 
    leaf -> tag = LEAF; 
    leaf -> u.leaf = s;
    return leaf; 
} 


/* constructs a tagged_tree node.
 * Assumes left and right are NOT null 
 */ 
tree* _tree_node_cons(tree* left, tree* right) { 
    
    tree* tr = (tree*) malloc(sizeof(tree)); 
    tr -> tag = NODE; 
    tr -> u.node.left = left; 
    tr -> u.node.right = right;
    return tr; 
}

/* prints out contents of in order tree. for debugging purposes */ 
void print_tree(tree* t) { 
    
    if(t == NULL) {  
        return; 
    } 
    if(t -> tag == NODE) {
	print_tree(t -> u.node.left);
	print_tree(t -> u.node.right);	
    }   
    else {
	if(t)
	    fprintf(stderr, "|%c|", t -> u.leaf); 
    } 	
} 

/* reconstructs a binary tree based on a string containing the
 * character values of the leafs of this special type of tree,
 * read left-to-right. If string len is not power of 2, err -> exit 
 */
tree* make_tree(char* leafs) { 
   
    if(leafs == NULL) { 
	fprintf(stderr, "no null strings, please."); 
	exit(1); 
    } 	
    int len = strlen(leafs); 

    if(len == 1) { 
	return _tree_leaf_cons(*leafs); 
    }

    _is_power_two(len);  
    
    char left [len / 2 + 1]; 
    memcpy(left, leafs, len / 2); 
    left[len / 2] = '\0';

    tree* left_tr = make_tree(left); 
    tree* right_tr = make_tree(leafs + len / 2);
    return _tree_node_cons(left_tr, right_tr);  
} 


/* tests to see if the tree is valid, that is, 
 * it is not null or is just a lead 
 */ 
void _valid_tree(tree* key) { 

    if(key == NULL) { 
	fprintf(stderr, "Tree is null\n."); 
	exit(1); 
    } 
    if(key -> tag == LEAF) { 
	fprintf(stderr, "Impossible to decode with one letter.\n"); 
	exit(1); 
    } 
} 

/* decodes the specified message, using the provided key. 
 * resulting string should be heap-allocated 
 */ 
char* decode(tree* key, char* cipher) { 

    _valid_tree(key); 
    if(cipher == NULL) 
	return NULL; 
    int i = 0; //to parse thru cipher 
    tree* spot = key; 
    char code [strlen(cipher) + 1];
    int index = 0;
    
    
    while(cipher[i] != '\0') { 	    
	 
	if(cipher[i] == 'L') { 
	    spot = spot -> u.node.left;  
	} 
	if(cipher[i] == 'R') { 
	    spot = spot -> u.node.right; 
	} 

	if(spot -> tag == LEAF) { 
	    code[index] = spot -> u.leaf; 
	    ++index; 
	    spot = key;  
	}
	++i; 	
    }  
    code[index] = '\0';     
    return strdup(code); 
} 

