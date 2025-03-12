#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    char jmeno[21];
    char prijmeni[21];
    int vek;
    char povolani[21];
    char zeme[21];
    int plat;
    bool smazano; // true smazano, false neni smazano
} Osoba;

int Nacti(FILE* file, Osoba* pOsoba) {
    
    int i = 0;

    while (i < 100 && fscanf(file, "%d%20s%20s%d%20s%20s%d", &pOsoba[i].id, pOsoba[i].jmeno, pOsoba[i].prijmeni, &pOsoba[i].vek, pOsoba[i].povolani, pOsoba[i].zeme, &pOsoba[i].plat) == 7) {
        pOsoba[i].smazano = false;
        i++;
    }
    printf("Nacetlo se %d zaznamu", i);
    rewind(file);
    return i;
}

int Zmeny(FILE* file, Osoba* pOsoba, int n) {
    Osoba pom;
    int identificator = 0;
    
    while (fscanf(file, "%d%20s%20s%d%20s%20s%d%d", &pom.id, pom.jmeno, pom.prijmeni, &pom.vek, pom.povolani, pom.zeme, &pom.plat, &identificator) == 8) {
        switch (identificator) {
            case 0: {
                pom.smazano = false;
                pOsoba[pom.id - 1] = pom;
                break;
            }
            case -1: {
                pOsoba[pom.id - 1].smazano = true;
                break;
            }
            case 1: {
                pOsoba[n] = pom;
                pOsoba[n].id = n + 1;
                pOsoba[n].smazano = false;
                n++;
                break;
            }
        }
    }
    return n;

}

void Zapis(FILE* k, Osoba pOsoba[], int n) {
    int i, j = 1;
    for (i = 0; i < n; i++) {
        if (pOsoba[i].smazano == false) {
            fprintf(k, "%d%20s%20s\t%d%20s%20s\t%d\n", j, pOsoba[i].jmeno, pOsoba[i].prijmeni, pOsoba[i].vek, pOsoba[i].povolani, pOsoba[i].zeme, pOsoba[i].plat);
            j++;
        }
    }
}

int main() {
    FILE* kmenovy, *zmeny;
    Osoba pole[100];
    int count;

    kmenovy = fopen("kmenovy.txt", "r");
    zmeny = fopen("zmeny.txt", "r");
    if (kmenovy == NULL || zmeny == NULL) {
        return -1;
    }

    count = Nacti(kmenovy, pole);
    count = Zmeny(zmeny, pole, count);

    fclose(kmenovy);
    kmenovy = fopen("kmenovyNovy.txt", "w");

    Zapis(kmenovy, pole, count);

    fclose(kmenovy);
    fclose(zmeny);
    return 0;
}