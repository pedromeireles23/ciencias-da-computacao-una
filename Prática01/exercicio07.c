
// Em linguagem de programação C, escreva um algoritmo que:
// 7) Receba o valor do salário mínimo e o valor do salário de um funcionário. O algoritmo
// deve calcular e apresentar a quantidade de salários mínimos que esse funcionário
// recebe.

#include <stdio.h>

int main() {
    float salarioMinimo, salarioFuncionario, qtdSalariosMinimos;

    // Solicita ao usuário que insira o valor do salário mínimo
    printf("Digite o valor do salário mínimo: ");
    scanf("%f", &salarioMinimo);

    // Solicita ao usuário que insira o valor do salário do funcionário
    printf("Digite o valor do salário do funcionário: ");
    scanf("%f", &salarioFuncionario);

    // Calcula a quantidade de salários mínimos que o funcionário recebe
    qtdSalariosMinimos = salarioFuncionario / salarioMinimo;

    // Apresenta a quantidade de salários mínimos
    printf("O funcionário recebe %.2f salários mínimos.\n", qtdSalariosMinimos);

    return 0;
}