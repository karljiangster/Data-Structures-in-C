#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bucket.h"

/* bucket: linked list of hash table entries */

/*
typedef struct bucket bucket;
struct bucket {
  char *s;
  unsigned long int hash; 
  // store the hash with the string for faster comparison 
  bucket *next;
};
*/

/* bucket_cons : (char*,unsigned long,bucket*) -> bucket* 
 * Given a string, a hash function, and a bucket, insert
 * the string into the bucket.
 * Copy the string with strdup so as to get a new copy.
 */
bucket *bucket_cons(char *s, unsigned long h, bucket *b)
{
    bucket* cons = (bucket*) malloc(sizeof(bucket)); 
    cons -> s = strdup(s); 
    cons -> hash = h; 
    cons -> next = b; 
    return cons; 
}

/* bucket_num_entries : bucket* -> unsigned int */
unsigned int bucket_num_entries(bucket *b)
{
    unsigned int count = 0; 
    for(bucket* tmp = b; tmp != NULL; tmp = tmp -> next) 
	count++;
    return count; 	
}

/* bucket_contains : (char*,unsigned long int,bucket*) -> int
 * Look for string in bucket.
 * - note: check first that hashes are equal, and only then call
 *   strcmp; strcmp is relatively expensive, so this is a savings
 */
int bucket_contains(char *s, unsigned long int h, bucket *b)
{
    for(bucket* tmp = b; tmp != NULL; tmp = tmp -> next) { 
	if(tmp -> hash == h) { 
	    if(strcmp(tmp -> s, s) == 0)
		return 1; 	
	} 
    } 
    return 0; 
}

/* bucket_show : (FILE*,bucket*) -> <void> 
 * Display bucket to FILE *f.
 * You may display it in any format you like (within reason).
 */
void bucket_show(FILE *f, bucket *b)
{
    for(bucket* tmp = b; tmp != NULL; tmp = tmp -> next) 
	fprintf(f, "%s|", tmp -> s); 
}

/* bucket_free : bucket* -> <void> */
void bucket_free(bucket *b)
{
    bucket* tmp = b; 
    while(tmp) { 	
	bucket* willdie = tmp;
	tmp = tmp -> next; 	
	free(willdie -> s); 
	free(willdie);
    } 
}
