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

void Vyhodnoceni(FILE* out, Soutezici* pSoutezici, int pocet) {
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
	fprintf(out, "%s", winner->name);
}

void ReadFrom(FILE* in, Soutezici* pSoutezici, int pocet) {
	for (int i = 0; i < pocet; i++) {
		fscanf_s(in, "%s", pSoutezici[i].name, 10);
		for (int j = 0; j < 5; j++) {
			fscanf_s(in, "%d", &pSoutezici[i].points[j]);
		}
	}
}

int main() {
	FILE* in = fopen("data.txt", "r");
	FILE* out = fopen("vysledek.txt", "w");
	if (in == NULL || out == NULL) {
		printf("Nelze otevrit soubory!\n");
		return 0;
	}

	Soutezici soutezici[6];
	ReadFrom(in, soutezici, 6);
	fclose(in);

	Vyhodnoceni(out, soutezici, 6);
	fclose(out);
}