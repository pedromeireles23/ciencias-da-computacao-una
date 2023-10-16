#include <stdio.h>

#define NUM_CIDADES 4

// Estrutura para representar o grafo
struct Grafo {
    int matrizDistancia[NUM_CIDADES][NUM_CIDADES];
};

// Função para inserir a distância entre duas cidades na matriz
void inserirDistancia(struct Grafo *grafo, int cidadeOrigem, int cidadeDestino, int distancia) {
    if (cidadeOrigem >= 0 && cidadeOrigem < NUM_CIDADES && cidadeDestino >= 0 && cidadeDestino < NUM_CIDADES) {
        grafo->matrizDistancia[cidadeOrigem][cidadeDestino] = distancia;
        grafo->matrizDistancia[cidadeDestino][cidadeOrigem] = distancia;  // Grafo não direcionado
    } else {
        printf("Cidades inválidas.\n");
    }
}

// Função para contar quantas estradas ligam as cidades
int contarEstradas(struct Grafo *grafo, int cidade) {
    int totalEstradas = 0;
    if (cidade >= 0 && cidade < NUM_CIDADES) {
        for (int i = 0; i < NUM_CIDADES; i++) {
            if (grafo->matrizDistancia[cidade][i] > 0) {
                totalEstradas++;
            }
        }
    } else {
        printf("Cidade inválida.\n");
    }
    return totalEstradas;
}

// Função para imprimir a matriz de distância
void imprimirMatriz(struct Grafo *grafo) {
    printf("Matriz de Distâncias:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            printf("%d\t", grafo->matrizDistancia[i][j]);
        }
        printf("\n");
    }
}

// Função recursiva para obter a distância entre cidades
int obterDistanciaEntreCidades(struct Grafo *grafo, int cidadeOrigem, int cidadeDestino) {
    if (cidadeOrigem >= 0 && cidadeOrigem < NUM_CIDADES && cidadeDestino >= 0 && cidadeDestino < NUM_CIDADES) {
        return grafo->matrizDistancia[cidadeOrigem][cidadeDestino];
    } else {
        return 0;  // Retorna 0 se as cidades não forem válidas ou não estiverem conectadas
    }
}

int main() {
    struct Grafo grafo;

    // Inicializa a matriz de distância
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            grafo.matrizDistancia[i][j] = 0;
        }
    }

    // Insere as distâncias entre as cidades
    inserirDistancia(&grafo, 0, 1, 100);
    inserirDistancia(&grafo, 1, 2, 150);
    inserirDistancia(&grafo, 2, 3, 120);
    inserirDistancia(&grafo, 3, 0, 80);

    // Imprime a matriz de distância
    imprimirMatriz(&grafo);

    // Teste da função recursiva
    int cidadeOrigem, cidadeDestino;
    printf("Informe a cidade de origem e destino (0 a 3): ");
    scanf("%d %d", &cidadeOrigem, &cidadeDestino);

    int distancia = obterDistanciaEntreCidades(&grafo, cidadeOrigem, cidadeDestino);
    if (distancia > 0) {
        printf("A distância entre as cidades é %d.\n", distancia);
    } else {
        printf("Não há uma estrada ligando as cidades ou cidades inválidas.\n");
    }

    // Contar estradas a partir de uma cidade
    int cidadeParaContarEstradas;
    printf("Informe uma cidade para contar estradas a partir dela (0 a 3): ");
    scanf("%d", &cidadeParaContarEstradas);

    int estradas = contarEstradas(&grafo, cidadeParaContarEstradas);
    if (estradas >= 0) {
        printf("Total de estradas a partir da cidade %d: %d\n", cidadeParaContarEstradas, estradas);
    } else {
        printf("Cidade inválida.\n");
    }

    return 0;
}