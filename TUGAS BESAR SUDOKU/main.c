/*------------------------PROGRAM MAIN SUDOKU------------------------*/

/*-------header--------*/
#include <stdio.h>
#include <stdlib.h>
#include "GameSudoku.h"
#include "Menu.h"

/*------------------------PROGRAM------------------------*/
int main(int argc, char *argv[]) {

	//Kamus data		
	int choice;
	
	// Loop untuk menampilkan menu sampai user memilih "Exit"
    while (1) {
    	bannerSudoku(50,2);		//Memanggil modul bannerSudoku
        kursorOut(71, 9);		//Memanggil modul kursorOut
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
		201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        kursorOut(71,10);
        setTextColor(12);
        printf("   WELCOME TO OUR GAME  ");
        setTextColor(15);
        kursorOut(71,10);
        printf("%c",186);
        kursorOut(95,10);
        printf("%c",186);
        kursorOut(71, 11);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 
		200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        setTextColor(15);
        kursorOut(72, 13);
        printf("1. Start");
        kursorOut(72, 15);
        printf("2. Load Game");
        kursorOut(72, 17);
        printf("3. Highscore");
        kursorOut(72, 19);
        printf("4. Exit");
        kursorOut(72, 21);
        printf("Pilih opsi (1-4): ");
        scanf("%d", &choice);
        getchar(); 			// Scanf untuk menangani enter setelah input angka
        system("cls"); 			// Membersihkan layar setiap kali menu ditampilkan

        switch (choice) {		//Selection berdasarkan input user
            case 1:
                
                startGame();		//Memanggil modul startGame
                system("cls");	
                break;
                
            case 2:
                
                loadGame();		//Memanggil modul loadGame
                system("cls"); 
                break;
            case 3:
                
                highScore();		//Memanggil modul highScore
                system("cls"); 
                break;
            case 4:
                exitGame();		//Memanggil modul exitGame
                return 0;
            default:
                printf("Pilihan tidak valid! Silakan pilih lagi.\n");
                getchar(); 
        }
    }
	
	return 0;
}
/*------------------------END PROGRAM------------------------*/
