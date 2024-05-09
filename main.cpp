#include <iostream>
#include <stdio.h>
#include "GAANTRE.h"

int main() {
	int opsi = 1;
	int display = 1;
	
	while (opsi != 0) {
		switch (display) {
			case 1:
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|======================================================================================|+|\n");
			case 2:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         GaAntre                                      |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         LOGIN                                        |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Sudah punya akun?                                                                     |+|\n");
				printf("|+|1. Sudah                                                                              |+|\n");
				printf("|+|2. Belum                                                                              |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|Pilih opsi:                                                                           |+|\n");
				printf("|+|======================================================================================|+|\n");
				scanf("%d", &opsi);
				if (opsi == 1) {
					opsi = 3;
				} else 
				if (opsi == 2) {
					opsi = 2;
				}

			case 3:
				// belum punya
			case 4:
				// login
			case 5:
				// tampilan admin
			case 6:
				// tampilan pasien
			default:
				printf("Pilih opsi yang sesuai!");
		}
	}
	


	return 0;
}