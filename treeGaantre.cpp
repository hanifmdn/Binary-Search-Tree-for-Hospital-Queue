#include "GAANTRE.h"
#include "DISPLAYGAANTRE.h"
#include "VALIDGAANTRE.h"
#include "TREEGAANTRE.h"

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
        printf("|+|Tree kosong.\n");
    } else {
        displayPop(root);
    }
}
