#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// V souboru data.txt jsou záznamy osob, vždy je na øádku jméno a èíslo (øeknìme že napøíklad plat).
// Úkolem je seøadit osoby podle výšky platu od nejmenší po nejvìtší.
// Použijte dostateènì "dobrý" algoritmus øazení z tìch, které máte.Pokud váš algoritmus bude trvat déle jak 1 minutu, sdìlte tuto skuteènost vyuèujícímu, dostanete od nìj za 5.
// Úkoly:
//  + * Seøadit (popis výše) a seøazené vypsat do druhého souboru, jehož název zadá uživatel.
//    * Zjistit, kolik je v souboru rùzných jmen a poèet vypsat na obrazovku (volitelnì mùžete vypsat i samotná jména). Bez struktury se asi neobejdete.
//    * Zjistit, jaké jméno se objevuje nejèastìji a s kolika výskyty.

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
