#include <iostream>
#include <string>

using namespace std;

// struct mahasiswa{
//     int nim;
//     string nama;
//     int nilai;
// };

// //membuatkan deklarasi struct
// struct mahasiswa mhs;
// // atau
// mahasiswa mhs;

// typedef struct{
//     char nim;
//     string nama;
//     float nilai;
// } mahasiswa;

#define MAX_MAHASISWA 100
int panjang = 0; // Jumlah elemen saat ini
mahasiswa mhs[MAX_MAHASISWA];

struct Tanggal{
    int hari;
    int bulan;
    int tahun;            
};

struct mahasiswa{
    string nama;
    Tanggal tgl_lahir;
    int umur;
    string jurusan;
};

int main(){
    int pilihan, index;
    do {
        system("clear");
        cout << "Menu Program" << endl;
    cout << "1. Tampilkan Mahasiswa" << endl;
    cout << "2. Tambah Mahasiswa" << endl;
    cout << "3. Ubah Mahasiswa" << endl;
    cout << "4. Hapus Mahasiswa" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;
    switch (pilihan) {
        case 1:

        // Tampilkan Data Mahasiswa
        break;
        case 2:
        // Tambah Data Mahasiswa
        break;
        case 3:
        // Ubah Data Mahasiswa
        break;
        case 4:
        // Hapus Data Mahasiswa
        break;
        case 5:
        cout << "Program selesai" << endl;
        break;
        default:
        cout << "Pilihan tidak valid" << endl;
        break;
        }
    } 
    while (pilihan != 5);
    return 0;
}