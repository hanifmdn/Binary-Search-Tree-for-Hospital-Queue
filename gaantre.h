#ifndef GAANTRE_H
#define GAANTRE_H
#include <stdio.h>
#include <stdlib.h>
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
	
	
void updateTime();
bool cariUsername (FILE *dataAkun, char namaCari[20]);
void membuatAkun(int *display);
bool cariAkun (FILE *dataAkun, account *cek, char cariUsername[20]);
bool cekTodayList (char namaCari[20]);
void login (int *display, account *sedangLogin);
void daftarAdmin (address *root, account *sedangLogin, int *display);
void daftarPengguna (address *root, account *sedangLogin, int *display);
void totalBarisFile(char filename);
void sortBasedPriority();
address createNode (Pasien info);
bool cekKosong (address *root);
address push (address root, Pasien info);
address pop (address root, Pasien *info);
void displayPreorder(address root); 
void displayTree(address root);
void antrianSekarang (address root);

#endif
