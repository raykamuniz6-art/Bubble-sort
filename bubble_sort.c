
#include <stdio.h>

#define TAMANHO 10

int main() {
    float temperaturas[TAMANHO];
    float temporaria;
    int i, j;

    printf("=== ORDENACAO DE TEMPERATURAS ===\n\n");

    // Entrada das 10 temperaturas
    for (i = 0; i < TAMANHO; i++) {
        printf("Digite a temperatura %d: ", i + 1);

        if (scanf("%f", &temperaturas[i]) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            return 1;
        }
    }

    // Exibe as temperaturas antes da ordenacao
    printf("\nTemperaturas originais:\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%.1f ", temperaturas[i]);
    }

    // Algoritmo Bubble Sort em ordem crescente
    for (i = 0; i < TAMANHO - 1; i++) {
        for (j = 0; j < TAMANHO - 1 - i; j++) {

            // Compara dois elementos vizinhos
            if (temperaturas[j] > temperaturas[j + 1]) {

                // Troca os elementos de posicao
                temporaria = temperaturas[j];
                temperaturas[j] = temperaturas[j + 1];
                temperaturas[j + 1] = temporaria;
            }
        }
    }

    // Exibe as temperaturas depois da ordenacao
    printf("\n\nTemperaturas em ordem crescente:\n");

    for (i = 0; i < TAMANHO; i++) {
        printf("%.1f ", temperaturas[i]);
    }

    printf("\n");

    return 0;
}
