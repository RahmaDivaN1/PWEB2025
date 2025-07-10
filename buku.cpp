#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Buku {
    int kode;
    char judul[50];
    int jumlah;
};

Buku daftar[MAX];
int jumlahData = 0;

void tambahBuku() {
    cout << "Masukkan kode buku   : ";
    cin >> daftar[jumlahData].kode;
    cin.ignore();
    cout << "Masukkan judul buku  : ";
    cin.getline(daftar[jumlahData].judul, 50);
    cout << "Masukkan jumlah buku : ";
    cin >> daftar[jumlahData].jumlah;
    jumlahData++;
}

void tampilkanBuku() {
    cout << "\nKode\tJudul\t\tJumlah\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << daftar[i].kode << "\t" << daftar[i].judul << "\t\t" << daftar[i].jumlah << endl;
    }
}

void urutkanJudul() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (strcmp(daftar[j].judul, daftar[j+1].judul) > 0) {
                Buku temp = daftar[j];
                daftar[j] = daftar[j+1];
                daftar[j+1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan judul A-Z.\n";
}

void simpanKeFile() {
    FILE* file = fopen("stok_buku.txt", "w");
    for (int i = 0; i < jumlahData; i++) {
        fprintf(file, "%d;%s;%d\n", daftar[i].kode, daftar[i].judul, daftar[i].jumlah);
    }
    fclose(file);
    cout << "Data berhasil disimpan ke file.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU STOK BUKU ===\n";
        cout << "1. Tambah Buku\n2. Tampilkan Buku\n3. Urutkan Judul A-Z\n4. Simpan ke File\n0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: tampilkanBuku(); break;
            case 3: urutkanJudul(); break;
            case 4: simpanKeFile(); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    return 0;
}
