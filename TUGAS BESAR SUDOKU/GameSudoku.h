#ifndef GameSudoku_h
#define GameSudoku_h

struct sudoku{
	int number;
	int mask;
};

int BaseSudoku();
int sudokuGenerator(struct sudoku**,int,int,int);
void showFull(struct sudoku**,int);

#endif
