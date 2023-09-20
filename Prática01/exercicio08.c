
// Em linguagem de programação C, escreva um algoritmo que:
// 8) Receba o peso de uma pessoa, calcule e apresente o novo peso:

// a. Se a pessoa engordar 15%.
// b. Se a pessoa emagrecer 20%.

#include <stdio.h>

int main() {
    float pesoAtual, novoPesoEngordar, novoPesoEmagrecer;

    // Solicita ao usuário que insira o peso atual
    printf("Digite o peso atual da pessoa: ");
    scanf("%f", &pesoAtual);

    // Calcula o novo peso se a pessoa engordar 15%
    novoPesoEngordar = pesoAtual * 1.15; // Aumento de 15% é o mesmo que multiplicar por 1.15

    // Calcula o novo peso se a pessoa emagrecer 20%
    novoPesoEmagrecer = pesoAtual * 0.8; // Redução de 20% é o mesmo que multiplicar por 0.8

    // Apresenta os novos pesos
    printf("Se a pessoa engordar 15%%, o novo peso será: %.2f\n", novoPesoEngordar);
    printf("Se a pessoa emagrecer 20%%, o novo peso será: %.2f\n", novoPesoEmagrecer);

    return 0;
}