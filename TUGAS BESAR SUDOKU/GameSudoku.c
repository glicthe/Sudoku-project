#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void kondisiAwalSudoku(){
	int k = 0, i = 0, j = 0;
	int sudokuArr[81];			 
	int grid[81];
	
	for (i = 1; i <= 9; i++){
		sudokuArr[i] = i;
	}
	
	//membuat sudokunya dimana setiap 3*3 berisikan 1-9
	for (i = 0; i <= 81; i++){
		 int perBox = ((i / 3) % 3) * 9 + ((i % 27) / 9) * 3 + (i / 27) * 27 + (i %3);
		 grid[perBox] = sudokuArr[i%9];	 
		 if (grid[perBox] == 0) grid[perBox] = 9;
	}
	
	for (i = 0; i < 81; i++){		
		printf("%d ", grid[i]);
		if (i % 9 == 8 ){
			printf("\n");
		}
	}
}	

