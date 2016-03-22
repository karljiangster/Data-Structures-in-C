#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_vcard_todo_format = "TODO [vcard]: %s\nhalting\n";

/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string 
 *   arguments are not to be shared by the newly allocated vcard
 */
vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
    vcard* new = malloc(sizeof(vcard)); 
    new -> cnet = strdup(cnet);
    new -> email = strdup(email); 
    new -> fname = strdup(fname); 
    new -> lname = strdup(fname); 
    new -> tel = strdup(tel); 
    return new;  
}

/* vcard_free : free vcard and the strings it points to */
void vcard_free(vcard *c)
{
    free(c -> cnet); 
    free(c -> email); 
    free(c -> fname); 
    free(c -> lname); 
    free(c -> tel); 
    free(c); 
}


/* prints contents to file f */ 
void vcard_show(FILE *f, vcard *c)
{
    fprintf(f, "cnet: %s\nemail: %s\nfname: %s\nlname: %s\ntel: %s\n",
	    c -> cnet, c -> email, c -> fname, c -> lname, c -> tel); 
}
