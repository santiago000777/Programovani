#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
	Ti rychlej�� si m��ou zkusit toto cvi�en�, kde m�te za �kol vytvo�it 3 indexov� soubory: jeden odpov�d� se�azen� podle jm�na, 
	dal�� indexov� soubor odpov�d� se�azen� podle ��sla a posledn� indexov� soubor odpov�d� se�azen� podle zem�.
	
	Pro ty nejrychlej��: Dal�� program bude zobrazovat data podle indexov�ch soubor�: na�te data, indexov� soubory a 
	u�ivatel si jen vybere, podle �eho chce data se�adit a d�ky indexov�m soubor�m se data rovnou vyp�� (nic se nese�azuje, 
	ji� je to hotovo v indexov�ch souborech.)
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