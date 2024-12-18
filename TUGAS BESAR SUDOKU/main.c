#include <stdio.h>
#include <stdlib.h>
#include "GameSudoku.h"
#include "Menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	    int choice;

    // Loop untuk menampilkan menu sampai user memilih "Exit"
    while (1) {
        int opsi;
        bannerSudoku(50,2);
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
        printf("1. Start\n");
        kursorOut(72, 15);
        printf("2. Load Game\n");
        kursorOut(72, 17);
        printf("3. How to play\n");
        kursorOut(72, 19);
        printf("4. Exit\n");
        kursorOut(72, 21);
        printf("Pilih opsi (1-4): ");
        scanf("%d", &choice);
        getchar(); // Untuk menangani enter setelah input angka
        system("cls"); // Membersihkan layar setiap kali menu ditampilkan

        switch (choice) {
            case 1:
                opsi = 1;
                startGame(opsi);
                system("cls"); // Bersihkan layar sebelum masuk ke menu Start
                break;
                
            case 2:
                opsi = 2;
                loadGame(opsi);
                system("cls"); // Bersihkan layar sebelum masuk ke Load Game
                break;
            case 3:
                opsi = 3;
                howToPlay(opsi);
                system("cls"); // Bersihkan layar sebelum masuk ke Highscore
                break;
            case 4:
                exitGame();
                return 0;
            default:
                printf("Pilihan tidak valid! Silakan pilih lagi.\n");
                getchar(); // Menunggu user menekan enter sebelum kembali ke menu
        }
    }
			
	
	return 0;
}

