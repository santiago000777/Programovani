#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
	Ti rychlej�� si m��ou zkusit toto cvi�en�, kde m�te za �kol vytvo�it 3 indexov� soubory: jeden odpov�d� se�azen� podle jm�na, 
	dal�� indexov� soubor odpov�d� se�azen� podle ��sla a posledn� indexov� soubor odpov�d� se�azen� podle zem�.
	
	Pro ty nejrychlej��: Dal�� program bude zobrazovat data podle indexov�ch soubor�: na�te data, indexov� soubory a 
	u�ivatel si jen vybere, podle �eho chce data se�adit a d�ky indexov�m soubor�m se data rovnou vyp�� (nic se nese�azuje, 
	ji� je to hotovo v indexov�ch souborech.)
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

void AgeIndexInsert(Entity* array, int* indexArray, int count) {
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

int SmallerValue(char text1[21], int index1, char text2[21], int index2) {
    
    int charIndex = 0;
    while (text1[charIndex] == text2[charIndex]) {
        charIndex++;
    }

    if (text1[charIndex] < text2[charIndex]) {
        return index1;
    } else {
        return index2;
    }

}

void NameIndexInsert(Entity* array, int* indexArray, int count) {
    int i, vkladanyIndex;
    int charIndex = 0;
    char* vkladanyCharArr;
    for (int d = 1; d < count; d++) {
        vkladanyIndex = indexArray[d];
        vkladanyCharArr = array[vkladanyIndex].name;
        i = d;


        

        while (i > 0 && array[indexArray[i - 1]].name[charIndex] > vkladanyCharArr[charIndex]) {
            indexArray[i] = indexArray[i - 1];
            i--;
        }

        indexArray[i] = vkladanyIndex;
        charIndex = 0;
    }

    int pom;
    charIndex = 0;
    bool zmeneno;

    for (int d = 0; d < count - 2; d++) {
        for (int i = count - 1; i >= d + 1; i--) {
            zmeneno = false;
            charIndex = 0;
            if (array[indexArray[i - 1]].name[charIndex] == array[indexArray[i]].name[charIndex]) {
                while (array[indexArray[i - 1]].name[charIndex] == array[indexArray[i]].name[charIndex]) {
                    charIndex++;
                }

                if (array[indexArray[i - 1]].name[charIndex] > array[indexArray[i]].name[charIndex]) {

                    pom = indexArray[i];
                    indexArray[i] = indexArray[i - 1];
                    indexArray[i - 1] = pom;
                    zmeneno = true;
                }
            }
        }
        if (zmeneno == false) {
            break;
        }
    }
}

void CountryIndexInsert(Entity* array, int* indexArray, int count) {
    int i, vkladanyIndex;
    int charIndex = 0;
    char* vkladanyCharArr;
    for (int d = 1; d < count; d++) {
        vkladanyIndex = indexArray[d];
        vkladanyCharArr = array[vkladanyIndex].country;
        i = d;

        while (i > 0 && array[indexArray[i - 1]].country[charIndex] > vkladanyCharArr[charIndex]) {
            indexArray[i] = indexArray[i - 1];
            i--;
        }

        indexArray[i] = vkladanyIndex;
        charIndex = 0;
    }

    int pom;
    charIndex = 0;
    bool zmeneno;

    for (int d = 0; d < count - 2; d++) {
        for (int i = count - 1; i >= d + 1; i--) {
            zmeneno = false;
            charIndex = 0;
            if (array[indexArray[i - 1]].country[charIndex] == array[indexArray[i]].country[charIndex]) {
                while (array[indexArray[i - 1]].country[charIndex] == array[indexArray[i]].country[charIndex]) {
                    charIndex++;
                }

                if (array[indexArray[i - 1]].country[charIndex] > array[indexArray[i]].country[charIndex]) {

                    pom = indexArray[i];
                    indexArray[i] = indexArray[i - 1];
                    indexArray[i - 1] = pom;
                    zmeneno = true;
                }
            }
        }
        if (zmeneno == false) {
            break;
        }
    }
}

void NameIndexBubble(Entity* array, int* indexArray, int count) {
    int pom, charIndex = 0;
    bool zmeneno;

    for (int d = 0; d < count - 2; d++) {
        for (int i = count - 1; i >= d + 1; i--) {
            zmeneno = false;
            if (array[indexArray[i - 1]].name[charIndex] == array[indexArray[i]].name[charIndex]) {
                while (array[indexArray[i - 1]].name[charIndex] == array[indexArray[i]].name[charIndex]) {
                    charIndex++;
                }

                if (array[indexArray[i - 1]].name[charIndex] > array[indexArray[i]].name[charIndex]) {

                    pom = indexArray[i];
                    indexArray[i] = indexArray[i - 1];
                    indexArray[i - 1] = pom;
                    zmeneno = true;
                    charIndex = 0;
                }
            }
        }
        if (zmeneno == false) {
            break;
        }
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

    //AgeIndexInsert(entities, indexArray, count);
    NameIndexInsert(entities, indexArray, count);
    //CountryIndexInsert(entities, indexArray, count);

    PrintArray(out, entities, indexArray, count);

    fclose(in);
    fclose(out);

	return 0;
}