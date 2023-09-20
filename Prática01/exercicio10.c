
// Em linguagem de programação C, escreva um algoritmo que:
// 10) Receba o raio, calcule e apresente:

// a. O comprimento de uma esfera: C = 2 * π * R.
// b. A área de uma esfera: A = π * R2
// c. O volume de uma esfera: V = 3⁄4 * π * R3
// .

#include <stdio.h>
#include <math.h>

int main() {
    float raio, comprimento, area, volume;
    const float pi = 3.14159265359; // Valor de π (pi)

    // Solicita ao usuário que insira o raio da esfera
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    // Calcula o comprimento da esfera
    comprimento = 2 * pi * raio;

    // Calcula a área da esfera
    area = pi * raio * raio;

    // Calcula o volume da esfera
    volume = (3.0 / 4.0) * pi * pow(raio, 3);

    // Apresenta os resultados
    printf("O comprimento da esfera é: %.2f\n", comprimento);
    printf("A área da esfera é: %.2f\n", area);
    printf("O volume da esfera é: %.2f\n", volume);

    return 0;
}