#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "GAANTRE.h"

int main() {
	
	int opsi = 1;
	char opsichar;
	int display = 1;
	address root = NULL;
	
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
				system("cls");
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
				system("cls");
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
				system("cls");
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
				login(&display);
				break;
	
			case 5:
				system("cls");
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
                    //panggil Fungsi untuk pop
                }
                break;
                opsi = 0;
                break;

			case 6:
				system("cls");
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
                daftarAdmin(&root);
                printf("Keseluruhan Antrian:\n");
                displayTree(root); 
                opsi = 0;
                break;
				
			case 7:
				system("cls");
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
				break;
				
			case 8:
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
                daftarPengguna(&root);
                printf("Keseluruhan Antrian:\n");
                displayTree(root); 
                opsi = 0;
                break;
				
			case 9:
				system("cls");
                printf("Nomor Antrian Sekarang:\n");
                // Implementasi untuk menampilkan nomor antrian sekarang
                opsi = 0;
                break;
                
			default:
				printf("Pilih opsi yang sesuai!");
		}
	}
	


	return 0;
}
