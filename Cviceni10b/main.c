// 10. cv

/*
Vytvoøte program s MENU (viz 6. cvièení), kde si uživatel vybere, jakým algoritmem pro vyhledávání uživatel vyhledá jím zadanou hodnotu v 
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

	rewind(file);
	return i;
}

void NactiPole(FILE* file, int* pArr, int pocet) {
	int cis;
	for (int i = 0; i < pocet; i++) {
		fscanf(file, "%d", &cis);
		pArr[i] = cis;
	}
}

bool JeSerazeno(int* pArr, int pocet) {
	for (int i = 0; i < pocet - 1; i++) {
		if (pArr[i] > pArr[i + 1]) {
			return false;
		}
	}

	return true;
}

//void BubbleSort(int* pole, int pocet) {
//	int pom;
//	for (int d = 0; d < pocet - 2; d++) {
//		for (int i = pocet - 1; i >= d + 1; i--) {
//			if (pole[i - 1] > pole[i]) {
//				pom = pole[i];
//				pole[i] = pole[i - 1];
//				pole[i - 1] = pom;
//			}
//		}
//	}
//}

void InsertSortZarazkaKonec(int* pole, int pocet) {
	pocet++;
	int i;
	for (int d = pocet - 3; d >= 0; d--) {
		pole[pocet - 1] = pole[d];
		i = d;
		while (pole[pocet - 1] > pole[i + 1]) {
			pole[i] = pole[i + 1];
			i++;
		}
		pole[i] = pole[pocet - 1];
	}
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
		return BinVyhledavani(pArr, stred + 1, pravy, klic);
	}
	else {
		return BinVyhledavani(pArr, levy, stred - 1, klic);
	}
}

void Menu() {
	printf("\t1 .. Sekvencni vyhledavani bez zarazky\n");
	printf("\t2 .. Sekvencni vyhledavani\n");
	printf("\t3 .. Binarni vyhledavani\n\n");
	printf("\t0 .. Konec!\n");
	printf("Vyber, co se ma dit:  ");
}

int main() {
	printf("Zdadej nazev souboru:\n");
	char soubor[20];
	scanf("%19s", soubor);

	FILE* in = fopen(soubor, "r");
	//FILE* out = fopen("vysledek.txt", "w");

	if (in == NULL/* || out == NULL*/) {
		return -1;
	}

	int pocet = PocetPrvku(in); 
	int* pole = malloc(sizeof(int) * pocet + 1); // zarazka
	NactiPole(in, pole, pocet);

	printf("Zdadej cislo ke hledani:\t");
	int klic;
	scanf("%d", &klic);
	printf("\n");

	bool serazeno = false;
	if (!JeSerazeno(pole, pocet)) {
		printf("Vase pole je neserazeno, chcete jej seradit? (0 - ne; 1 - ano)\n");
		int volba;
		scanf("%d", &volba);

		if (volba == 1) {
			InsertSortZarazkaKonec(pole, pocet); // zarazka uz zapocitana
			serazeno = true;
		}
		
	}
	
	int volba, index;

	system("cls");
	do {
		printf("Tvuj klic je cislo: %d\n", klic);
		Menu();
		scanf("%d", &volba);

		switch (volba) {
			case 1: {
				if (serazeno) {
					index = SekvenciSerazeno(pole, pocet, klic);
				}
				else {
					index = SekvencniVyhledavani(pole, pocet, klic);
				}

				break;
			}
			case 2: {
				if (serazeno) {
					index = SeZaraskouSerazeno(pole, pocet, klic);
				}
				else {
					index = SekvencniVyhledavaniZarazka(pole, pocet, klic);
				}

				break;
			}
			case 3: {
				if (!serazeno) {
					InsertSortZarazkaKonec(pole, pocet);
					serazeno = true;
				}

				index = BinVyhledavani(pole, 0, pocet - 1, klic);
				break;
			}
		}

		if (index != -1) {
			printf("Hledane cislo %d je na %d. pozici!\n", klic, index + 1);
		}
		else {
			printf("Hledane cislo %d se v souboru nevyskytuje!\n", klic);
		}

		system("pause");
		system("cls");
	} while (volba != 0);


	fclose(in);
	//fclose(out);

	return 0;
}