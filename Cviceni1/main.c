#include <stdio.h>

typedef struct {
	char name[11];
	int points[5];
} Soutezici;

void SetName(Soutezici* pSoutezici) {
	printf("Nacitej jmeno souteziciho:\n");
	scanf_s("%s", pSoutezici->name, 10);
}

void SetPoints(Soutezici* pSoutezici) {
	printf("Nacitej 5 bodu od porotcu:\n");
	for (int i = 0; i < 5; i++) {
		printf("Porotce %d.\t", i + 1);
		scanf_s("%d", &pSoutezici->points[i]);
	}
}

void Vyhodnoceni(Soutezici* pSoutezici, int pocet) {
	Soutezici* winner = &pSoutezici[0];
	int pom = 0;
	for (int i = 0; i < 5; i++) {
		pom += pSoutezici[0].points[i];
	}
	int winnerPoints = pom;

	for (int j = 1; j < pocet; j++) {
		pom = 0;
		for (int i = 0; i < 5; i++) {
			pom += pSoutezici[j].points[i];
		}

		if (winnerPoints < pom) {
			winnerPoints = pom;
			winner = &pSoutezici[j];
		}
	}
	printf("Vyherce je: %s", winner->name);
}

int main() {

	Soutezici soutezici[6];
	for (int i = 0; i < 6; i++) {
		SetName(&soutezici[i]);
		SetPoints(&soutezici[i]);
	}

	Vyhodnoceni(soutezici, 6);
}