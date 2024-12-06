#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include "GameSudoku.h"
#include "LoadSudoku.h"

void bannerSudoku(int x, int y) {
	
    //Mencetak S besar
    setTextColor(12);
    kursorOut(x, y);
    printf(" %c%c%c%c", 178, 178, 178, 178);
    kursorOut(x, y+1);
    printf("%c%c", 178, 178);
    kursorOut(x, y+2);
    printf("%c%c%c%c%c", 178, 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+4, y+3);
    printf("%c%c", 178, 178);
    kursorOut(x, y+4);
    printf("%c%c%c%c%c", 178, 178, 178, 178, 178);

    //Mencetak U besar
    setTextColor(12);
    kursorOut(x+12, y);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+12, y+1);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+12, y+2);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+12, y+3);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+12, y+4);
    printf("%c%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178, 178);

    //Mencetak D besar
    setTextColor(12);
    kursorOut(x+24, y);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);
    kursorOut(x+24, y+1);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+24, y+2);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+24, y+3);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+24, y+4);
    printf("%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178);

    //Mencetak O besar
    setTextColor(12);
    kursorOut(x+36, y);
    printf("%c%c%c%c%c", 178, 178, 178, 178, 178);
    kursorOut(x+35, y+1);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+35, y+2);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+35, y+3);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+36, y+4);
    printf("%c%c%c%c%c", 178, 178, 178, 178, 178);

    //Mencetak K besar
    setTextColor(12);
    kursorOut(x+48, y);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+48, y+1);
    printf("%c%c %c%c", 178, 178, 178, 178);
    kursorOut(x+48, y+2);
    printf("%c%c%c%c", 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+48, y+3);
    printf("%c%c %c%c", 178, 178, 178, 178);
    kursorOut(x+48, y+4);
    printf("%c%c   %c%c", 178, 178, 178, 178);

    //Mencetak U besar
    setTextColor(12);
    kursorOut(x+60, y);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+60, y+1);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+60, y+2);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    setTextColor(15);
    kursorOut(x+60, y+3);
    printf("%c%c   %c%c", 178, 178, 178, 178);
    kursorOut(x+60, y+4);
    printf("%c%c%c%c%c%c%c", 178, 178, 178, 178, 178, 178, 178);
}

int BaseSudoku(int mode, int opsi){
	int i, m, sisa, salah = 0;
	int n = 3;
	int size = n * n;
	struct sudoku** table;
	table = (struct sudoku**)malloc(size * sizeof(struct sudoku*));
	for(i = 0; i < size; i++)
        table[i] = (struct sudoku*)malloc(size * sizeof(struct sudoku));     
	while(1) {
		srand(time(NULL));
	    char papan[9][9];
	    
	    if (opsi == 1) goto NewSudoku;
	    else if (opsi == 2) goto LoadSudoku;
		
	    NewSudoku:
      		sudokuGenerator(table, n, 0, 0);
      		hideNumbers(table, n, &m, mode);
	    	kursorOut(67, 13);
			printf("Permainan akan segera dimulai...");
	    	Sleep(1000);
			goto Play;
	    
	    LoadSudoku:
	    	loadGameSudoku(table, &m, salah);
	    	kursorOut(69, 13);
			printf("=== Memuat Game Tersimpan ===");
    		Sleep(1000);
	    	goto Play;
		
		
		Play:
			system("cls");
			inputToCompare(table, n);
			play(table, &m, papan, &salah);
			if (m == 81) {	
				kursorOut(70, 10);
				printf("======Selamat Anda Menang!!======");
				Sleep(1000);
				system("cls");
				goto Return;
			}
			else if (salah == 3) {	
				kursorOut(69, 10);
				printf("====Sayang Sekali Anda Payah!!====");
				Sleep(1000);
				system("cls");
				goto Return;
			} else goto Return;
		
		
		Return:	
			kursorOut(64, 10);
			printf("Anda Sebentar Lagi akan Dialihkan ke Menu");
			Sleep(1000);
			Sleep(500);
   			system("cls");
			return;
		
			
		return 0;
	}
	
	
}

void play(struct sudoku** table, int* m, char sudoku[9][9], int* salah) {
	// i untuk baris
	// j untuk kolom
	int i = 10, j = 10, val;
	int n = 3;
	int sisa;
	int datasalah;
	while (*m < 81){
		inputInJ:
			sisa = *m;
			datasalah = *salah;
			initPapan(sudoku, table, n);
			system("cls");
		//	pthread_t newThread;
		//	pthread_create(&newThread, NULL, timer, NULL);
		//	printf("\n");
			printPapan(sudoku, *salah, i, j);
			kursorOut(38, 45);
			printf("Masukkan Nomor Baris: ");
			scanf("%d", &i);
		//pause game	
		if (i == 11){
			int cek = 2;
			cek = PauseGame(table, sisa, datasalah);
			system("cls");
			
			if (cek == 0) goto inputInJ;
			else break;
		}
			kursorOut(38, 47);
			printf("Masukkan Nomor Kolom: ");
			scanf("%d", &j);
			system("cls");
			printPapan(sudoku, *salah, i, j);
		if (sudoku[i-1][j-1] == ' ') {
			kursorOut(38, 45);
			printf("Masukkan Nomor Yang Ingin Diinput: ");
			scanf("%d", &val);
			if (val == table[i-1][j-1].compare) {
				table[i-1][j-1].mask = 1;
				val = 0;
				*m = *m + 1;
			} else {
				*salah = *salah + 1;
				if (*salah != 3) goto inputInJ;
				else {
					system("cls");
					break;	
				}
			}
		} else {
			kursorOut(38, 45);
			printf("Sudoku sudah memiliki nilai!!");
			Sleep(700);
			goto inputInJ;
		} 
	}	
	system("cls");
}

