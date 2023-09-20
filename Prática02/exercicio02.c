// Em linguagem de programação C, escreva um algoritmo que possua:
// Um(a) procedimento/função que leia as duas sequências de números naturais a partir
// do arquivo, armazene-as em dois vetores e apresente os vetores na tela.

#include <stdio.h>
#include <stdlib.h>

// Função para ler sequência de um arquivo e armazená-la em um vetor
void lerSequenciaDeArquivo(const char* nomeArquivo, int vetor[], int tamanho) {
    FILE* arquivo = fopen(nomeArquivo, "r");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s'.\n", nomeArquivo);
        return;
    }

    // Ler e armazenar a sequência no vetor
    for (int i = 0; i < tamanho; i++) {
        if (fscanf(arquivo, "%d", &vetor[i]) != 1) {
            printf("Erro ao ler a sequência do arquivo '%s'.\n", nomeArquivo);
            fclose(arquivo);
            return;
        }
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Apresentar o vetor na tela
    printf("Sequência lida do arquivo '%s':\n", nomeArquivo);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanhoSequencia = 3;
    // Solicita ao usuário que insira o tamanho da sequência
    // printf("Digite o tamanho da sequência: ");
    // scanf("%d", &tamanhoSequencia);

    // Verifica se o tamanho da sequência é válido
    // if (tamanhoSequencia <= 0) {
    //     printf("Tamanho de sequência inválido.\n");
    //     return 1; // Encerra o programa com código de erro
    // }
    int sequencia1[tamanhoSequencia];
    int sequencia2[tamanhoSequencia];

    // Chama a função para ler a primeira sequência do arquivo "sequencia1.txt"
    lerSequenciaDeArquivo("sequencia1.txt", sequencia1, tamanhoSequencia);

    // Chama a função para ler a segunda sequência do arquivo "sequencia2.txt"
    lerSequenciaDeArquivo("sequencia2.txt", sequencia2, tamanhoSequencia);

    return 0;
}