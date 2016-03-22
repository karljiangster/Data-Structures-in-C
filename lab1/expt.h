/* Karl Jiang, karljiang
 * CS 152, Winter 2016
 * Lab 1
 * expt.h 
 */
 
/* expt : linear time recursive exponentiation */
long int expt(int a, unsigned int n);

/* ss : exponentiation by successive squaring */
long int ss(int a, unsigned int n);

/* ssm : exponentiation modulo m by successive squaring */
int ssm(int a, unsigned int n, unsigned int m);
