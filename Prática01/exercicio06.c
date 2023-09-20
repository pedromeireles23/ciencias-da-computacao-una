// Em linguagem de programação C, escreva um algoritmo que:
// 6) Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
// OBS: F = (C * 1,8) + 32.


#include <stdio.h>

int main() {
    float temperaturaCelsius, temperaturaFahrenheit;

    // Solicita ao usuário que insira a temperatura em Celsius
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &temperaturaCelsius);

    // Calcula a temperatura em Fahrenheit
    temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32.0;

    // Apresenta a temperatura em Fahrenheit
    printf("A temperatura em graus Fahrenheit é: %.2f\n", temperaturaFahrenheit);

    return 0;
}