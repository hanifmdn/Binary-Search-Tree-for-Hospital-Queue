#include "GAANTRE.h"

void membuatAkun (int *display) {
	char username[20];
	FILE *akunPengguna;
	bool ditemukan = false;
	account akun;
	
	printf("|+|Username: "); 
	scanf(" %[^\n]", akun.username);
	printf("|+|Password: ");
	scanf(" %[^\n]", akun.password);
	
	akunPengguna = fopen("akunPengguna.txt", "a+");
	
	if (akunPengguna == NULL) {
		printf("Tidak dapat membuka file akunPengguna.txt\n");
	}
	
	while (fscanf(akunPengguna, "%s", username) == 1) {
		if (strcmp(akun.username, username) == 0) {
			printf("Username sudah ada!");
			ditemukan = true;
			*display = 3;
			break;
		}
	}
		
	if (!ditemukan) {
		fprintf(akunPengguna, "%s %s %d\n", akun.username, akun.password, 0);
		printf("Akun berhasil dibuat!");
		*display = 4;
		fclose(akunPengguna);
	}
}

void login (int *display) {
	FILE *akunPengguna;
	account masuk;
	account cek[100];
	int pengguna = 0;
	bool ditemukan = false;
	
	akunPengguna = fopen("akunPengguna.txt", "r");
	
	if (akunPengguna == NULL) {
		printf("Tidak dapat membuka file akunPengguna.txt");
	}
	printf("|+|Username: "); 
	scanf(" %[^\n]", masuk.username);
	printf("|+|Password: ");
	scanf(" %[^\n]", masuk.password);
	
	while (fscanf(akunPengguna, "%s %s %d", &cek[pengguna].username, &cek[pengguna].password, &cek[pengguna].identifier) == 3) {
		if (strcmp(cek[pengguna].username, masuk.username) == 0) {
			ditemukan = true;
			break;
		}
		pengguna++;
	}
	if (ditemukan) {
		if (strcmp(cek[pengguna].password, masuk.password) == 0) {
			printf("berhasil masuk!");
			if (cek[pengguna].identifier == 1) {
				*display = 5;
			} else {
				*display = 6;
			}
		} else {
			printf("Password Salah!");
			
		}
		
	} else {
		printf("Username tidak ada! Silahkan buat akun terlebih dahulu!");
	}
	// buka file
	// cek satu satu
	// kalo username ada, nama ada berarti bisa masuk
	// kalo ngga gabisa masuk
	// cek dia admin atau bukan
}

Tree createNode () {
	
}

void cekKosong () {
	
}

Tree push () {
	
}

Tree pop ()	{
	
}
void daftarAdmin () {
	// mendaftar
	// isi nama, usia, no telp, prioritas
	// masukan keluhan sebagai keterangan untuk dokter
	// push ke tree
	// menampilkan hasil daftar beserta jam daftar dan nomor antrian beliau
}

void popAntrian () {
	// mengeluarkan node dari tree ketika orang tersebut sudah selesai konsultasi dengan dokter
}

void daftarPengguna () {
	// pengguna mendaftarkan
	// isi nama, usia, no telp, pilih penyakit, ceritakan keluhan
	// dari pilihan penyakit, di tentukan prioritasnya (bisa dibuat function)
	// push ke tree
	// menampilkan hasil daftar beserta jam daftar dan nomor antrian beliau
}

void antrianSekarang () {
	// menampilkan antrian sekarang (root)
}
