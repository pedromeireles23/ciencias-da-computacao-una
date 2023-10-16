#include <stdio.h>

// Função para verificar se um elemento está presente no conjunto
int estaNoConjunto(int elemento, int conjunto[], int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        if (conjunto[i] == elemento) {
            return 1; // elemento está no conjunto
        }
    }
    return 0; // elemento não está no conjunto
}

// Função para calcular a união de dois conjuntos
void uniaoDeConjuntos(int conjuntoA[], int tamanhoA, int conjuntoB[], int tamanhoB, int uniao[], int *tamanhoUniao) {
    *tamanhoUniao = 0;

    // Adiciona elementos de A à união
    for (int i = 0; i < tamanhoA; ++i) {
        uniao[*tamanhoUniao] = conjuntoA[i];
        (*tamanhoUniao)++;
    }

    // Adiciona elementos de B à união se eles não estiverem já presentes
    for (int i = 0; i < tamanhoB; ++i) {
        if (!estaNoConjunto(conjuntoB[i], uniao, *tamanhoUniao)) {
            uniao[*tamanhoUniao] = conjuntoB[i];
            (*tamanhoUniao)++;
        }
    }
}

int main() {
    int conjuntoA[] = {1, 2, 3, 4, 5};
    int tamanhoA = 5;
    int conjuntoB[] = {3, 4, 5, 6, 7};
    int tamanhoB = 5;

    int uniao[10]; // assumindo que o tamanho máximo da união é 10
    int tamanhoUniao;

    // Calcula a união dos conjuntos
    uniaoDeConjuntos(conjuntoA, tamanhoA, conjuntoB, tamanhoB, uniao, &tamanhoUniao);

    // Abre o arquivo para escrita
    FILE *arquivo = fopen("conjunto.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    // Escreve a união no arquivo
    for (int i = 0; i < tamanhoUniao; ++i) {
        fprintf(arquivo, "%d ", uniao[i]);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("União dos conjuntos foi armazenada no arquivo 'conjunto.txt'.\n");

    return 0;
}
