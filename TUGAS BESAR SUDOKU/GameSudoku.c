#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include "GameSudoku.h"

int BaseSudoku(){
	while(1) {
		srand(time(NULL));
	    int i, j, m;
	    int n = 3;
	    struct sudoku** table;
	    int size = n * n;
	    // 1.3. Get n, m 
      
      table = (struct sudoku**)malloc(size * sizeof(struct sudoku*));
      for(i = 0; i < size; i++)
        table[i] = (struct sudoku*)malloc(size * sizeof(struct sudoku));

      printf("\n---------- 2: RANDOM A SUDOKU TABLE ------------------\n\n");
      printf("Full Sudoku table[%d][%d]: \n", size, size);
	    sudokuGenerator(table, n, 0, 0);
	    showFull(table, n);
		return 0;
	}
}

int sudokuGenerator(struct sudoku** table, int n, int x, int y){
// 1. Delcare some vars
	int i, j; // loop indexes.
	int size = n*n; // sudoku width.
	
	// 2. Mask Array
	int* maskArray = (int*)malloc(size*sizeof(int*));
	// Mark 1 as the POSIBLE value.
	for (i = 0; i < size; i++) maskArray[i] = 1;
    
	// 3. Find and mark 0 as IMPOSIBLE values.
    for (i = 0; i < y; i++) maskArray[table[x][i].number - 1] = 0;
    for (i = 0; i < x; i++) maskArray[table[i][y].number - 1] = 0;
    for (i = (n * (int)(x/n)); i < (n * (int)(x/n) + n); i++)
        for (j = (n * (int)(y/n)); j < y; j++)
            maskArray[table[i][j].number - 1] = 0;
    
	// 4. Group all possible values into a new array
    // 4.1. Declare and allocate a new array
    int k = 0;
    for (i = 0; i < size; i++) k += maskArray[i]; // ount
    int* randArray;
    randArray = (int*)malloc(k * sizeof(int*));
    // 4.2. Assign those values into this array.
    j = 0; // reset j for a new loop
    for (i = 0; i < size; i++) {
        if (maskArray[i] == 1) { // Neu the position i is a possible value
            randArray[j] = i + 1; // Do assign
            j++; // go to the next position
        } else continue;
    }
    
	// 5. Compute the next cell position.
    int newX, newY;
    if (x == size-1) {
        newY = y + 1;
        newX = 0;
    } else {
        newY = y;
        newX = x + 1;
    }	
	
	// 6. Take random possible values into current cell.
    while (k > 0) { // And try all of them.
        int index = rand() % k; 
        table[x][y].number = randArray[index];
        for (i = index; i < (k-1); i++) randArray[i] = randArray[i+1];
        k--;
		
		// Stop if at the last cell.
		if ((x == size-1) && (y == size-1)) {
        free(randArray); free(maskArray);
        return 1; 
    }
        
    // Or go to the next cell
    if (sudokuGenerator(table, n, newX, newY)) {
       free(randArray); free(maskArray);
       return 1;
    }
    }
    
	// 7. Release memory.
    free(randArray); free(maskArray);
    return 0;
}

void showFull(struct sudoku** table, int n) {
	int size = n * n;
    int i, j;
    char format[5];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
        	if (size > 10 && table[i][j].number < 10) strcpy(format, "0%d ");
        	else strcpy(format, "%d ");
	        printf(format, table[i][j].number);
	        if ((j+1)%n == 0) printf(" ");
	        Sleep(10);
        }
        if ((i+1) % n == 0) printf("\n");
        printf("\n");
    }
}
