#include <stdio.h>
#include <stdlib.h>

void calcularDiferenca(FILE *arquivo) {
    int conjuntoA[100], conjuntoB[100];
    int numElementosA, numElementosB, i, j, diferenca[100], numDiferenca = 0;

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

    // Calcular a diferença entre os conjuntos
    for (i = 0; i < numElementosA; i++) {
        int encontrado = 0;
        for (j = 0; j < numElementosB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            diferenca[numDiferenca++] = conjuntoA[i];
        }
    }

    // Escrever a diferença no arquivo original
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d ", numDiferenca);
    for (i = 0; i < numDiferenca; i++) {
        fprintf(arquivo, "%d ", diferenca[i]);
    }
}

int main() {
    FILE *arquivo = fopen("conjuntos.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    calcularDiferenca(arquivo);

    fclose(arquivo);
    printf("Diferença calculada e armazenada no arquivo original.\n");

    return 0;
}
