#include<iostream>
using namespace std;
void dowhile(){
    cout << "Penggunaan Do While" << endl;
    int a = 1;
    int b = 2;

    do{
        cout << a << endl;
        a = a+1;
    }while(a<=b);
}
void penggunaanwhile(){
    cout << "Penggunaan While" << endl;
    int a = 1;
    int b = 2;
    while(a<=b){
        cout << a << endl;
        a = a+1;
    }
}
void penggunaanwhilebreak(){
    cout<< "Penggunaan While Break" << endl;
    int a=0;
    while(a<=5){
        a = a+1;
        if (a==6){
            cout << a << endl;
            break;
        }
        cout << "Looping while berhenti" << endl;
    }
    cout << "Looping diluar while berhenti" << endl;
}
int main(){
    dowhile();
    penggunaanwhile();
    penggunaanwhilebreak();
    return 0;
}