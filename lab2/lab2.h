/* Changes from decimal to hexadecimal. 8 bits -> 2 digits. */
void hex_char(unsigned char byte);  
/* Changes from decimal to hexadecimal. 32 bits -> 8 digits*/
void hex_int(unsigned int n);

/* Changes from decimal to octal. 8 bits -> 3 digits. */
void octal_char(unsigned char byte);  
/* Changes from decimal to octal. 32 bits -> 11 digits */
void octal_int(unsigned int n);

/* Changes from decimal to binary. 8  digits*/
void binary_char(unsigned char byte);  
/* Changes from decimal to binary. 32 digits */
void binary_int(unsigned int n);

