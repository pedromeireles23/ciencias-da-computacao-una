#include <stdio.h>

void calcularProdutoCartesiano(FILE *arquivo) {
    int conjuntoA[100], conjuntoB[100];
    int numElementosA, numElementosB, i, j;

    // Ler conjunto A do arquivo
    fscanf(arquivo, "%d", &numElementosA);
    for (i = 0; i < numElementosA; i++) {
        fscanf(arquivo, "%d", &conjuntoA[i]);
    }

    // Ler conjunto B do arquivo
    fscanf(arquivo, "%d", &numElementosB);
    for (i = 0; i < numElementosB; i++) {
        fscanf(arquivo, "%d", &conjuntoB[i]);
    }

    // Calcular e armazenar o produto cartesiano no arquivo original
    fprintf(arquivo, "\nProduto Cartesiano:\n");
    for (i = 0; i < numElementosA; i++) {
        for (j = 0; j < numElementosB; j++) {
            fprintf(arquivo, "(%d, %d)\n", conjuntoA[i], conjuntoB[j]);
        }
    }
}

int main() {
    FILE *arquivo = fopen("conjuntos.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Ir para o final do arquivo
    fseek(arquivo, 0, SEEK_END);

    calcularProdutoCartesiano(arquivo);

    fclose(arquivo);
    printf("Produto cartesiano calculado e armazenado no arquivo original.\n");

    return 0;
}
