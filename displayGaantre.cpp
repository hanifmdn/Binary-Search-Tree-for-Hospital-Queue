#include "GAANTRE.h"
#include "DISPLAYGAANTRE.h"
#include "VALIDGAANTRE.h"

void displayAwal (int *display) {
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n|+|");
                system("pause");
                system("cls");
                *display = 2;
}

void displaySignUp (int *display, bool *running) {
				int opsi;
				bool valid;
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         GaAntre                                      |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         Sign Up                                      |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|1. Log In                                                                             |+|\n");
				printf("|+|2. Sign Up                                                                            |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|--------------------------------------------------------------------------------------|+|\n");
				printf("|+|Pilih opsi: ");
				valid = false;
				do {
			        if (scanf("%d", &opsi) == 1 && opsi >= 0 && opsi < 3) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!                                  |+|\n");
			            printf("|+|Pilih opsi: ");
			            clearBuffer();
			        }
			    } while (!valid);

				if (opsi == 1) {
					system("cls");
					*display = 4;
				} else 
				if (opsi == 2) {
					system("cls");
					*display = 3;
				} else
				if (opsi == 0) {
					system("cls");
					*running = false;
				} else {
					printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!                                  |+|\n");
				}
}

void displayBuatAkun (int *display) {
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                       GaAntre                                        |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                      Buat Akun                                       |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Silahkan buat akun baru                                                               |+|\n");
				membuatAkun(display);
				system("cls");
}


void displayLogin (int *display, account *sedangLogin) {
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                        GaAntre                                       |+|\n");
				printf("|+|                                Ga Perlu CAPE-CAPE Ngantre                            |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");                                                                                                                                                                   
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         LOGIN                                        |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Silahkan Login                                                                        |+|\n");
				login(display, sedangLogin);
				system("cls");
}

void displayDaftarAdmin (address root, account *sedangLogin, int *display) {
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
                daftarAdmin(&root, sedangLogin, display);
                system("cls");
}

void displayMenuPengguna (int *display, int *noAntrian) {
				int opsi;
				bool valid;
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                        GaAntre                                       |+|\n");
				printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
                printf("|+|No Antrian Sekarang: %04d                                                             |+|\n", *noAntrian);
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         MENU                                         |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|1. Daftar Antrian                                                                     |+|\n");
				printf("|+|2. Tampilkan Nomor Antrian Anda                                                       |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|--------------------------------------------------------------------------------------|+|\n");
				printf("|+|Pilih opsi: ");
				valid = false;
				do {
			        if (scanf("%d", &opsi) == 1 && opsi >= 0 && opsi < 3) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!                                  |+|\n");
			            printf("|+|Pilih opsi: ");
			            clearBuffer();
			        }
			    } while (!valid);
			    
			    
				if (opsi == 1) {
					system("cls");
					*display = 11;
				} else
				if (opsi == 2) {
					system("cls");
					*display = 12;
				} else
				if (opsi == 0) {
					system("cls");
					*display  = 2;
				} else {
					printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!                                  |+|\n");
				}
}

