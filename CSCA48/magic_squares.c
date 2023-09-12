////////////////////////////////////////////////
// CSC A48 - Winter 2022
//
// Exercise 5 - Solving Magic Squares
//
// (c) 2022 F. Estrada
////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

int magique(int square[6][6]){
	int magic_num = 0;
	int not_unknown = 0;
	for (int row = 0; row < 6; row = row + 1){
		not_unknown = 0;
		magic_num = 0; 
		for (int col = 0; col < 6; col = col + 1){
			if (square[row][col] != -1){
				not_unknown = not_unknown + 1;
				magic_num = magic_num + square[row][col];
			}
		}
		if (not_unknown == 6){
			return magic_num;
		}
	}
	return 0;
}

int calc_total(int square[6][6]){
	int total = 0;
	for (int row = 0; row <= 5; row = row + 1){
		for (int col = 0; col <= 5; col = col + 1){
			if (square[row][col] == -1){
				total = total + 1;
			}
		}
	}
	return total;
}

int row_calc(int square[6][6], int row, int col){
	for (int lum = 0; lum < col; lum = lum + 1){
		if (square[row][lum] == -1){
			return 1;
		}
	}
	for (int lum = col + 1; lum <= 5; lum = lum + 1){
		if (square[row][lum] == -1){
			return 1;
		}
	}
	int row_total = 0;
	for (int lum = 0; lum < 6; ++lum){
		row_total = row_total + square[row][lum];
	}
	row_total = row_total + 1;
	return row_total;
}	

int col_calc(int square[6][6], int col, int row){
	for (int wor = 0; wor < row; ++wor){
		if (square[wor][col] == -1){
			return 1;
		}
	}
	for (int wor = row + 1; wor <= 5; ++wor){
		if (square[wor][col] == -1){
			return 1;
		}
	}
	int col_total = 0;
	for (int wor = 0; wor < 6; ++wor){
		col_total = col_total + square[wor][col];
	}
	col_total = col_total + 1;
	return col_total;
}	

void solveMagicSquare(int square[6][6]){
	int magic_num = magique(square);
	//printf("%d\n", magic_num);
	
	int total = calc_total(square);
	//printf("%d\n", total);
	
	while (total != 0){
		for (int row = 0; row <= 5; row = row + 1){
			for (int col = 0; col < 6; col = col + 1){
				if (square[row][col] == -1){
					int calc_by_row = row_calc(square, row, col);
					//printf("%d\n", calc_by_row);
					
					int calc_by_col = col_calc(square, col, row);
					//printf("%d\n", calc_by_col);
					
					if (calc_by_row != 1){
						square[row][col] = magic_num - calc_by_row;
						total = total - 1;
					}
					else if (calc_by_col != 1){
						square[row][col] = magic_num - calc_by_col;
						total = total - 1; 
					}
				}
			}
		}
	}
}
					
 // This function receives an array of size 6x6
 // that corresponds to a magic square.
 // It then finds any entries with value -1
 // (which means they are not known),
 // and figures out what their value should
 // be to solve the magic square.
 //
 // Conditions:
 // You can not hard-code the value of the rows
 // and columns in the magic square - because
 // we will test this with a *different* magic
 // square than the one in this starter code
 //
 // Your function has to (somehow) figure out
 // what the sum of the rows and columns should be,
 // and then figure out for each entry whose
 // value is -1, what its value is to correctly
 // complete the magic square.
 //
 // This is about problem solving - you don't
 // need any fancy pointer management or anything
 // like that. Just plain old C with a 2D array
 // and a bit of thinking.
 //
 // As a reminder. 2D arrays in C are indexed as
 // array[i][j] - gives you the element at row i,
 // column j

 //////////////////////////////////////
 // TO DO: Complete this function
 //////////////////////////////////////


// DO NOT MODIFY ANYTHING BELOW THIS LINE!
// (we mean it! the auto-checker won't be happy)
void printMagicSquare(int square[6][6])
{
   // Prints out the contents of a magic square 6x6

   int i,j,sum;

   for (i=0; i<6; i++)
   {
       sum=0;
       for (j=0; j<6; j++)
       {
           printf("%03d, ",square[i][j]);
           sum=sum+square[i][j];
       }
       printf(" : %03d\n",sum);
   }

   printf("---------------------------\n");

   for (j=0; j<6; j++)
   {
       sum=0;
       for (i=0; i<6; i++)
       {
	   sum=sum+square[i][j];
       }
       printf("%03d, ",sum);
   }
   printf("\n");
}

#ifndef __testing   // This is a compiler directive - used by the auto-checker to enable/disable this part of the code
int main()
{
    int magic[6][6]={{32,29,4,1,24,21},{30,-1,2,3,-1,23},{12,9,17,20,28,25},{10,11,18,-1,26,27},{13,-1,36,33,5,8},{14,15,34,35,6,-1}};

    printMagicSquare(magic);
    printf("Solving Magic Square!\n");
    solveMagicSquare(magic);
    printMagicSquare(magic);

    return 0;
}
#endif
