// 10. cv

/*Vytvo�te program s MENU (viz 6. cvi�en�), kde si u�ivatel vybere, jak�m algoritmem pro vyhled�v�n� u�ivatel vyhled� j�m zadanou hodnotu v 
souboru ��sel (bude na�teno v poli).
V menu bude na v�b�r z 5 vyhled�vac�ch algoritm�: sekven�n� na nese�azen�m poli se zar�kou i bez zar�ky, sekven�n� na se�azen�m poli ��sel 
bez zar�ky i se zar�kou, bin�rn� vyhled�v�n�.
D�le vytvo�te funkci, kter� ov���, zda na�ten� ��sla v poli jsou se�azena. Pokud budete vyhled�vat na se�azen�m poli, zjist�te si, 
zda je se�azen� a pokud ne, tak si ta ��sla se�a�te.

Vyhled�vat budete tak dlouho, dokud ned�te povel "ukon�it program".

Soubory s cel�mi ��sly jsou v p��loze. Na za��tku programu zadejte n�zev souboru.
Velikost statick�ho pole v�m bude sta�it nastavit na velikost 7000. (int pole[MAX] se symbolickou konstantou) Nezapome�te nechat m�sto 
na zar�ku.*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int PocetPrvku(FILE* file) {
	int i = 0;
	int cis;

	while (fscanf(file, "%d", &cis) == 1) {
		i++;
	}

	return i;
}

bool JeSerazeno(int* pArr, int pocet) {
	for (int i = 0; i < pocet - 1; i++) {
		if (pArr[i] > pArr[i + 1]) {
			return false;
		}
	}

	return true;
}

int SekvencniVyhledavani(int* pArr, int pocet, int klic) {
	int index = 0;
	while (index < pocet && pArr[index] != klic) {
		index++;
	}

	if (index >= pocet) {
		return -1;
	}
	return index;
}

int SekvencniVyhledavaniZarazka(int* pArr, int pocet, int klic) {
	pArr[pocet - 1] = klic;
	int index = 0;

	while (pArr[index] != klic) {
		index++;
	}

	if (index >= pocet) {
		return -1;
	}

	return index;
}

int SekvenciSerazeno(int* pArr, int pocet, int klic) {
	int index = 0;

	while (index < pocet && pArr[index] < klic) {
		index++;
	}

	if (index < pocet && pArr[index] == klic) {
		return index;
	}
	
	return -1;
}

int SeZaraskouSerazeno(int* pArr, int pocet, int klic) {
	pArr[pocet - 1] = klic;
	int index = 0;

	while (pArr[index] < klic) {
		index++;
	}

	if (index < pocet && pArr[index] == klic) {
		return index;
	}

	return -1;
}

int BinVyhledavani(int* pArr, int levy, int pravy, int klic) {
	if (levy > pravy) {
		return -1;
	}

	int stred = (levy + pravy) / 2;
	if (pArr[stred] == klic) {
		return stred;
	}
	if (pArr[stred] < klic) {
		BinVyhledavani(pArr, stred + 1, pravy, klic);
	}
	else {
		BinVyhledavani(pArr, levy, stred - 1, klic);
	}
}

// zkouska zadavani jmena
 

void Menu() {
	printf("Zadej cislo:\n");
	printf("Sekvencni vyhledavani\n");
	printf("Sekvencni vyhledavani bez zarazky\n");

}

int main() {
	printf("Zdadej nazev Souboru\n");
	char soubor[20];
	scanf("%19s", soubor);

	FILE* in = fopen(soubor, "r");
	FILE* out = fopen("vysledek.txt", "w");

	int pocet = PocetPrvku(in);
	int* pole = malloc(sizeof(int) * pocet);

	bool serazeno = JeSerazeno(pole, pocet);



	fclose(in);
	fclose(out);

	return 0;
}