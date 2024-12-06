#ifndef GameSudoku_h
#define GameSudoku_h

struct sudoku{
	int compare;
	int number;
	int mask;
};



void kursorOut(int, int);
void setTextColor(int);
void bannerSudoku(int, int);
int BaseSudoku(int, int);
int sudokuGenerator(struct sudoku**,int,int,int);
void inputToCompare(struct sudoku**, int);
void hideNumbers(struct sudoku**,int, int*, int);
void initPapan (char papan[9][9], struct sudoku**, int);
void printPapan(char papan[9][9], int, int, int);
void play(struct sudoku**, int*, char papan[9][9], int*);
int PauseGame(struct sudoku**, int, int);

#endif
