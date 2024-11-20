#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define MAX 100

/**
Jmeno:
**/

int nacti(FILE* in, int* pole) {
    int cis, i = 0;
    while (fscanf(in, "%d", &cis) == 1) {
        pole[i] = cis;
        i++;
    }
    return i;
}

void vypis(int* pole, int pocet) {
    printf("\n");
    for (int i = 0; i < pocet; i++) {
        printf("%d, ", pole[i]);
    }
    printf("\n");
}

void vypis3(int* pole, int pocet) {
    printf("\n");
    for (int i = 1; i <= pocet; i++) {
        printf("%d, ", pole[i]);
    }
    printf("\n");
}

void SelectionSort(int* pArr, int pocet) {
    int minIndex, pom;
    for (int f = 0; f < pocet - 1; f++) {
        minIndex = f;
        for (int i = f + 1; i < pocet; i++) {
            if (pArr[minIndex] > pArr[i]) {
                minIndex = i;
            }
        }
        pom = pArr[minIndex];
        pArr[minIndex] = pArr[f];
        pArr[f] = pom;
    }
}

void InsertSort(int* pole, int pocet) {
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
//9, 100, 4, 6, 92, 0, 1, 21
void InsertSort_zarazka_zacatek(int* pole, int pocet) {
    pocet++;
    int* pole2 = malloc((pocet) * 4);
    for (int i = 1; i < pocet; i++) {
        pole2[i] = pole[i-1];
    }

    int vkladany, i;
    for (int d = 2; d < pocet; d++) {
        vkladany = pole2[d];
        pole2[0] = vkladany;
        i = d;
        while (pole2[i - 1] > vkladany) {
            pole2[i] = pole2[i - 1];
            i--;
        }
        pole2[i] = vkladany;
        vypis(pole2, pocet);
    }
    for (int i = 0; i < pocet - 1; i++) {
        pole[i] = pole2[i + 1];
    }
}

void InsertSort_zarazka_konec(int* pole, int pocet) {
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

void BubbleSort(int* pole, int pocet) {
    int pom;
    for (int d = 0; d < pocet - 1; d++) {
        vypis(pole, pocet);
        for (int i = pocet - 1; i >= d + 1; i--) {
            if (pole[i - 1] > pole[i]) {
                pom = pole[i];
                pole[i] = pole[i - 1];
                pole[i - 1] = pom;
                vypis(pole, pocet);
            }
        }
    }
}

void RippleSort(int* pole, int pocet) {
    int pom, vymena, zarazka = pocet - 1;
    bool isVymeneno = true;
    for (int d = 0; isVymeneno; d++) {
        isVymeneno = false;
        for (int i = 0; i < zarazka; i++) {
            if (pole[i] > pole[i + 1]) {
                pom = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = pom;
                vymena = i;
                isVymeneno = true;
            }
        }
        zarazka = vymena;
    }
}

void ShakerSort(int* pole, int pocet) {
    bool ok = true, ok2 = true;
    int zEnd = pocet - 1;
    int zStart = 0;
    int zarazka, pom;

    for (int j = 0; j < pocet && ok2; j++) {
        ok = false;
        for (int i = zStart; i < zEnd; i++) {
            if (pole[i] > pole[i + 1]) {
                pom = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = pom;
                ok = true;
                zarazka = i;
            }
        }
        zEnd = zarazka;
        ok2 = false;

        for (int i = zEnd - 1; i >= zStart && ok; i--) {
            if (pole[i] > pole[i + 1]) {
                pom = pole[i];
                pole[i] = pole[i + 1];
                pole[i + 1] = pom;

                ok2 = true;
                zarazka = i;
            }
        }
        zStart = zarazka;
    }
}


int Menu() {
    int volba;
    printf("Zadej svou volbu\n-----------------\n");
    printf("(1) ... Selection Sort\n");
    printf("(2) ... Insert Sort\n");
    printf("(3) ... Insert Sort se zarazkou na zacatku\n");
    printf("(4) ... Insert Sort se zarazkou na konci\n");
    printf("(5) ... Bubble Sort\n");
    printf("(6) ... Ripple Sort\n");
    printf("(7) ... Shaker Sort\n");
    printf("jine cislo ... KONEC PROGRAMU\n-----------------\n");


    printf("Zadej cislo volby: ");
    scanf("%d", &volba);
    return volba;
}


int main() {
    int volba = 1, n = 3, pole[MAX];
    char nazev[20];
    FILE* in;
    printf("Zadej nazev souboru s cisly: ");
    scanf("%19s", nazev);
    in = fopen(nazev, "r");

    if (in == NULL) {
        printf("Nenacetl se soubor!\n");
        return -1;
    }

    if ((n = nacti(in, pole)) > MAX) {
        return -2;
    }

    while (volba >= 1 && volba <= 7) {
        volba = Menu();
        if (volba >= 1 && volba <= 7)
            vypis(pole, n);
        switch (volba) {
            case 1: SelectionSort(pole, n);
                break;
            case 2: InsertSort(pole, n);
                break;
            case 3: InsertSort_zarazka_zacatek(pole, n);
                break;
            case 4: InsertSort_zarazka_konec(pole, n);
                break;
            case 5: BubbleSort(pole, n);
                break;
            case 6: RippleSort(pole, n);
                break;
            case 7: ShakerSort(pole, n);
                break;
            default: printf("\nKonec");
        }
        if (volba >= 1 && volba <= 7) {
            vypis(pole, n);
        }

        rewind(in);
        if ((n = nacti(in, pole)) > MAX)
            return -2;
        printf("\n\n");
        system("pause");
        system("cls");
    }

    fclose(in);
    return 0;
}