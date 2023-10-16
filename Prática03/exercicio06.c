#include <stdio.h>
#include <stdbool.h>

#define NUM_CIDADES 4

// Estrutura para representar o grafo
struct Grafo {
    int matrizAdjacencia[NUM_CIDADES][NUM_CIDADES];
};

// Função para inicializar o grafo
void inicializarGrafo(struct Grafo *grafo) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            grafo->matrizAdjacencia[i][j] = 0;
        }
    }
}

// Função para adicionar uma aresta (arco) direcionada entre cidades
void adicionarAresta(struct Grafo *grafo, int cidadeOrigem, int cidadeDestino) {
    if (cidadeOrigem >= 0 && cidadeOrigem < NUM_CIDADES && cidadeDestino >= 0 && cidadeDestino < NUM_CIDADES) {
        grafo->matrizAdjacencia[cidadeOrigem][cidadeDestino] = 1;
    } else {
        printf("Cidades inválidas.\n");
    }
}

// Função recursiva para calcular o comprimento do caminho entre cidades
int calcularComprimentoCaminho(struct Grafo *grafo, int cidadeOrigem, int cidadeDestino) {
    if (cidadeOrigem >= 0 && cidadeOrigem < NUM_CIDADES && cidadeDestino >= 0 && cidadeDestino < NUM_CIDADES) {
        if (cidadeOrigem == cidadeDestino) {
            return 0;  // Caso base: chegou ao destino
        } else {
            int menorComprimento = -1;  // Inicializa com um valor impossível
            for (int i = 0; i < NUM_CIDADES; i++) {
                if (grafo->matrizAdjacencia[cidadeOrigem][i] == 1) {
                    int comprimentoSubcaminho = calcularComprimentoCaminho(grafo, i, cidadeDestino);
                    if (comprimentoSubcaminho >= 0 && (menorComprimento == -1 || comprimentoSubcaminho < menorComprimento)) {
                        menorComprimento = 1 + comprimentoSubcaminho;
                    }
                }
            }
            return menorComprimento;
        }
    } else {
        return -1;  // Retorna -1 se as cidades não forem válidas
    }
}

// Função para verificar se há ciclos no grafo (detecta ciclo de Euler)
bool temCiclo(struct Grafo *grafo, int cidadeAtual, int cidadeOrigem, bool visitado[NUM_CIDADES]) {
    visitado[cidadeAtual] = true;
    for (int i = 0; i < NUM_CIDADES; i++) {
        if (grafo->matrizAdjacencia[cidadeAtual][i] == 1) {
            if (!visitado[i]) {
                if (temCiclo(grafo, i, cidadeAtual, visitado)) {
                    return true;
                }
            } else if (i != cidadeOrigem) {
                return true;
            }
        }
    }
    visitado[cidadeAtual] = false;
    return false;
}

// Função para calcular o grau de entrada de cada nó
void calcularGrauEntrada(struct Grafo *grafo, int grauEntrada[NUM_CIDADES]) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        grauEntrada[i] = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            grauEntrada[i] += grafo->matrizAdjacencia[j][i];
        }
    }
}

// Função para calcular o grau de saída de cada nó
void calcularGrauSaida(struct Grafo *grafo, int grauSaida[NUM_CIDADES]) {
    for (int i = 0; i < NUM_CIDADES; i++) {
        grauSaida[i] = 0;
        for (int j = 0; j < NUM_CIDADES; j++) {
            grauSaida[i] += grafo->matrizAdjacencia[i][j];
        }
    }
}

int main() {
    struct Grafo grafo;
    int grauEntrada[NUM_CIDADES];
    int grauSaida[NUM_CIDADES];
    bool visitado[NUM_CIDADES];

    inicializarGrafo(&grafo);

    // Adicionar arestas (arcos) direcionados entre cidades
    adicionarAresta(&grafo, 0, 1);
    adicionarAresta(&grafo, 1, 2);
    adicionarAresta(&grafo, 2, 0);
    adicionarAresta(&grafo, 3, 1);
    adicionarAresta(&grafo, 1, 3);

    // Calcular o comprimento do caminho entre cidades
    int cidadeOrigem, cidadeDestino;
    printf("Informe a cidade de origem e destino (0 a 3): ");
    scanf("%d %d", &cidadeOrigem, &cidadeDestino);

    int comprimento = calcularComprimentoCaminho(&grafo, cidadeOrigem, cidadeDestino);

    if (comprimento >= 0) {
        printf("Comprimento do caminho entre as cidades: %d\n", comprimento);
    } else {
        printf("Cidades inválidas ou sem caminho entre elas.\n");
    }

    // Verificar se há ciclos no grafo
    bool ciclo = false;
    for (int i = 0; i < NUM_CIDADES; i++) {
        for (int j = 0; j < NUM_CIDADES; j++) {
            visitado[j] = false;
        }
        if (temCiclo(&grafo, i, i, visitado)) {
            ciclo = true;
            break;
        }
    }

    if (ciclo) {
        printf("O grafo contém ciclos.\n");
    } else {
        printf("O grafo não contém ciclos.\n");
    }

    // Calcular o grau de entrada de cada nó
    calcularGrauEntrada(&grafo, grauEntrada);
    printf("Grau de entrada de cada nó:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Nó %d: %d\n", i, grauEntrada[i]);
    }

    // Calcular o grau de saída de cada nó
    calcularGrauSaida(&grafo, grauSaida);
    printf("Grau de saída de cada nó:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("Nó %d: %d\n", i, grauSaida[i]);
    }

    return 0;
}