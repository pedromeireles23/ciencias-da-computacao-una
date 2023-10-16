#include <stdio.h>

// Função para calcular e armazenar o produto cartesiano de dois conjuntos
void calcularProdutoCartesiano(int B[], int tamanhoB, int A[], int tamanhoA) {
    FILE *arquivo = fopen("produto_cartesiano.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return;
    }

    // Calcula o produto cartesiano e armazena no arquivo
    for (int i = 0; i < tamanhoB; i++) {
        for (int j = 0; j < tamanhoA; j++) {
            fprintf(arquivo, "(%d, %d)\n", B[i], A[j]);
        }
    }

    // Fecha o arquivo após a escrita
    fclose(arquivo);
}

int main() {
    // Defina os conjuntos B e A
    int B[] = {1, 2, 3};
    int tamanhoB = sizeof(B) / sizeof(B[0]);
    int A[] = {4, 5, 6};
    int tamanhoA = sizeof(A) / sizeof(A[0]);

    // Chama a função para calcular e armazenar o produto cartesiano
    calcularProdutoCartesiano(B, tamanhoB, A, tamanhoA);

    printf("Produto cartesiano calculado e armazenado no arquivo produto_cartesiano.txt.\n");

    return 0;
}
