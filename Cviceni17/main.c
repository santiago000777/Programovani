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