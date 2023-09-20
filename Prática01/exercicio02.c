// Em linguagem de programação C, escreva um algoritmo que:

// 2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:

// a. A idade da pessoa no ano atual.
// b. A idade que a pessoa terá em 2050.


#include <stdio.h>

int main() {
    int anoNascimento, anoAtual;
    
    // Solicita ao usuário que insira o ano de nascimento
    printf("Digite o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    // Solicita ao usuário que insira o ano atual
    printf("Digite o ano atual: ");
    scanf("%d", &anoAtual);

    // Calcula a idade no ano atual
    int idadeAtual = anoAtual - anoNascimento;

    // Calcula a idade em 2050
    int idade2050 = 2050 - anoNascimento;

    // Apresenta os resultados
    printf("A idade da pessoa no ano atual é: %d anos\n", idadeAtual);
    printf("A idade da pessoa em 2050 será: %d anos\n", idade2050);

    return 0;
}