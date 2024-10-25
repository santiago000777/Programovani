#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE	10

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



int main() {
	int pole[SIZE] = { 9, 100, 8, 5, 0, 7, 6, 5, 0, 16 };

	SelectionSort(pole, SIZE);
	PrintPole(pole, SIZE);

	return 0;
}