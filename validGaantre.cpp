#include "GAANTRE.h"
#include "DISPLAYGAANTRE.h"
#include "VALIDGAANTRE.h"


bool waktuPendaftaran(int jamBuka, int menitBuka, int jamTutup, int menitTutup) {
	bool buka = false;
    updateTime();

    int bukaDalamMenit = jamBuka * 60 + menitBuka;
    int tutupDalamMenit = jamTutup * 60 + menitTutup;
    int sekarangDalamMenit = timeSekarang.tm_hour * 60 + timeSekarang.tm_min;
    

	if (sekarangDalamMenit >= bukaDalamMenit && sekarangDalamMenit <= tutupDalamMenit ) { 
		buka = true;
	}
	return buka;
}

bool cariUsername (FILE *dataAkun, char namaCari[]) {
	bool ditemukan = false;
	char username[17];
	
	if (dataAkun == NULL) {
		printf("|+|\n|+|Tidak dapat membuka file akunPengguna.txt\n");
	} else {
		while (fscanf(dataAkun, "%s", username) == 1) {
			if (strcmp(username, namaCari) == 0) {
				ditemukan = true;
				break;
			}
		}
	}
	return ditemukan;
}

bool cariAkun (FILE *dataAkun, account *cek, char cariUsername[20]) {
	bool ditemukan;
	if (dataAkun == NULL) {
		printf("|+|\n|+|Tidak dapat membuka file akunPengguna.txt");
	} else {
		while (fscanf(dataAkun, "%s %s %d", &cek->username, &cek->password, &cek->identifier) == 3) {
			if (strcmp(cek->username, cariUsername) == 0) {
				ditemukan = true;
				break;
			}
		}
	}
	return ditemukan;	
}

bool cekTodayList (char namaCari[]) {
	bool ditemukan = false;
	FILE *todayList;
	char filename[30];
	char username[17];
	
	updateTime();
	strftime(filename, sizeof(filename), "Data_Pasien_%d-%m-%Y.txt", &timeSekarang);
	
	
	todayList = fopen(filename, "a+");
	if (todayList == NULL) {
		printf("|+|\n|+|Tidak dapat membuka file %s\n", filename);
	} else {
		while (fscanf(todayList, "%s%*[^\n]", username) == 1) {
				if (strcmp(username, namaCari) == 0) {
					ditemukan = true;
					break;
			}
		}
		fclose (todayList);
	}
	return ditemukan;	
}

bool cekNoTelp(char *noTelp) {
	const char* listNomor[] = {"0811", "0812", "0813", "0821", "0822", "0852", "0853", 
	"0823", "0851", "0814", "0815", "0816", "0855", "0856", "0857", "0858", 
	"0817", "0818", "0819", "0859", "0877", "0878", "0895", "0896", "0897", "0898", 
	"0899", "0881", "0882", "0883", "0884", "0885", "0886", "0887", "0888", "0889"};
	
    if (strlen(noTelp) < 10 || strlen(noTelp) > 15) {
        return false;
    }

	int cekNomor = sizeof(listNomor) / sizeof(listNomor[0]);
	
	for (int i = 0; i < cekNomor; i++) {
    if (strncmp(noTelp, listNomor[i], strlen(listNomor[i])) == 0) {
        return true;
    	}
	}

    return false;
}

bool validasiWaktu(const char* waktu, int* jam, int* menit) {
	bool valid = true;
	int pisah = sscanf(waktu, "%2d:%2d", jam, menit);
    if (pisah != 2) {
        valid = false;
    }
	
	if (strlen(waktu) != 5) {
        valid = false;
    }
    
    if (*jam < 0 || *jam > 23 || *menit < 0 || *menit > 59) {
        valid = false;
    }
    return valid;
}

bool validasiWaktuBuka(int jam, int menit) {
	bool valid = true;
	updateTime();
	if (jam * 60 + menit < timeSekarang.tm_hour * 60 + timeSekarang.tm_min) {
		valid = false;
	}
	return valid;
}

bool validasiWaktuTutup(int jam, int menit, int jBuka, int mBuka) {
	bool valid = false;
	updateTime();
	if (jam * 60 + menit > timeSekarang.tm_hour * 60 + timeSekarang.tm_min && jam * 60 + menit > jBuka * 60 + mBuka) {
		valid = true;
	}
	return valid;
}

bool isAngka (const char* str) {
	bool valid = true;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (!isdigit(str[i])) {
			valid = false;
		}
	}
	return valid;
	
}

bool validasiUsia (const char* usia) {
	bool valid = true;
	if (strlen(usia) > 3) {
		valid = false;
	} else if (!isAngka(usia)) {
		valid = false;
	}
	return valid;
}

bool validasiUsername (const char* username) {
	bool valid = true;
	int len = strlen(username);
	if (len < 3 || len > 16) {
		valid = false;
	}
	
	for (int i = 0; i < len; i++) {
		if (!isalnum(username[i]) && username[i] != '_') {
			valid = false;
		}
	}
	return valid;
}

bool validasiPassword (const char* password) {
	int len = strlen(password);
	bool adaUpper, adaLower, adaAngka = false;
	
	if (len < 8 && len > 20) {
		return false;
	}
	
	for (int i = 0; i < len; i++) {
		if (isupper(password[i])) {
			adaUpper = true;
		} else
		if (islower(password[i])) {
			adaLower = true;	
		} else
		if (isdigit(password[i])) {
			adaAngka = true;
		}
	}
	
	return adaUpper && adaLower && adaAngka;
}

bool validasiPrioritas (int pilihan) {
	return (pilihan > 0 && pilihan < 5);
}

bool validasiPenyakit (int pilihan) {
	return (pilihan > 0 && pilihan < 16);
}

bool validasiNama (const char* nama) {
	bool valid = true;
	int len = strlen(nama);
	
	if (len < 2 || len > 50) {
		valid = false;
	}
	
	for (int i = 0; i < len; i++) {
		if (!isalpha(nama[i]) && !isspace(nama[i])) {
			valid = false;
		}
	}
	return valid;
}

bool sudahDibuka () {
	FILE *filePendaftaran = fopen("Data_Pembukaan.txt", "r");
	char tanggalToday[11];
	char tanggalCari[11];
	bool ditemukan = false;
	
	updateTime();
	strftime(tanggalToday, sizeof(tanggalToday), "%d-%m-%Y", &timeSekarang);
	
	if (filePendaftaran == NULL) {
		printf("|+|Gagal membuka file!\n");
	} else {
		while (fscanf(filePendaftaran, "%s", tanggalCari) == 1) {
			if (strcmp(tanggalCari, tanggalToday) == 0) {
				ditemukan = true;
				break;
			}
		}		
	}
	return ditemukan;
}

