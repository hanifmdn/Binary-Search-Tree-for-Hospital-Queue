#include "GAANTRE.h"
#include "DISPLAYGAANTRE.h"
#include "VALIDGAANTRE.h"

waktu timeSekarang;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void updateTime() {
	time_t jam = time(NULL);
	timeSekarang = *localtime(&jam);
}

void membuatAkun (int *display) {
	FILE *akunPengguna;
	bool ditemukan = false;
	account akun;
	bool valid = false;

	printf("|+|Username terdiri dari 3-16 karakter, huruf, angka, dan garis bawah (_)\n");
	while (!valid) {	
		printf("|+|Username: "); 
		scanf(" %[^\n]", akun.username);
		clearBuffer();
		if (validasiUsername(akun.username)) {
			valid = true;
		} else {
			printf("|+|Username tidak valid! Coba lagi sesuai dengan kriteria yang ditentukan!\n");
		}
	}
	
	valid = false;
	printf("|+|Password terdiri dari minimal 8-20 karakter, huruf besar, huruf kecil, dan angka\n");
	while (!valid) {
		printf("|+|Password: ");
		scanf(" %[^\n]", akun.password);
		clearBuffer();
		if (validasiPassword(akun.password)) {
			valid = true;
		} else {
			printf("|+|Password tidak valid! Coba lagi sesuai dengan kriteria yang ditentukan!\n");
		}
	}
	akunPengguna = fopen("akunPengguna.txt", "a+");
	ditemukan = cariUsername(akunPengguna, akun.username);
		
	if (ditemukan) {
		printf("|+|Username sudah tersedia!\n\n");
		*display = 3;
	} else {
		fprintf(akunPengguna, "%s %s %d\n", akun.username, akun.password, 0);
		printf("|+|Akun berhasil dibuat!\n\n");
		*display = 4;
		fclose(akunPengguna);
	}
}


void login (int *display, account *sedangLogin) {
	FILE *akunPengguna;
	account masuk;
	account cek;
	bool ditemukan = false;
	
	printf("|+|Username: "); 
	scanf(" %[^\n]", masuk.username);
	printf("|+|Password: ");
	scanf(" %[^\n]", masuk.password);
	
	akunPengguna = fopen("akunPengguna.txt", "r");
	ditemukan = cariAkun(akunPengguna, &cek, masuk.username);
		
	if (ditemukan) {
		*sedangLogin = cek;
		if (strcmp(cek.password, masuk.password) == 0) {
			printf("|+|Berhasil Masuk                                                                        |+|\n");
			if (cek.identifier == 1) {
				*display = 5;
			} else {
				*display = 7;
			}
		} else {
			printf("|+|Password Salah!\n\n");	
		}
	} else {
		printf("|+|Username tidak ada! Silahkan buat akun terlebih dahulu!\n\n");
		*display = 2;
	}
	// buka file
	// cek satu satu
	// kalo username ada, nama ada berarti bisa masuk
	// kalo ngga gabisa masuk
	// cek dia admin atau bukan
}
	
int totalBarisFile(char filename[]) {
	FILE *file = fopen(filename, "r");
	pasienAkun temp;
	int totBaris = 0;
    if (file == NULL) {
        printf("Tidak dapat membuka file %s\n", filename);
    } else {
    	while (fscanf(file, "%s %s %s %s %s %s %d %d %d\n", 
					temp.akun.username,
					temp.akun.password,
					temp.pasien.nama,
					temp.pasien.usia,
					temp.pasien.noTelp,
					temp.pasien.jamDaftar,
					&temp.pasien.penyakit,
					&temp.pasien.prioritas,
					&temp.pasien.urutan) == 9) {
					totBaris++;
					}
		fclose(file);
	}
	return totBaris;
}

