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
		printf("|+|\n|+|Tidak dapat membuka file akunPengguna.txt\n");
	}
	
	while (fscanf(akunPengguna, "%s", username) == 1) {
		if (strcmp(akun.username, username) == 0) {
			printf("|+|Username sudah tersedia!\n\n");
			ditemukan = true;
			*display = 3;
			break;
		}
	}
		
	if (!ditemukan) {
		fprintf(akunPengguna, "%s %s %d\n", akun.username, akun.password, 0);
		printf("|+|Akun berhasil dibuat!\n\n");
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
		printf("|+|\n|+|Tidak dapat membuka file akunPengguna.txt");
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
			printf("|+|Berhasil masuk!\n\n");
			if (cek[pengguna].identifier == 1) {
				*display = 5;
			} else {
				*display = 6;
			}
		} else {
			printf("|+|Password Salah!\n\n");
			
		}
		
	} else {
		printf("|+|Username tidak ada! Silahkan buat akun terlebih dahulu!\n\n");
	}
	// buka file
	// cek satu satu
	// kalo username ada, nama ada berarti bisa masuk
	// kalo ngga gabisa masuk
	// cek dia admin atau bukan
}


void daftarAdmin (address *root) {
	char opsi;
	Pasien daftar;
	address newNode;
	
	printf("|+|Nama       : "); scanf(" %[^\n]", daftar.nama);
	printf("|+|Usia       : "); scanf(" %c", &daftar.usia);  while ((getchar()) != '\n');
	printf("|+|No.Telepon : "); scanf(" %[^\n]", daftar.noTelp);
	printf("|+|                                                                                      |+|\n");
	printf("|+|Pilih Prioritas Pasien:                                                               |+|\n");
	printf("|+|1.  Prioritas 1 (Tidak Darurat)                                                       |+|\n");
    printf("|+|2.  Prioritas 2                                                                       |+|\n");
	printf("|+|3.  Prioritas 3                                                                       |+|\n");
	printf("|+|4.  Prioritas 4 (Darurat)                                                             |+|\n");
	printf("|+|Pilih opsi: "); 
	scanf("%d", &daftar.prioritas);
	printf("|+|edit? (y/n)");
	scanf(" %c", &opsi);
		if (opsi == 'y') {
		daftarAdmin(root);
		} 
		newNode = createNode (daftar);
		printf("new node ada\n");
		if (newNode == NULL) {
			printf("Alokasi gagal!\n");
		} else {
			printf("newnode tidak null");
		}
		*root = push(*root, daftar);
    	printf("Pasien berhasil didaftarkan.\n");
	// mendaftar
	// isi nama, usia, no telp, prioritas
	// masukan keluhan sebagai keterangan untuk dokter
	// push ke tree
	// menampilkan hasil daftar beserta jam daftar dan nomor antrian beliau	
	}



