#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE	11

void PrintPole(int* pArr, int pocet) {
	for (int i = 0; i < pocet; i++) {
		printf("%d ", pArr[i]);
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

void BubbleSort(int* pole, int pocet) {
	int pom;
	for (int d = 0; d < pocet - 2; d++) {
		for (int i = pocet - 1; i >= d + 1; i--) {
			if (pole[i - 1] > pole[i]) {
				pom = pole[i];
				pole[i] = pole[i - 1];
				pole[i - 1] = pom;
			}
		}
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

int main() {
	int pole[SIZE] = { 9, 100, 8, 5, 0, 7, 6, 5, 0, 16, -8 };

	//SelectionSort(pole, SIZE);
	//BubbleSort(pole, SIZE);
	InsertSort_zarazka_konec(pole, SIZE);
	PrintPole(pole, SIZE);

	return 0;
}