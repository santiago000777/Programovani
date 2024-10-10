#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
1. p��klad
Napi�te program pro zkop�rov�n� jednoho textov�ho souboru do druh�ho (po znac�ch - viz va�e pozn�mky z teorie). N�zev souboru zad�vejte z kl�vesnice 
(zkop�rujte si do adres��e projektu soubory zadani1.txt, zadani2.txt a zadani3.txt.
Roz���en�:
De�ifr�tor: Program p�ekop�ruje soubor (bu� zadani1.txt, nebo zadani2.txt, nebo zadani3.txt) do nov�ho souboru (n�zev zad� u�ivatel)   
znak po znaku, aby se zapsaly i nov� ��dky, a to tak, �e m�sto ka�d�ho ��sla (kop�rujeme znaky, tak�e uva�ujeme pouze jednocifern� ��sla) 
0, 1, 2, 3, 4, 5 zap�e mezeru a m�sto ��sel (cifer) 6, 7, 8, 9 zap�e symbol dolaru $. Ostatn� znaky zap�e nezm�n�ny.
HINTy:
znak 0 m� ��selnou hodnotu 48
znak 1 m� ��selnou hodnotu 49
...
znak 9 m� ��selnou hodnotu 57
tzn. �e pro char x = '1' vyp�e p��kaz printf("%c   %d", x, x);  n�sleduj�c�:  1   49
D�le pro z�pis pou��vejte p��kaz fputc(znak,soubor);
*/

void CopyFiles(FILE* in, FILE* out) {
    int c;
    while ((c = fgetc(in)) && c != EOF) {
        if (c >= '0' && c <= '5') {
            fputc(' ', out);
            continue;
        }
        if (c >= '6' && c <= '9') {
            fputc('$', out);
            continue;
        }
        fputc(c, out);
    }
}

int main() {
    char fileName[20];
    printf("Zadej nazev souboru, ktery chces prekopirovat (nezapomen na koncovku):\t");
    scanf("%19s", fileName);

    FILE* in = fopen(fileName, "r");
    FILE* out = fopen("vysledek.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Nepodarilo se otevrit soubory!\n");
        return 0;
    }

    CopyFiles(in, out);

    return 0;
}
