
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deklarasi fungsi
void startGame();
void loadGame();
void highscore();
void exitGame();

int main() {
    int choice;

    // Loop untuk menampilkan menu sampai user memilih "Exit"
    while (1) {
        
        printf("\n=== MENU UTAMA SUDOKU ===\n");
        printf("1. Start\n");
        printf("2. Load Game\n");
        printf("3. Highscore\n");
        printf("4. Exit\n");
        printf("Pilih opsi (1-4): ");
        scanf("%d", &choice);
        getchar(); // Untuk menangani enter setelah input angka
        system("cls"); // Membersihkan layar setiap kali menu ditampilkan

        switch (choice) {
            case 1:
                
                startGame();
                system("cls"); // Bersihkan layar sebelum masuk ke menu Start
                break;
                
            case 2:
                
                loadGame();
                system("cls"); // Bersihkan layar sebelum masuk ke Load Game
                break;
            case 3:
                
                highscore();
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
}

// Fungsi untuk memulai game
void startGame() {
    int mode;
    char nama[50];
    
     // Input nama pemain
    printf("Masukkan Nama kamu: ");
    fgets(nama, sizeof(nama), stdin);
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
    if (mode == 1) printf("Kamu memilih mode Mudah.\n");
    else if (mode == 2) printf("Kamu memilih mode Sedang.\n");
    else printf("Kamu memilih mode Sulit.\n");

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

