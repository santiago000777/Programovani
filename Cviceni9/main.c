#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// V souboru data.txt jsou z�znamy osob, v�dy je na ��dku jm�no a ��slo (�ekn�me �e nap��klad plat).
// �kolem je se�adit osoby podle v��ky platu od nejmen�� po nejv�t��.
// Pou�ijte dostate�n� "dobr�" algoritmus �azen� z t�ch, kter� m�te.Pokud v� algoritmus bude trvat d�le jak 1 minutu, sd�lte tuto skute�nost vyu�uj�c�mu, dostanete od n�j za 5.
// �koly:
//  + * Se�adit (popis v��e) a se�azen� vypsat do druh�ho souboru, jeho� n�zev zad� u�ivatel.
//    * Zjistit, kolik je v souboru r�zn�ch jmen a po�et vypsat na obrazovku (voliteln� m��ete vypsat i samotn� jm�na). Bez struktury se asi neobejdete.
//    * Zjistit, jak� jm�no se objevuje nej�ast�ji a s kolika v�skyty.

typedef struct {
    char name[20];
    int count;
} HashTable;






typedef struct {
    char* data;
    unsigned int dataSize;
    unsigned int capacity;
} DynamicArray;

//void PushBack(DynamicArray* array, HashTable* element) {
//    if (array->capacity < 0) {
//        array->capacity = 2;
//        array->dataSize = 24;
//        array->data = malloc(array->dataSize * array->capacity);
//        array->data = (char*)element;
//    }
//    else {
//        char* old = array->data;
//        //array->dataSize += 24;
//        if (array->dataSize + 24 > 24 * array->capacity) {
//            array->capacity++;
//            array->capacity *= 2;
//            array->data = realloc(array->data, 24 * array->capacity);
//            free(old);
//        }
//        else {
//            old += array->dataSize;
//            for (int i = 0; i < 24; i++) {
//                *old = element
//                
//            }
//
//        }
//        array->dataSize += 24;
//    }
//}
//
//void At(DynamicArray* array, unsigned int index, HashTable* element) {
//    array->data += array->elementSize * index;
//    element = (HashTable*)array->data;
//}
//
//
//void PushBack(DynamicArray* array, HashTable* element) {
//    if (array->capacity < 0) {
//        array->capacity = 0;
//        array->capacity++;
//        array->elementSize = 24;
//        array->data = malloc(array->elementSize);
//    } else {
//        array->capacity++;
//    }
//    array->capacity *= 2;
//
//    free(array->data);
//    array->data = realloc(array->data, array->elementSize * array->capacity);
//}
//
//void At(DynamicArray* array, unsigned int index, HashTable* element) {
//    array->data += array->elementSize * index;
//    element = (HashTable*)array->data;
//}

typedef struct {
    char name[20];
    int salary;
} Employee;

int CountOfObjects(FILE* in) {
    char name[20];
    int salary;
    int pocitadlo = 0;
    while (fscanf(in, "%19s%d", name, &salary) == 2) {
        pocitadlo++;
    }

    rewind(in);

    return pocitadlo;
}

void Nacteni(FILE* in, Employee* pole, int pocet) {
    for (int i = 0; i < pocet; i++) {
        if (fscanf(in, "%19s%d", pole[i].name, &pole[i].salary) != 2) {
            printf("Chyba!");
        }
    }
}

void RippleSort(Employee* pole, int pocet) {
    Employee pom;
    int vymena, zarazka = pocet - 1;
    bool isVymeneno = true;
    for (int d = 0; isVymeneno; d++) {
        isVymeneno = false;
        for (int i = 0; i < zarazka; i++) {
            if (pole[i].salary > pole[i + 1].salary) {
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

void InsertSort(Employee* pole, int pocet) {
    Employee vkladany;
    int i;
    for (int d = 1; d < pocet; d++) {
        vkladany = pole[d];
        i = d;
        while (i > 0 && pole[i - 1].salary > vkladany.salary) {
            pole[i] = pole[i - 1];
            i--;
        }
        pole[i] = vkladany;
    }
}

void Zapsani(FILE* out, Employee* pole, int pocet) {
    for (int i = 0; i < pocet; i++) {
        fprintf(out, "%s %d\n", pole[i].name, pole[i].salary);
    }
}

#define SORT    0

int main() {

    printf("Nazev souboru pro ukladani:\t");
    char fileName[20];
    scanf("%19s", fileName);

    FILE* in = fopen("data.txt", "r");
    FILE* out = fopen(fileName, "w");

    if (in == NULL || out == NULL) {
        printf("Nepodarilo se nacist soubory!\n");
        return -1;
    }

    int count = CountOfObjects(in);
    Employee* zamestanci = malloc(sizeof(Employee) * count);

    Nacteni(in, zamestanci, count);

#if SORT == 0
    RippleSort(zamestanci, count);
#elif SORT == 1
    InsertSort(zamestanci, count);
#endif

    Zapsani(out, zamestanci, count);

    fclose(in);
    fclose(out);

    return 0;
}
