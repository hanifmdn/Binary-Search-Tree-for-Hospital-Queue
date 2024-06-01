#ifndef VALIDGAANTRE_H
#define VALIDGAANTRE_H

bool waktuPendaftaran(int jamBuka, int menitBuka, int jamTutup, int menitTutup);
/* 
Digunakan untuk mengetahui waktu pendaftaran sedang dibuka atau tidak.
IS : tidak diketahui apakah sekarang sedang waktu pendaftaran atau tidak.
FS :  mengembalikan boolean apakah sekarang sedang waktu daftar atau tidak.
*/

bool cariUsername (FILE *dataAkun, char namaCari[]);
/*
Digunakan untuk mencari apakah username yang di masukan oleh pengguna ada di file atau tidak
IS : username ada atau tidaknya tidak diketahui
FS :  mengembalikan boolean apakah username ada atau tidak
*/

bool cariAkun (FILE *dataAkun, account *cek, char cariUsername[]);
/*
Digunakan untuk menentukan akun pengguna apakah ada di file atau tidak saat ingin login
IS : tidak diketahui sudah ada akun pengguna atau belum
FS : mengembalikan boolean apakah ada atau tidaknya akun pengguna tersebut
*/

bool cekNoTelp(char *noTelp);
/*
Digunakan untuk memvalidasi nomor telepon berdasarkan nomor telepon yang sebenarnya yang ada di Indonesia
IS : nomor telepon belum di validasi
FS : mengembalikan true jika nomor telepon benar.
*/

bool cekTodayList (char namaCari[]);
/*
Digunakan untuk mengecek apakah pengguna dengan username tersebut sudah mendaftar di hari ini atau belum
dengan cara mengecek apakah akun dia ada di file pendaftaran hari ini atau tidak
IS : tidak diketahui pengguna sudah daftar atau belum
FS : mengembalikan boolean apakah pengguna sudah daftar atau belum
*/

bool validasiWaktu(const char* waktu, int* jam, int* menit);
/*
Digunakan untuk memvalidasi input waktu dari pengguna. Pengguna harus menginputkan waktu sesuai dengan format yang telah ditentukan
IS : tidak diketahui pengguna menginputkan format waktu yang sesuai atau tidak
FS : mengembalikan boolean apakah pengguna menginputkan format waktu yang sesuai atau tidak 
*/
bool validasiWaktuBuka(int jam, int menit);
/*
Digunakan untuk memvalidasi waktu buka yang mana waktu buka harus lebih dari waktu sekarang
IS : input belum di cek validasinya
FS : mengembalikan true jika waktu buka tidak melebihi waktu saat ini, false jika melebihi
*/

bool validasiWaktuTutup(int jam, int menit, int jBuka, int mBuka);
/*
Digunakan untuk memvalidasi waktu tutup yang mana waktu tutup harus lebih dari waktu sekarang dan lebih dari waktu buka
IS : input belum di cek validasinya
FS : mengembalikan true jika waktu tutup tidak lebih awal dari waktu buka dan tidak melebihi waktu saat ini
*/

bool validasiUsia (const char* usia);
/*
Digunakan untuk mengecek apakah string usia berisi angka atau ada huruf
IS : string belum di validasi
FS : mengembalikan true jika string hanya terdiri dari angka
*/

bool validasiUsername (const char* username);
/*
Digunakan untuk memvalidasi apakah username memiliki panjang antara 3 - 16 karakter
dan hanya boleh mengandung alfanumerik dan underscore
IS : string berisi username belum di validasi
FS : mengembalikan true jika username valid, false jika tidak valid
*/

bool validasiPassword (const char* password);
/*
Digunakan untuk memvalidasi apakah password memenuhi syarat panjang antara 8-20 karakter 
serta harus mengandung huruf besar, huruf kecil, dan angka.
IS : string berisi password belum di validasi
FS : mengembalikan true jika password valid dan false jika tidak sesuai dengan kriteria
*/

bool validasiPrioritas (int pilihan);
/*
Digunakan untuk memvalidasi apakah input dari prioritas berada dalam rentang 1 sampai 4
IS : pilihan belum divalidasi
FS : mengembalikan true jika pilihan valid, false jika tidak valid
*/

bool validasiPenyakit (int pilihan);
/*
Digunakan untuk memvalidasi apakah input dari penyakit berada dalam rentang 1 sampai 15
IS : pilihan belum divalidasi
FS : mengembalikan true jika pilihan valid, false jika tidak valid
*/

bool validasiNama (const char* nama);
/*
Digunakan untuk memvalidasi apakah nama hanya mengandung
karakter alfabet dan spasi serta panjangnya antara 2 dan 50 karakter
IS : string berisi nama belum di validasi
FS : mengembalikan true jika nama valid, false jika tidak valid
*/

bool sudahDibuka ();
/*
digunakan untuk mengecek apakah pendaftaran sudah dibuka atau belum.
IS: Tidak diketahui apakah pendaftaran sudah dibuka atau tidak.
FS: Diketahui apakah pendaftaran sudah dibuka atau tidak.
*/

#endif
