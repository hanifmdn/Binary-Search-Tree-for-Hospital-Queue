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
	Pasien formulir;
	
	printf("|+|Isi Formulir di bawah ini!                                                            |+|\n");
	printf("|+|Nama 	: ");
	scanf(" %[^\n]", formulir.nama);
	printf("|+|Usia 	: ");
	scanf(" %[^\n]", formulir.usia);
	printf("|+|No.Telepon  	: ");
	scanf(" %[^\n]", formulir.noTelp);
	printf("|+|Kondisi      : ");
	scanf(" %[^\n]", formulir.keluhan);
	printf ("|+|======================================================================================|+|");
	printf("|+|Prioritas Pasien                                                                       |+|\n");
	printf("|+|1. Prioritas 1 (Kondisi Tidak Darurat)                                                 |+|\n");
	printf("|+|2. Prioritas 2 (Kondisi Serius)                                                        |+|\n");
	printf("|+|3. Prioritas 3 (Kondisi Ringan)                                                        |+|\n");
	printf("|+|4. Prioritas 4 (Kondisi Darurat)                                                       |+|\n");
	printf("|+|Pilih opsi:
		
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
	Pasien formulir;
	
	printf("|+|Isi Formulir di bawah ini!                                                            |+|\n");
	printf("|+|Nama 	: ");
	scanf(" %[^\n]", formulir.nama);
	printf("|+|Usia 	: ");
	scanf(" %[^\n]", formulir.usia);
	printf("|+|No.Telepon  	: ");
	scanf(" %[^\n]", formulir.noTelp);
	printf("|+|Kondisi      : ");
	scanf(" %[^\n]", formulir.keluhan;)
	printf("|+|Penyakit yang diderita:	 					                                         |+|\n")
	printf("|+|1.  Pemeriksaan Rutin 							                                	 |+|\n")
	printf("|+|2.  Konsultasi Penyakit Diderita                                                      |+|\n")
	printf("|+|3.  Kebutuhan Resep Ulang                                                             |+|\n")
	printf("|+|4.  Luka Kecil (luka Goresan)                                                         |+|\n")
	printf("|+|5.  Influenza (Demam, Pilek atau hidung tersumbat, Batuk, Sakit tenggorokan.)	     |+|\n")
	printf("|+|6.  Gastritis (Kembung, Mulas, Mual)                                                  |+|\n")
	printf("|+|7.  Dermatitis (Ruam kulit, Gatal-gatal, Kulit kemerahan)                             |+|\n")
	printf("|+|8.  Infeksi Saluran Kemih (Nyeri saat buang air kecil, Urin keruh atau berbau)        |+|\n")
	printf("|+|9.  Apendisitis (Nyeri perut di kanan bawah, Mual dan muntah, Demam)                  |+|\n")
	printf("|+|10. Eksaserbasi Asma (Sesak Napas, Batuk, Nyeri Dada, Napas Pendek)                   |+|\n")  
	printf("|+|11. Fraktur Tulang (Patah Tulang, Dislokasi Tulang)                                   |+|\n")
	printf("|+|12. Pneumonia Berat (Nyeri dada, Sesak napas, Demam tinggi, Batuk berdahak)           |+|\n")
	printf("|+|13. Dehidrasi Berat (Mulut kering, Kulit kemerahan, Pusing, Detak jantung cepat)      |+|\n")
	printf("|+|14. Infark Miokard Non-stemi (Nyeri dada, Berkeringat dingin, Sesak napas, Mual)      |+|\n")
	printf("|+|15. Abses Hati (Kulit Kuning, Demam Tinggi, Nyeri Abdomen, Penggumpalan Darah)        |+|\n")
	printf("|+|======================================================================================|+|\n")
	// pengguna mendaftarkan
	// isi nama, usia, no telp, pilih penyakit, ceritakan keluhan
	// dari pilihan penyakit, di tentukan prioritasnya (bisa dibuat function)
	// push ke tree
	// menampilkan 
	hasil daftar beserta jam daftar dan nomor antrian beliau
	|+|
	|+|Usia 	:									 |+|
	|+|No.Telepon  	: 									 |+|
}

void antrianSekarang () {
	// menampilkan antrian sekarang (root)
}
