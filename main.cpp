#include "GAANTRE.h"

int main() {
	
	int opsi = 1, display = 1, jamBuka = 0, menitBuka = 0, jamTutup = 0, menitTutup = 0;
	bool valid, running = true;
	address root = NULL;
	account sedangLogin;
	char filename[30];
	Pasien pasienSelesai;

	
	while (running) {
		switch (display) {
			case 1:
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n|+|");
                system("pause");
                system("cls");
                display = 2;
                
				break;


			case 2:
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
			        if (scanf("%d", &opsi) == true) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
			            printf("|+|Pilih Opsi: ");
			            fflush(stdin);
			        }
			    } while (!valid);
				
				if (opsi == 1) {
					//system("cls");
					display = 4;
				} else 
				if (opsi == 2) {
					//system("cls");
					display = 3;
				} else
				if (opsi == 0) {
					running = false;
				}
				break;
				
			case 3:
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
				membuatAkun(&display);
				//system("cls");
				break;
				

			case 4:
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
				login(&display, &sedangLogin);
				//system("cls");
				break;
	
			case 5:
                printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                        GaAntre                                       |+|\n");
                printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                         MENU                                         |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|======================================================================================|+|\n");
                printf("|+|1. Daftar Antrian                                                                     |+|\n");
                printf("|+|2. Mengeluarkan pasian yang selesai dari antrian                                      |+|\n");
                printf("|+|3. Pemberian nomor antrian                                                            |+|\n");
                printf("|+|4. Menentukan pembukaan dan penutupan pendaftaran                                     |+|\n");
                printf("|+|0. Keluar                                                                             |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Pilih opsi: ");
                valid = false;
				do {
			        if (scanf("%d", &opsi) == true) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
			            printf("|+|Pilih Opsi: ");
			            fflush(stdin);
			        }
			    } while (!valid);
			    
			    
				if (opsi == 1) {
					//system("cls");
                    display = 6;
                } else
				if (opsi == 2) {
                    root = pop(root, &pasienSelesai);
                    printf("|+|Pasien yang sedang konsultasi\n");
                    printf("|+|Nama: %s (%d)\n|+|\n|+|\n", pasienSelesai.nama, pasienSelesai.prioritas);
                    
                    displayTree(root);
                    printf("|+|");
                    system("pause");
                    //system("cls");
                    display = 5;
                } else 
				if (opsi == 3) {
					if (!waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)){
						display = 5;
					} else {
						sortAntrian(&root);
	                	displayTree(root); 
	                	printf("|+|");
	                	system("pause");
	                	//system("cls");
	                	display = 5;
					}
				} else
				if (opsi == 4){
				    printf("|+|Masukkan waktu buka pendaftaran (jam dan menit, pisahkan dengan spasi): ");
				    scanf("%d %d", &jamBuka, &menitBuka);
				
				    printf("|+|Masukkan waktu tutup pendaftaran (jam dan menit, pisahkan dengan spasi): ");
				    scanf("%d %d", &jamTutup, &menitTutup);
					waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup);
				} else
				if (opsi == 0) {
					//system("cls");
					display = 2;
				} 
				break;
					
			case 6:
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
                daftarAdmin(&root, &sedangLogin, &display);
                displayTree(root); 
                system("pause");
                //system("cls");
                opsi = 0;
                break;
				
			case 7:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                        GaAntre                                       |+|\n");
				printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         MENU                                         |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|1. Daftar Antrian                                                                     |+|\n");
				printf("|+|2. Tampilkan Nomor Antrian Sekarang                                                   |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|--------------------------------------------------------------------------------------|+|\n");
				printf("|+|Pilih opsi: ");
				valid = false;
				do {
			        if (scanf("%d", &opsi) == true) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
			            printf("|+|Pilih Opsi: ");
			            fflush(stdin);
			        }
			    } while (!valid);
			    
			    
				if (opsi == 1) {
					//system("cls");
					display = 8;
				} else
				if (opsi == 2) {
					//system("cls");
					display = 9;
				} else
				if (opsi == 0) {
					//system("cls");
					display  = 2;
				}
				break;
				
			case 8:
				printf("yang lagi login: %s %s\n", sedangLogin.username, sedangLogin.password);
				if (!waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)){
					display = 7;
				} else {
	                daftarPengguna(&root, &sedangLogin, &display);
	                //system("cls");
	                display = 7;
				}
				break;	
			case 9:
				if (!waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)){
					display = 7;
				} else {
					antrianSekarang (pasienSelesai, &display);
                	display = 7;
				}
                break;
			default:
				printf("Pilih opsi yang sesuai!");
				break;
		}
	}
	system("cls");
	printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                           Terimakasi Telah Menggunakan GaAntre                       |+|\n");
    printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|--------------------------------------------------------------------------------------|+|\n");
    sleep(3);
	return 0;
}

