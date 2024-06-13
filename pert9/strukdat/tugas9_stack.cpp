#include <iostream>
#include <stack>// Digunakan untuk menggunakan struktur data stack didalam library jadi tidak perlu membuat code stack lagi
#include <string>

using namespace std;
//Function untuk menampilkan menu saja
void showMenu() {
    cout << "Pilih operasi yang ingin dilakukan:\n";
    cout << "1. Tambah Buku\n";
    cout << "2. Menghapus Buku Teratas\n";
    cout << "3. Melihat Buku Teratas\n";
    cout << "4. Memeriksa Apakah Tumpukan Kosng\n";
    cout << "5. Melihat Ukuran/Jumlah Stack\n";
    cout << "6. EXIT\n";
    cout << "Masukkan pilihan: ";
}

int main() {
    //Mendeklarasikan Variable
    stack<string> books; // Untuk Menampung Nilai dalam Stack
    int choice; // Untuk Menyimpan pilihan operasi dari pengguna
    string book; // Variabel ini menyimpan nama buku yang akan ditambahkan ke stack.

    while (true) {
        showMenu();
        cin >> choice;
        cin.ignore();  // mengabaikan karakter newline setelah angka pilihan

        //Pakai Switch Case karna memiliki lebih dari 2 opsi
        switch (choice) {

            // Case 1 memasukan stack
            case 1:
                cout << "Masukkan Nama buku: ";
                getline(cin, book);
                books.push(book);
                cout << "Buku \"" << book << "\" telah ditambahkan.\n";
                break;

            // Case 2 mengambil stack paling atas
            case 2:
                if (!books.empty()) {
                    cout << "Buku \"" << books.top() << "\" telah dihapus.\n";
                    books.pop();
                } else {
                    cout << "Tumpukan kosong, tidak ada buku yang dapat dihapus.\n";
                }
                break;

            // Case 3 Melihat buku yg paling atas
            case 3:
                if (!books.empty()) {
                    cout << "Buku teratas adalah: \"" << books.top() << "\"\n";
                } else {
                    cout << "Tumpukan kosong.\n";
                }
                break;
            
            // Case 4 Mengecek apakah Stack kosong atau tidak
            case 4:
                if (books.empty()) {
                    cout << "Tumpukan kosong.\n";
                } else {
                    cout << "Tumpukan tidak kosong.\n";
                }
                break;

            //Case 5 Mengecek brp uukuran Stackan/brp jumlah yang ad didalam stack
            case 5:
                cout << "Ukuran tumpukan: " << books.size() << "\n";
                break;

            // Case 6 Menu Exit
            case 6:
                cout << "Keluar dari program.\n";
                return 0;

            // Default Menangani input yang tidak valid.
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }

        cout << "\n";  // newline untuk memisahkan output antar operasi
    }

    return 0;
}
