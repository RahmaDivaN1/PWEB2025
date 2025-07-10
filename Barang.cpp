#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Barang {
    int id;
    char nama[50];
    int jumlah;
    float harga;
};

Barang daftar[MAX];
int jumlahData = 0;

void tambahBarang() {
    cout << "ID Barang     : ";
    cin >> daftar[jumlahData].id;
    cin.ignore();
    cout << "Nama Barang   : ";
    cin.getline(daftar[jumlahData].nama, 50);
    cout << "Jumlah Barang : ";
    cin >> daftar[jumlahData].jumlah;
    cout << "Harga Barang  : ";
    cin >> daftar[jumlahData].harga;
    jumlahData++;
}

void tampilkanBarang() {
    for (int i = 0; i < jumlahData; i++) {
        cout << "\nBarang ke-" << i + 1 << endl;
        cout << "ID     : " << daftar[i].id << endl;
        cout << "Nama   : " << daftar[i].nama << endl;
        cout << "Jumlah : " << daftar[i].jumlah << endl;
        cout << "Harga  : Rp " << daftar[i].harga << endl;
        cout << "Subtotal: Rp " << (daftar[i].jumlah * daftar[i].harga) << endl;
    }
}

void updateBarang() {
    int idCari;
    cout << "Masukkan ID barang yang ingin diupdate: ";
    cin >> idCari;
    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].id == idCari) {
            cout << "Data lama ditemukan. Masukkan data baru:\n";
            cin.ignore();
            cout << "Nama Barang   : ";
            cin.getline(daftar[i].nama, 50);
            cout << "Jumlah Barang : ";
            cin >> daftar[i].jumlah;
            cout << "Harga Barang  : ";
            cin >> daftar[i].harga;
            return;
        }
    }
    cout << "Data tidak ditemukan.\n";
}

void hapusBarang() {
    int idHapus;
    cout << "Masukkan ID barang yang ingin dihapus: ";
    cin >> idHapus;
    for (int i = 0; i < jumlahData; i++) {
        if (daftar[i].id == idHapus) {
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

void cariBarang() {
    cin.ignore();
    char cari[50];
    cout << "Masukkan nama barang yang dicari: ";
    cin.getline(cari, 50);
    bool ditemukan = false;
    for (int i = 0; i < jumlahData; i++) {
        if (strcmp(daftar[i].nama, cari) == 0) {
            cout << "\nDitemukan:\n";
            cout << "ID     : " << daftar[i].id << endl;
            cout << "Nama   : " << daftar[i].nama << endl;
            cout << "Jumlah : " << daftar[i].jumlah << endl;
            cout << "Harga  : Rp " << daftar[i].harga << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Data tidak ditemukan.\n";
}

void urutkanBarang() {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            if (strcmp(daftar[j].nama, daftar[j + 1].nama) > 0) {
                Barang temp = daftar[j];
                daftar[j] = daftar[j + 1];
                daftar[j + 1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan berdasarkan nama (A-Z).\n";
}

void totalPendapatan() {
    float total = 0;
    for (int i = 0; i < jumlahData; i++) {
        total += daftar[i].jumlah * daftar[i].harga;
    }
    cout << "Total Pendapatan: Rp " << total << endl;
}

void simpanKeFile() {
    FILE* file = fopen("penjualan.txt", "w");
    if (file == NULL) {
        cout << "Gagal membuka file.\n";
        return;
    }
    for (int i = 0; i < jumlahData; i++) {
        fprintf(file, "%d;%s;%d;%.2f\n", daftar[i].id, daftar[i].nama, daftar[i].jumlah, daftar[i].harga);
    }
    fclose(file);
    cout << "Data berhasil disimpan ke penjualan.txt\n";
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU PENJUALAN BARANG ===\n";
        cout << "1. Tambah Barang\n2. Tampilkan Semua\n3. Update Barang\n4. Hapus Barang\n";
        cout << "5. Cari Barang\n6. Urutkan Nama Barang\n7. Total Pendapatan\n8. Simpan ke File\n0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBarang(); break;
            case 2: tampilkanBarang(); break;
            case 3: updateBarang(); break;
            case 4: hapusBarang(); break;
            case 5: cariBarang(); break;
            case 6: urutkanBarang(); break;
            case 7: totalPendapatan(); break;
            case 8: simpanKeFile(); break;
            case 0: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 0);
    return 0;
}
