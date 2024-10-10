#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
1. pøíklad
Napište program pro zkopírování jednoho textového souboru do druhého (po znacích - viz vaše poznámky z teorie). Název souboru zadávejte z klávesnice 
(zkopírujte si do adresáøe projektu soubory zadani1.txt, zadani2.txt a zadani3.txt.
Rozšíøení:
Dešifrátor: Program pøekopíruje soubor (buï zadani1.txt, nebo zadani2.txt, nebo zadani3.txt) do nového souboru (název zadá uživatel)   
znak po znaku, aby se zapsaly i nové øádky, a to tak, že místo každého èísla (kopírujeme znaky, takže uvažujeme pouze jednociferná èísla) 
0, 1, 2, 3, 4, 5 zapíše mezeru a místo èísel (cifer) 6, 7, 8, 9 zapíše symbol dolaru $. Ostatní znaky zapíše nezmìnìny.
HINTy:
znak 0 má èíselnou hodnotu 48
znak 1 má èíselnou hodnotu 49
...
znak 9 má èíselnou hodnotu 57
tzn. že pro char x = '1' vypíše pøíkaz printf("%c   %d", x, x);  následující:  1   49
Dále pro zápis používejte pøíkaz fputc(znak,soubor);
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
