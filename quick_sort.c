
#include <stdio.h>

#define TAMANHO 10

// Bubble Sort: compara elementos vizinhos e troca
// suas posicoes quando estao na ordem incorreta.
void bubbleSort(float temperaturas[], int tamanho) {
    int i, j;
    float temporaria;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (temperaturas[j] > temperaturas[j + 1]) {
                temporaria = temperaturas[j];
                temperaturas[j] = temperaturas[j + 1];
                temperaturas[j + 1] = temporaria;
            }
        }
    }
}

// Quick Sort: escolhe um pivo e separa os elementos
// menores ou iguais ao pivo dos elementos maiores.
int particionar(float temperaturas[], int inicio, int fim) {
    float pivo = temperaturas[fim];
    float temporaria;
    int i = inicio - 1;
    int j;

    for (j = inicio; j < fim; j++) {
        if (temperaturas[j] <= pivo) {
            i++;

            temporaria = temperaturas[i];
            temperaturas[i] = temperaturas[j];
            temperaturas[j] = temporaria;
        }
    }

    // Coloca o pivo na sua posicao correta.
    temporaria = temperaturas[i + 1];
    temperaturas[i + 1] = temperaturas[fim];
    temperaturas[fim] = temporaria;

    return i + 1;
}

// Quick Sort: ordena recursivamente as duas partes
// criadas pela funcao de particionamento.
void quickSort(float temperaturas[], int inicio, int fim) {
    if (inicio < fim) {
        int posicaoPivo = particionar(temperaturas, inicio, fim);

        quickSort(temperaturas, inicio, posicaoPivo - 1);
        quickSort(temperaturas, posicaoPivo + 1, fim);
    }
}

// Exibe todos os valores de um vetor.
void mostrarTemperaturas(float temperaturas[], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%.1f ", temperaturas[i]);
    }

    printf("\n");
}

int main(void) {
    float original[TAMANHO];
    float dadosBubble[TAMANHO];
    float dadosQuick[TAMANHO];
    int i;

    printf("=== ORDENACAO DE TEMPERATURAS ===\n");
    printf("Digite %d temperaturas.\n\n", TAMANHO);

    // Le as temperaturas e cria copias para os algoritmos.
    for (i = 0; i < TAMANHO; i++) {
        printf("Digite a temperatura %d: ", i + 1);

        if (scanf("%f", &original[i]) != 1) {
            printf("Entrada invalida. Execute novamente e digite numeros.\n");
            return 1;
        }

        dadosBubble[i] = original[i];
        dadosQuick[i] = original[i];
    }

    printf("\nTemperaturas originais:\n");
    mostrarTemperaturas(original, TAMANHO);

    // Ordena uma copia com Bubble Sort.
    bubbleSort(dadosBubble, TAMANHO);

    printf("\nResultado do Bubble Sort (crescente):\n");
    mostrarTemperaturas(dadosBubble, TAMANHO);

    // Ordena outra copia com Quick Sort.
    quickSort(dadosQuick, 0, TAMANHO - 1);

    printf("\nResultado do Quick Sort (crescente):\n");
    mostrarTemperaturas(dadosQuick, TAMANHO);

    return 0;
}