void sortAntrian(address *root) {
	FILE *todayList;
	int urutan = 1;
    char filename[30];
    int i, lenOperasiFile;
    
    // Mendapatkan nama file hari ini
    updateTime();
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
    
    // Mengambil banyaknya baris dalam file
	lenOperasiFile = totalBarisFile(filename);
    pasienAkun operasiFile[lenOperasiFile];
    
	todayList = fopen(filename, "r");
    if (todayList == NULL) {
        printf("Tidak dapat membuka file %s\n", filename);
        return;
    } else {
//	    	printf("masuk else scan file\n");
    	i = 0;
    	while (fscanf(todayList, "%s %s %s %s %s %s %d %d %d\n", 
					operasiFile[i].akun.username,
					operasiFile[i].akun.password,
					operasiFile[i].pasien.nama,
					operasiFile[i].pasien.usia,
					operasiFile[i].pasien.noTelp,
					operasiFile[i].pasien.jamDaftar,
					&operasiFile[i].pasien.penyakit,
					&operasiFile[i].pasien.prioritas,
					&operasiFile[i].pasien.urutan) == 9) {
					i++;
					}
		fclose(todayList);
		int len = i;
		int min;
		int hour1, minute1, second1, hour2, minute2, second2;
//		printf("beres scan file mau masuk for\n");
		for (i = 0; i < len - 1; i++) {
			min = i;
//			printf("masuk for pertama\n");
			for (int j = i + 1; j < len; j++) {
//				printf("masuk for kedua\n");
				if (operasiFile[j].pasien.prioritas > operasiFile[min].pasien.prioritas) {
					min = j;
				} else 
				if (operasiFile[j].pasien.prioritas == operasiFile[min].pasien.prioritas) {
					sscanf(operasiFile[min].pasien.jamDaftar , "%d:%d:%d", &hour1, &minute1, &second1);
					sscanf(operasiFile[j].pasien.jamDaftar, "%d:%d:%d", &hour2, &minute2, &second2);
					
//						printf("jam min %d:%d:%d", hour1, minute1, second1);
//						printf("jam j %d:%d:%d", hour2, minute2, second2);
					if (hour2 < hour1 || (hour2 == hour1 && minute2 < minute1) || (hour2 == hour1 && minute2 == minute1 && second2 < second1)) {
						min = j;
					}
				}
			}
			
			pasienAkun temp = operasiFile[min];
			operasiFile[min] = operasiFile[i];
			operasiFile[i] = temp;
//			printf("berhasil swap\n");
		}
		for (i = 0; i < len; i++) {
			operasiFile[i].pasien.urutan = i + 1;
		}
		
//		printf("membuka file lagi untuk write ulang");
		todayList = fopen(filename, "w");
		if (todayList == NULL) {
        printf("Tidak dapat membuka file %s\n", filename);
        return;
  		} else {
//  			printf("siap menulis ulang");
  				for (i = 0; i < len; i++) {
					fprintf(todayList, "%s %s %s %s %s %s %d %d %d\n", 
						operasiFile[i].akun.username,
						operasiFile[i].akun.password,
						operasiFile[i].pasien.nama,
						operasiFile[i].pasien.usia,
						operasiFile[i].pasien.noTelp,
						operasiFile[i].pasien.jamDaftar,
						operasiFile[i].pasien.penyakit,
						operasiFile[i].pasien.prioritas,
						operasiFile[i].pasien.urutan);
				}
				fclose(todayList);
		}
		buildBST(root);
	}
	
}

void buildBST(address *root) {
	char filename[30];
	FILE *todayList;
	pasienAkun buatTree;
	
	if (*root != NULL) {
		printf("|+|Antrian sudah di bangun!\n|+|\n|+|\n");
		return;
	} 
	
	// Mendapatkan nama file hari ini
    updateTime();
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
    
	todayList = fopen(filename, "r");
    if (todayList == NULL) {
        printf("|+|Tidak dapat membuka file %s\n", filename);
        return;
    } else {
//    	printf("masuk else scan file\n");
    	while (fscanf(todayList, "%s %s %s %s %s %s %d %d %d\n", 
					buatTree.akun.username,
					buatTree.akun.password,
					buatTree.pasien.nama,
					buatTree.pasien.usia,
					buatTree.pasien.noTelp,
					buatTree.pasien.jamDaftar,
					&buatTree.pasien.penyakit,
					&buatTree.pasien.prioritas,
					&buatTree.pasien.urutan) == 9) {
					*root = push (*root, buatTree.pasien);
					}
		fclose(todayList);
	}
}


address createNode (Pasien info) {
	address node = (address) malloc(sizeof (Tree));
	node->info = info;
	node->kanan = NULL;
	node->kiri = NULL;
	return (node);
}

bool cekKosong (address root) {
	return (root == NULL);
}

