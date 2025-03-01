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
    char name[21];
    int age;
    char country[31];

} Entity;

int LoadArray(FILE* file, Entity* array, int count) {
    Entity temp;
    int index = 0;
    while (index < count && fscanf(file, "%20s%d%30s", temp.name, &temp.age, temp.country) == 3) {
        array[index] = temp;
        index++;
    }

    return index;
}

void PrintArray(FILE* file, const Entity* array, const int* indexArray, int count) {
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\t%s\t%d\t%s\n", indexArray[i], array[indexArray[i]].name, array[indexArray[i]].age, array[indexArray[i]].country);
    }
}

void InsertSort(int* array, int* indexArray, int count) { // predelat na 
    int vkladany, i;
    for (int d = 1; d < count; d++) {
        vkladany = array[d];
        i = d;
        while (i > 0 && array[i - 1] > vkladany) {
            array[i] = array[i - 1];
            i--;
        }
        array[i] = vkladany;
    }
}

void AgeIndexInsert(Entity* array, int* indexArray, int count) { // predelat na 
    int vkladany, i, vkladanyIndex;
    for (int d = 1; d < count; d++) {
        vkladanyIndex = indexArray[d];
        vkladany = array[vkladanyIndex].age;
        i = d;

        while (i > 0 && array[indexArray[i - 1]].age > vkladany) {
            indexArray[i] = indexArray[i - 1];
            i--;
        }
        indexArray[i] = vkladanyIndex;
    }
}

int main() {
    FILE* in = fopen("entities.txt", "r");
    FILE* out = fopen("result.txt", "w");

    if (in == NULL || out == NULL) {
        return -1;
    }

    Entity entities[20];
    int const count = LoadArray(in, entities, 20);

    int* indexArray = malloc(4 * count);
    for (int i = 0; i < count; i++) {
        indexArray[i] = i;
    }

    AgeIndexInsert(entities, indexArray, count);

    PrintArray(out, entities, indexArray, count);

    fclose(in);
    fclose(out);

	return 0;
}