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
        kursorOut(71, 10);
        printf("=== MENU UTAMA SUDOKU ===\n");
        kursorOut(71, 11);
        printf("1. Start\n");
        kursorOut(71, 12);
        printf("2. Load Game\n");
        kursorOut(71, 13);
        printf("3. Highscore\n");
        kursorOut(71, 14);
        printf("4. Exit\n");
        kursorOut(71, 15);
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
                highscore(opsi);
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