address push (address root, Pasien info) {
	if (cekKosong (root)) {
		return createNode (info);
	}
	
    if (info.prioritas > root->info.prioritas) {
        root->kiri = push(root->kiri, info);
    } else {
        root->kanan = push(root->kanan, info);
    }

    return root;
}

address pop (address root, Pasien *info) {
	if (cekKosong(root)) {
		return root;
	}
	
	if (root->kiri != NULL) {
		root->kiri = pop(root->kiri, info);
	} else {
		address temp = root->kanan;
		*info = root->info;
		free(root);
		return temp;
	}
	return root;
}

void displayPop(address root) {
    if (cekKosong(root)) {
        return;
    }
	displayTree(root->kiri);
	printf("|+|%d %s [%d]\n", root->info.urutan, root->info.nama, root->info.prioritas);
	displayTree(root->kanan);
}


void displayTree(address root) {
    if (cekKosong(root)) {
        return;
    } else {
        displayPop(root);
    }
}

void daftarAdmin (address *root, account *sedangLogin, int *display) {
	char opsi;
	Pasien daftar;
	address newNode;
	FILE *todayList;
	char filename[30];
	bool valid = false;
	
	do {
		while (true) {
			printf("|+|Nama       : ");
			scanf(" %[^\n]", daftar.nama);
			clearBuffer();
			
			if (validasiNama(daftar.nama)) {
				break;
			} else {
				printf("|+|Nama tidak valid! Masukan nama yang sesuai!\n");
			} 
		} 
		spasiToGarisBawah(daftar.nama);
		
		
		while (true) {
			printf("|+|Usia       : ");
			scanf(" %[^\n]", daftar.usia);
			clearBuffer();
			if (validasiUsia(daftar.usia)) {
				break;
			} else {
				printf("|+|Usia tidak valid! Usia maksimum 3 digit dan harus berupa angka\n");
			}
		}
		
		while (true) {
		    printf("|+|No.Telepon : "); 
		    scanf(" %[^\n]", daftar.noTelp);
		    clearBuffer();
		    if (cekNoTelp(daftar.noTelp)) {
		        break;
		    } else {
		        printf("|+|Nomor telepon tidak valid. Silakan masukkan nomor telepon yang valid.\n");
		    }
		}
		printf("|+|                                                                                      |+|\n");
		printf("|+|Pilih Prioritas Pasien:                                                               |+|\n");
		printf("|+|1.  Prioritas 1 (Tidak Darurat)                                                       |+|\n");
	    printf("|+|2.  Prioritas 2                                                                       |+|\n");
		printf("|+|3.  Prioritas 3                                                                       |+|\n");
		printf("|+|4.  Prioritas 4 (Darurat)                                                             |+|\n");
	
		while (true) {
			printf("|+|Pilih opsi: "); 
			scanf("%d", &daftar.prioritas);
			clearBuffer();
			if (validasiPrioritas(daftar.prioritas)) {
				break;
			} else {
				printf("|+|Pilih opsi yang sesuai!\n");
			}
		}
	
		printf("|+|Edit? (y/n) ");
		scanf(" %c", &opsi);
		clearBuffer();
			if (opsi == 'y' || opsi == 'Y') {
				valid = false;
			} else
			if (opsi == 'n' || opsi == 'N') {
				updateTime();
				strftime(daftar.jamDaftar, sizeof(daftar.jamDaftar), "%H:%M:%S", &timeSekarang);
	//			printf("waktu daftar: %s", daftar.jamDaftar);
				strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
				
				daftar.penyakit = 0;
				daftar.urutan = 0;
				todayList = fopen(filename, "a");
				if (todayList == NULL) {
					printf("|+|Gagal menyimpan data Pasien!\n");
				} else {
					fprintf(todayList, "%s %s %s %s %s %s %d %d %d\n", 
						sedangLogin->username,
						sedangLogin->password,
						daftar.nama,
						daftar.usia,
						daftar.noTelp,
						daftar.jamDaftar,
						daftar.penyakit,
						daftar.prioritas,
						daftar.urutan);
						
						fclose(todayList);
					*display = 5;
					
					if (*root != NULL) {
						*root = push (*root, daftar);
					}
				}
				valid = true;
				break;
			} else {
				printf("|+|Input tidak valid! Mohon masukan input yang sesuai!\n");
			}	
			
	} while (!valid);
	// mendaftar
	// isi nama, usia, no telp, prioritas
	// masukan keluhan sebagai keterangan untuk dokter
	// push ke tree
	// menampilkan hasil daftar beserta jam daftar dan nomor antrian beliau	
}

