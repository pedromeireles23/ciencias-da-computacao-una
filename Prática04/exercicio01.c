// Em linguagem de programação C, escreva um algoritmo quê:

// 1) Leia uma string a partir de um arquivo no modo texto e:
// a. Determine o tamanho (comprimento) da string de forma recursiva. Armazene o
// tamanho da string no arquivo original.
// b. Determine o reverso da string de forma recursiva. Armazene o reverso da string no
// arquivo original.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o tamanho da string de forma recursiva
int calcularTamanhoRecursivo(const char *str, int index) {
    if (str[index] == '\0') {
        return 0;
    }
    return 1 + calcularTamanhoRecursivo(str, index + 1);
}

// Função para calcular o reverso da string de forma recursiva
void calcularReversoRecursivo(const char *str, char *reverso, int index) {
    if (str[index] == '\0') {
        reverso[index] = '\0';
        return;
    }
    calcularReversoRecursivo(str, reverso, index + 1);
    reverso[strlen(str) - 1 - index] = str[index];
}

int main() {
    // Abrir o arquivo de entrada
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        return 1;
    }

    // Ler a string do arquivo de entrada
    char inputString[1000];  // Suponhamos que a string tenha no máximo 1000 caracteres
    if (fgets(inputString, sizeof(inputString), inputFile) == NULL) {
        perror("Erro ao ler a string do arquivo de entrada");
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);

    // Abrir o arquivo de saída para escrever o tamanho da string e o reverso
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        return 1;
    }

    // Calcular o tamanho da string de forma recursiva
    int tamanho = calcularTamanhoRecursivo(inputString, 0);
    fprintf(outputFile, "Tamanho da string: %d\n", tamanho);

    // Calcular o reverso da string de forma recursiva
    char reverso[1000];  // Suponhamos que o reverso tenha no máximo 1000 caracteres
    calcularReversoRecursivo(inputString, reverso, 0);
    fprintf(outputFile, "Reverso da string: %s\n", reverso);

    fclose(outputFile);

    printf("Operações concluídas. Verifique o arquivo 'output.txt' para os resultados.\n");

    return 0;
}