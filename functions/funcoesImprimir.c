#include <stdio.h>
#include <string.h>
#include "../funcoesImprimir.h"

void imprimirCentroLinha(const char *texto, int L) {
    int len = (int)strlen(texto);
    int pad = (L - len) / 2;
    printf("\xBA");
    for (int i = 0; i < pad; i++) printf(" ");
    printf("%s", texto);
    for (int i = 0; i < L - pad - len; i++) printf(" ");
    printf("\xBA\n");
}