int setPriority (int penyakit) {
	int prioritas = 0;
	
	if (penyakit == 1 || penyakit == 2 || penyakit == 3 || penyakit == 4) {
			prioritas = 1;
	} else 
	if (penyakit == 5 || penyakit == 6 || penyakit == 7 || penyakit == 8 || penyakit == 9 || penyakit == 10) {
			prioritas = 2;
	} else 
	if (penyakit == 11 || penyakit == 12 || penyakit == 13 || penyakit == 14 || penyakit == 15 ) {
			prioritas = 3;
	}
	return (prioritas);
}

void daftarPengguna (address *root, account *sedangLogin, int *display, int maks) {
	char opsi;
	Pasien daftar;
	address newNode;
	FILE *todayList;
    char filename[30];
    bool sudahDaftar;
	bool valid = false;
	
	do {
	    if (sudahDaftar = cekTodayList (sedangLogin->username)) {
	    	printf("|+|Anda sudah melakukan pendaftaran hari ini!\n");
	    	*display = 7;
	    	return;
		} else {
			printf("|+|======================================================================================|+|\n");
	        printf("|+|                                                                                      |+|\n");
	        printf("|+|                                        GaAntre                                       |+|\n");
	        printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
	        printf("|+|                                                                                      |+|\n");
	        printf("|+|======================================================================================|+|\n");
	        printf("|+|                                                                                      |+|\n");
	        printf("|+|                                        Daftar                                        |+|\n");
	        printf("|+|                                                                                      |+|\n");
	        printf("|+|======================================================================================|+|\n");
	        printf("|+|Isi Formulir di bawah ini                                                             |+|\n");
			while (true) {
				printf("|+|Nama       : ");
				scanf(" %[^\n]", daftar.nama);
				clearBuffer();
				
				if (validasiNama(daftar.nama)) {
					break;
				} else {
					printf("|+|Nama tidak valid! Masukan nama yang sesuai!\n");
				} 
			} 
			spasiToGarisBawah(daftar.nama);
	
			while (true) {
				printf("|+|Usia       : ");
				scanf(" %[^\n]", daftar.usia);
				clearBuffer();
				if (validasiUsia(daftar.usia)) {
					break;
				} else {
					printf("|+|Usia tidak valid! Usia maksimum 3 digit dan harus berupa angka\n");
				}
			}
			
			
			while (true) {
		        printf("|+|No.Telepon : "); 
		        scanf(" %[^\n]", daftar.noTelp);
		        clearBuffer();
		        if (cekNoTelp(daftar.noTelp)) {
		            break;
		        } else {
		            printf("|+|Nomor telepon tidak valid. Silakan masukkan nomor telepon yang valid.\n");
		        }
		    }
		    
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
			while (true) {
				printf("|+|Pilih opsi: "); 
				scanf("%d", &daftar.penyakit);
				clearBuffer();
				if (validasiPenyakit(daftar.penyakit)) {
					break;
				} else {
					printf("|+|Pilih opsi yang sesuai!\n");
				}
			}	
			
			
			printf("|+|Edit? (y/n)");
			scanf(" %c", &opsi);
			clearBuffer();
			if (opsi == 'y' || opsi == 'Y') {
				valid = false;
			} else {
				daftar.prioritas = setPriority(daftar.penyakit);
				
				updateTime();
				strftime(daftar.jamDaftar, sizeof(daftar.jamDaftar), "%H:%M:%S", &timeSekarang);
	//			printf("waktu daftar: %s", daftar.jamDaftar);
				strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
				
				daftar.urutan = 0;
				todayList = fopen(filename, "a");
				if (todayList == NULL) {
					printf("|+|Gagal menyimpan data!");
				} else
				if (urutanTerakhir() >= maks) {
					printf("|+|Mohon maaf antrian sudah penuh!");
				} else {
					fprintf(todayList, "%s %s %s %s %s %s %d %d %d\n", 
		
						sedangLogin->username,
						sedangLogin->password,
						daftar.nama,
						daftar.usia,
						daftar.noTelp,
						daftar.jamDaftar,
						daftar.penyakit,
						daftar.prioritas,
						daftar.urutan);
						
						fclose(todayList);
					*display = 7;
				}
					// tampilkan nomor antrian dia
			}
			valid = true;
			break;
		}
	} while (!valid);
}

