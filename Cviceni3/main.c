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
	//	1) Vytvoøte program, který pøeète soubor data.txt (øádkù není více jak 8 000), kde na každém øádku je jméno, pøíjmení a vìk. 
	//	Tento program poté nakopíruje do druhého souboru, který vhodnì pojmenujte(tøeba povolavaci_prikaz.txt) všechny osoby které dosáhli
	//	minimálnì 18 let a maximálnì 60 let.Na obrazovku vypište, kolik jich bylo a jaký je prùmìrný vìk této nedobrovolné armády,
	//	která se už domù nepodívá.
	/*FILE* in = fopen("opravena_data.txt", "r");
	FILE* out = fopen("povolavaci_prikaz.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nelze otevrit soubory!\n");
		return 0;
	}

	
	Osoba lidi[8000];
	int pocet = Nacti(in, lidi);
	Prekopiruj(out, lidi, pocet);*/

	/*2) Vytvoøte program(pøekladaè politického dopisu do pravdivé podoby),
		který pøeète dopis.txt a bìhem toho bude všechna slova pøepisovat do druhého souboru(nìjak rozumnì pojmenujte),
		a to tak, že vše zùstane nezmìnìno až na slova zaèínající na ne / Ne, pøekladaè tato slova upraví tak,
		že jen vynechá to ne / Ne a zbytek zùstane beze zmìny(zdatnìjší by mohli poøešit i velikost písmene na zaèátku vìty).
		Takže napøíklad vìtu :
	Neuhodil jsem ji do oblièeje, takže jsem nevinný.
		Pøeloží na :
	Uhodil jsem ji do oblièeje, takže jsem vinný.*/

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