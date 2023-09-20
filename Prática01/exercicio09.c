
// Em linguagem de programação C, escreva um algoritmo que:
// 9) Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
// hipotenusa. OBS - Teorema de Pitágoras: a
// 2 = b2 + c2


#include <stdio.h>
#include <math.h>

int main() {
    float catetoA, catetoB, hipotenusa;

    // Solicita ao usuário que insira os valores dos catetos
    printf("Digite o valor do primeiro cateto: ");
    scanf("%f", &catetoA);

    printf("Digite o valor do segundo cateto: ");
    scanf("%f", &catetoB);

    // Calcula a hipotenusa usando o Teorema de Pitágoras
    hipotenusa = sqrt(catetoA * catetoA + catetoB * catetoB);

    // Apresenta o valor da hipotenusa
    printf("O valor da hipotenusa é: %.2f\n", hipotenusa);

    return 0;
}