#include <iostream>
#include <stdio.h>
#include "gaantre.h"

int main() {
	int opsi ;
	char pilihan;
	
	do {
		printf("|+|======================================================================================|+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
        printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
        printf("|+|                                                                                      |+|\n");
        printf("|+|======================================================================================|+|\n");
        printf("|+|Lanjut (y/n)? ");
		scanf(" %c", &pilihan);
		
		switch (pilihan) {
			case 'y' :
				system("cls");
				menu();
				printf("|+|Sudah punya akun?                                                                     |+|\n");
				printf("|+|1. Sudah                                                                              |+|\n");
				printf("|+|2. Belum                                                                              |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|Pilih opsi: ");
	        	scanf("%d", &opsi);
	        	
	        	switch (opsi){
		        	case 1:
						system("cls");
						menu();
						login();
				case 2:
					system(cls);
					menu();
					membuatAkun();
				//case 3:
					// belum punya
				//case 4:
					// login
				//case 5:
					// tampilan admin
				//case 6:
					// tampilan pasien
				default:
					printf("Pilih opsi yang sesuai!");
				}
				
	        case 'n' :
	        	break;
	        	

			default:
				printf("Pilih opsi yang sesuai!");
		}
	} while (opsi != 0);
	


	return 0;
}
