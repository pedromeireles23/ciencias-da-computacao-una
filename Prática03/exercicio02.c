// Em linguagem de programação C, escreva um algoritmo quê:
// 2) Implemente de forma recursiva a função soma a partir da função sucessor, como
// apresentado abaixo:
// DEFINIÇÃO RECURSIVA DE SOMA
// i) Base: se n = 0, então m + n = m (m + 0 = m)

// ii) Passo recursivo: m + s(n) = s(m + n)
// Exemplo:
// 3 + 2 = 5
// s(s(s(0))) + s(s(0)) = s(s(s(s(s(0)))))
// O usuário deve informar os números a serem somados.

#include <stdio.h>

// Função sucessor (s)
int sucessor(int n) {
    return n + 1;
}

// Função de soma recursiva
int soma(int m, int n) {
    if (n == 0) {
        return m;
    } else {
        return soma(m, sucessor(n));
    }
}

int main() {
    int num1, num2;
    printf("Informe o primeiro número: ");
    scanf("%d", &num1);
    printf("Informe o segundo número: ");
    scanf("%d", &num2);

    int resultado = soma(num1, num2);
    printf("Resultado: %d\n", resultado);

    return 0;
}