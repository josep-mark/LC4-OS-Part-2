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
 
 void lc4_draw_box(int x_coord, int y_coord, int len, int * colors_ptr)	; //Call TRAP_DRAW_BOX
 
 /*Initialize two 2D arrays 10x10 for the box color values*/
 int box1[10][10];
 int black_box[10][10];
 
 

 
int main()
{

	/* declare variables at top of functions in C */
	/*Create the string to print to the console*/
  	char string1 [] = {'C', 'I', 'T', ' ', '5', '9', '3', ' ', 'G', 'r', 'a', 'p', 'h', 'i', 'c', 's', '\n', '<', 'j', '>', 'L', 'T', ',', '<', 'l', '>', 'R', 'T', ',', '<', 'i', '>', 'U', 'P', ',', '<', 'k', '>', 'D', 'N', ',', '\0'} ;
	char a ; //initialize a
	/* output string1 array to LC4 ASCII display using lc4_putc() trap wrapper */
	
	/*create initial box parameters*/
    int x1 = 59; //center screen is around 59
	int y1 = 59;
	int len1 = 10;
	int * box1_ptr = &box1[0][0]; 	//pointer to colored box
	int * black_box_ptr = &black_box[0][0]; //pointer to black box
	int color_main = 32736;	//yellow
	int color_black = 0; //black
	
	/*counter variables*/
	
	int i = 0; 
	int j = 0;
	int k = 0;
	int l = 0;
	
	/*Fill color for the main box*/
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			box1[i][j] = color_main;
		}
	}
	
	
	/*Fill black for the black box*/
	for (k = 0; k < 10; k++){
		for (l = 0; l < 10; l++){
			black_box[k][l] = color_black;
		}
	}

	/*Draw initial yellow box in center screen*/
	lc4_draw_box(x1, y1, len1, box1_ptr)	;
	
	/*Print string to console*/
	lc4_puts(string1) ;

	
	
	
	
	do {
		a = lc4_getc(); //get char from user
		if (a == 'j'){				//if char is j
			if ( x1 > 5){			//Check if x is in bounds of the display
				lc4_draw_box(x1, y1, len1, black_box_ptr)	; //draw black box
				x1 = x1 - 5;										//x1 = x - 1
				lc4_draw_box(x1, y1, len1, box1_ptr)	;		//draw new box in adjusted position (left one pixel)
			}
		}
		else if(a == 'l'){		//if char is l
			if(x1 < 112){		//Check if x is in bounds of the display
				lc4_draw_box(x1, y1, len1, black_box_ptr)	;	//black out box		
				x1  = x1 + 5;											//x + 1 move right
				lc4_draw_box(x1, y1, len1, box1_ptr)	;		//draw new box one pixel right
			}
		}
		else if (a == 'i'){			//if char is i
			if (y1 > 5){			//Check if y is in bounds of the display
				lc4_draw_box(x1, y1, len1, black_box_ptr)	;	//black out box
				y1 = y1 - 5;									//y -1 move up
				lc4_draw_box(x1, y1, len1, box1_ptr)	;		//draw new box 1 pixel up
			}
		}
		else if(a == 'k'){			//if char is k
			if (y1 < 114){			//Check if y is in bounds of the display
				lc4_draw_box(x1, y1, len1, black_box_ptr)	;	//black out box
				y1 = y1 + 5;											//y + 1
				lc4_draw_box(x1, y1, len1, box1_ptr)	;		//draw new box down one pixel
			}
		}
		else if (a == 'c'){			//if char is c
			//newbox
			color_main = color_main + 16; //change color of box
			//color_box(color_main, len1, box1_ptr);
			i = 0;					//reset i and j to 0
			j = 0;
			for (i = 0; i < 10; i++){			//fill color of main box to new color
				for (j = 0; j < 10; j++){
				box1[i][j] = color_main;
				}
			}
			lc4_draw_box(x1, y1, len1, box1_ptr)	;	//redraw box using the new color
		}
		else {
			a = lc4_getc();			//if no char hits keep running
		}	
	}
	while (a != '\n');				//if new line break from loop and end program
	


	

	return 0 ;
}
