#include <stdio.h>

// Definir o tamanho máximo para as sequências e conjuntos
#define MAX_SIZE 100

// Função para gerar o conjunto A a partir da primeira sequência
int gerarConjuntoA(int seq[], int n, int A[]) {
    int tamanhoA = 0;
    
    for (int i = 0; i < n; i++) {
        int elemento = seq[i];
        int elementoJaExiste = 0;
        
        // Verificar se o elemento já existe no conjunto A
        for (int j = 0; j < tamanhoA; j++) {
            if (A[j] == elemento) {
                elementoJaExiste = 1;
                break;
            }
        }
        
        // Se o elemento não existe no conjunto A, adicioná-lo
        if (!elementoJaExiste) {
            A[tamanhoA] = elemento;
            tamanhoA++;
        }
    }
    
    return tamanhoA;
}

// Função para gerar o conjunto B a partir da segunda sequência
int gerarConjuntoB(int seq[], int n, int B[]) {
    int tamanhoB = 0;
    
    for (int i = 0; i < n; i++) {
        int elemento = seq[i];
        int elementoJaExiste = 0;
        
        // Verificar se o elemento já existe no conjunto B
        for (int j = 0; j < tamanhoB; j++) {
            if (B[j] == elemento) {
                elementoJaExiste = 1;
                break;
            }
        }
        
        // Se o elemento não existe no conjunto B, adicioná-lo
        if (!elementoJaExiste) {
            B[tamanhoB] = elemento;
            tamanhoB++;
        }
    }
    
    return tamanhoB;
}

int main() {
    int primeiraSequencia[MAX_SIZE];
    int segundaSequencia[MAX_SIZE];
    int conjuntoA[MAX_SIZE];
    int conjuntoB[MAX_SIZE];
    
    int n1, n2;
    
    // Solicitar o tamanho da primeira sequência
    printf("Informe o tamanho da primeira sequência: ");
    scanf("%d", &n1);
    
    // Ler a primeira sequência
    printf("Informe os elementos da primeira sequência:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &primeiraSequencia[i]);
    }
    
    // Solicitar o tamanho da segunda sequência
    printf("Informe o tamanho da segunda sequência: ");
    scanf("%d", &n2);
    
    // Ler a segunda sequência
    printf("Informe os elementos da segunda sequência:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &segundaSequencia[i]);
    }
    
    // Gerar os conjuntos A e B a partir das sequências
    int tamanhoA = gerarConjuntoA(primeiraSequencia, n1, conjuntoA);
    int tamanhoB = gerarConjuntoB(segundaSequencia, n2, conjuntoB);
    
    // Abrir o arquivo original para escrita
    FILE *arquivo = fopen("arquivo.txt", "w");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }
    
    // Escrever os conjuntos A e B no arquivo
    fprintf(arquivo, "Conjunto A:\n");
    for (int i = 0; i < tamanhoA; i++) {
        fprintf(arquivo, "%d ", conjuntoA[i]);
    }
    
    fprintf(arquivo, "\nConjunto B:\n");
    for (int i = 0; i < tamanhoB; i++) {
        fprintf(arquivo, "%d ", conjuntoB[i]);
    }
    
    // Fechar o arquivo
    fclose(arquivo);
    
    printf("Conjuntos A e B foram armazenados no arquivo 'arquivo.txt'.\n");
    
    return 0;
}
