#include <stdio.h>
#include <math.h>

void printPowerSet(int A[], int B[], int n) {
    int totalSubsets = pow(2, n);
    
    printf("Conjuntos próprios dos conjuntos potência de A:\n");
    for (int i = 1; i < totalSubsets - 1; i++) {
        printf("{");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", A[j]);
            }
        }
        printf("}\n");
    }
    
    printf("\nConjuntos próprios dos conjuntos potência de B:\n");
    for (int i = 1; i < totalSubsets - 1; i++) {
        printf("{");
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                printf("%d ", B[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    int A[] = {1, 2, 3}; // Exemplo de conjunto A
    int B[] = {4, 5, 6}; // Exemplo de conjunto B
    int n = sizeof(A) / sizeof(A[0]); // Número de elementos nos conjuntos A e B
    
    printPowerSet(A, B, n);
    
    return 0;
}
