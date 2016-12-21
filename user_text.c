/**
 *
 *  Wrapper function declarations
 *
 **/
void lc4_putc(char c) ;	/* calls TRAP_PUTC, passing character to write to ASCII display  */

/**
 *
 *  Simple C program to write an char array out to ASCII display
 *
 */
 
 void lc4_puts(char arr[])	;	/*calls TRAP_PUTS */
 /**
 *program to print a string to the screen in the LC4
 *
 */
 
 char lc4_getc()	;	/* calls TRAP_GETC */
 
int main()
{

	/* declare variables at top of functions in C */

	int  i = 0 ; //Initialize i to 0
  	char string1 [] = {'S', 't', 'a', 'r', 't', ' ', 'T', 'y', 'p', 'i', 'n', 'g', '>', ' ', '\0'} ;
	char a ;
	/* output string1 array to LC4 ASCII display using lc4_putc() trap wrapper */

    //while (string1[i] != '\0') {
	//	lc4_putc (string1[i]) ;
	//	i++ ;
	//}

	/* CIT 593 TO-DO: replace loop above with a call to lc4_puts() */
	
	
	lc4_puts(string1) ; /* call puts on String1*/
	
	/* CIT 593 TO-DO: echo characters from keyboard */
	a = lc4_getc(); 	/*set a to getc return char*/
	while (a != '\n'){	/*While loop to keep getting and printing a char unitl new line char is entered */
		lc4_putc(a);
		a = lc4_getc();
	}
	
	

	return 0 ;
}
