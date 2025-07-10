#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Penerbangan {
    char nama[50], maskapai[30], asal[30], tujuan[30];
    char kode[10], jamBerangkat[10], jamPulang[10], tanggal[15];
    float harga;
};

Penerbangan daftar[MAX];
int jumlahData = 0;

void tambahData() {
    cin.ignore();
    cout << "Nama Penumpang       : "; cin.getline(daftar[jumlahData].nama, 50);
    cout << "Maskapai             : "; cin.getline(daftar[jumlahData].maskapai, 30);
    cout << "Asal                 : "; cin.getline(daftar[jumlahData].asal, 30);
    cout << "Tujuan               : "; cin.getline(daftar[jumlahData].tujuan, 30);
    cout << "Kode Penerbangan     : "; cin.getline(daftar[jumlahData].kode, 10);
    cout << "Jam Berangkat        : "; cin.getline(daftar[jumlahData].jamBerangkat, 10);
    cout << "Jam Pulang           : "; cin.getline(daftar[jumlahData].jamPulang, 10);
    cout << "Tanggal              : "; cin.getline(daftar[jumlahData].tanggal, 15);
    cout << "Harga                : Rp "; cin >> daftar[jumlahData].harga;
    jumlahData++;
}

void tampilkan() {
    for (int i = 0; i < jumlahData; i++) {
        cout << "\nPenumpang: " << daftar[i].nama
             << "\nMaskapai : " << daftar[i].maskapai
             << "\nRute     : " << daftar[i].asal << " ? " << daftar[i].tujuan
             << "\nKode     : " << daftar[i].kode
             << "\nJadwal   : " << daftar[i].jamBerangkat << " - " << daftar[i].jamPulang
             << "\nTanggal  : " << daftar[i].tanggal
             << "\nHarga    : Rp " << daftar[i].harga << endl;
    }
}

void updateData() {
    cin.ignore();
    char cari[50];
    cout << "Masukkan nama penumpang yang ingin diupdate: ";
    cin.getline(cari, 50);

    for (int i = 0; i < jumlahData; i++) {
        if (strcmp(cari, daftar[i].nama) == 0) {
            cout << "Update data untuk " << daftar[i].nama << endl;
            tambahData(); // Ganti dengan input ulang
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void hapusData() {
    cin.ignore();
    char hapus[50];
    cout << "Masukkan nama penumpang yang ingin dihapus: ";
    cin.getline(hapus, 50);

    for (int i = 0; i < jumlahData; i++) {
        if (strcmp(hapus, daftar[i].nama) == 0) {
            for (int j = i; j < jumlahData - 1; j++) {
                daftar[j] = daftar[j + 1];
            }
            jumlahData--;
            cout << "Data berhasil dihapus.\n";
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void simpanKeFile() {
    FILE* file = fopen("data_penerbangan.txt", "w");
    for (int i = 0; i < jumlahData; i++) {
        fprintf(file, "Penumpang: %s | Maskapai: %s | Rute: %s - %s\n",
                daftar[i].nama, daftar[i].maskapai, daftar[i].asal, daftar[i].tujuan);
    }
    fclose(file);
    cout << "Data berhasil disimpan ke file.\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU PENERBANGAN ===\n";
        cout << "1. Tambah Data\n2. Tampilkan\n3. Update\n4. Hapus\n5. Simpan\n0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkan(); break;
            case 3: updateData(); break;
            case 4: hapusData(); break;
            case 5: simpanKeFile(); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
