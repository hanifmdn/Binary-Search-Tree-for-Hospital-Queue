#ifndef GAANTRE_H
#define GAANTRE_H
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include "boolean.h"

typedef struct tm waktu;
typedef struct {
	char nama[50];
	char usia[3];
	char noTelp[16];
	char jamDaftar[9];
	int penyakit;
	int prioritas;
	int urutan;
} Pasien;

extern waktu timeSekarang;

typedef struct Tree* address;
typedef struct Tree {
	Pasien info;
	address kiri, kanan;
} Tree;

typedef struct {
		char username[17];
		char password[21];	
		bool identifier;
} account;

typedef struct {
    	account akun;
		Pasien pasien;
} pasienAkun;
	
void clearBuffer();
/*
Digunakan untuk menghilangkan buffer dari input pengguna, untuk menghindari error dari kesalahan input pengguna.
Diimplementasikan dalam setiap input yang telah dilakukan oleh pengguna.
*/

void updateTime();
/*
Digunakan untuk mengupdate Waktu dari variabel timeSekarang 
IS : variabel timeSekarang tidak sesuai dengan waktu asli di dunianyata.
FS : variabel timeSekarang sesuai dengan waktu asli di dunianyata.
*/

void membuatAkun(int *display);
/*
Digunakan untuk membuat akun khusus untuk pengguna dan menyimpannya kedalam file
IS : akun pengguna tidak ada di dalam file
FS : akun pengguna yang berhasil dibuat ada di dalam file
*/

void login (int *display, account *sedangLogin);
/*
Digunakan untuk melakukan login baik itu pengguna atau admin dengan mengecek ke file akunPengguna.txt
IS : belum login
FS : berhasil login dan diketahui itu akun admin atau akun pengguna
*/

void sortAntrian(address *root);
/*
Digunakan untuk mengurutkan data pendaftar di dalam file berdasarkan prioritas dan jam daftar.
File akan diambil ke array sesuai panjang dari modul urutanTerakhir. Lalu dilakukan operasi,
setelah selesai akan di tulis kembali kedalam file tersebut.
IS : file belum terurut berdasarkan jam daftar dan prioritas
FS : file sudah terurut berdasarkan jam daftar dan prioritas

// referensi bubble sort
*/

int totalBarisFile(char filename);
/*
Digunakan untuk menentukan banyaknya baris dari file Data_Pasien
untuk membuat array sesuai banyaknya baris di file.
Dipanggil di modul sortAntrian untuk mengolah data tersebut.
IS : tidak diketahui banyaknya baris di dalam file
FS : mengembalikan banyaknya baris di dalam file
*/
void buildBST(address *root);
/* 
Digunakan untuk membangun Tree berdasarkan file Data_Pasien yang sudah terurut di modul sortAntrian
IS : tree untuk antrian belum ada
FS : tree untuk antrian sudah ada
*/

address createNode (Pasien info);
/*
Digunakan untuk membuat sebuah node baru dalam BST.
IS: Tidak ada spesifikasi khusus.
FS: Sebuah node baru dengan informasi pasien tertentu sudah dibuat.
*/

bool cekKosong (address *root);
/*
Digunakan untuk pengecekan tree kosong.
*/

address push (address root, Pasien info);
/*
digunakan untuk insertion sebuah node pasien ke dalam BST.
IS: BST belum memiliki node yang akan ditambahkan.
FS: Sebuah node baru dengan informasi pasien sudah ditambahkan ke dalam BST.
*/

address pop (address root, Pasien *info);
/*
digunakan untuk menghapus sebuah node pasien dari BST.
IS: BST memiliki node dengan informasi pasien yang akan dihapus.
FS: Node dengan informasi pasien sudah dihapus dari BST.
*/

void displayPreorder(address root); 
/*
digunakan untuk menampilkan data dalam BST secara Preorder traversal.
IS: BST memiliki node-node yang berisi data yang akan ditampilkan.
FS: Data dalam BST ditampilkan secara Preorder traversal.
*/

void displayTree(address root);
/*
digunakan untuk menampilkan struktur BST secara berhierarki.
IS: BST sudah dibangun berisi data yang akan ditampilkan..
FS: Struktur BST ditampilkan secara berhierarki.
*/

void daftarAdmin (address *root, account *sedangLogin, int *display);
/*
Digunakan untuk mendaftarkan pasien ke antrian oleh admin, lalu disimpan di file.
Jika antrian tree sudah dibuat maka akan langsung dimasukan kedalam tree
IS : pasien belum didaftarkan ke antrian
FS : pasien sudah didaftarkan ke antrian dan tercatat di dalam file
*/

void daftarPengguna (address *root, account *sedangLogin, int *display, int maks);
/*
Digunakan untuk mendaftarkan pasien ke antrian oleh pengguna sendiri, lalu disimpan di file.
IS : pasien belum didaftarkan ke antrian
FS : pasien sudah didaftarkan ke antrian dan tercatat di dalam file
*/


int urutanTerakhir();
/*
Digunakan untuk mencari banyaknya pendaftar dari file.
Digunakan untuk menentukan batas maksimal pengguna yang bisa daftar di hari itu
IS : tidak diketahui banyaknya pendaftar
FS : mengembalikan banyaknya pendaftar
*/

void antrianSekarang (Pasien pasien, int *display);
/*
digunakan untuk menampilkan nomor antrian pasien yang sedang konsultasi.
IS: Informasi pasien yang sedang konsultasi sudah tersedia.
FS: Nomor antrian pasien yang sedang konsultasi ditampilkan.
*/

pasienAkun noAntrianUser (account *sedangLogin);
/*
Digunakan untuk mencari nomor antrian yang dimiliki oleh pengguna berdasarkan akun nya di dalam file Data_Pasien.
Hanya bisa ditampilkan ketika antrian/tree sudah dibuat oleh admin.
IS : nomor antrian pengguna yang bersangkutan tidak diketahui
FS : nomor antrian pengguna yang bersangkutan diketahui
*/

void spasiToGarisBawah (char* nama);
void garisBawahToSpasi (char* nama);

void simpanWaktuPendaftaran (char buka[], char tutup[], int maks);
/*
digunakan untuk menyimpan waktu pembukaan dan penutupan pendaftaran ke dalam file.
IS: Waktu pembukaan dan penutupan pendaftaran belum disimpan.
FS: Waktu pembukaan dan penutupan pendaftaran telah disimpan ke dalam file.
*/

void buatFilePembukaan();
/*
digunakan untuk membuat file pembukaan pendaftaran dan file pasien baru jika belum ada.
IS: File pembukaan pendaftaran atau file pasien belum ada.
FS: File pembukaan pendaftaran atau file pasien sudah dibuat.
*/

void buatFilePasien();
/*
digunakan untuk mendapatkan data pendaftaran hari ini dari file.
IS: Data pendaftaran hari ini belum diambil dari file.
FS: Data pendaftaran hari ini sudah diambil dari file dan disimpan.

*/

void dataPendaftaranToday (char waktuBuka[], char waktuTutup[], int *maks);
void aturJamMenit (char waktuBuka[], char waktuTutup[], int *jBuka, int *mBuka, int *jTutup, int *mTutup);

#endif