void displayMenuAdmin(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *noAntrian, address *root, char waktuBuka[], char waktuTutup[], bool *setTree, int maksPasien) {
    int opsi;
    char edit;
    bool valid;
    Pasien pasienSelesai;

    printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                                        GaAntre                                       |+|\n");
    printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
    printf("|+|No Antrian Sekarang: %04d                                                             |+|\n", *noAntrian);
    printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                                         MENU                                         |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|======================================================================================|+|\n");
    printf("|+|1. Daftar Antrian                                                                     |+|\n");
    printf("|+|2. Mengeluarkan pasien yang selesai dari antrian                                      |+|\n");
    printf("|+|3. Pemberian nomor antrian                                                            |+|\n");
    printf("|+|4. Menentukan pembukaan dan penutupan pendaftaran                                     |+|\n");
    printf("|+|0. Keluar                                                                             |+|\n");
    printf("|+|--------------------------------------------------------------------------------------|+|\n");
    printf("|+|Pilih opsi: ");
    valid = false;
    do {
        if (scanf("%d", &opsi) == 1 && opsi >= 0 && opsi < 5) {
            valid = true;
        } else {
            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!                                  |+|\n");
            printf("|+|Pilih opsi: ");
            clearBuffer();
        }
    } while (!valid);

    if (opsi == 1) {
    	system("cls");
        *display = 6;
    } else if (opsi == 2) {
        if (!sudahDibuka()) {
            printf("|+|Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!                |+|\n");
            sleep(1);
            system("cls");
        } else if (!setTree) {
            printf("|+|Antrian belum dibangun! Bangun antrian terlebih dahulu!                               |+|\n");
            sleep(1);
            system("cls");
        } else if (*root != NULL) {
        	system("cls");
            *display = 7;
        } else {
            printf("|+|Antrian kosong!                                                                       |+|\n");
            sleep(1);
            system("cls");
        }
    } else if (opsi == 3) {
        updateTime();
        if (!sudahDibuka()) {
            printf("|+|Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!                |+|\n");
            sleep(1);
            system("cls");
        } else if (waktuPendaftaran(*jamBuka, *menitBuka, *jamTutup, *menitTutup)) {
            printf("|+|Tunggu setelah pendaftaran ditutup pada pukul %s!                                     |+|\n", waktuTutup);
            system("pause");
            system("cls");
			*display = 5;
        } else {
            if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (*jamBuka * 60 + *menitBuka)) {
                printf("|+|Pendaftaran belum dibuka! Tidak dapat membangun antrian!                          |+|\n");
                sleep(1);
                system("cls");
            } else if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (*jamTutup * 60 + *menitTutup)) {
                system("cls");
				*display = 8;
                *setTree = true;
            }
        }
    } else if (opsi == 4) {
        if (sudahDibuka()) {
            printf("|+|Waktu pendaftaran hari ini telah ditentukan! %s - %s                             |+|\n", waktuBuka, waktuTutup);
            sleep(2);
            system("cls");
        } else {
        	system("cls");
            *display = 9;
        }
    } else if (opsi == 0) {
    	system("cls");
        *display = 2;
    }
}

void displayPop(int *display, address *root, int *noAntrian) {
    bool valid;
    Pasien pasienSelesai;
    
	    *root = pop(*root, &pasienSelesai);
	    printf("|+|======================================================================================|+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|                                        GaAntre                                       |+|\n");
        printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|======================================================================================|+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|                             Pasien yang Sedang konsultasi                            |+|\n");
        printf("                                 Nama: %s (%d)                                     \n", pasienSelesai.nama, pasienSelesai.prioritas);
        printf("|+|                                                                                      |+|\n");
        printf("|+|======================================================================================|+|\n");
	    *noAntrian = pasienSelesai.urutan;
        system("pause");
        system("cls");
        *display = 5;
}

void displayBangunAntrian(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup,address *root, char waktuBuka[6], char waktuTutup[6]){
    bool valid;
    Pasien pasienSelesai;
    
	printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                                        GaAntre                                       |+|\n");
    printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|======================================================================================|+|\n");
    sortAntrian(root);
    displayTree(*root);
    printf("|+|======================================================================================|+|\n");
    system("pause");
    system("cls");
    *display = 5;
}

void displayBukaTutupDaftar(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, address *root, char waktuBuka[6], char waktuTutup[6]){
	int maksPasien;
    char edit;
    bool setTree, valid;
    
    printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                                        GaAntre                                       |+|\n");
    printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|======================================================================================|+|\n");
	while (!sudahDibuka()) {
        printf("|+|Masukan maksimal jumlah pasien: ");
        scanf("%d", &maksPasien);
        clearBuffer();
        valid = false;
        while (!valid) {
            printf("|+|Masukan waktu buka pendaftaran (HH:MM): ");
            scanf("%s", waktuBuka);
            clearBuffer();
            if (validasiWaktu(waktuBuka, jamBuka, menitBuka)) {
                if (validasiWaktuBuka(*jamBuka, *menitBuka)) {
                    valid = true;
                    break;
                } else {
                    printf("|+|Waktu pembukaan harus lebih dari waktu sekarang!\n");
                }
            } else {
                printf("|+|Format waktu tidak valid!                                                             |+|\n");
            }
        }

        valid = false;
        while (!valid) {
            printf("|+|Masukan waktu tutup pendaftaran (HH:MM): ");
            scanf("%s", waktuTutup);
            clearBuffer();
            if (validasiWaktu(waktuTutup, jamTutup, menitTutup)) {
                if (validasiWaktuTutup(*jamTutup, *menitTutup, *jamBuka, *menitBuka)) {
                    valid = true;
                    break;
                } else {
                    printf("|+|Waktu penutupan harus lebih dari waktu sekarang dan waktu buka!                       |+|\n");
                }
            } else {
                printf("|+|Format waktu tidak valid                                                              |+|\n");
            }
        }
        printf("|+|[INFO] Anda tidak bisa mengubah waktu pendaftaran lagi setelah di submit              |+|\n");
        printf("|+|Edit? (y/n) ");
        scanf(" %c", &edit);

        if (edit == 'n' || edit == 'N') {
            waktuPendaftaran(*jamBuka, *menitBuka, *jamTutup, *menitTutup);
            simpanWaktuPendaftaran(waktuBuka, waktuTutup, maksPasien);
        }
    }
    system("cls");
    *display = 5;
}

