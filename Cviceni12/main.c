#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef struct {
//    int id;
//    char jmeno[21];
//    char prijmeni[21];
//    int vek;
//    char povolani[21];
//    char zeme[21];
//    int plat;
//    bool smazano; // true smazano, false neni smazano
//} Osoba;
//
//int Nacti(FILE* file, Osoba* pOsoba) {
//    
//    int i = 0;
//
//    while (i < 100 && fscanf(file, "%d%20s%20s%d%20s%20s%d", &pOsoba[i].id, pOsoba[i].jmeno, pOsoba[i].prijmeni, &pOsoba[i].vek, pOsoba[i].povolani, pOsoba[i].zeme, &pOsoba[i].plat) == 7) {
//        pOsoba[i].smazano = false;
//        i++;
//    }
//    printf("Nacetlo se %d zaznamu", i);
//    rewind(file);
//    return i;
//}
//
//int Zmeny(FILE* file, Osoba* pOsoba, int n) {
//    Osoba pom;
//    int identificator = 0;
//    
//    while (fscanf(file, "%d%20s%20s%d%20s%20s%d%d", &pom.id, pom.jmeno, pom.prijmeni, &pom.vek, pom.povolani, pom.zeme, &pom.plat, &identificator) == 8) {
//        switch (identificator) {
//            case 0: {
//                pom.smazano = false;
//                pOsoba[pom.id - 1] = pom;
//                break;
//            }
//            case -1: {
//                pOsoba[pom.id - 1].smazano = true;
//                break;
//            }
//            case 1: {
//                pOsoba[n] = pom;
//                pOsoba[n].id = n + 1;
//                pOsoba[n].smazano = false;
//                n++;
//                break;
//            }
//        }
//    }
//    return n;
//
//}
//
//void Zapis(FILE* k, Osoba pOsoba[], int n) {
//    int i, j = 1;
//    for (i = 0; i < n; i++) {
//        if (pOsoba[i].smazano == false) {
//            fprintf(k, "%d%20s%20s\t%d%20s%20s\t%d\n", j, pOsoba[i].jmeno, pOsoba[i].prijmeni, pOsoba[i].vek, pOsoba[i].povolani, pOsoba[i].zeme, pOsoba[i].plat);
//            j++;
//        }
//    }
//}
//
//int main() {
//    FILE* kmenovy, *zmeny;
//    Osoba pole[100];
//    int count;
//
//    kmenovy = fopen("kmenovy.txt", "r");
//    zmeny = fopen("zmeny.txt", "r");
//    if (kmenovy == NULL || zmeny == NULL) {
//        return -1;
//    }
//
//    count = Nacti(kmenovy, pole);
//    count = Zmeny(zmeny, pole, count);
//
//    fclose(kmenovy);
//    kmenovy = fopen("kmenovyNovy.txt", "w");
//
//    Zapis(kmenovy, pole, count);
//
//    fclose(kmenovy);
//    fclose(zmeny);
//    return 0;
//}

typedef struct {
	int id;
	char jmeno[20];
	char prijmeni[20];
	int vek;
	char povolani[20];
	char stat[30];
	int plat;

	bool smazano;
} Osoba;

int Nacti(FILE* in, Osoba* pArr, int maxAmount) {
	int count = 0;
	while (count < maxAmount && fscanf(in, "%d%19s%19s%d%19s%29s%d", &pArr[count].id, pArr[count].jmeno, pArr[count].prijmeni, &pArr[count].vek, pArr[count].povolani, pArr[count].stat, &pArr[count].plat) == 7) {
		pArr[count].smazano = false;
		count++;
	}

	return count;
}

int Zmeny(FILE* in, Osoba* pArr, int count) {
	Osoba pom;
	int identificator;

	while (fscanf(in, "%d%19s%19s%d%19s%29s%d%d", &pom.id, pom.jmeno, pom.prijmeni, &pom.vek, pom.povolani, pom.stat, &pom.plat, &identificator) == 8) {
		switch (identificator) {
			case -1: {
				pArr[pom.id - 1].smazano = true;
				break;
			}
			case 0: {
				pom.smazano = false;
				pArr[pom.id - 1] = pom;
				break;
			}
			case 1: {
				pom.smazano = false;
				pom.id = count + 1;
				pArr[count] = pom;
				count++;
				break;
			}
		}
	}

	return count;
}

void Vypis(FILE* out, Osoba* pArr, int count) {
	int seznamId = 1;
	for (int i = 0; i < count; i++) {
		if (pArr[i].smazano) {
			continue;
		}

		fprintf(out, "%d%19s%20s\t%d%19s%29s\t%d\n", seznamId, pArr[i].jmeno, pArr[i].prijmeni, pArr[i].vek, pArr[i].povolani, pArr[i].stat, pArr[i].plat);
		seznamId++;
	}
}

int main() {
	FILE* kmenovy = fopen("kmenovy.txt", "r");
	FILE* zmeny = fopen("zmeny.txt", "r");
	if (kmenovy == NULL || zmeny == NULL) {
		return -1;
	}

	Osoba osoby[30];
	// nacteni osob do pole z Kmenoveho
	int count = Nacti(kmenovy, osoby, 30);
	
	// uplatneni zmen v Poli
	count = Zmeny(zmeny, osoby, count);

	fclose(kmenovy);
	kmenovy = fopen("kmenovyNovy.txt", "w");
	if (kmenovy == NULL) {
		return -1;
	}

	// vypis
	Vypis(kmenovy, osoby, count);

	fclose(kmenovy);
	fclose(zmeny);
	return 0;
}