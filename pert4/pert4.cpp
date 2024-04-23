#include<iostream>
using namespace std;

void tambah(int angka1,int angka2){ 
    cout << "Hasil Tambah = "<<angka1 + angka2<<endl;
}

void kurang(int angka1,int angka2){
    cout << "Hasil Kurang = "<<angka1 - angka2<<endl;
}

void kali(int angka1,int angka2){
    cout << "Hasil Kali = "<<angka1 + angka2<<endl;
}

void bagi(int angka1,int angka2){
    cout << "Hasil Bagi = "<<angka1 / angka2<<endl;    
}
int main(){
    int angka1,angka2;
    int pilih;
    Menu:
    cout<<"Menu"<< endl;
    cout<<"1. Tambah"<< endl;
    cout<<"2. Kurang"<< endl;
    cout<<"3. Kali"<< endl;
    cout<<"4. Bagi"<< endl;
    cout<<"5. EXIT"<< endl;
    cout<<"Pilihan : ";
    cin >>pilih;
    switch(pilih){
        case 1:
            cout << "Angka 1 = ";
            cin >> angka1;
            cout << "Angka 2 = ";
            cin >> angka2;
            tambah(angka1,angka2);
            break;
        case 2:
            cout << "Angka 1 = ";
            cin >> angka1;
            cout << "Angka 2 = ";
            cin >> angka2;
            kurang(angka1,angka2);
            break;
        case 3:
            cout << "Angka 1 = ";
            cin >> angka1;
            cout << "Angka 2 = ";
            cin >> angka2;
            kali(angka1,angka2);
            break;
        case 4:
            cout << "Angka 1 = ";
            cin >> angka1;
            cout << "Angka 2 = ";
            cin >> angka2;
            bagi(angka1,angka2);
            break;
        case 5:
            cout<<"EXIT"<<endl;
            break;
        default:
            cout<<"Pilihan Tidak Ada"<<endl;
            goto Menu;
            break;
    }
    return 0;
}