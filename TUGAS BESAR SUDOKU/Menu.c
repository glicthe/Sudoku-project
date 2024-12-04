#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameSudoku.h"
#include "PlaySudoku.h"

void startGame() {
    int mode;
    char nama[50];
    FILE* fp;
    fp = fopen("filename.txt", "a");
    
     // Input nama pemain
    kursorOut(67, 15);
    printf("Masukkan Nama kamu: ");
    fgets(nama, sizeof(nama), stdin); 
    fprintf(fp, "%s", nama);
    fclose(fp);
    nama[strcspn(nama, "\n")] = 0; // Menghilangkan newline dari input
	system("cls");
	
	kursorOut(67, 10);
    printf("=== Memulai Game Baru ===\n");
    kursorOut(67, 11);
	printf("1. Mudah\n");
	kursorOut(67, 12);
    printf("2. Sedang\n");
    kursorOut(67, 13);
	printf("3. Sulit\n");
    kursorOut(67, 14);
	printf("Pilih mode (1-3): ");
    scanf("%d", &mode);
    getchar(); // Untuk menangani enter setelah input angka
    system("cls");

    if (mode < 1 || mode > 3) {
    	kursorOut(71, 15);
        printf("Mode tidak valid! Kembali ke menu utama.\n");
        getchar();
        return;
    }

    // Tampilkan mode dan nama pemain
    kursorOut(67, 10);
    printf("Selamat datang, %s!", nama);
    
    if (mode == 1) {
    	kursorOut(67, 11);
		printf("Kamu memilih mode Mudah.");
		BaseSudoku(mode);
	}
    else if (mode == 2) {
    	kursorOut(67, 11);
		printf("Kamu memilih mode Sedang.");	
		BaseSudoku(mode);
	}
	else {
		kursorOut(67, 11);
		printf("Kamu memilih mode Sulit.");
		BaseSudoku(mode);
	}


    
}

// Fungsi untuk memuat game yang tersimpan
void loadGame() {
    printf("\n=== Memuat Game Tersimpan ===\n");
    printf("Fitur Load Game belum tersedia.\n");
    printf("Tekan Enter untuk kembali ke menu utama.");
    getchar(); // Menunggu user menekan enter sebelum kembali ke menu
}

// Fungsi untuk menampilkan skor tertinggi
void highscore() {
    printf("\n=== Highscore ===\n");
    printf("Fitur Highscore belum tersedia.\n");
    printf("Tekan Enter untuk kembali ke menu utama.");
    getchar(); // Menunggu user menekan enter sebelum kembali ke menu
}

// Fungsi untuk keluar dari game
void exitGame() {
    printf("\nTerima kasih telah bermain! Sampai jumpa lagi!\n");
}
