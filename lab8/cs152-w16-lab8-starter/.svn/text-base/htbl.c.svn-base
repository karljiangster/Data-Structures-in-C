#include "bucket.h"
#include "htbl.h"

/* hash table of strings, with linked list buckets */

/*
struct hash_table {
  unsigned long int(*hash)(char *);
  bucket **buckets;
  unsigned int n_buckets;
};
typedef struct hash_table htbl;
*/

/* good_hash : char -> unsigned int
 * compute hash code for given string
 * - see description of exercise for algorithm 
 */
unsigned long int good_hash(char *s)
{
    unsigned long res = 17; 
    char* cur = s; 
    while(*cur != '\0') { 
	res = 37 * res + (int)(*s); 
	cur++; 
    } 
    return res; 
}

/* bad_hash : char -> unsigned int
 * implement this however you like, as long as it's bad 
 */
unsigned long int bad_hash(char *s)
{
    return 34 * (int)(*s) % 60; 
}

/* htbl_new : ((string -> unsigned long),int) -> htbl*
 * allocate space for a new hash table of given size
 * - all buckets must initially be the empty list 
 */
htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl* new = malloc(sizeof(htbl)); 
    new -> hash = h; 
    bucket** buckets = malloc(sizeof(bucket*) * sz);
    for(int i = 0; i < sz; ++i) 
	buckets[i] = NULL; 
    new -> n_buckets = sz;   
    new -> buckets = buckets; 
    return new; 
}

/* htbl_num_entries : htbl* -> unsigned int
 * return the total number of entries in all buckets 
 */
unsigned int htbl_num_entries(htbl *t)
{
    unsigned int count = 0; 
    for(int i = 0; i < (t -> n_buckets); ++i) { 
	count += bucket_num_entries( t -> buckets[i] );  
    } 
    return count; 
}

/* htbl_load_factor : htbl* -> float
 * The load factor is the mean number of elements per bucket. 
 */
double htbl_load_factor(htbl *t)
{
    double total =  htbl_num_entries(t); 
    double divisor = t -> n_buckets;  
    return total / divisor; 
}

/* htbl_max_bucket : (htbl*, unsigned int*, int*) -> <void>
 * Return, via out parameters, the max number of items in any
 * bucket, and the index of that bucket.
 * - If there is more than one bucket with that number of
 *   items, you may return any of those bucket indexes.
 */
void htbl_max_bucket(htbl *t, unsigned int *m, unsigned int *i)
{
    *m = 0, *i = 0; 
    for(int j = 0; j < (t -> n_buckets); ++j) {
	int num_entries = bucket_num_entries( t -> buckets[j] ); 
	if( num_entries > *m) {
	    *m = num_entries; 
    	    *i = j; 
	} 
    } 
}

/* htbl_ins : (char*, htbl*, unsigned int*) -> int
 * add string s to hash table t 
 * - no special treatment for duplicates, just insert them again
 * - return, via out parameter n, the number of strings in s's bucket 
 *   after inserting s
 */
void htbl_ins(char *s, htbl *t, unsigned int *n)
{
    unsigned long int hash_val = t -> hash(s); 
    int index = hash_val % t -> n_buckets;  
    t -> buckets[index] = bucket_cons(s, hash_val, t -> buckets[index] ); 
    *n = bucket_num_entries(t -> buckets[index]);
}

/* htbl_member : (char*, htbl*) -> int
 * test membership of given string in given table 
 */
int htbl_member(char *s, htbl *t)
{
    unsigned long int hash_val = t -> hash(s); 
    int index = hash_val % (t -> n_buckets); 
   
    return bucket_contains(s, hash_val, t -> buckets[index] );  
}

/* htbl_show : (FILE*, htbl*) -> <void>
 * Print a representation of the hash table to f.
 * See exercise description for details.
 */
void htbl_show(FILE *f, htbl *t)
{
    fprintf(f, "~~~HASH TABLE~~~\n"); 
    for(int i = 0; i < t -> n_buckets; ++i) { 
	fprintf(f, "Bucket %u) \t|", i); 
	bucket_show( f, t -> buckets[i] ); 
	puts(" "); 
    } 	
}

/* htbl_free : htbl* -> <void>
 * Be sure to free everything. Drawing a picture may help.
 */
void htbl_free(htbl *t)
{
    for(int i = 0; i < t -> n_buckets; ++i) { 
	bucket_free( t -> buckets[i] ); 
    } 
    free(t); 
}
