// 10. cv

/*Vytvoøte program s MENU (viz 6. cvièení), kde si uživatel vybere, jakým algoritmem pro vyhledávání uživatel vyhledá jím zadanou hodnotu v 
souboru èísel (bude naèteno v poli).
V menu bude na výbìr z 5 vyhledávacích algoritmù: sekvenèní na neseøazeném poli se zarážkou i bez zarážky, sekvenèní na seøazeném poli èísel 
bez zarážky i se zarážkou, binární vyhledávání.
Dále vytvoøte funkci, která ovìøí, zda naètená èísla v poli jsou seøazena. Pokud budete vyhledávat na seøazeném poli, zjistìte si, 
zda je seøazené a pokud ne, tak si ta èísla seøaïte.

Vyhledávat budete tak dlouho, dokud nedáte povel "ukonèit program".

Soubory s celými èísly jsou v pøíloze. Na zaèátku programu zadejte název souboru.
Velikost statického pole vám bude staèit nastavit na velikost 7000. (int pole[MAX] se symbolickou konstantou) Nezapomeòte nechat místo 
na zarážku.*/

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