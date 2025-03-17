#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string Nama[1] = {"Zulfikar Aryawinata"};
string NIM[1] = {"2409106020"};
string nama_hotwheels[100] = {"Bone Shaker", "Twin Mill", "Deora II", "Rip Rod", "Rodger Dodger", "Night Shifter"};
string seri[100] = {"Hot Rods", "Legends", "Surf", "Concept", "Muscle", "Street"};
int tahun_rilis[100] = {2006, 1969, 2000, 2014, 1974, 2018};
int harga[100] = {50000, 1200000, 75000, 25000, 200000, 25000};
int stok[100] = {12, 2, 13, 90, 5, 120};
int jumlah = 6;

int main() {
    string nim, username;
    int percobaan = 3;
    while (percobaan > 0) {
        cout << "______________________________________" << endl;
        cout << "|Masukkan Nama : ";
        getline(cin, username);
        cout << "|Masukkan NIM : ";
        cin >> nim;
        cout << "======================================" << endl;
        if (nim == NIM[0] && username == Nama[0]) {
            cout << endl;
            cout << "===Selamat datang!===" << endl;
            break;
        } else {
            percobaan--;
            cout << "!Login Gagal!" << endl; cout << "NIM atau Nama salah!" << endl;
        }
        if (percobaan == 0) {
            cout << endl;
            cout << "(X)Melewati Batas Percobaan. Program Berhenti." << endl;
            return 0;
        }
        cin.ignore();
    }

    while (true) {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|=== Manajemen Penjualan Hot Wheels ===|" << endl;
        cout << "|1. Tampilkan Data                     |" << endl;
        cout << "|2. Tambah Data                        |" << endl;
        cout << "|3. Edit Data                          |" << endl;
        cout << "|4. Hapus Data                         |" << endl;
        cout << "=======================================|" << endl;
        cout << "|5. Keluar                             |" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Pilih menu (1-5) : ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (jumlah == 0) {
                cout << endl;
                cout << "Belum ada data Hot Wheels." << endl;
            } else {
                cout << endl;
                cout << "Daftar HotWheels:";
                cout << endl;
                cout << left << setw(20) << "Nama" 
                     << setw(15) << "Seri" 
                     << setw(15) << "Tahun Rilis" 
                     << setw(10) << "Harga(Rp)" 
                     << setw(10) << "Stok" << endl;
                cout << string(70, '-') << endl;
                cout << string(65, '-') << endl;
                for (int i = 0; i < jumlah; i++) {
                    cout << left << setw(20) << nama_hotwheels[i] 
                         << setw(15) << seri[i] 
                         << setw(15) << tahun_rilis[i] 
                         << setw(10) << fixed << setprecision(2) << harga[i] 
                         << setw(10) << stok[i] << endl;
                }
            }
        } else if (pilihan == 2) {
            if (jumlah >= 100) {
                cout << "(X)Data penuh! Tidak bisa menambahkan lagi." << endl;
            } else {
                cout << endl;
                cout << "<=>|Masukkan Nama HotWheels : "; getline(cin, nama_hotwheels[jumlah]);
                cout << "<=>|Masukkan Seri : "; getline(cin, seri[jumlah]);
                cout << "<=>|Masukkan Tahun Rilis : "; cin >> tahun_rilis[jumlah];
                cout << "<=>|Masukkan Harga : "; cin >> harga[jumlah];
                cout << "<=>|Masukkan jumlah stok masuk :"; cin >> stok[jumlah];
                cout << endl;
                jumlah++;
                cout << "==Data Berhasil Ditambahkan!==" << endl;
                cin.ignore();
            }
        } else if (pilihan == 3) {
            string nama_hotwheels_edit;
            cout << "Masukkan Nama HotWheels yang ingin diubah datanya : ";
            getline(cin, nama_hotwheels_edit);
            cout << endl;
            for (int i = 0; i < jumlah; i++) {
                if (nama_hotwheels[i] == nama_hotwheels_edit) {
                    cout << "Data ditemukan. Masukkan data baru:" << endl;
                    cout << "<=>|Masukkan Harga Baru : "; cin >> harga[i];
                    cout << "<=>|Masukkan Stok Baru :"; cin >> stok[i];
                    cout << endl;
                    cout << "|==|Data berhasil diperbarui!";
                    cout << endl;
                    break;
                }
                else{
                    cout << "(X)Data Tidak Ditemukan" << endl;
                    cout << endl;
                }
            }
        } else if (pilihan == 4) {
            string nama_hotwheels_hapus;
            cout << endl;
            cout << "<=>|Masukkan Nama HotWheels yang ingin dihapus : ";
            getline(cin, nama_hotwheels_hapus);
            for (int i = 0; i < jumlah; i++) {
                if (nama_hotwheels[i] == nama_hotwheels_hapus) {
                    for (int j = i; j < jumlah - 1; j++) {
                        nama_hotwheels[j] = nama_hotwheels[j + 1];
                        seri[j] = seri[j + 1];
                        tahun_rilis[j] = tahun_rilis[j + 1];
                        harga[j] = harga[j + 1];
                        stok[j] = stok[j + 1];
                    }
                    jumlah--;
                    cout << endl;
                    cout << "|==|Data Berhasil Dihapus|==|" << endl;
                    break;
                }
                else{
                    cout << endl;
                    cout << "==Data Tidak Ditemukan==";
                }
            }
        } else if (pilihan == 5) {
            cout << endl;
            cout << "==Program Ditutup==" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid!" << endl;;
        }
    }
    return 0;
}
