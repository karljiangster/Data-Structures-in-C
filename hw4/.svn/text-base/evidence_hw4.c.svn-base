/* Karl Jiang, karljiang
 * CS 152, Winter 2016 
 * HW4
 */ 

#include <stdio.h> 
#include <stdlib.h> 
#include "hw4.h" 

/* function that tests split_at.*/ 
void evidence_split_at() { 

    printf("\nTesting split_at\n");     

    int cases = 4; 	
    int words = 4; 
    char* tests[5] = {"CMSC 154 = hell." , 
		    "Extra  space.  ", 
		    " tricky   lol ",	
		    "  sanders bern <3 "}; 
    char* expt[4][4] = { {"CMSC", "154", "=", "hell"},
			{"Extra", "", "space.", ""}, 
			{"tricky", "", "", "lol"}, 
			{"", "sanders", "bern", "<3",} };  	

    for(int i = 0; i < cases; ++i) {
	printf("expected: "); 	
	for(int j = 0; j < words; ++j) { 
		 printf("{%s}, ", expt[i][j]); 
	} 
	printf("\nactual: ");
	char** split = split_at(tests[i], ' '); 	
	for(int j = 0; j < words; ++j) {
	    printf("{%s}, ", split[j]); 
	}
	printf("\n\n"); 
    } 	
} 


void print_m(measurement m) {
    if ( m.exponent != 1 )
	printf("%.2lf %s^%u\n", m.value, m.units, m.exponent);  
    else 
    	printf("%.2lf %s\n", m.value, m.units);  
}

/* function for testing add_measurements */ 
void evidence_add_measurements() { 
    
    printf("\nTesting add_measurements.\n"); 
    
    measurement m_arr [] = { {1, "uc", 1}, {2, "swag", 4}, {3, "in", 2}, 
	{8, "ft", 3} };
    measurement m_arr_2 [] = { {2, "uc", 1}, {4, "swag", 4}, {2, "in", 3}, 
	{9, "in", 3} };
    char* expt [] = {"3 uc", "6 swag^4", "Error", "Error"}; 

    print_m( add_measurements( new_m(1, "m", 2), new_m(2, "m", 2) ) );
    for(int i = 0; i < 2; ++i) { 
	printf("expected: %s\t|", expt[i]);
	printf("actual: "); 
	print_m( add_measurements( m_arr[i], m_arr_2[i] ) );  
	printf("\n");  
    } 
    
} 


/* fuction to test scale measurements */ 
void evidence_scale_measurement() { 
    
    printf("\nTesting scale measurement.\n"); 
    measurement m_arr [] = { {1, "uc", 1}, {2, "swag", 4}, {3, "in", 2}, 
	{8, "ft", 3} };
    double factors [] = {5.4, 0, -1.3, 10}; 
    
    for(int i = 0; i < 4; ++i) { 
	print_m( scale_measurement( m_arr[i], factors[i] ) ); 
	printf("\n");  
    }  
}


/* function to test mult measurements */ 
void evidence_multiply_measurements() { 
    printf("\nTesting multiply_measurements.\n"); 
    
    measurement m_arr [] = { {1, "uc", 1}, {2, "swag", 4}, {3, "in", 2}, 
	{8, "ft", 3} };
    measurement m_arr_2 [] = { {2, "uc", 1}, {4, "swag", 4}, {2, "in", 3}, 
	{9, "in", 3} };
    char* expt [] = {"2 uc^2", "8 swag^8", "6 in^5", "Error"}; 

    for(int i = 0; i < 3; ++i) { 
	printf("expected: %s\t|", expt[i]);
	printf("actual: "); 
	print_m( multiply_measurements( m_arr[i], m_arr_2[i] ) );  
	printf("\n");  
    }
}


/* function to test measurement tos. */ 
void evidence_measurement_tos() { 
    
    printf("\nTesting measurement tos\n"); 
    
    measurement m_arr [] = { {1, "uc", 1}, {2, "swag", 4}, {3, "in", 2}, 
	{8, "ft", 3} };
    for(int i = 0; i < 4; ++i) { 	
	printf("expected: "); 
	print_m( m_arr[i] ); 
	printf("actual: %s", measurement_tos( m_arr[i] ) ); 
	printf("\n"); 
    } 
}   


