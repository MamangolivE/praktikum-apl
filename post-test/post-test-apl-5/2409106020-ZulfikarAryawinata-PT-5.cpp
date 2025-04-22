#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct DataUser {
    string user[100] = {};
    string password[100] = {};
    string Nama[1] = {"Zulfikar Aryawinata"};
    string NIM[1] = {"2409106020"};
};

struct DataHotwheels {
    string nama_hotwheels[100] = {"Bone Shaker", "Twin Mill", "Deora II", "Rip Rod", "Rodger Dodger", "Night Shifter"};
    string seri[100] = {"Hot Rods", "Legends", "Surf", "Concept", "Muscle", "Street"};
    int tahun_rilis[100] = {2006, 1969, 2000, 2014, 1974, 2018};
    int harga[100] = {50000, 1200000, 75000, 25000, 200000, 25000};
    int stok[100] = {12, 2, 13, 90, 5, 120};
    int jumlah = 6;
};

DataUser DU;
DataHotwheels DH;

void tampilkanData(DataHotwheels* DH) {
    if (DH->jumlah == 0) {
        cout << "Belum ada data Hot Wheels." << endl;
        return;
    }
    else {
        cout << endl;
        cout << "Daftar HotWheels:";
        cout << endl;
        cout << left << setw(5) << "No."
            << setw(20) << "Nama" 
            << setw(15) << "Seri" 
            << setw(15) << "Tahun Rilis" 
            << setw(10) << "Harga" 
            << setw(10) << "Stok" << endl;
        cout << string(70, '-') << endl;
        cout << string(65, '-') << endl;
        for (int i = 0; i < DH->jumlah; i++) {
            cout << left << setw(5) << i+1
                << setw(20) << DH->nama_hotwheels[i] 
                << setw(15) << DH->seri[i] 
                << setw(15) << DH->tahun_rilis[i] 
                << setw(10) << fixed << setprecision(2) << DH->harga[i] 
                << setw(10) << DH->stok[i] << endl;
        }
    }
}

void tambahData(DataHotwheels* DH) {
    if (DH->jumlah >= 100) {
        cout << "(X)Data penuh! Tidak bisa menambahkan lagi." << endl;
        return;
    }
    else {
        cin.ignore();
        cout << endl;
        cout << "<=>|Masukkan Nama HotWheels : "; getline(cin, DH->nama_hotwheels[DH->jumlah]);
        cout << "<=>|Masukkan Seri : "; getline(cin, DH->seri[DH->jumlah]);
        cout << "<=>|Masukkan Tahun Rilis : "; cin >> DH->tahun_rilis[DH->jumlah];
        cout << "<=>|Masukkan Harga : "; cin >> DH->harga[DH->jumlah];
        cout << "<=>|Masukkan jumlah stok masuk :"; cin >> DH->stok[DH->jumlah];
        cout << endl;
        DH->jumlah++;
        cout << "==Data Berhasil Ditambahkan!==" << endl;
    }
}

void editData(DataHotwheels* DH) {
    tampilkanData(*&DH);
    int urutan_hotwheels;
    cout << endl << "Masukkan Urutan HotWheels pada tabel yang ingin diubah datanya : ";
    cin >> urutan_hotwheels;
    cout << endl;
    if (DH->jumlah >= urutan_hotwheels) {
        if (DH->jumlah == 0) {
            cout << endl;
            cout << "Belum ada data Hot Wheels." << endl;
        }
        else if (urutan_hotwheels < 1){
            cout << endl << "Nomor Tidak Valid!!!" << endl;
        }
        else {
            cout << "Data ditemukan. Masukkan data baru:" << endl;
            cout << "<=>|Masukkan Harga Baru : "; cin >> DH->harga[urutan_hotwheels - 1];
            cout << "<=>|Masukkan Stok Baru :"; cin >> DH->stok[urutan_hotwheels - 1];
            cout << endl;
            cout << "|==|Data berhasil diperbarui!";
            cout << endl;
        }
    }
    else{
        cout << "(X)Data Tidak Ditemukan" << endl;
        cout << endl;
    }
}

