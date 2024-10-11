#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Kdo si poctivì sám naprogramuje úkoly, nemìl by mít problém na programovací písemce. V každé úloze nechte uživatele, a zadává jména souborù/souboru pøes klávesnici:

void Copy1(FILE* in, FILE* out) {
	char slovo[20];
	int plat;
	int sumPlat = 0;
	int pocetLidi = 0;
	while ((fscanf(in, "%19s%d", slovo, &plat)) == 2) {
		sumPlat += plat;
		pocetLidi++;
	}
	rewind(in);
	float prumPlat = (float)sumPlat / pocetLidi;
	printf("%0.2f", prumPlat);
	while ((fscanf(in, "%19s%d", slovo, &plat)) == 2) {
		fprintf(out, "%s %0.2f%%\n", slovo, (float)(plat * 100) / prumPlat);
	}
}

void Copy2(FILE* in, FILE* out) {
	int index;
	char slovo[20];
	
	while ((fscanf(in, "%d%19s", &index, slovo)) == 2) {
		fputc((int)slovo[index], out);
	}
}

void Copy3(FILE* in, FILE* out) {
	/*
	3)
	V textovém souboru je text a program jej pøekopíruje znak po znaku tak, že vynechá èíslice, jinak vše zapisuje beze zmìny:
	Aho5j Kar4le 110j00ak se t11i vede0
	zapíše
	Ahoj Karle jak se ti vede
	*/

	int c;
	while ((c = fgetc(in)) && c != EOF) {
		if (c >= '0' && c <= '9') {
			continue;
		}
		fputc(c, out);
	}
}

void Copy4(FILE* in, FILE* out) {

}

int main() {
	/*1)
	V textovém souboru jsou na každém øádku jméno a plat. Vytvoøte program, který pøekopíruje jména do druhého souboru a 
	místo platu ke každému jménu napíše v procentech hodnotu odpovídající procentuálnímu množství prùmìrné mzdy.
	Napø.
	Pavel 8000
	Karel 10000
	Program zjistí prùmìrnou mzdu 9000 a do druhého souboru napíše:
	Pavel 88 %
	Karel 111 %
	
	TIP: Aby se vypsala procenta, je potøeba napsat %%: printf("Procenta %%");
	*/
	/*char fileName[20];
	printf("Zadej nazev souboru, ktery bude zadanim:\t");
	scanf("%19s", fileName);

	FILE* in = fopen(fileName, "r");
	FILE* out = fopen("vysledek.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nepodarilo se otevrit soubory!\n");
		return 0;
	}

	Copy1(in, out);

	fclose(in);
	fclose(out);*/

	/*
	2)
	V textovém souboru je vždy èíslo a slovo. Program pøekopíruje soubor do druhého souboru tak, 
	že vždy vezme tolikáté písmeno ze slova, kolik nám udává èíslo stojící pøed slovem a toto písmeno zapíše. 
	Indexuje se od 0, takže 0 Ahoj zapíše A.
	Pø.: 0 Adam 2 vyhral 1 fotbal 0 jasne
	Zapíše: Ahoj
	*/

	/*char fileName[20];
	printf("Zadej nazev souboru:\t");
	scanf("%19s", fileName);

	FILE* in = fopen(fileName, "r");
	FILE* out = fopen("vysledek.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nepodarilo se otevrit soubory!\n");
		return 0;
	}

	Copy2(in, out);

	fclose(in);
	fclose(out);*/

	/*
	3)
	V textovém souboru je text a program jej pøekopíruje znak po znaku tak, že vynechá èíslice, jinak vše zapisuje beze zmìny:
	Aho5j Kar4le 110j00ak se t11i vede0 
	zapíše
	Ahoj Karle jak se ti vede
	*/

	/*char fileName[20];
	printf("Zadej nazev souboru:\t");
	scanf("%19s", fileName);

	FILE* in = fopen(fileName, "r");
	FILE* out = fopen("vysledek.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nepodarilo se otevrit soubory!\n");
		return 0;
	}

	Copy3(in, out);

	fclose(in);
	fclose(out);*/

	/*
	4)
	V textovém souboru je text a program zapíše každé slovo obrácenì do druhého souboru:
	johA elvaP kaj es ?edev
	Zapíše jako: Ahoj Pavle jak se vede?
	*/

	char fileName[20];
	printf("Zadej nazev souboru:\t");
	scanf("%19s", fileName);

	FILE* in = fopen(fileName, "r");
	FILE* out = fopen("vysledek.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nepodarilo se otevrit soubory!\n");
		return 0;
	}

	Copy4(in, out);

	fclose(in);
	fclose(out);

	return 0;
}