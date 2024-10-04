#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
	char jmeno[50], prijmeni[50];
	int vek;
} Osoba;

int Nacti(FILE* in, Osoba* pOsoba) {
	int pocet = 0;
	while (fscanf_s(in, "%s%s%d", pOsoba[pocet].jmeno, 49, pOsoba[pocet].prijmeni, 49, &pOsoba[pocet].vek) == 3) {
		pocet++;
	}
	
	return pocet;
}

void Prekopiruj(FILE* out, Osoba* pOsoba, int pocet) {
	int pocetPovolanych = 0;
	int sumVek = 0;
	for (int i = 0; i < pocet; i++) {
		if (pOsoba[i].vek >= 18 && pOsoba[i].vek <= 60) {
			fprintf(out, "%s %s %d\n", pOsoba[i].jmeno, pOsoba[i].prijmeni, pOsoba[i].vek);
			sumVek += pOsoba[i].vek;
			pocetPovolanych++;
		}
	}
	printf("Pocet: %d\nPrumer: %0.2f", pocetPovolanych, (float)sumVek / pocetPovolanych);
}

int main() {
	//	1) Vytvo�te program, kter� p�e�te soubor data.txt (��dk� nen� v�ce jak 8 000), kde na ka�d�m ��dku je jm�no, p��jmen� a v�k. 
	//	Tento program pot� nakop�ruje do druh�ho souboru, kter� vhodn� pojmenujte(t�eba povolavaci_prikaz.txt) v�echny osoby kter� dos�hli
	//	minim�ln� 18 let a maxim�ln� 60 let.Na obrazovku vypi�te, kolik jich bylo a jak� je pr�m�rn� v�k t�to nedobrovoln� arm�dy,
	//	kter� se u� dom� nepod�v�.
	/*FILE* in = fopen("opravena_data.txt", "r");
	FILE* out = fopen("povolavaci_prikaz.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nelze otevrit soubory!\n");
		return 0;
	}

	
	Osoba lidi[8000];
	int pocet = Nacti(in, lidi);
	Prekopiruj(out, lidi, pocet);*/

	/*2) Vytvo�te program(p�eklada� politick�ho dopisu do pravdiv� podoby),
		kter� p�e�te dopis.txt a b�hem toho bude v�echna slova p�episovat do druh�ho souboru(n�jak rozumn� pojmenujte),
		a to tak, �e v�e z�stane nezm�n�no a� na slova za��naj�c� na ne / Ne, p�eklada� tato slova uprav� tak,
		�e jen vynech� to ne / Ne a zbytek z�stane beze zm�ny(zdatn�j�� by mohli po�e�it i velikost p�smene na za��tku v�ty).
		Tak�e nap��klad v�tu :
	Neuhodil jsem ji do obli�eje, tak�e jsem nevinn�.
		P�elo�� na :
	Uhodil jsem ji do obli�eje, tak�e jsem vinn�.*/

	FILE* in = fopen("dopis.txt", "r");
	FILE* out = fopen("novyDopis.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nelze otevrit soubory!\n");
		return 0;
	}
	char slovo[50];
	while (fscanf_s(in, "%s", slovo, 49) == 1) {
		if (slovo[0] == 'N' || slovo[0] == 'n' && slovo[1] == 'e') {
			fprintf(out, "%s ", &slovo[2]);
		}
		else {
			fprintf(out, "%s ", slovo);
		}
	}

	return 0;
}