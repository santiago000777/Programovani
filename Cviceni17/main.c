#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	V souboru je nejd��ve maska a pot� 10 IP adres. �kolem je zjistit, kter� IP adresy na sebe "vid�" podle masky s�t�
	(kter� PC s touto ip adresou jsou ve stejn� s�t�). Kontrolujte i to, zda se jedn� o korektn� IP adresu.
*/

typedef struct {
	int ip[4];

	bool isUsed;
} IP;

bool IsCorrect(IP adress) {
	bool kontrola = true;
	for (int i = 0; i < 4; i++) {
		kontrola = kontrola && adress.ip[i] >= 0 && adress.ip[i] <= 255;
	}

	return kontrola;
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

	fclose(file);
	return 0;
}