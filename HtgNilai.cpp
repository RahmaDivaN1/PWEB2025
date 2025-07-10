#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Mahasiswa {
    string nim;
    string nama;
    int uts, uas;
    float nilaiAkhir;
    string status;
};

Mahasiswa data[MAX];
int jumlahData = 0;

void hitungNilaiDanStatus(Mahasiswa& mhs) {
    mhs.nilaiAkhir = (mhs.uts + mhs.uas) / 2.0;
    mhs.status = (mhs.nilaiAkhir >= 75) ? "Lulus" : "Tidak Lulus";
}

void bacaFile() {
    ifstream file("dataMhs.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka dataMhs.txt!\n";
        return;
    }

    while (file >> data[jumlahData].nim >> data[jumlahData].nama >> data[jumlahData].uts >> data[jumlahData].uas) {
        hitungNilaiDanStatus(data[jumlahData]);
        jumlahData++;
    }

    file.close();
    cout << "Data berhasil dibaca dari dataMhs.txt\n";
}

void tampilkanData() {
    cout << "\nData Mahasiswa:\n";
    cout << "------------------------------------------\n";
    cout << "NIM\tNama\tUTS\tUAS\tNA\tStatus\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << data[i].nim << "\t" << data[i].nama << "\t" << data[i].uts << "\t" << data[i].uas << "\t"
             << fixed << setprecision(2) << data[i].nilaiAkhir << "\t" << data[i].status << endl;
    }
}

void simpanNilaiAkhir() {
    ofstream file("nilaiakhir.txt");
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << " " << data[i].nama << " "
             << fixed << setprecision(2) << data[i].nilaiAkhir << endl;
    }
    file.close();
    cout << "Nilai akhir berhasil disimpan ke nilaiakhir.txt\n";
}

void simpanStatusLulus() {
    ofstream file("statuslulus.txt");
    for (int i = 0; i < jumlahData; i++) {
        file << data[i].nim << " " << data[i].nama << " " << data[i].status << endl;
    }
    file.close();
    cout << "Status lulus berhasil disimpan ke statuslulus.txt\n";
}

void bubbleSort(bool ascending = true) {
    for (int i = 0; i < jumlahData - 1; i++) {
        for (int j = 0; j < jumlahData - i - 1; j++) {
            bool kondisi = ascending ? data[j].nilaiAkhir > data[j + 1].nilaiAkhir
                                     : data[j].nilaiAkhir < data[j + 1].nilaiAkhir;
            if (kondisi) {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    cout << "Data berhasil diurutkan secara " << (ascending ? "ascending" : "descending") << ".\n";
}

void cariNama(string namaCari) {
    Mahasiswa hasil[MAX];
    int jmlHasil = 0;
    for (int i = 0; i < jumlahData; i++) {
        if (data[i].nama == namaCari) {
            hasil[jmlHasil++] = data[i];
        }
    }

    if (jmlHasil == 0) {
        cout << "Data dengan nama tersebut tidak ditemukan.\n";
        return;
    }

    for (int i = 0; i < jmlHasil - 1; i++) {
        for (int j = 0; j < jmlHasil - i - 1; j++) {
            if (hasil[j].nilaiAkhir < hasil[j + 1].nilaiAkhir) {
                swap(hasil[j], hasil[j + 1]);
            }
        }
    }

    cout << "\nData ditemukan dan diurutkan berdasarkan nilai akhir (terbesar -> terkecil):\n";
    cout << "NIM\tNama\tUTS\tUAS\tNA\tStatus\n";
    for (int i = 0; i < jmlHasil; i++) {
        cout << hasil[i].nim << "\t" << hasil[i].nama << "\t" << hasil[i].uts << "\t" << hasil[i].uas << "\t"
             << fixed << setprecision(2) << hasil[i].nilaiAkhir << "\t" << hasil[i].status << endl;
    }
}

int main() {
    int pilihan;
    string namaCari;

    bacaFile();
    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampilkan Data\n";
        cout << "2. Sorting Ascending\n";
        cout << "3. Sorting Descending\n";
        cout << "4. Cari Berdasarkan Nama\n";
        cout << "5. Simpan Nilai Akhir\n";
        cout << "6. Simpan Status Lulus\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilkanData(); break;
            case 2: bubbleSort(true); tampilkanData(); break;
            case 3: bubbleSort(false); tampilkanData(); break;
            case 4:
                cout << "Masukkan nama: ";
                cin >> namaCari;
                cariNama(namaCari);
                break;
            case 5: simpanNilaiAkhir(); break;
            case 6: simpanStatusLulus(); break;
            case 0: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