void hapusData(DataHotwheels* DH) {
    tampilkanData(*&DH);
    int urutan;
    cout << endl;
    cout << "<=>|Masukkan Urutan HotWheels pada tabel yang ingin dihapus : ";
    cin >> urutan;
    if (urutan > 0 && urutan <= DH->jumlah){
        for (int i = urutan - 1; i < DH->jumlah; i++){
            DH->nama_hotwheels[i] = DH->nama_hotwheels[i + 1];
            DH->seri[i] = DH->seri[i + 1];
            DH->tahun_rilis[i] = DH->tahun_rilis[i + 1];
            DH->harga[i] = DH->harga[i + 1];
            DH->stok[i] = DH->stok[i + 1];
            DH->jumlah--;
            cout << endl;
            cout << "|==|Data Berhasil Dihapus|==|" << endl;
            break;
        }
    }
    else if (urutan < 1){
        cout << endl << "Nomor Tidak Valid!!!" << endl;
    }
    else{
        cout << endl;
        cout << "==Data Tidak Ditemukan==";
    }
}

void pesanHotwheels(DataHotwheels* DH) {
    tampilkanData(*&DH);
    int pesan;
    int jumlah_pesan;
    cout << endl;
    cout << "Masukkan Urutan HotWheels yang ingin dipesan : ";
    cin >> pesan;
    if (pesan <= DH->jumlah){
        cout << endl;
        cout << "HotWheels yang ingin dipesan : " << DH->nama_hotwheels[pesan-1] << endl;
        cout << "Seri : " << DH->seri[pesan-1] << endl;
        cout << "Tahun Rilis : " << DH->tahun_rilis[pesan-1] << endl;
        cout << "Harga : " << DH->harga[pesan-1] << endl;
        cout << "Stok : " << DH->stok[pesan-1] << endl;
        cout << "Jumlah Pesanan : ";
        cin >> jumlah_pesan;
        if (jumlah_pesan <= DH->stok[pesan-1]){
            cout << endl;
            cout << "Pesanan : " << endl;
            cout << DH->nama_hotwheels[pesan-1] << endl;
            cout << jumlah_pesan << " Buah" << endl;
            cout << "Rp." << DH->harga[pesan-1]*jumlah_pesan << endl;
            DH->stok[pesan-1]-=jumlah_pesan;
        }
        else{
            cout << endl;
            cout << "Jumlah Pesanan Melebihi Stok.";
        }
    }
    else{
    cout << endl;
    cout << "(x)Data Tidak Ditemukan";
    cout << endl;
    }
}

void loginAdmin(string &nama, string &nim, DataUser* DU) {
    cout << "______________________________________" << endl;
    cout << "|Masukkan Nama : ";
    getline(cin, nama);
    cout << "|Masukkan NIM : ";
    cin >> nim;
    cout << "======================================" << endl;
}

void loginUser(string &username, string &pw, DataUser* DU) {
    cout << endl << "______________________________________" << endl;
    cout << "|Masukkan username : ";
    getline(cin, username);
    cout << "|Masukkan password : ";
    getline(cin, pw);
    cout << "======================================" << endl;
}

int menuAdmin() {
    while (true) {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|=== Manajemen Penjualan Hot Wheels ===|" << endl;
        cout << "|1. Tampilkan Data                     |" << endl;
        cout << "|2. Tambah Data                        |" << endl;
        cout << "|3. Edit Data                          |" << endl;
        cout << "|4. Hapus Data                         |" << endl;
        cout << "========================================" << endl;
        cout << "|5. Keluar Program                     |" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Pilih menu (1-5) : ";
        int pilihan;
        cin >> pilihan;
        if (pilihan == 1) {
            tampilkanData(&DH);
        }
        else if (pilihan == 2) {
            tambahData(&DH);
        }
        else if (pilihan == 3) {
            editData(&DH);
        }
        else if (pilihan == 4) {
            hapusData(&DH);
        }
        else if (pilihan == 5) {
            cout << endl << "=|Keluar Dari Program|=" << endl; cout << endl;
            return 0;
        }
    }
}

