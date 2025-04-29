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
int TipeSorting = 0;



int PartisiNama(string arr[], int low, int high, int indeks[]) {
    string pivot = arr[indeks[high]];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[indeks[j]] > pivot) { // Descending
            i++;
            swap(indeks[i], indeks[j]);
        }
    }
    swap(indeks[i + 1], indeks[high]);
    return i + 1;
}

void QuickSortNama(string arr[], int low, int high, int indeks[]) {
    if (low < high) {
        int pi = PartisiNama(arr, low, high, indeks);
        QuickSortNama(arr, low, pi - 1, indeks);
        QuickSortNama(arr, pi + 1, high, indeks);
    }
}

void BubbleSortHarga(int harga[], int indeks[], int n){ // secara ascending
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (harga[j] > harga[j + 1]){
                swap(harga[j], harga[j + 1]);
                swap(indeks[j], indeks[j + 1]);
            }
        }
    }
}

void BubbleSortStok(int stok[], int indeks[], int n){ //secara descending
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (stok[j] < stok[j + 1]){
                swap(stok[j], stok[j + 1]);
                swap(indeks[j], indeks[j + 1]);
            }
        }
    }
}

void tampilkanData(DataHotwheels* DH) {
    if (DH->jumlah == 0) {
        cout << "Belum ada data Hot Wheels." << endl;
        return;
    }

    int indeks[100];
    for (int i = 0; i < DH->jumlah; i++) indeks[i] = i;

    if (TipeSorting == 1) { // nama descending
        QuickSortNama(DH->nama_hotwheels, 0, DH->jumlah - 1, indeks);
    } else if (TipeSorting == 2) { // harga ascending
        int temp[100];
        for (int i = 0; i < DH->jumlah; i++) temp[i] = DH->harga[i];
        BubbleSortHarga(temp, indeks, DH->jumlah);
    } else if (TipeSorting == 3) { // stok descending
        int temp[100];
        for (int i = 0; i < DH->jumlah; i++) temp[i] = DH->stok[i];
        BubbleSortStok(temp, indeks, DH->jumlah);
    }

    cout << "\nDaftar HotWheels:\n";
    cout << left << setw(5) << "No."
        << setw(20) << "Nama"
        << setw(15) << "Seri"
        << setw(15) << "Tahun Rilis"
        << setw(10) << "Harga"
        << setw(10) << "Stok" << endl;
    cout << string(70, '-') << endl;

    for (int i = 0; i < DH->jumlah; i++) {
        int idx = (TipeSorting == 0) ? i : indeks[i];
        cout << left << setw(5) << i + 1
            << setw(20) << DH->nama_hotwheels[idx]
            << setw(15) << DH->seri[idx]
            << setw(15) << DH->tahun_rilis[idx]
            << setw(10) << DH->harga[idx]
            << setw(10) << DH->stok[idx] << endl;
    }
}

void menuSorting(DataHotwheels* DH) {
    cout << "\n===== Menu Sorting HotWheels =====\n";
    cout << "1. Urutkan berdasarkan Nama (Z-A)\n";
    cout << "2. Urutkan berdasarkan Harga (terendah ke tertinggi)\n";
    cout << "3. Urutkan berdasarkan Stok (terbanyak ke tersedikit)\n";
    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    int pilihan;
    cin >> pilihan;

    switch (pilihan) {
        case 1: TipeSorting = 1; break;
        case 2: TipeSorting = 2; break;
        case 3: TipeSorting = 3; break;
        case 0: return;
        default: cout << "(x) Pilihan tidak valid!" << endl; return;
    }
    cout << "\nData berhasil disorting!\n";
    tampilkanData(DH);
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
        cout << "|0. Urutan Hotwheels                   |" << endl;
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
        if (pilihan == 0) {
            menuSorting(&DH);
        }
        else if (pilihan == 1) {
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
        cout << "|2. Urutan Data HotWheels              |" << endl;
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
        else if (pilihan == 3) {
            menuSorting(&DH);
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