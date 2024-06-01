#include "GAANTRE.h"
#include "DISPLAYGAANTRE.h"
#include "VALIDGAANTRE.h"

int main() {
	int opsi = 1, display = 1, jamBuka = 0, menitBuka = 0, jamTutup = 0, menitTutup = 0, maksPasien, noAntrian = 0, urutUser;
	bool running = true;
	bool valid, setTree = false;
	char edit;
	char waktuBuka[6], waktuTutup[6];
	address root = NULL;
	account sedangLogin;
	char filename[30];
	Pasien pasienSelesai;
	buatFilePembukaan();
	buatFilePasien();
	dataPendaftaranToday(waktuBuka, waktuTutup, &maksPasien);
	aturJamMenit (waktuBuka, waktuTutup, &jamBuka, &menitBuka, &jamTutup, &menitTutup);

	
	while (running) {
		switch (display) {
			case 1:
				displayAwal (&display);
				break;
				
			case 2:
				displaySignUp (&display, &running);
				break;
				
			case 3:
				displayBuatAkun (&display);
				break;
				
			case 4:
				displayLogin (&display, &sedangLogin);
				break;
	
			case 5:
                displayMenuAdmin(&display, &jamBuka, &menitBuka, &jamTutup, &menitTutup, &noAntrian, &root, waktuBuka, waktuTutup);
				break;
				
			case 6:
				displayDaftarAdmin(root, &sedangLogin, &display);
                break;
				
			case 7:
				displayPop(&display, &root, &noAntrian);
				break;
				
			case 8:
				displayBangunAntrian(&display, &jamBuka, &menitBuka, &jamTutup, &menitTutup, &root, waktuBuka, waktuTutup);
				break;
				
			case 9:
				displayBukaTutupDaftar(&display, &jamBuka, &menitBuka, &jamTutup, &menitTutup, &root, waktuBuka, waktuTutup);
				break;
				
			case 10:
				displayMenuPengguna (&display, &noAntrian);
				break;
				
			case 11:
				displayDaftarPengguna(&display, &jamBuka, &menitBuka, &jamTutup, &menitTutup, &maksPasien, &root, &sedangLogin, waktuBuka, waktuTutup);
				break;
		
			case 12:
				displayMenuAntrianSekarang(&display, &jamBuka, &menitBuka, &jamTutup, &menitTutup, &sedangLogin);
                break;
                
			default:
				printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
				break;
		}
	}
	displayAkhir();
	return 0;
}

