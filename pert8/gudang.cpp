#include <iostream>
#include <unordered_map>

using namespace std;

class InventorySystem {
private:
    unordered_map<string, int> inventory;

public:
    void add_item(string item_id, int quantity) {
        if (inventory.find(item_id) != inventory.end()) {
            inventory[item_id] += quantity;
        } else {
            inventory[item_id] = quantity;
        }
        cout << "Stok berhasil ditambahkan." << endl;
    }

    void process_order(string item_id, int quantity) {
        if (inventory.find(item_id) != inventory.end() && inventory[item_id] >= quantity) {
            inventory[item_id] -= quantity;
            cout << "Pesanan diproses. Persediaan telah dikurangi." << endl;
        } else {
            cout << "Stok tidak mencukupi untuk pesanan ini." << endl;
        }
    }
};

int main() {
    InventorySystem inventory_system;

    while (true) {
        cout << "Menu Utama:" << endl;
        cout << "1. Tambah Stok" << endl;
        cout << "2. Proses Pesanan" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        if (choice == 1) {
            string item_id;
            int quantity;
            cout << "Masukkan ID barang: ";
            cin >> item_id;
            cout << "Masukkan jumlah barang yang ditambahkan: ";
            cin >> quantity;
            inventory_system.add_item(item_id, quantity);
        } else if (choice == 2) {
            string item_id;
            int quantity;
            cout << "Masukkan ID barang: ";
            cin >> item_id;
            cout << "Masukkan jumlah barang yang dipesan: ";
            cin >> quantity;
            inventory_system.process_order(item_id, quantity);
        } else if (choice == 3) {
            cout << "Keluar dari sistem." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
