// Em linguagem de programação C, escreva um algoritmo quê:

// 1) Implemente e apresente a relação entre números naturais e inteiros dada por:
// I = { ..., -3, -2, -1, 0, 1, 2, 3, ... }
// é enumerável com:

// f(n) = div(n, 2) + 1, se n for impar
// f(n) = -div(n, 2), se n for par
// para n ε N.
// O usuário deve informar o número limite de execuções do algoritmo. Exemplo:
// Informe o limite: 5
// [0, 0], [1, 1], [2, -1], [3, 2], [4, -2], [5, 3],
// O algoritmo deve ser implementado em duas versões:
// 1. Não recursiva.
// 2. Recursiva


#include <stdio.h>

int main() {
    int limite;
    printf("Informe o limite: ");
    scanf("%d", &limite);

    for (int n = 0; n <= limite; n++) {
        int resultado;
        if (n % 2 == 0) {
            resultado = -n / 2;
        } else {
            resultado = n / 2 + 1;
        }
        printf("[%d, %d], ", n, resultado);
    }

    printf("\n");
    return 0;
}