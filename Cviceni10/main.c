#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    FILE* file;
    unsigned int count;
    bool isSorted;
} File;

int Nacti(FILE* in, int* pole) {
    int cis, i = 0;
    while (fscanf(in, "%d", &cis) == 1) {
        pole[i] = cis;
        i++;
    }
    return i;
}

void Vypis(FILE* out, int* pole, int pocet) {
    for (int i = 0; i < pocet; i++) {
        fprintf(out, "%d ", pole[i]);
    }
}

void IsSorted(File* file, int pocet) {
    int count = 0, cis1, cis2;
    for (int j = 0; j < pocet; j++) {
        if (file[j].isSorted == false) {
            continue;
        }

        file[j].isSorted = true;
        while (fscanf(file[j].file, "%d", &cis1) == 1) {
            count++;
        }

        file[j].count = count;
        count = 0;
        rewind(file[j].file);
        int i = 2, pom;
        fscanf(file[j].file, "%d", &cis1);
        fscanf(file[j].file, "%d", &cis2);
        if (cis1 > cis2) {
            file[j].isSorted = false;
        }
        for (int i = 2; i < file[j].count; i++) {
            cis1 = cis2;
            fscanf(file[j].file, "%d", &cis2);

            if (cis1 > cis2) {
                file[j].isSorted = false;
                break;
            }
        }
        
    }

    for (int i = 0; i < pocet; i++) {
        rewind(file[i].file);
    }
}


void Slevani(File* files, int filesCount, FILE* out) {
    FILE* file[2];
    file[0] = NULL;
    file[1] = NULL;

    for (int i = 0; i < 4; i++) {
        if (files[i].isSorted) {
            if (file[0] == NULL) {
                file[0] = files[i].file;
                continue;
            }
            if (file[1] == NULL) {
                file[1] = files[i].file;
                continue;
            }
        }
    }

    

    int index1 = 0, index2 = 0;
    int cislo1, cislo2;
    fscanf(file[0], "%d", &cislo1);
    fscanf(file[1], "%d", &cislo2);
    while (index1 < files[0].count && index2 < files[1].count) {
        if (cislo1 < cislo2) {
            fprintf(out, "%d ", cislo1);
            fscanf(file[0], "%d", &cislo1);
            index1++;
        } else {
            fprintf(out, "%d ", cislo2);
            fscanf(file[1], "%d", &cislo2);
            index2++;
        }
    }
    if (index1 < files[0].count - 1) {
        for (index1; index1 < files[0].count; index1++) {
            fprintf(out, "%d ", cislo1);
            fscanf(file[0], "%d", &cislo1);
        }
    }
    if (index2 < files[1].count - 1) {
        for (index2; index2 < files[1].count; index2++) {
            fprintf(out, "%d ", cislo2);
            fscanf(file[1], "%d", &cislo2);
        }
    }
}

int main() {
    File files[4];
    files[0].file = fopen("sluc1.txt", "r");
    files[1].file = fopen("sluc2.txt", "r");
    files[2].file = fopen("sluc3.txt", "r");
    files[3].file = fopen("sluc4.txt", "r");
    
    FILE* out = fopen("vypis.txt", "w");

    if (files[0].file == NULL || files[1].file == NULL || files[2].file == NULL || files[3].file == NULL || out == NULL) {
        return -1;
    }

    IsSorted(files, 4);

    Slevani(files, 4, out);
    for (int i = 0; i < 4; i++) {
        fclose(files[0].file);
    }

    fclose(out);
	return 0;
}