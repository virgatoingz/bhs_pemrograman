#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Menu {
private:
    unordered_map<string, int> makanan;
    unordered_map<string, int> minuman;

public:
    Menu() {
        makanan["Pecel Lele"] = 15000;
        makanan["Nasi Goreng"] = 12000;
        minuman["Es Teh"] = 5000;
        minuman["Jus Jeruk"] = 7000;
    }

    void tampilkanMenuUtama();
    void tampilkanMenuMakanan();
    void tampilkanMenuMinuman();
    void prosesPilihan(const string& item, int harga);
};

void Menu::tampilkanMenuUtama() {
    while (true) {
        cout << "\nMenu Utama:\n";
        cout << "1. Makanan\n";
        cout << "2. Minuman\n";
        cout << "3. Exit\n";
        cout << "Pilih menu: ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanMenuMakanan();
                break;
            case 2:
                tampilkanMenuMinuman();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan aplikasi ini.\n";
                return;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}

void Menu::tampilkanMenuMakanan() {
    while (true) {
        cout << "\nMenu Makanan:\n";
        int index = 1;
        for (const auto& item : makanan) {
            cout << index++ << ". " << item.first << " - Rp" << item.second << "\n";
        }
        cout << index << ". Kembali\n";
        cout << "Pilih makanan: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            auto it = makanan.begin();
            advance(it, pilihan - 1);
            prosesPilihan(it->first, it->second);
        } else if (pilihan == 3) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}

void Menu::tampilkanMenuMinuman() {
    while (true) {
        cout << "\nMenu Minuman:\n";
        int index = 1;
        for (const auto& item : minuman) {
            cout << index++ << ". " << item.first << " - Rp" << item.second << "\n";
        }
        cout << index << ". Kembali\n";
        cout << "Pilih minuman: ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1 || pilihan == 2) {
            auto it = minuman.begin();
            advance(it, pilihan - 1);
            prosesPilihan(it->first, it->second);
        } else if (pilihan == 3) {
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    }
}

void Menu::prosesPilihan(const string& item, int harga) {
    cout << "Masukkan jumlah " << item << ": ";
    int jumlah;
    cin >> jumlah;
    if (jumlah > 0) {
        int totalHarga = jumlah * harga;
        cout << "Total harga untuk " << jumlah << " " << item << " adalah Rp" << totalHarga << "\n";
    } else {
        cout << "Jumlah tidak valid. Silakan masukkan angka positif.\n";
    }
}

int main() {
    Menu menu;
    menu.tampilkanMenuUtama();
    return 0;
}
