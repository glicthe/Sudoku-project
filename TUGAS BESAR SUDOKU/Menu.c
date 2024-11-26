#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameSudoku.h"


void startGame() {
    int mode;
    char nama[50];
    FILE* fp;
    fp = fopen("filename.txt", "a");
    
     // Input nama pemain
    printf("Masukkan Nama kamu: ");
    fgets(nama, sizeof(nama), stdin); 
    fprintf(fp, "%s", nama);
    fclose(fp);
    nama[strcspn(nama, "\n")] = 0; // Menghilangkan newline dari input
	system("cls");

    printf("\n=== Memulai Game Baru ===\n");
    printf("1. Mudah\n");
    printf("2. Sedang\n");
    printf("3. Sulit\n");
    printf("Pilih mode (1-3): ");
    scanf("%d", &mode);
    getchar(); // Untuk menangani enter setelah input angka
    system("cls");

    if (mode < 1 || mode > 3) {
        printf("Mode tidak valid! Kembali ke menu utama.\n");
        getchar();
        return;
    }

    // Tampilkan mode dan nama pemain
    printf("\nSelamat datang, %s!\n", nama);
    
    if (mode == 1) {
		printf("Kamu memilih mode Mudah.\n");
		kondisiAwalSudoku();
	}
    else if (mode == 2) {
		printf("Kamu memilih mode Sedang.\n");	
	}
	else {
		printf("Kamu memilih mode Sulit.\n");
	}

    printf("Permainan akan segera dimulai...\n");
    printf("Tekan Enter untuk kembali ke menu utama.");
    getchar(); // Menunggu user menekan enter sebelum kembali ke menu
    system("cls");
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
