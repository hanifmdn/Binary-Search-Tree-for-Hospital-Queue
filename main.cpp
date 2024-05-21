
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GAANTRE.h"

int main() {
	
	int opsi = 1;
	bool running = true;
	int display = 1;
	address root = NULL;
	account sedangLogin;
	char filename[30];
	Pasien pasienSelesai;

	
	while (running) {
		switch (display) {
			case 1:
				system("cls");
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n|+|");
                system("pause");
                display = 2;
                system("cls");
				break;


			case 2:
//				system("cls");
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
				scanf("%d", &opsi);
				if (opsi == 1) {
					display = 4;
				} else 
				if (opsi == 2) {
					display = 3;
				} else
				if (opsi == 0) {
					running = false;
				}
				break;

			case 3:
//				system("cls");
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
				break;
				

			case 4:
//				system("cls");
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
				break;
	
			case 5:
//				system("cls");
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
                printf("|+|2. Mengeluarkan pasian yang selesai                                                   |+|\n");
                printf("|+|3. Pemberian nomor antrian                                                            |+|\n");
                printf("|+|0. Keluar                                                                             |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Pilih opsi: ");
                scanf("%d", &opsi);
				if (opsi == 1) {
                    display = 6;
                } else
				if (opsi == 2) {
                    root = pop(root, &pasienSelesai);
                    printf("|+|Pasien yang telah selesai\n");
                    printf("|+|Nama: %s (%d)\n", pasienSelesai.nama, pasienSelesai.prioritas);
                    
                    displayTree(root);
                    system("pause");
                    display = 5;
                } else 
				if (opsi == 3) {
                	sortAntrian(&root);
                	displayTree(root); 
                	system("pause");
                	display = 5;
				} else
				if (opsi == 0) {
					display = 2;
				} 
				break;
					
			case 6:
//				system("cls");
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
                opsi = 0;
                break;
				
			case 7:
//				system("cls");
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
				scanf("%d", &opsi);
				if (opsi == 1) {
					display = 8;
				} else
				if (opsi == 2) {
					display = 9;
				} else
				if (opsi == 0) {
					display  = 2;
				}
				break;
				
			case 8:
//				system("cls");
				printf("yang lagi login: %s %s\n", sedangLogin.username, sedangLogin.password);
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
                daftarPengguna(&root, &sedangLogin, &display);
//                displayTree(root);
                display = 7;
                break;
				
			case 9:
//				system("cls");
				if (isItAlreadyTheTime()) {
					printf("Antrian Sekarang");
	                printf("Nama     : %s\n", pasienSelesai.nama);
	                printf("Prioritas: %d\n", pasienSelesai.prioritas);
	                printf("Urutan   : %d\n", pasienSelesai.urutan);
	                system("pause");
	                display = 7;
				} else {
					printf("Nomor antrian belum keluar! Silahkan coba saat sudah jam 9\n");
					display = 7;
				}
                
                break;
                
			default:
				printf("Pilih opsi yang sesuai!");
		}
	}
	


	return 0;
}

