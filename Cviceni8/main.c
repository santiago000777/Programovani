#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
    int vkladany, i;
    for (int d = 2; d <= pocet; d++) {
        vkladany = pole[d];
        pole[0] = vkladany;
        i = d;
        while (pole[i - 1] > vkladany) {
            pole[i] = pole[i - 1];
            i--;
        }
        pole[i] = vkladany;
        vypis(pole, pocet);
    }
}

void InsertSort_zarazka_konec(int* pole, int pocet) {

}

void BubbleSort(int* pole, int pocet) {

}

void RippleSort(int* pole, int pocet) {

}

void ShakerSort(int* pole, int pocet) {

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
        if (volba >= 1 && volba <= 7)
            vypis(pole, n);

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