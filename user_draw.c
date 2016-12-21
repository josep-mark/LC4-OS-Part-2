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
 
 void lc4_draw_box(int x_coord, int y_coord, int len, int * colors)	; /*calls TRAP_DRAW_BOX*/
 
 /*Set 2D array for boxes as global variables*/
 int box1[50][50];
 int box2 [20][20];
 int box3 [30][30];
 
int main()
{

	/*Initialize variables for the three boxes parameters: x, y, length, and a pointer to the box color 2d arrays*/

	int x1 = 50;
	int y1 = 5;
	int len1 = 50;
	int * box1_ptr = &box1[0][0];
	
	int x2 = -10;
	int y2 = -10;
	int len2 = 20;
	int * box2_ptr = &box2[0][0];
	
	
	int x3 = 110;
	int y3 = 100;
	int len3 = 30;
	int * box3_ptr = &box3[0][0];
	
	/*Initialize counter variables and color variables to fill the 2D arrays with*/
	
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int p = 0;
	int box_color1 = 992; //green
	int box_color2 = 31744; //red
	int box_color3 = 32736; //yellow
	
	/*Fill box_color1 values with green*/
	for (i = 0; i < 50; i++){
		for (j = 0; j < 50; j++){
			box1[i][j] = box_color1;
		}
	}
	
	/*Fill box_color2 values with red*/
	for (k = 0; k < 20; k++){
		for (l = 0; l < 20; l++){
			box2[k][l] = box_color2;
		}
	}
	
	/*Fill box_color3 values with yellow*/
	for (m = 0; m < 30; m++){
		for (p = 0; p < 30; p++){
			box3[m][p] = box_color3;
		}
	}
	
	/*Call draw box function for our three boxes*/
	lc4_draw_box(x1, y1, len1, box1_ptr)	;
	lc4_draw_box(x2, y2, len2, box2_ptr)	;
	lc4_draw_box(x3, y3, len3, box3_ptr)	;

	return 0 ;
}
