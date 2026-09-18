#include <iostream>
using namespace std;

int cariPanjangString(char str[]) {
    int n = 0;
    while (str[n] != '\0') {
        n++;
    }
    return n;
}

int main() {
    char inputTeks[1000];
    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> inputTeks;

    int panjang = cariPanjangString(inputTeks);
    char hasilEnkripsi[1000];
    
    int geser = 0;

    for (int i = 0; i < panjang; i++) {
        int urutanAsli = inputTeks[i] - 'A' + 1;
        int urutanBaru = urutanAsli + geser;

        if (urutanBaru > 26) {
            urutanBaru = urutanBaru - 26;
        }

        hasilEnkripsi[i] = urutanBaru - 1 + 'A';
        geser = urutanAsli;
    }

    hasilEnkripsi[panjang] = '\0';

    cout << "Pesan tersandi: " << hasilEnkripsi << endl;

    return 0;
}