#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

/* create single bst with vcard */ 
bst *bst_singleton(vcard *c)
{
    bst* single = (bst*) malloc( sizeof(bst) ); 
    single -> c = c; 
    return single; 
}

/* insert vcard into bst */ 
int bst_insert(bst *t, vcard *c)
{
    if(t == NULL) { 
	fprintf(stderr, "Tree is null.\n"); 
	exit(1); 
    } 
    int cmp = strcmp(c -> cnet, t -> c -> cnet); 
    if(cmp == 0) 
	return 0; 
    
    if(cmp < 0) { 
	if(t -> lsub == NULL) { 
	    t -> lsub = bst_singleton(c); 
	    return 1; 
	} 
	return bst_insert(t -> lsub, c); 
    } 

    if(t -> rsub == NULL) { 
	    t -> rsub = bst_singleton(c); 
	    return 1; 
    } 
    
    return bst_insert(t -> rsub, c);     
}

/* returns number of entries in bst t */ 
unsigned int bst_num_entries(bst *t)
{
    int sum = 0; 
    if(t != NULL)  
	sum++; 
    if(t -> lsub != NULL) 
	sum += bst_num_entries(t -> lsub); 
    if(t -> rsub != NULL) 
	sum += bst_num_entries(t -> rsub); 
    return sum; 
}

/* returns height of the bst */ 
unsigned int bst_height(bst *t)
{
    if(t == NULL) 
	return 0; 
    
    unsigned int left_height = 0; 
    unsigned int right_height = 0;  
    
    if(t -> lsub != NULL) 
	left_height = bst_height(t -> lsub); 
    if(t -> rsub != NULL) 
	right_height = bst_height(t -> rsub); 
    
    if(left_height > right_height) 
	return 1 + left_height; 
    return 1 + right_height; 
}


/* Return NULL if nothing is found, else returns said vcard */
vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    if(t == NULL) 
	return NULL; 
    (*n_comparisons)++; 
    int cmp = strcmp(cnet, t -> c -> cnet);

    if(cmp == 0) 
	return t -> c; 
    if(cmp < 0) 	
	return bst_search(t -> lsub, cnet, n_comparisons); 
    
    return bst_search(t -> rsub, cnet, n_comparisons); 
    
}
 

/* shows all the cnets that start with the given char, 
 * in alphabetical order. returns the count of cnets displayed  
 */ 
unsigned int bst_c(FILE *f, bst *t, char c) { 

    if(t == NULL) 
	return 0;

    char* cnet = t -> c -> cnet;  
    int cmp = c - *cnet; 
    if(cmp == 0) { 
	int left = bst_c(f, t -> lsub, c); 
	fprintf(f, "%s\n", cnet); 
	int right = bst_c(f, t -> rsub, c); 
	return 1 + left + right; 		
    } 

    if(cmp > 0)  
	return bst_c(f, t -> rsub, c); 
    return bst_c(f, t -> lsub, c); 
}  


/* Frees the BST */ 
void bst_free(bst *t)
{
    if(t == NULL) //in event null tree passed  
	return; 
    if(t -> lsub != NULL) 
	bst_free(t -> lsub); 
    if(t -> rsub != NULL) 
	bst_free(t -> rsub); 
    vcard_free(t -> c); 
    free(t); 

}
