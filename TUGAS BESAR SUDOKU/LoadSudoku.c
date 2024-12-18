#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "LoadSudoku.h"
#include "GameSudoku.h"
        
int loadSudoku(struct sudoku** table, int m, int salah){
	int i,j;
	FILE* SUDOKU;
	remove("Sudoku.txt");
	SUDOKU = fopen("Sudoku.txt", "w");
	
	fprintf(SUDOKU, "%d", m);
	fprintf(SUDOKU, "%d", salah);
	for (i = 0; i < 9; i++){
		for (j =0; j < 9; j++){
			fprintf(SUDOKU, "%d", table[i][j].number);
		}
	}
	
	for (i = 0; i < 9; i++){
		for (j =0; j < 9; j++){
			fprintf(SUDOKU, "%d", table[i][j].mask);
		}
	}
	fclose(SUDOKU);
	return 0;
}

void loadGameSudoku(struct sudoku** table, int* m, int salah) {
	int i, j, n;
	FILE* SUDOKU;
	SUDOKU = fopen("Sudoku.txt", "r");
	fscanf(SUDOKU, "%1d", &*m);
	fscanf(SUDOKU, "%1d", &n);
	*m = (*m * 10) + n;
	fscanf(SUDOKU, "%1d", &salah);
    for (i = 0; i < 9; i++){
    	for (j = 0; j < 9; j++){
			fscanf(SUDOKU, "%1d", &table[i][j].number);	
		}
    }
    for (i = 0; i < 9; i++){
    	for (j = 0; j < 9; j++){
			fscanf(SUDOKU, "%1d", &table[i][j].mask);
		}
    }
    fclose(SUDOKU);
}


//void* timer( void * arg){
//	int hour = 0, minute = 0, second = 0;
//	printTimer(hour, minute, second);
//	counter(hour, minute, second);
//	return NULL;	
//}

//int printTimer(int h, int m, int s){
//	printf("%d:%d:%d", h, m, s);
//}

//int counter(int h, int m, int s){
//	while(1){
//		if (m > 59){
//			m = 0;
//			h++;
//		}
//		if (s > 59){
//			s = 0;
//			m++;
//		}
//		printTimer(h, m, s);
//		delay(1000);
//		s++;
//	}
//}

//void delay(int ms){
//	clock_t timeDelay = ms + clock();
//	while(timeDelay > clock());
//}
