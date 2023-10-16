#include <stdio.h>

// Função para verificar se [n, m] pertence a MQ
int pertenceAMQ(int n, int m) {
    if (n == 0 && m == 1) {
        return 1;  // Caso base
    }
    if (n > 0 && m > 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= m; j++) {
                if (!pertenceAMQ(i, j)) {
                    return 0;  // Se algum par [i, j] não pertencer à MQ, então [n, m] também não pertence
                }
            }
        }
        return 1;  // Se todas as condições passarem, [n, m] pertence a MQ
    }
    return 0;  // Se não atender a nenhuma das condições, não pertence a MQ
}

int main() {
    int i;
    printf("Informe o valor de i: ");
    scanf("%d", &i);

    printf("Conjunto MQ%d:\n", i);
    for (int n = 0; n <= i; n++) {
        for (int m = 1; m <= i + 1; m++) {
            if (pertenceAMQ(n, m)) {
                printf("[%d, %d] ", n, m);
            }
        }
    }

    printf("\n");

    return 0;
}