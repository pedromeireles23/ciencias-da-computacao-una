#include <stdio.h>
#include <math.h>

void gerarConjuntoPotencia(int conjunto[], int tamanho, FILE *arquivo) {
    int totalSubconjuntos = pow(2, tamanho);
    fprintf(arquivo, "Conjunto potência:\n");

    for (int i = 0; i < totalSubconjuntos; ++i) {
        fprintf(arquivo, "{ ");
        for (int j = 0; j < tamanho; ++j) {
            if (i & (1 << j)) {
                fprintf(arquivo, "%d ", conjunto[j]);
            }
        }
        fprintf(arquivo, "}\n");
    }
}

int main() {
    int conjuntoA[] = {1, 2}; // Altere os elementos de acordo com o conjunto A
    int tamanhoA = sizeof(conjuntoA) / sizeof(conjuntoA[0]);
    
    int conjuntoB[] = {3, 4}; // Altere os elementos de acordo com o conjunto B
    int tamanhoB = sizeof(conjuntoB) / sizeof(conjuntoB[0]);

    FILE *arquivo = fopen("conjunto_potencia.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    gerarConjuntoPotencia(conjuntoA, tamanhoA, arquivo);
    fprintf(arquivo, "\n");
    gerarConjuntoPotencia(conjuntoB, tamanhoB, arquivo);

    fclose(arquivo);

    printf("Conjuntos potência foram salvos no arquivo 'conjunto_potencia.txt'.\n");

    return 0;
}
