#include <iostream>
using namespace std;

void buatDaftarAstronot(int arrayAstronot[], int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        arrayAstronot[i] = i + 1;
    }
}

int main() {
    int total, k;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> total;
    cout << "Masukkan nilai awal K: ";
    cin >> k;

    int peserta[1000];
    buatDaftarAstronot(peserta, total);

    int sisaPeserta = total;
    int posSekarang = 0;

    cout << "Urutan astronot yang dieliminasi: ";

    while (sisaPeserta > 1) {
        for (int step = 1; step < k; step++) {
            posSekarang = (posSekarang + 1) % sisaPeserta;
        }

        int yangGugur = peserta[posSekarang];
        cout << yangGugur;

        if (sisaPeserta > 2) {
            cout << ", ";
        }

        for (int i = posSekarang; i < sisaPeserta - 1; i++) {
            peserta[i] = peserta[i + 1];
        }
        sisaPeserta--;

        if (yangGugur % 2 == 0) {
            k = k + 2;
        } else {
            k = k - 1;
        }

        if (k < 2) {
            k = 2;
        }

        if (posSekarang >= sisaPeserta) {
            posSekarang = 0;
        }
    }

    cout << endl;
    cout << "Astronot terakhir yang bertahan: " << peserta[0] << endl;

    return 0;
}