void displayDaftarPengguna(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, int *maksPasien, address *root, account *sedangLogin, char waktuBuka[6], char waktuTutup[6]) {
    if (waktuPendaftaran(*jamBuka, *menitBuka, *jamTutup, *menitTutup)) {
        daftarPengguna(root, sedangLogin, display, *maksPasien);
        *display = 10;
    } else {
        if (!sudahDibuka()) {
            printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat melakukan pendaftaran!        |+|\n");
        } else if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (*jamBuka * 60 + *menitBuka)) {
            printf("|+|Pendaftaran belum dibuka! Silahkan coba lagi saat pukul %s                            |+|\n", waktuBuka);
        } else if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (*jamTutup * 60 + *menitTutup)) {
            printf("|+|Mohon maaf pendaftaran hari ini telah ditutup pada pukul %s                           |+|\n", waktuTutup);
        }
        system("pause");
        system("cls");
        *display = 10;
    }
}

void displayAntrianPengguna(int *display, int *jamBuka, int *menitBuka, int *jamTutup, int *menitTutup, account *sedangLogin, bool setTree) {
    pasienAkun akun = noAntrianUser(sedangLogin);
    updateTime();
	garisBawahToSpasi(akun.pasien.nama);
	bool sudahDaftar = cekTodayList(sedangLogin->username);
    if (sudahDaftar && setTree && (timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (*jamTutup * 60 + *menitTutup)) {
        printf("|+|======================================================================================|+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|                                        GaAntre                                       |+|\n");
        printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|======================================================================================|+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|                                   Nomor Antrian Anda                                 |+|\n");
        printf("|+|                                         %04d                                         |+|\n", akun.pasien.urutan);
        printf("|+|                                                                                      |+|\n");
        printf("|+|======================================================================================|+|\n");
        printf("|+|Nama : %s                                                                             |+|\n", akun.pasien.nama);
        printf("|+|Usia : %s                                                                             |+|\n", akun.pasien.usia);
    	printf("|+|Telp : %s                                                                             |+|\n", akun.pasien.noTelp);
        printf("|+|Jam  : %s                                                                             |+|\n", akun.pasien.jamDaftar);
		printf("|+|======================================================================================|+|\n");
		system("pasue");
 		system("cls");
        *display = 10;
    } else {
        if (!sudahDibuka()) {
            printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat menampilkan antrian!          |+|\n");
        } else if (waktuPendaftaran(*jamBuka, *menitBuka, *jamTutup, *menitTutup)) {
            printf("|+|Antrian belum bisa ditampilkan. Coba lagi setelah pendaftaran ditutup pukul %2d:%2d   |+|\n", *jamTutup, *menitTutup);
        } else if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (*jamBuka * 60 + *menitBuka)) {
            printf("|+|Pendaftaran belum dibuka! Tidak dapat menampilkan antrian!                            |+|\n");
        } else if (!sudahDaftar) {
        	printf("|+|Anda belum melakukan pendaftaran, tidak dapat menampilkan nomor antrian!              |+|\n");
        } else {	
		    printf("|+|Mohon maaf antrian belum bisa ditampilkan karena antrian belum dibangun               |+|\n");
        }
        system("pause");
        system("cls");
        *display = 10;
    }
}

void displayAkhir () {
	system("cls");
	printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                          Terimakasih Telah Menggunakan GaAntre                       |+|\n");
    printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|--------------------------------------------------------------------------------------|+|\n");
    sleep(3);
}
