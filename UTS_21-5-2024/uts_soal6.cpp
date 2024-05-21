#include <iostream>

using namespace std;

// Fungsi untuk menampilkan menu dan mendapatkan pilihan dari pengguna
void menu() {
    cout << "Pilih operasi aritmatika:" << endl;
    cout << "1. Penjumlahan (+)" << endl;
    cout << "2. Pengurangan (-)" << endl;
    cout << "3. Perkalian (*)" << endl;
    cout << "4. Pembagian (/)" << endl;
    cout << "Masukkan pilihan Anda (1/2/3/4): ";
}

// Fungsi untuk penjumlahan
void tambah(double a, double b) {
    cout << "Hasil: " << a + b << endl;
}

// Fungsi untuk pengurangan
void kurang(double a, double b) {
    cout << "Hasil: " << a - b << endl;
}

// Fungsi untuk perkalian
void kali(double a, double b) {
    cout << "Hasil: " << a * b << endl;
}

// Fungsi untuk pembagian
void bagi(double a, double b) {
    if (b != 0) {
        cout << "Hasil: " << a / b << endl;
    } else {
        cout << "Error: Pembagian dengan nol tidak diperbolehkan." << endl;
    }
}


int main() {
    int pilihan;
    double num1, num2;

    menu();
    cin >> pilihan;

    // Meminta pengguna untuk memasukkan dua angka setelah memilih operasi
    cout << "Masukkan angka pertama: ";
    cin >> num1;
    cout << "Masukkan angka kedua: ";
    cin >> num2;

    switch (pilihan) {
        case 1:
            tambah(num1, num2);
            break;
        case 2:
            kurang(num1, num2);
            break;
        case 3:
            kali(num1, num2);
            break;
        case 4:
            bagi(num1, num2);
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }
    return 0;
}
