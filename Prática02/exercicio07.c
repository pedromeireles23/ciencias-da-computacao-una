#include <stdio.h>

void calcularIntersecao(FILE *arquivo) {
    int conjuntoA[100], conjuntoB[100], intersecao[100];
    int tamanhoA, tamanhoB, tamanhoIntersecao = 0;

    // Lê os conjuntos A e B do arquivo
    fscanf(arquivo, "%d", &tamanhoA);
    for (int i = 0; i < tamanhoA; i++) {
        fscanf(arquivo, "%d", &conjuntoA[i]);
    }

    fscanf(arquivo, "%d", &tamanhoB);
    for (int i = 0; i < tamanhoB; i++) {
        fscanf(arquivo, "%d", &conjuntoB[i]);
    }

    // Calcula a interseção dos conjuntos
    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            if (conjuntoA[i] == conjuntoB[j]) {
                intersecao[tamanhoIntersecao] = conjuntoA[i];
                tamanhoIntersecao++;
                break;
            }
        }
    }

    // Escreve a interseção no arquivo original
    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "\nInterseção: ");
    for (int i = 0; i < tamanhoIntersecao; i++) {
        fprintf(arquivo, "%d ", intersecao[i]);
    }

    printf("Interseção dos conjuntos foi calculada e armazenada no arquivo.\n");
}

int main() {
    FILE *arquivo;
    arquivo = fopen("conjuntos.txt", "r+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    calcularIntersecao(arquivo);

    fclose(arquivo);
    return 0;
}
