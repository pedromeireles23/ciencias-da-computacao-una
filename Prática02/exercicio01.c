// Em linguagem de programação C, escreva um algoritmo que possua:
// a) Um(a) procedimento/função que leia duas sequências finitas de números naturais (N)
// a partir do teclado, apresente-as na tela e, depois, armazene-as em um arquivo no
// formato texto.


#include <stdio.h>

// Função para ler e armazenar sequência em um arquivo
void lerEArmazenarSequencia(int sequencia[], int tamanho, const char* nomeArquivo) {
    int i;

    // Ler a sequência do teclado e apresentá-la
    printf("Digite %d números naturais para a sequência:\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        scanf("%d", &sequencia[i]);
        printf("%d ", sequencia[i]);
    }
    printf("\n");

    // Abrir o arquivo no modo de escrita
    FILE* arquivo = fopen(nomeArquivo, "w");

    // Verificar se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Armazenar a sequência no arquivo
    for (i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d ", sequencia[i]);
    }

    // Fechar o arquivo
    fclose(arquivo);

    printf("Sequência armazenada com sucesso no arquivo '%s'.\n", nomeArquivo);
}

int main() {
    int tamanhoSequencia = 0;

    // Solicita ao usuário que insira o tamanho da sequência
    printf("Digite o tamanho da sequência: ");
    scanf("%d", &tamanhoSequencia);

    // Verifica se o tamanho da sequência é válido
    if (tamanhoSequencia <= 0) {
        printf("Tamanho de sequência inválido.\n");
        return 1; // Encerra o programa com código de erro
    }

    int sequencia1[tamanhoSequencia];
    int sequencia2[tamanhoSequencia];

    // Chama a função para ler e armazenar a primeira sequência
    lerEArmazenarSequencia(sequencia1, tamanhoSequencia, "sequencia1.txt");

    // Chama a função para ler e armazenar a segunda sequência
    lerEArmazenarSequencia(sequencia2, tamanhoSequencia, "sequencia2.txt");

    return 0;
}