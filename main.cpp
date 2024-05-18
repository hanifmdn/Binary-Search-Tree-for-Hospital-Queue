#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GAANTRE.h"

int main() {
	
	int opsi = 1;
	char opsichar;
	int display = 1;
	address root = NULL;
	account sedangLogin;
	
	while (opsi != 0) {
		switch (display) {
			case 1:
				system("cls");
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Lanjut? (y/n) ");
                scanf(" %c", &opsichar);
                if (opsichar == 'y') {
                	display = 2;
				} else
				if (opsichar == 'n') {
					opsi = 0;
				}
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
				printf("|+|Sudah punya akun?                                                                     |+|\n");
				printf("|+|1. Sudah                                                                              |+|\n");
				printf("|+|2. Belum                                                                              |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|--------------------------------------------------------------------------------------|+|\n");
				printf("|+|Pilih opsi: ");
				scanf("%d", &opsi);
				if (opsi == 1) {
					display = 4;
				} else 
				if (opsi == 2) {
					display = 3;
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
                printf("|+|0. Keluar                                                                             |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Pilih opsi: ");
                scanf("%d", &opsi);
				if (opsi == 1) {
                    display = 6;
                } else if (opsi == 2) {
					Pasien pasienSelesai;
                    root = pop(root, &pasienSelesai);
                    displayTree(root);
                    system("pause");
                    display = 5;
                } else if (opsi == 0){
                	display = 2;
				} 
					display = 5;

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
				} else if (opsi == 2) {
					display = 9;
				} else if (opsi == 0){
					display  = 7;
				}
				break;
				
			case 8:
//				system("cls");
				printf("yang lagi login: %s %s", sedangLogin.username, sedangLogin.password);
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
                displayTree(root); 
                display = 2;
                break;
				
			case 9:
				system("cls");
                antrianSekarang (root);
                // Implementasi untuk menampilkan nomor antrian sekarang
                opsi = 0;
                break;
                
			default:
				printf("Pilih opsi yang sesuai!");
		}
	}
	


	return 0;
}
