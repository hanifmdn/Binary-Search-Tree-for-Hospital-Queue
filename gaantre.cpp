#include "GAANTRE.h"

void membuatAkun () {
	FILE *akunPengguna;
	account akun;
	
	printf("Masukan username: ");
	scanf(" %[^\n]", akun.username);
	printf("Masukan password: ");
	scanf(" %[^\n]", akun.password);
	
	akunPengguna = fopen("akunPengguna.txt", "a+");
	
	if (akunPengguna != NULL) {
		while (!EOF) {
			// cek akun sudah ada atau belum
			// jika sudah ada kembali ke punya akun
		}
	}
	if (akunPengguna != NULL) {
		fprintf(akunPengguna, "%s %s %d\n", akun.username, akun.password, 0);
		printf("Akun berhasil dibuat!");
		fclose(akunPengguna);
	} else {
		printf("Tidak dapat membuka file Akun Pengguna\n");
	}
}

void login () {
	account masuk;
	printf("Masukan username: ");
	scanf(" %[^\n]", masuk.username);
	printf("Masukan password: ");
	scanf(" %[^\n]", masuk.password);
	
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