void daftarPengguna (address *root) {
	char opsi;
	Pasien daftar;
	address newNode;
	
	printf("|+|Nama       : "); scanf(" %[^\n]", daftar.nama);
	printf("|+|Usia       : "); scanf(" %c", &daftar.usia);  while ((getchar()) != '\n');
	printf("|+|No.Telepon : "); scanf(" %[^\n]", daftar.noTelp);
	printf("|+|                                                                                      |+|\n");
	printf("|+|Pilih jenis penyakit yang diderita:                                                   |+|\n");
	printf("|+|1.  Pemeriksaan Rutin                                                                 |+|\n");
    printf("|+|2.  Konsultasi Penyakit Diderita                                                      |+|\n");
	printf("|+|3.  Kebutuhan Resep Ulang                                                             |+|\n");
	printf("|+|4.  Luka Kecil (luka Goresan)                                                         |+|\n");
	printf("|+|5.  Influenza (Demam, Pilek atau hidung tersumbat, Batuk, Sakit tenggorokan)          |+|\n");
	printf("|+|6.  Gastritis (Kembung, Mulas, Mual)                                                  |+|\n");
	printf("|+|7.  Dermatitis (Ruam kulit, Gatal-gatal, Kulit kemerahan)                             |+|\n");
	printf("|+|8.  Infeksi Saluran Kemih (Nyeri saat buang air kecil, Urin keruh atau berbau)        |+|\n");
	printf("|+|9.  Apendisitis (Nyeri perut di kanan bawah, Mual dan muntah, Demam)                  |+|\n");
	printf("|+|10. Eksaserbasi Asma (Sesak Napas, Batuk, Nyeri Dada, Napas Pendek)                   |+|\n");
    printf("|+|11. Fraktur Tulang (Patah Tulang, Dislokasi Tulang)                                   |+|\n");
    printf("|+|12. Pneumonia Berat (Nyeri dada, Sesak napas, Demam tinggi, Batuk berdahak)           |+|\n");
	printf("|+|13. Dehidrasi Berat (Mulut kering, Kulit kemerahan, Pusing, Detak jantung cepat)      |+|\n");
	printf("|+|14. Infark Miokard Non-stemi (Nyeri dada, Berkeringat dingin, Sesak napas, Mual)      |+|\n");
	printf("|+|15. Abses Hati (Kulit Kuning, Demam Tinggi, Nyeri Abdomen, Penggumpalan Darah)        |+|\n");
	printf("|+|--------------------------------------------------------------------------------------|+|\n");
	printf("|+|Pilih opsi: "); 
	scanf("%d", &daftar.penyakit);
	printf("|+|edit? (y/n)");
	scanf(" %c", &opsi);
	if (opsi == 'y') {
		daftarPengguna(root);
	} else {
		if (daftar.penyakit == 1 || daftar.penyakit == 2 || daftar.penyakit == 3 || daftar.penyakit == 4) {
			daftar.prioritas = 1;
		} else 
		if (daftar.penyakit == 5 || daftar.penyakit == 6 || daftar.penyakit == 7 || daftar.penyakit == 8 || daftar.penyakit == 9 || daftar.penyakit == 10) {
			daftar.prioritas = 2;
		} else 
		if (daftar.penyakit == 11 || daftar.penyakit == 12 || daftar.penyakit == 13 || daftar.penyakit == 14 || daftar.penyakit == 15 ) {
			daftar.prioritas = 3;
		}
		
		newNode = createNode (daftar);
		printf("new node ada\n");
		if (newNode == NULL) {
			printf("Alokasi gagal!\n");
		} else {
			printf("newnode tidak null");
		}
		*root = push(*root, daftar);
    	printf("Pasien berhasil didaftarkan.\n");
	}
	// pengguna mendaftarkan
	// isi nama, usia, no telp, pilih penyakit, ceritakan keluhan
	// dari pilihan penyakit, di tentukan prioritasnya (bisa dibuat function)
	// push ke tree
	// menampilkan hasil daftar beserta jam daftar dan nomor antrian beliau
}


address createNode (Pasien info) {
	address node;
	node = (address) malloc(sizeof (Tree));
	node->info = info;
	node->kanan = NULL;
	node->kiri = NULL;
	return (node);
}


bool cekKosong (address *root) {
	return (root == NULL);
}

address push(address root, Pasien info) {
    if (root == NULL) {
        root = createNode(info);
    } else {
        if (info.prioritas < root->info.prioritas) {
            root->kiri = push(root->kiri, info);
        } else {
            root->kanan = push(root->kanan, info);
        }
    }
    return root;
}


address popAntrian(address root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->kiri == NULL) {
        address temp = root->kanan;
        free(root);
        return temp;
    }

}



void antrianSekarang () {
	// menampilkan antrian sekarang (root)
}

//void displayTree(Tree root) {
//    if (root != NULL) {
//        displayTree(root->kiri);
//        printf("Nama: %s, Prioritas: %d\n", root->info.nama, root->info.prioritas);
//        displayTree(root->kanan);
//    }
//}
