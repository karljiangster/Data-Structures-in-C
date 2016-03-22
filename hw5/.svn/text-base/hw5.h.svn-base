#ifndef __HW5_H__ 
#define __HW5_H__

typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};


/* removes the nth element from the linked list.
 * returns the head pointer for the resulting list
 * if index is beyond the end of the list, raise an error and exit.
 * free the list cell that held the now-removed element
 */  
intlist* intlist_remove_nth(intlist* xs, unsigned int n);

typedef struct inttree inttree;

struct inttree {
    int val;
    inttree *left, *right;
};


/* in-order traversal. traverses its left subtree, 
 * then prints the node's value, then traverses the right subtree.
 * Seperate by single space
 */ 
void inttree_inorder_show(inttree* t);

/* modifies the tree to aggregate its values upwards. 
 * node's value is updated to be the sum of its original value 
 * and the aggregated values of its subtrees.
 * returns the aggregated value of the root node.
 */ 
int inttree_aggregate(inttree* t);


/* modifies the provided tree by updating the value 
 * at each node to be the result obtained by calling 
 * the passed-in function (represented by a function pointer) 
 * on the original value for that node.
 */
void inttree_apply(inttree* t, int (*f)(int));

typedef struct tagged_tree tree;

struct node {
    tree *left, *right;
};

union tree_union {
    struct node node;
    char leaf;
};

typedef enum tree_tag tree_tag; 

enum tree_tag {
    NODE, LEAF
};

struct tagged_tree {
    enum tree_tag tag;
    union tree_union u;
};

/* prints out contents of in order tree. for debugging purposes */ 
void print_tree(tree* t); 

/* reconstructs a binary tree based on a string containing the
 * character values of the leafs of this special type of tree,
 * read left-to-right. If string len is not power of 2, err -> exit */ 
tree* make_tree(char* leafs);

/* decodes the specified message, using the provided key. 
 * resulting string should be heap-allocated 
 */ 
char* decode(tree* key, char* cipher);

#endif /* __HW5_H__ */ 
