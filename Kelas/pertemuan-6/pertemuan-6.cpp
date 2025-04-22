#include <iostream>
using namespace std;
string buku[4] = {"Kamus", "Novel", "Rahasia Cepat Kaya", "Cerita Seram"};
int harga[4] = {15000, 35000, 70000, 1000};
int n = sizeof(harga)/sizeof(harga[0]);
// BUBBLE SORT
// void bubbleSort () {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < (n-i-1); j++) {
//             if(arr[j] > arr[j+1]) {
//                 // Menukar elemen jika elemen sebelumnya lebih besar
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//         // Menampilkan proses sorting pada setiap iterasi
//         cout << endl << endl;
//         cout << "Proses [" << i + 1 << "] :";
//         for (int k = 0; k < n; k++) {
//         cout << " " << arr[k];
//         }
//     }
// }
// int main() {
//     // Menampilkan data sebelum dilakukan sorting
//     cout << "Data sebelum diurutkan: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i]<< " ";
//     }
//     bubbleSort();
//     // Menampilkan data setelah dilakukan sorting
//     cout << endl << "Data sesudah diurutkan: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " " ;
//     }
//     return 0;
// }

//QUICK SORT STUDI KASUS
// void quickSort(int harga[], int low, int high) {
//     if (low >= high) return;
//         // menentukan data tengah sebagai pivot
//         int mid = low + (high - low) / 2;
//         int pivot = harga[mid];
//         int i = low, j = high;
//     while (i <= j) {
//         while (harga[i] < pivot) {
//             i++;
//         }
//         while (harga[j] > pivot) {
//             j--;
//         }
//         if (i <= j) { // Tukar elemen jika berada di posisi yang salah
//             swap(harga[i], harga[j]);
//             i++;
//             j--;
//         }
//     }
//     // Rekursi untuk bagian kiri dan kanan array
//     if (low < j) {
//         quickSort(harga, low, j);
//     }
//     if (i < high) {
//         quickSort(harga, i, high);
//     }
// }
// int main() {
//     cout << "Data Belum Terurut: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << buku[i] << " " << harga[i] << endl;
//     }
//     quickSort(harga, 0, n - 1);
//     cout << endl << "Hasil Quick Sort: " << endl;
//     for (int i = 0; i < n; i++) {
//         cout << buku[i] << " " << harga[i] << endl;
//     }
//     return 0;
// }