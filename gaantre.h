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
Digunakan untuk menghilangkan buffer dari input pengguna, untuk menghindari error dari kesalahan input pengguna
*/

void updateTime();
/*
Digunakan untuk mengupdate Waktu dari variabel timeSekarang 
IS : variabel timeSekarang tidak sesuai dengan waktu asli di dunianyata.
FS : variabel timeSekarang sesuai dengan waktu asli di dunianyata.
*/

bool waktuPendaftaran(int jamBuka, int menitBuka, int jamTutup, int menitTutup);
/* 
Digunakan untuk mengetahui waktu pendaftaran sedang dibuka atau tidak.
IS : tidak diketahui apakah sekarang sedang waktu pendaftaran atau tidak.
FS : diketahui sekarang sedang waktu daftar atau tidak.
*/

bool cariUsername (FILE *dataAkun, char namaCari[]);
/*
Digunakan untuk mencari apakah username yang di masukan oleh pengguna ada di file atau tidak
IS : username ada atau tidaknya tidak diketahui
FS : username ada atau tidaknya diketahui
*/

void membuatAkun(int *display);
/*
Digunakan untuk membuat akun khusus untuk pengguna dan menyimpannya kedalam file
IS : akun pengguna tidak ada di dalam file
FS : akun pengguna yang berhasil dibuat ada di dalam file
*/

bool cariAkun (FILE *dataAkun, account *cek, char cariUsername[]);
/*
Digunakan untuk menentukan akun pengguna apakah ada di file atau tidak saat ingin login
IS : tidak diketahui sudah ada akun pengguna atau belum
FS : diketahui ada atau tidaknya akun pengguna tersebut
*/

bool cekTodayList (char namaCari[]);
/*
Digunakan untuk mengecek apakah pengguna dengan username tersebut sudah mendaftar di hari ini atau belum
dengan cara mengecek apakah akun dia ada di file pendaftaran hari ini atau tidak
IS : tidak diketahui pengguna sudah daftar atau belum
FS : diketahui pengguna sudah daftar atau belum
*/
void login (int *display, account *sedangLogin);
/*
Digunakan untuk melakukan login baik itu pengguna atau admin dengan mengecek ke file akunPengguna.txt
IS : belum login
FS : berhasil login dan diketahui itu akun admin atau akun pengguna
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

int totalBarisFile(char filename);
/*
Digunakan untuk menentukan banyaknya baris dari file Data_Pasien
untuk membuat array sesuai banyaknya baris di file.
Dipanggil di modul sortAntrian untuk mengolah data tersebut.
IS : tidak diketahui banyaknya baris di dalam file
FS : diketahui banyaknya baris di dalam file
*/


int urutanTerakhir();
/*
Digunakan untuk mencari banyaknya pendaftar dari file.
Digunakan untuk menentukan batas maksimal pengguna yang bisa daftar di hari itu
IS : tidak diketahui banyaknya pendaftar
FS : diketahui banyaknya pendaftar
*/

void sortAntrian(address *root);
/*

*/
void buildBST(address *root);
address createNode (Pasien info);
bool cekKosong (address *root);
address push (address root, Pasien info);
address pop (address root, Pasien *info);
void displayPreorder(address root); 
void displayTree(address root);
void antrianSekarang (Pasien pasien, int *display);
int noAntrianUser (account *sedangLogin);
bool validasiWaktu(const char* waktu, int* jam, int* menit);
bool validasiWaktuBuka(int jam, int menit);
bool validasiWaktuTutup(int jam, int menit, int jBuka, int mBuka);
bool validasiUsia (const char* usia);
bool validasiUsername (const char* username);
bool validasiPassword (const char* password);
bool validasiPrioritas (int pilihan);
bool validasiPenyakit (int pilihan);
bool validasiNama (const char* nama);
void spasiToGarisBawah (char* nama);
void garisBawahToSpasi (char* nama);
void simpanWaktuPendaftaran (char buka[], char tutup[], int maks);
bool sudahDibuka ();
void buatFilePembukaan();
void buatFilePasien();
void dataPendaftaranToday (char waktuBuka[], char waktuTutup[], int *maks);
void aturJamMenit (char waktuBuka[], char waktuTutup[], int *jBuka, int *mBuka, int *jTutup, int *mTutup);
void displayAwal (int *display);
void displaySignUp (bool *valid, int *display, bool *running);
void displayBuatAkun (int *display);
void displayLogin (int *display, account *sedangLogin);
void displayDaftarAdmin (address root, account *sedangLogin, int *display);
void displayMenuPengguna (int *display, bool *valid, int *noAntrian);
void displayAkhir ();

#endif