int PauseGame(struct sudoku** table, int sisa, int salah){
	int pause = 0;
	while (pause != 1 || pause != 2) {
		
		system("cls");
		kursorOut(71, 10);
		printf("=====PAUSE GAME=====");
		kursorOut(71, 11);
		printf("1. Lanjut game");
		kursorOut(71, 12);
		printf("2. Save and Exit");
		kursorOut(71, 13);
		printf("Pilih Opsi 1 atau 2: ");
		scanf("%d", &pause);	
		
		if (pause == 1) return 0;
		else if (pause == 2) {
			loadSudoku(table, sisa, salah);
			return 1;
		}
		else continue;
	}
}

int sudokuGenerator(struct sudoku** table, int n, int x, int y){
	int i, j; 
	int size = n*n; 
	
	// 2. Mask Array
	int* maskArray = (int*)malloc(size*sizeof(int*));
	// tandai 1 untuk value yang mungkin
	for (i = 0; i < size; i++) maskArray[i] = 1;
    
	// 3. cari dan tandai untuk value yang tidak mungkin
    for (i = 0; i < y; i++) maskArray[table[x][i].number - 1] = 0;
    for (i = 0; i < x; i++) maskArray[table[i][y].number - 1] = 0;
    for (i = (n * (int)(x/n)); i < (n * (int)(x/n) + n); i++)
        for (j = (n * (int)(y/n)); j < y; j++)
            maskArray[table[i][j].number - 1] = 0;
    
	// 4. kelompokkan semua value yang mungkin ke dalam array baru
    // 4.1. Declare dan allocate array baru
    int k = 0;
    for (i = 0; i < size; i++) k += maskArray[i]; 
    int* randArray;
    randArray = (int*)malloc(k * sizeof(int*));
    // 4.2. masukkan array tersebut ke dalam array berikut
    j = 0; // reset j 
    for (i = 0; i < size; i++) {
        if (maskArray[i] == 1) { // posisi i merupakan posisi yang mungkin
            randArray[j] = i + 1; // assign value
            j++;
        } else continue;
    }
    
	// 5. menghitung posisi sel selanjutnya.
    int newX, newY;
    if (x == size-1) {
        newY = y + 1;
        newX = 0;
    } else {
        newY = y;
        newX = x + 1;
    }	
	
	// 6. Ambil nilai acak yang memungkinkan ke dalam sel saat ini.
    while (k > 0) { // coba semuanya
        int index = rand() % k; 
        table[x][y].number = randArray[index];
        for (i = index; i < (k-1); i++) randArray[i] = randArray[i+1];
        k--;
		
		// berhenti jika berada di sel terakhir
		if ((x == size-1) && (y == size-1)) {
        free(randArray); free(maskArray);
        return 1; 
    }
        
    // atau ke sel berikutnya
    if (sudokuGenerator(table, n, newX, newY)) {
       free(randArray); free(maskArray);
       return 1;
    }
    }
    
	// 7. melepaskan memory
    free(randArray); free(maskArray);
    return 0;
}

void inputToCompare(struct sudoku** table, int n){
	int i, j, size = n * n;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
	        table[i][j].compare = table[i][j].number;
		}
	}
}

void hideNumbers(struct sudoku **table, int n, int* m, int mode) {
    int i, j, x, y, size = n * n;
    // 1. atur mask=0 untuk semua sel
    if (mode == 1) *m = 45;
    else if (mode == 2) *m = 30;
    else *m = 20;
    
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
        	table[i][j].mask = 0;
        }
    }
    // 2. mengubah sel m terbuka secara acak
    for (i = 0; i < *m; i++) {
    	do {
    		x = rand() % size;
    		y = rand() % size;
    	} while (table[x][y].mask == 1); // jika sel telah berubah sebelumnya
    	table[x][y].mask = 1; // atur mask=1 untuk sel(x,y)
    }
}

void initPapan(char sudoku[9][9], struct sudoku** table, int n) {
    int i, j, size = n * n;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
	        if (table[i][j].mask == 0) sudoku[i][j] = ' '; // mask=0
	        else sudoku[i][j]= table[i][j].number + '0'; // mask=1
		}
	}
}
 
void printPapan(char sudoku[9][9], int salah, int b, int k)
{
	int i;
	
	kursorOut(38,10);
	printf("salah: %d/3", salah);
		
	kursorOut(25, 15);
	printf("ketik 11 untuk pause game");
	
	kursorOut(54,5);
	for(i=0;i<9;i++){
		if (i+1 == k){
			setTextColor(9);
			printf("   %d  ",i+1);
			setTextColor(15);
		} else printf("   %d  ",i+1);
	}
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
        printf("%c     %c     %c     %c     %c     %c     %c     %c     %c     %c", 
            179, 179, 179, 179, 179, 179, 179, 179, 179, 179);
		// Baris untuk konten
        kursorOut(54, 8 + i * 4);
		printf("%c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c  %c", 
               179, sudoku[i][0], 179, sudoku[i][1], 179, sudoku[i][2], 179, sudoku[i][3], 179, 
               sudoku[i][4], 179, sudoku[i][5], 179, sudoku[i][6], 179, sudoku[i][7], 179, sudoku[i][8], 179);
		
        kursorOut(180, 8 + i * 4);
        if (i+1 == b) {
        	setTextColor(9);
        	printf(" %d", i+1);
        	setTextColor(15);
		} else printf(" %d", i+1);
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

void kursorOut(int x, int y) {
    COORD p;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    p.X = x;
    p.Y = y;
    SetConsoleCursorPosition(hOut, p);
}

void setTextColor(int color) {
   HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hCon,color);
}
