#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
	Ti rychlejší si mùžou zkusit toto cvièení, kde máte za úkol vytvoøit 3 indexové soubory: jeden odpovídá seøazení podle jména, 
	další indexový soubor odpovídá seøazení podle èísla a poslední indexový soubor odpovídá seøazení podle zemì.
	
	Pro ty nejrychlejší: Další program bude zobrazovat data podle indexových souborù: naète data, indexové soubory a 
	uživatel si jen vybere, podle èeho chce data seøadit a díky indexovým souborùm se data rovnou vypíší (nic se neseøazuje, 
	již je to hotovo v indexových souborech.)
*/

typedef struct {
    char name[20];
    int age;
    char country[30];

} Entity;

void Print 

void InsertSort(int* pole, int* poleIndex, int pocet) { // predelat na 
    int vkladany, i;
    for (int d = 1; d < pocet; d++) {
        vkladany = pole[d];
        i = d;
        while (i > 0 && pole[i - 1] > vkladany) {
            pole[i] = pole[i - 1];
            i--;
        }
        pole[i] = vkladany;
    }
}

void IndexInsertSort(Entity* pole, int* poleIndex, int pocet) { // predelat na 
    int vkladany, i;
    for (int d = 1; d < pocet; d++) {
        vkladany = pole[d];
        i = d;
        while (i > 0 && pole[i - 1] > vkladany) {
            pole[i] = pole[i - 1];
            i--;
        }
        pole[i] = vkladany;
    }
}

int main() {
	

	return 0;
}