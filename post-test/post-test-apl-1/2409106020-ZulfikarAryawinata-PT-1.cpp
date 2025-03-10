#include <iostream>
using namespace std;

int main(){
    float meter,cm,mile,foot;
    int pilihan,coba;
    long long int NIM,NIM_login;
    string nama,nama_login;

    while(true){
        cout << "=====|Selamat Datang|=====" << endl;
        cout << "1. Registrasi" << endl;
        cout << "2. Masuk" << endl;
        cout << "==========================" << endl; cout << "0. Close" << endl; cout << "Pilihan : ";
        cin >> pilihan; cout << endl; cin.ignore();
        if (pilihan == 1){
            cout << "==========|Menu Registrasi|==========" << endl;
            cout << "Nama Lengkap : ";
            getline(cin, nama);
            cout << "NIM : ";
            cin >> NIM;
            cout << "======|Data Berhasil Disimpan|======="; cout << endl; cout << endl;
        }
        else if (pilihan == 2){
            coba = 0;
            while(coba < 3){
                cout << "=====|Login Akun|=====" << endl;
                cout << "Nama : ";
                getline(cin, nama_login);
                cout << "NIM : ";
                cin >> NIM_login; cout << endl;
                if (nama_login == nama && NIM_login == NIM){
                    cout << "==|Login Berhasil|==" << endl << endl;
                    while(coba < 3){
                        cout << "==|Menu Konversi Ukuran Panjang|=======" << endl;
                        cout << "1. Konversi Meter Ke: cm, Mil, dan Kaki" << endl;
                        cout << "2. Konversi cm Ke: Meter, MIl, dan Kaki" << endl;
                        cout << "3. Konversi Mil ke: Meter, cm, dan Kaki" << endl;
                        cout << "4. Konversi Kaki ke: Meter, cm, dan Mil" << endl;
                        cout << "========================================" << endl; cout << "5. Exit" << endl; cout << endl;
                        cout << "Pilihan : ";
                        cin >> pilihan; cout << endl;
                        if (pilihan == 1){
                            cout << "Masukkan Angka : "; cin >> meter; cout << endl;
                            cout << meter << " Meter =" << endl << endl;
                            cout << meter * 100; cout << " cm" << endl;
                            cout << meter * 0.000621371; cout << " Mil" << endl;
                            cout << meter * 3.28084; cout << " Kaki" << endl << endl;
                        }
                        else if (pilihan == 2){
                            cout << "Masukkan Angka : "; cin >> cm; cout << endl;
                            cout << cm << " cm =" << endl << endl;
                            cout << cm / 100; cout << " Meter" << endl;
                            cout << cm / 160934; cout << " Mil" << endl;
                            cout << cm / 30.48; cout << " Kaki" << endl << endl;
                        }
                        else if (pilihan == 3){
                            cout << "Masukkan Angka : "; cin >> mile; cout << endl;
                            cout << mile << " Mil =" << endl << endl;
                            cout << mile * 1609.34; cout << " Meter" << endl;
                            cout << mile * 160934; cout << " cm" << endl;
                            cout << mile * 5280; cout << " Kaki" << endl << endl;
                        }
                        else if (pilihan == 4){
                            cout << "Masukkan Angka : "; cin >> foot; cout << endl;
                            cout << foot << " Kaki =" << endl << endl;
                            cout << foot * 0.3048; cout << " Meter" << endl;
                            cout << foot * 30.48; cout << " cm" << endl;
                            cout << foot / 5280; cout << " Mil" << endl << endl;
                        }
                        else if (pilihan == 5){
                            coba += 3;
                            break;
                        }
                    }
                }
                else{
                    coba++;
                    cout << "===|Login Gagal|===" << endl << endl;
                    if (coba == 3){
                        cout << "==|Anda telah melebihi batas percobaan. Kembali ke menu utama|==" << endl << endl;
                    }
                }
                cin.ignore();
            }
        }
        else if (pilihan == 0){
            cout << "=====|Program Ditutup|=====";
            break;
        }
        else{
            cout << "===|Pilihan Tidak Valid|===" << endl << endl;
        }
    }
}