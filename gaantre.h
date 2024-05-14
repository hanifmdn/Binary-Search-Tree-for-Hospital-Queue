#ifndef GAANTRE_H
#define GAANTRE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "boolean.h"

typedef struct {
	char nama[50];
	char usia;
	char noTelp[16];
	char jamDaftar;
	int penyakit;
	char keluhan[500];
	int prioritas;
	int urutan;
} Pasien;

typedef struct Tree* address;
typedef struct Tree {
	Pasien info;
	address kiri, kanan;
} Tree;

typedef struct {
		char username[20];
		char password[20];	
		int identifier;
		int loggedIn;
} account;
	

void membuatAkun(int *display);
void login (int *display);
void daftarAdmin (address *root);
void daftarPengguna (address *root);
address createNode (Pasien info);
bool cekKosong (address *root);
address push (address root, Pasien info);
address pop (address root, Pasien *info);
void displayPreorder(address root); 
void displayTree(address root);

#endif
