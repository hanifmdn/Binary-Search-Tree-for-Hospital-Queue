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
		char username[20];
		char password[20];	
		bool identifier;
} account;

typedef struct {
    	account akun;
		Pasien pasien;
} pasienAkun;
	
void clearBuffer();
void updateTime();
bool waktuPendaftaran(int jamBuka, int menitBuka, int jamTutup, int menitTutup);
bool cariUsername (FILE *dataAkun, char namaCari[20]);
void membuatAkun(int *display);
bool cariAkun (FILE *dataAkun, account *cek, char cariUsername[20]);
bool cekTodayList (char namaCari[20]);
void login (int *display, account *sedangLogin);
void daftarAdmin (address *root, account *sedangLogin, int *display);
void daftarPengguna (address *root, account *sedangLogin, int *display, int maks);
int totalBarisFile(char filename);
int urutanTerakhir();
void sortAntrian(address *root);
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

#endif
