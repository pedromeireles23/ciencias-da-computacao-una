// Em linguagem de programação C, escreva um algoritmo que:
// 4) Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
// salário, sabendo-se que ele teve um aumento de 25%.

#include <stdio.h>

int main() {
    float salarioAtual, novoSalario;

    // Solicita ao usuário que insira o salário atual
    printf("Digite o salário atual do funcionário: ");
    scanf("%f", &salarioAtual);

    // Calcula o novo salário com aumento de 25%
    novoSalario = salarioAtual * 1.25; // Aumento de 25% é o mesmo que multiplicar por 1.25

    // Apresenta o novo salário
    printf("O novo salário do funcionário é: %.2f\n", novoSalario);

    return 0;
}