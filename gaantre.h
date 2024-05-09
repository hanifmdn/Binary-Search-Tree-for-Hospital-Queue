#ifndef GAANTRE_H
#define GAANTRE_H
#include <stdio.h>
#include <time.h>
#include <cstring>

typedef struct {
	char nama[50];
	char usia;
	char noTelp;
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
		char username[16];
		char password[16];	
		int identifier;
} account;
	

void membuatAkun();

#endif
