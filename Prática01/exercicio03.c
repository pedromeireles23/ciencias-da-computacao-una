// Em linguagem de programação C, escreva um algoritmo que:

// 3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
// Imprima este valor em reais.

#include <stdio.h>

int main() {
    float cotacaoDolar, valorDolar, valorReais;

    // Solicita ao usuário que insira a cotação do dólar
    printf("Digite a cotação do dólar em reais: ");
    scanf("%f", &cotacaoDolar);

    // Solicita ao usuário que insira o valor em dólares
    printf("Digite o valor em dólares: ");
    scanf("%f", &valorDolar);

    // Calcula o valor em reais
    valorReais = valorDolar * cotacaoDolar;

    // Apresenta o resultado
    printf("O valor em reais é: $%.2f\n", valorReais);

    return 0;
}