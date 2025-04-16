#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	V souboru je nejdøíve maska a poté 10 IP adres. Úkolem je zjistit, které IP adresy na sebe "vidí" podle masky sítì
	(které PC s touto ip adresou jsou ve stejné sítí). Kontrolujte i to, zda se jedná o korektní IP adresu.
*/

typedef struct {
	int ip[4];

	bool vidi;
} IP;

bool IsCorrect(IP adress) {
	bool kontrola = true;
	for (int i = 0; i < 4; i++) {
		kontrola = kontrola && adress.ip[i] >= 0 && adress.ip[i] <= 255;
	}

	return kontrola;
}

int Nacti(FILE* in, IP* pArr) {
	int count = 0;
	int pocNeplatnych = 0;
	while (fscanf(in, "%d.%d.%d.%d", &pArr[count].ip[0], &pArr[count].ip[1], &pArr[count].ip[2], &pArr[count].ip[3]) == 4) {
		if (IsCorrect(pArr[count])) {
			pArr[count].vidi = 0;
			count++;
		}
		else {
			pocNeplatnych++;
			printf("%d. IP adresa je neplatna!\n", count + pocNeplatnych);
		}
	}

	return count;
}

bool Porovnani(IP mask, IP currAdress, IP ad) {
	char currBit, bit;

	for (int i = 0; i < 4; i++) {
		while (mask.ip[i] != 0) {
			currBit = currAdress.ip[i] & 0x01;
			bit = ad.ip[i] & 0x01;
			if ((currBit & (mask.ip[i] & 0x01)) != (bit & (mask.ip[i] & 0x01))) {
				return false;
			}
			mask.ip[i] >>= 1;
			currAdress.ip[i] >>= 1;
			ad.ip[i] >>= 1;
		}
	}
	return true;
}

void Print(IP* pArr, int count) {
	
	for (int i = 0; i < count; i++) {
		if (pArr[i].vidi) {
			
			printf("\t%d.%d.%d.%d\n", pArr[i].ip[0], pArr[i].ip[1], pArr[i].ip[2], pArr[i].ip[3]);
			pArr[i].vidi = 0;
		}
	}
}

void Kontrola(IP* const mask, IP* pArr, int count) {
	printf("\nNa stejne siti:\n");
	for (int k = 0; k < count; k++) {
		if (pArr[k].vidi) {
			continue;
		}
		for (int i = k + 1; i < count; i++) {
			if (Porovnani(*mask, pArr[k], pArr[i])) {
				pArr[k].vidi = 1;
				pArr[i].vidi = 1;
			}
		}

		Print(pArr, count);
		printf("--------------------\n");
	}
}

int main() {
	FILE* file = fopen("ip.txt", "r");
	if (file == NULL) {
		return -1;
	}

	IP mask;
	IP pole[100];
	if (fscanf(file, "%d.%d.%d.%d", &mask.ip[0], &mask.ip[1], &mask.ip[2], &mask.ip[3]) != 4) {
		return -1;
	}

	int count = Nacti(file, pole);
	Kontrola(&mask, pole, count);

	fclose(file);

	return 0;
}