/* function to test convert_units */ 
void evidence_convert_units() { 


    printf("\nTesting convert units\n"); 
    
    conversion convs [] = { {"ft", "in", 12}, {"in", "cm", 2.54} }; 
    measurement m_arr [] = { {1, "ft", 1}, {2, "in", 4}, {3, "ft", 2}, 
	{8, "swag", 3} };
    
    char* to_cm = "cm"; 
    char* to_in = "in"; 

    measurement m_c; 
    m_c = convert_units(convs, 2, m_arr[0], to_in);     
    printf("expected: 12.00 in\t|"); 
    printf("actual: %s", measurement_tos(m_c) ) ; 
    
    m_c = convert_units(convs, 2, m_arr[1], to_cm);     
    printf("expected: %.2f cm^4\t|", 83.2462851); 
    printf("actual: %s", measurement_tos(m_c) ) ; 
    
    m_c = convert_units(convs, 2, m_arr[2], to_in);     
    printf("expected: %d in^2\t|", 432); 
    printf("actual: %s", measurement_tos(m_c) ) ; 

    /* 
    * m_c = convert_units(convs, 2, m_arr[3], to_cm);     
    * printf("expected: ERROR\t|"); 
    * printf("actual: %s", measurement_tos(m_c) ) ; 
    */ 
}

/* general function for testing intlists */ 
void evidence_intlist(int_listtag tag) { 
    
    printf("\nTesting intlist\n"); 
    
    //test empty constructors 
    int_list test; 
    if(tag == ARRAY) { 
	printf("Creating ArrayList.\n"); 
	test = int_array_new(); 
    } 
    else {
	printf("Creating Linkedlist.\n"); 
	test = int_linked_new();  

    }
    
    //test int_list_append. All of these actually count as 10 tests 
    printf("expected: ");   
    for(int i = 0; i < 10; ++i) { 
	int_list_append(&test, i); 
	printf("%d ", i); 
    }
    printf("\nactual: "); 
    int_list_show(test);
    puts(""); 

    //test int_list_nth. 
    for (int i = 0; i < 10; i++)
    	if ( int_list_nth(test, i) != i )
    	    fprintf(stderr, "Mismatch at position %d!\n", i);
    
    //test int_list_set 
    for (int i = 0; i < 10; i++) {
    	int val = rand();
    	int_list_set(test, i, val);
    	if ( int_list_nth(test, i) != val )
    	    fprintf(stderr, "Mismatch at position %d!\n", i);
    }
    
    //test free
    int_list_free(test); 

    //test preprend 
    test = tag == ARRAY ? int_array_new() : int_linked_new();
    printf("expected: "); 
    for (int i = 0; i < 10; i++) { 
    	int_list_prepend(&test, i);	
	printf("%d ", 9 - i); 
    } 
    printf("\nactual: "); 
    int_list_show(test);
    puts("");  
    int_list_free(test);
} 


/* function for testing digitlist */ 
void evidence_digit_list() { 
    printf("\nTesting digitlist\n"); 
    
    digitlist* test = _new_dlist(3, NULL); //test constructor 
    _print_digits(test); //test to string 
    _free_digitlist(test); //test free 
    puts(""); 
    
    digitlist* ds1 = _new_dlist(3, NULL);
    printf("expected: 0 ");  
    for(int i = 2; i >= 0; --i) { 
    	ds1 = _new_dlist(i, ds1);
	printf("%d ", 3 - i); 	
    } 	
    printf("\nactual: "); 
    _print_digits(ds1);
    puts("");  
 
    digitlist* ds2 = _new_dlist(3, NULL); 
    for(int i = 2; i >= 0; --i) 
    	ds2 = _new_dlist(i, ds2);
   
    digitlist* ds3 = _new_dlist(6, NULL); 
    for(int i = 5; i >= 4; --i) 
    	ds3 = _new_dlist(i, ds3);
   
    digitlist* sum = add_digits(10, ds1, ds2); 
    printf("expected: 0 2 4 6\nactual: "); 
    _print_digits(sum); 
    puts(""); 
    
    digitlist* sum2 = add_digits(4, ds1, ds2); 
    printf("expected: 0 2 0 3 1\nactual: "); 
    _print_digits(sum2); 
    puts("");
    
    digitlist* sum3 = add_digits(7, ds2, ds3); 
    printf("expected: 4 6 1 4\nactual: "); 
    _print_digits(sum3); 
    puts("");
} 


int main() { 
    evidence_split_at();
     
    evidence_add_measurements(); 
    evidence_scale_measurement(); 
    evidence_multiply_measurements();
    evidence_measurement_tos(); 
    evidence_convert_units();

    evidence_intlist(ARRAY); 
    evidence_intlist(LINKED); 
 
    evidence_digit_list(); 
    return 0; 
} 
