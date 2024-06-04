#include <iostream>
#include <climits> // Untuk penggunaan INT_MAX

using namespace std;

// Struktur node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di depan linked list
    void insertFront(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        cout << "Node dengan data " << data << " berhasil ditambahkan di depan." << endl;
    }

    // Fungsi untuk menambahkan node di tengah linked list
    void insertMiddle(int position, int data) {
        Node* newNode = new Node;
        newNode->data = data;
        if (position == 0 || head == nullptr) {
            insertFront(data);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Posisi yang diminta tidak valid." << endl;
            delete newNode; // tambahkan penghapusan node baru jika posisi tidak valid
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Node dengan data " << data << " berhasil ditambahkan di tengah." << endl;
    }

    // Fungsi untuk menambahkan node di belakang linked list
    void insertEnd(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            cout << "Node dengan data " << data << " berhasil ditambahkan di belakang." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Node dengan data " << data << " berhasil ditambahkan di belakang." << endl;
    }

    // Fungsi untuk menghapus node di depan linked list
    void deleteFront() {
        if (head == nullptr) {
            cout << "Linked list sudah kosong." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node di depan berhasil dihapus." << endl;
    }

    // Fungsi untuk menghapus node di tengah linked list
    void deleteMiddle(int position) {
        if (head == nullptr) {
            cout << "Linked list sudah kosong." << endl;
            return;
        }
        if (position == 0) {
            deleteFront();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Posisi yang diminta tidak valid." << endl;
            return;
        }
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
        cout << "Node di tengah berhasil dihapus." << endl;
    }

    // Fungsi untuk menghapus node di belakang linked list
    void deleteEnd() {
        if (head == nullptr) {
            cout << "Linked list sudah kosong." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node di belakang berhasil dihapus." << endl;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Node di belakang berhasil dihapus." << endl;
    }

    // Fungsi untuk menampilkan isi linked list
    void displayList() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Node* temp = head;
        cout << "Isi linked list: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destruktor
    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    LinkedList list;
    char choice;
    int data, position;
    bool running = true;

    while (running) {
        cout << "\nMenu:\n";
        cout << "a. Insert depan\n";
        cout << "b. Insert tengah\n";
        cout << "c. Insert belakang\n";
        cout << "d. Delete depan\n";
        cout << "e. Delete tengah\n";
        cout << "f. Delete belakang\n";
        cout << "g. Tampilkan data\n";
        cout << "h. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Input tidak valid. Silakan coba lagi." << endl;
            cin.clear(); // membersihkan kesalahan input
            cin.ignore(INT_MAX, '\n'); // mengabaikan input yang salah
            continue;
        }

        switch (choice) {
            case 'a':
                cout << "Masukkan data untuk ditambahkan di depan: ";
                cin >> data;
                if (cin.fail()) {
                    cout << "Input tidak valid." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
                list.insertFront(data);
                break;
            case 'b':
                cout << "Masukkan posisi node sebelumnya: ";
                cin >> position;
                cout << "Masukkan data untuk ditambahkan di tengah: ";
                cin >> data;
                if (cin.fail()) {
                    cout << "Input tidak valid." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
                list.insertMiddle(position, data);
                break;
            case 'c':
                cout << "Masukkan data untuk ditambahkan di belakang: ";
                cin >> data;
                if (cin.fail()) {
                    cout << "Input tidak valid." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
                list.insertEnd(data);
                break;
            case 'd':
                list.deleteFront();
                break;
            case 'e':
                cout << "Masukkan posisi node yang akan dihapus: ";
                cin >> position;
                if (cin.fail()) {
                    cout << "Input tidak valid." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
                list.deleteMiddle(position);
                break;
            case 'f':
                list.deleteEnd();
                break;
            case 'g':
                list.displayList();
                break;
            case 'h':
                running = false;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