int urutanTerakhir() {
	char filename[30];
	updateTime();
	pasienAkun temp;
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
	FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Tidak dapat membuka file %s\n", filename);
    } else {
    	while (fscanf(file, "%s %s %s %s %s %s %d %d %d\n", 
					temp.akun.username,
					temp.akun.password,
					temp.pasien.nama,
					temp.pasien.usia,
					temp.pasien.noTelp,
					temp.pasien.jamDaftar,
					&temp.pasien.penyakit,
					&temp.pasien.prioritas,
					&temp.pasien.urutan) == 9) {
					}
		fclose(file);
	}
	return temp.pasien.urutan + 1;
}


int noAntrianUser (account *sedangLogin) {
	char filename[30];
	updateTime();
	pasienAkun temp;
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
	FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("|+|Tidak dapat membuka file %s\n", filename);
    } else {
    	while (fscanf(file, "%s %s %s %s %s %s %d %d %d\n", 
					temp.akun.username,
					temp.akun.password,
					temp.pasien.nama,
					temp.pasien.usia,
					temp.pasien.noTelp,
					temp.pasien.jamDaftar,
					&temp.pasien.penyakit,
					&temp.pasien.prioritas,
					&temp.pasien.urutan) == 9) {
						if (strcmp(temp.akun.username, sedangLogin->username) == 0) {
							break;
						}
					}
		fclose(file);
	}
	return temp.pasien.urutan;
}

void spasiToGarisBawah (char* nama) {
	int len = strlen(nama);
	for (int i = 0; i < len; i++) {
			if (nama[i] == ' ') {
				nama[i] = '_';
			}
	}
}

void garisBawahToSpasi (char *nama) { // dipake saat baca tree (passing parameter nama)
	int len = strlen(nama);
	for (int i = 0; i < len; i++) {
		if (nama[i] == '_') {
			nama[i] = ' ';
		}
	}
}

void simpanWaktuPendaftaran (char buka[], char tutup[], int maks) {
	FILE *filePendaftaran; 
	char tanggalToday[11];
	
	filePendaftaran = fopen("Data_Pembukaan.txt", "a");
	if (filePendaftaran == NULL) {
		printf("|+|Gagal membuka file!\n");
	} else {
		updateTime();
		strftime(tanggalToday, sizeof(tanggalToday), "%d-%m-%Y", &timeSekarang);
		fprintf(filePendaftaran, "%s %s %s %d\n", tanggalToday, buka, tutup, maks);
		
		fclose(filePendaftaran);
	}
}

void buatFilePembukaan() {
    FILE *file = fopen("Data_Pembukaan.txt", "r");
    if (file == NULL) {
        // File tidak ada, buat file baru
        file = fopen("Data_Pembukaan.txt", "w");
        if (file == NULL) {
            printf("|+|Gagal membuat file Data_Pembukaan.txt");
        }
    }
    fclose(file);
}

void buatFilePasien() {
	char filename[30];
	updateTime();
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
	
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        // File tidak ada, buat file baru
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("|+|Gagal membuat file Data_Pembukaan.txt");
        }
    }
    fclose(file);
}

void dataPendaftaranToday (char waktuBuka[], char waktuTutup[], int *maks) {
	FILE *filePendaftaran = fopen("Data_Pembukaan.txt", "r");
	char tanggalToday[11];
	char tanggalCari[11];
	updateTime();
	strftime(tanggalToday, sizeof(tanggalToday), "%d-%m-%Y", &timeSekarang);

	if (filePendaftaran == NULL) {
		printf("|+|Gagal membuka file!\n");
	} else {
		while (fscanf(filePendaftaran, "%s %s %s %d", tanggalCari, waktuBuka, waktuTutup, maks) == 4) {
			if (strcmp(tanggalCari, tanggalToday) == 0) {
				break;
			}
		}		
	}
}

void aturJamMenit (char waktuBuka[], char waktuTutup[], int *jBuka, int *mBuka, int *jTutup, int *mTutup) {
	sscanf(waktuBuka, "%2d:%2d", jBuka, mBuka);
	sscanf(waktuTutup, "%2d:%2d", jTutup, mTutup);
}

