#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Kdo si poctiv� s�m naprogramuje �koly, nem�l by m�t probl�m na programovac� p�semce. V ka�d� �loze nechte u�ivatele, a� zad�v� jm�na soubor�/souboru p�es kl�vesnici:

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
	V textov�m souboru je text a program jej p�ekop�ruje znak po znaku tak, �e vynech� ��slice, jinak v�e zapisuje beze zm�ny:
	Aho5j Kar4le 110j00ak se t11i vede0
	zap�e
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
	V textov�m souboru jsou na ka�d�m ��dku jm�no a plat. Vytvo�te program, kter� p�ekop�ruje jm�na do druh�ho souboru a 
	m�sto platu ke ka�d�mu jm�nu nap�e v procentech hodnotu odpov�daj�c� procentu�ln�mu mno�stv� pr�m�rn� mzdy.
	Nap�.
	Pavel 8000
	Karel 10000
	Program zjist� pr�m�rnou mzdu 9000 a do druh�ho souboru nap�e:
	Pavel 88 %
	Karel 111 %
	
	TIP: Aby se vypsala procenta, je pot�eba napsat %%: printf("Procenta %%");
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
	V textov�m souboru je v�dy ��slo a slovo. Program p�ekop�ruje soubor do druh�ho souboru tak, 
	�e v�dy vezme tolik�t� p�smeno ze slova, kolik n�m ud�v� ��slo stoj�c� p�ed slovem a toto p�smeno zap�e. 
	Indexuje se od 0, tak�e 0 Ahoj zap�e A.
	P�.: 0 Adam 2 vyhral 1 fotbal 0 jasne
	Zap�e: Ahoj
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
	V textov�m souboru je text a program jej p�ekop�ruje znak po znaku tak, �e vynech� ��slice, jinak v�e zapisuje beze zm�ny:
	Aho5j Kar4le 110j00ak se t11i vede0 
	zap�e
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
	V textov�m souboru je text a program zap�e ka�d� slovo obr�cen� do druh�ho souboru:
	johA elvaP kaj es ?edev
	Zap�e jako: Ahoj Pavle jak se vede?
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