#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameSudoku.h"
#include "LoadSudoku.h"

void startGame(int opsi) {
    int mode;
    char nama[50];
    
    bannerSudoku(50,2);
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
	
	bannerSudoku(50,2);
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
    bannerSudoku(50,2);
    kursorOut(67, 10);
    printf("Selamat datang, %s!", nama);
    
    if (mode == 1) {
    	kursorOut(67, 11);
		printf("Kamu memilih mode Mudah.");
		BaseSudoku(mode, opsi);
	}
    else if (mode == 2) {
    	kursorOut(67, 11);
		printf("Kamu memilih mode Sedang.");	
		BaseSudoku(mode, opsi);
	}
	else {
		kursorOut(67, 11);
		printf("Kamu memilih mode Sulit.");
		BaseSudoku(mode, opsi);
	}   
}

// Fungsi untuk memuat game yang tersimpan
void loadGame(int opsi) {
	int mode = 0;
    
    BaseSudoku(mode, opsi);
}

// Fungsi untuk menampilkan skor tertinggi
void howToPlay(int opsi) {
	int pilih;
	
	while (1) {
	system("cls");
	bannerSudoku(50,2);
	kursorOut(25,9);
	kursorOut(70,10);
    printf("CARA BERMAIN");
    kursorOut(25,13);
    printf("1. Kamu akan disuruh untuk input baris (baris disini adalah atas ke bawah) berapa angka yang ingin kamu masukkan");
    kursorOut(25,16);
    printf("2. Kamu akan disuruh untuk input kolom (kolom disini adalah kanan ke kiri) berapa angka yang ingin kamu masukkan");
    kursorOut(25,19);
    printf("3. Terakhir, masukkan angka yang ingin kamu masukkan ke papan sudoku!!!");
    kursorOut(24,21);
    printf("\033[91m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\033[0m",
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	kursorOut(70,24);
    printf("PERATURAN BERMAIN");
    kursorOut(25,27);
    printf("1. Angka yang dimasukkan pada papan harus berbeda di settiap baris, kolom, dan sub bagian papan");
    kursorOut(25,29);
    printf("2. Kamu akan menang ketika semua papan sudah terisi dengan angka yang sesuai");
    kursorOut(25,32);
    printf("3. Kamu akan kalah ketika jumlah salah melebihi tiga kali");
    kursorOut(24,36);
    printf("\033[91m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\033[0m",
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 205, 205, 205, 205, 205, 205, 205, 205, 
	205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	kursorOut(24,39);
    printf("Tekan 1 untuk kembali:  ");
    scanf("%d", &pilih);
    
    if(pilih == 1)
    	break;
	else continue;
	}
}

// Fungsi untuk keluar dari game
void exitGame() {
    printf("\nTerima kasih telah bermain! Sampai jumpa lagi!\n");
}
