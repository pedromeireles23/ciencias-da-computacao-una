// Em linguagem de programação C
// Implemente de forma recursiva a função "Menor Que" (MQ) a partir da função sucessor,
// como apresentado abaixo:
// Relação MQ:
// i) Base: [0, 1] ε MQ
// ii) Passo recursivo:
// se [n, m] ε MQ, então [n, s(m)] ε MQ
// OBS: a geração de um elemento pode não ser única:
// base: [0, 1]
// 1: [0, s(1)] = [0, 2] [s(0), s(1)] = [1, 2]
// 2 : ... [s(0), s(2)] = [1, 3] ... [1, s(2)] = [1, 3]
// Usando a descrição de união infinita, obtemos o conjunto MQ por:
// MQ0 = { [0, 1] }
// MQ1 = MQ0 Ս { [0, 2], [1, 2] }
// MQ2 = MQ1 Ս { [0, 3], [1, 3], [2, 3] }
// MQi = MQi - 1 Ս { [ j, i + 1] I j = 0, 1, ... , i }
// O usuário deve informar o valor de "i".

#include <stdio.h>

// Função sucessor (s)
int sucessor(int n) {
    return n + 1;
}

// Função para verificar se [n, m] pertence a MQ
int pertenceAMQ(int n, int m) {
    if (n == 0) {
        return 1;  // Caso base
    }
    if (m == 1) {
        return 0;  // Exceção para evitar [n, 1] em MQ
    }
    if (n > 0 && pertenceAMQ(n - 1, m - 1)) {
        return 1;  // Passo recursivo
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