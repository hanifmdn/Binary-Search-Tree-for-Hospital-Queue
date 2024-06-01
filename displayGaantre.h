#ifndef DISPLAYGAANTRE_H
#define DISPLAYGAANTRE_H

void displayAwal (int *display);
/*
digunakan untuk menampilkan tampilan awal program.
IS: Program belum ditampilkan ke layar.
FS: Program ditampilkan ke layar.
*/

void displaySignUp (int *display, bool *running);
/*
digunakan untuk menampilkan tampilan sign up.
IS: Tidak ada tampilan sign up yang ditampilkan.
FS: Tampilan sign up ditampilkan.
*/

void displayBuatAkun (int *display);
/*
digunakan untuk menampilkan tampilan pembuatan akun baru.
IS: Tidak ada tampilan pembuatan akun yang ditampilkan.
FS: Tampilan pembuatan akun baru ditampilkan kepada pengguna.
*/

void displayLogin (int *display, account *sedangLogin);
/*
digunakan untuk menampilkan tampilan login kepada pengguna .
IS: Tidak ada tampilan login yang ditampilkan.
FS: Tampilan login ditampilkan kepada pengguna atau admin berdasarkan login.
*/

void displayDaftarAdmin (address root, account *sedangLogin, int *display);
/*

*/

void displayMenuPengguna (int *display, int *noAntrian);
/*

*/

void displayAkhir ();
/*
digunakan untuk menampilkan tampilan keluar program.
IS: Tampilan keluar program belum ditampilkan ke layar.
FS: Tampilan keluar program ditampilkan ke layar.
*/

void displayMenuAdmin(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *noAntrian, address *root, char waktuBuka[6], char waktuTutup[6]);
/*

*/

void displayDaftarPengguna(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *maksPasien, address *root, account *sedangLogin, char waktuBuka[6], char waktuTutup[6]);
/*

*/

void displayMenuAntrianSekarang(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, account *sedangLogin);
/*

*/

#endif
