#include "GAANTRE.h"

int main() {
	
	int opsi = 1, display = 1, jamBuka = 1, menitBuka = 1, jamTutup = 1, menitTutup = 1, maksPasien = 1, noAntrian = 0, urutUser;
	bool running = true;
	bool valid, setWaktu, setTree = false;
	char edit;
	char waktuBuka[6], waktuTutup[6];
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
			        if (scanf("%d", &opsi) == 1) {
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
                printf("|+|No Antrian Sekarang: %04d                                                             |+|\n", noAntrian);
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
			        if (scanf("%d", &opsi) == 1) {
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
					if (setWaktu == false) {
						printf("|+| Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!\n");
					} else
					if (!setTree) {
						printf("|+| Antrian belum dibangun! Bangun antrian terlebih dahulu!\n");
					} else
					if (root != NULL) {
						root = pop(root, &pasienSelesai);
						printf("|+| Pasien yang sedang konsultasi\n");
                   		printf("|+| Nama: %s (%d)\n|+|\n|+|\n", pasienSelesai.nama, pasienSelesai.prioritas);
                   		noAntrian = pasienSelesai.urutan;
					} else {
						printf("|+| Antrian sudah kosong!");
					}
                    
                    
                    
//                    displayTree(root);
                    printf("|+|");
                    system("pause");
                    //system("cls");
                    display = 5;
                    
                } else 
				if (opsi == 3) {
					updateTime();
					if (setWaktu == false) {
						printf("|+|Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!\n");
					} else
					if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
						printf("|+|Tunggu setelah pendaftaran ditutup!\n");
						display = 5;
					} else {
						if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
							printf("|+|Pendaftaran belum dibuka! Tidak dapat membangun antrian!\n");
						} else
						if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
							sortAntrian(&root);
	                		displayTree(root); 
	                		printf("|+|");
	                		system("pause");
	                		//system("cls");
	                		display = 5;
	                		setTree = true;
						}
					}
			
					
				} else
				if (opsi == 4) {
					if (setWaktu) {
					printf("|+|Waktu pendaftaran hari ini telah ditentukan!\n"); // SEBELUM ADA YANG DAFTAR MASIH BISA DI EDIT, SETELAH ADA YANG DAFTAR GABISA LAGI, cek file tanggal hari ini ada ga gitu bro
					system("pause");
					} else {
						while (!setWaktu) {
							printf("|+|Masukan maksimal jumlah pasien: ");
							scanf("%d", &maksPasien);
							clearBuffer();
							valid = false;
							while (!valid) {
							    printf("|+|Masukan waktu buka pendaftaran (HH:MM): ");
							    scanf("%s", waktuBuka);
							    clearBuffer();
							    if (validasiWaktu(waktuBuka, &jamBuka, &menitBuka)) {
							    	valid = true;
								} else {
									printf("Format waktu tidak valid\n");
								}
							}
							
							valid = false;
							while (!valid) {
							    printf("|+|Masukan waktu tutup pendaftaran (HH:MM): ");
							    scanf("%s", waktuTutup);
							    clearBuffer();
							    if (validasiWaktu(waktuTutup, &jamTutup, &menitTutup)) {
							    	valid = true;
							    	break;
								} else {
									printf("|+|Format waktu tidak valid\n");
								}								
							} 

													
						
							printf("|+|[INFO] Anda tidak dapat mengubah waktu pendaftaran lagi\n");
							printf("|+|Edit? (y/n) ");
							scanf(" %c", &edit);
								
							if (edit == 'n' || edit == 'N') {
								waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup);
								setWaktu = true;
							} 
						} 
					display = 5;
					}
					
					
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
                printf("|+|No Antrian Sekarang: %04d                                                             |+|\n", noAntrian);
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
			        if (scanf("%d", &opsi) == 1) {
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
				if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
					daftarPengguna(&root, &sedangLogin, &display, maksPasien);
	                //system("cls");
					display = 7;
				} else {
					if (!setWaktu) {
						printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat melakukan pendaftaran!\n");		
					} else
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
						printf("|+|Pendaftaran belum dibuka! Silahkan coba lagi saat pukul %02d:%02d\n", jamBuka, menitBuka);
					} else
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
						printf("|+|Mohon maaf pendaftaran hari ini telah ditutup!\n");
					}
	                display = 7;
				}
				break;	
			case 9:
				updateTime();
				if (setTree && (timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
					printf("|+|Nomor antrian anda adalah %d", noAntrianUser(&sedangLogin));
                	display = 7;
				} else {
					if (!setWaktu) {
						printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat menampilkan antrian!\n");
					} else
					if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
						printf("|+|Mohon maaf antrian belum bisa ditampilkan. Coba lagi setelah pendaftaran ditutup pukul %2d:%2d\n", jamTutup, menitTutup);
					} else 
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
						printf("|+|Pendaftaran belum dibuka! Tidak dapat menampilkan antrian!\n");
					} else {
						printf("|+|Mohon maaf antrian belum bisa ditampilkan karena antrian belum buat\n"); // admin belum membangun antrian
					}
					display = 7;
				}
                break;
			default:
				printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
				break;
		}
	}
	system("cls");
	printf("|+|======================================================================================|+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|                          Terimakasih Telah Menggunakan GaAntre                       |+|\n");
    printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
    printf("|+|                                                                                      |+|\n");
    printf("|+|--------------------------------------------------------------------------------------|+|\n");
    sleep(3);
	return 0;
}