int menuUSer() {
    while (true) {
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|=== Manajemen Penjualan Hot Wheels ===|" << endl;
        cout << "|1. Tampilkan Daftar HotWheels         |" << endl;
        cout << "|2. Pesan HotWheels                    |" << endl;
        cout << "========================================" << endl;
        cout << "|0. Keluar Program                     |" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << "Pilih menu (1/0) : ";
        int pilihan;
        cin >> pilihan;
        if (pilihan == 1) {
            tampilkanData(&DH);
        }
        else if (pilihan == 2) {
            pesanHotwheels(&DH);
        }
        else if (pilihan == 0) {
            cout << endl << "Keluar Dari Program";
            return 0;
        }
    }
}

int main() {
    int pilihan;
    cout << "=====Menu Login=====" << endl;
    cout << "|1. Login Admin    |" << endl;
    cout << "|2. Login User     |" << endl;
    cout << "====================" << endl;
    cout << "0. Close" << endl;
    cout << "Pilihan :";
    cin >> pilihan;
    cin.ignore();
    if (pilihan == 1) {
        string nama, nim;
        int percobaan = 3;
        while (percobaan > 0) {
            loginAdmin(nama, nim, &DU);
            if (nim == DU.NIM[0] && nama == DU.Nama[0]) {
                cout << endl;
                cout << "===Selamat datang!===" << endl;
                menuAdmin();
                break;
            }
            else {
                percobaan--;
                cout << "!Login Gagal!" << endl; cout << "NIM atau Nama salah!" << endl;
                cin.ignore();
            }
            if (percobaan == 0) {
                cout << endl;
                cout << "(X)Melewati Batas Percobaan. Program Berhenti." << endl;
                return 0;
            }
        }
    }
    else if (pilihan == 2) {
        while (true) {
            cout << "=============" << endl;
            cout << "|1. Regis   |" << endl;
            cout << "|2. Login   |" << endl;
            cout << "=============" << endl;
            cout << "|0. Keluar  |" << endl;
            cout << "=============" << endl;
            int pilihan;
            cout << "Pilihan (1/2/0) : ";
            cin >> pilihan;
            cin.ignore();
            if (pilihan == 1) {
                int i;
                for (i = 0; i <= 100; i++){
                    cout << endl << "______________________________________" << endl;
                    cout << "|Masukkan username : ";
                    getline(cin, DU.user[i]);
                    cout << "|Masukkan password : ";
                    getline(cin, DU.password[i]);
                    cout << "======================================" << endl;
                    break;
                }
            }
            else if (pilihan == 2) {
                string username;
                string pw;
                int percobaan = 300;
                while (percobaan > 0){
                    loginUser(username, pw, &DU);
                    int i;
                    for (i = 0; i <= 100; i++){
                        if (username == DU.user[i] && pw == DU.password[i]){
                            cout << endl;
                            cout << "===Selamat datang!===" << endl;
                            menuUSer();
                            return 0;
                        }
                        else {
                            percobaan--;
                        } 
                        if (percobaan == 0){
                            cout << endl;
                            cout << "(X) Melewati batas percobaan." << endl;
                            break;
                        }
                    }    
                }
            }
            else if (pilihan == 0) {
                cout << endl;
                cout << "===Keluar Dari Program===";
                return 0;
            }
            else {
                cout << endl << "(x)Pilihan Tidak Valid" << endl;
            }
        }
    }
    else if (pilihan == 0){
        cout << endl;
        cout << "===Program Ditutup===";
        return 0;
    }
}