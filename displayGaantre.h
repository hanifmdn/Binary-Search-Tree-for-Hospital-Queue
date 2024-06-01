#ifndef DISPLAYGAANTRE_H
#define DISPLAYGAANTRE_H

void displayAwal (int *display);
/*
digunakan untuk menampilkan tampilan awal program.
*/

void displaySignUp (int *display, bool *running);
/*
digunakan untuk menampilkan tampilan log in atau sign up.
*/

void displayBuatAkun (int *display);
/*
digunakan untuk menampilkan tampilan pembuatan akun baru bagi pengguna.
*/

void displayLogin (int *display, account *sedangLogin);
/*
digunakan untuk menampilkan tampilan login kepada pengguna baik itu user atau admin.
*/

void displayDaftarAdmin (address root, account *sedangLogin, int *display);
/*
Digunakan untuk menampilkan tampilan mendaftarkan oleh admin
*/

void displayMenuPengguna (int *display, int *noAntrian);
/*
Digunakan untuk menampilkan tampilan menu pengguna
*/

void displayMenuAdmin(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *noAntrian, address *root, char waktuBuka[], char waktuTutup[], bool *setTree, int maksPasien);
/*
Digunakan untuk menampilkan tampilan menu admin
*/

void displayPop(int *display, address *root, int *noAntrian);
/*
Digunakan untuk menampilkan tampilan menu saat melakukan pop
*/

void displayBangunAntrian(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup,address *root, char waktuBuka[6], char waktuTutup[6]);
/*
Digunakan untuk menampilkan urutan nama dan prioritas yang telah terurut
*/

void displayBukaTutupDaftar(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, address *root, char waktuBuka[6], char waktuTutup[6]);
/*
Digunakan untuk menampilkan tampilan penentuan jumlah pasien waktu buka dan waktu tutup
*/

void displayDaftarPengguna(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *maksPasien, address *root, account *sedangLogin, char waktuBuka[6], char waktuTutup[6]);
/*
Digunakan untuk menampilkan tampilan mendaftarkan oleh daftar pengguna 
*/

void displayAntrianPengguna(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, account *sedangLogin, bool setTree);
/*
Digunakan untuk menampilkan nomor antrian pengguna yang telah mendaftar
*/

void displayAkhir ();
/*
digunakan untuk menampilkan tampilan setelah memutuskan untuk keluar program.
*/

#endif
