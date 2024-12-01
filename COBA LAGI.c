#include <stdio.h>
#include <windows.h>

//Program Mencetak Papan Sudoku
void kursorOut (int x, int y);
void initPapan (char papan[9][9]);
void printPapan(char sudoku[9][9]);

void kursorOut(int x, int y) {
    COORD p;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(hOut, p);
}

void initPapan(char papan[9][9]) {
	int i,j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            papan[i][j] = '3';
        }
    }
}

void printPapan(char sudoku[9][9])
{
	int i;
    // Baris horizontal atas
    kursorOut(54, 6);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
           218, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 
           196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194,
           196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 191);

    // Nomor kolom dan baris sel dengan kontennya
    for(i = 0; i < 9; i++) {
        // Baris untuk nomor
        kursorOut(54, 7 + i * 4);
        printf("%c%2d   %c%2d   %c%2d   %c%2d   %c%2d   %c%2d   %c%2d   %c%2d   %c%2d   %c", 
               179, i*9+1, 179, i*9+2, 179, i*9+3, 179, i*9+4, 179, i*9+5, 179, i*9+6, 179, i*9+7, 179, i*9+8, 179, i*9+9, 179);
        
        // Baris untuk konten
        kursorOut(54, 8 + i * 4);
        printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 
               179, sudoku[i][0], 179, sudoku[i][1], 179, sudoku[i][2], 179, sudoku[i][3], 179, 
               sudoku[i][4], 179, sudoku[i][5], 179, sudoku[i][6], 179, sudoku[i][7], 179, sudoku[i][8], 179);
        
        // Baris kosong
        kursorOut(54, 9 + i * 4);
        printf("%c     %c     %c     %c     %c     %c     %c     %c     %c     %c", 
               179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
        
        // Garis horizontal pembatas (kecuali baris terakhir)
        if(i < 8) {
            kursorOut(54, 10 + i * 4);
            printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
                   195, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197,
                   196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197,
                   196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 180);
        }
    }

    // Garis horizontal bawah
    kursorOut(54, 42);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
           192, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193,
           196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193,
           196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 217);
    
}

int main()	
{
    char tabel[9][9];
    initPapan(tabel);  
    system("cls");     
    printPapan(tabel);
    printf("\n\n");
    return 0;
}
