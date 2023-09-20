// Em linguagem de programação C, escreva um algoritmo que:
// 5) Calcule e apresente a área de um losango. As diagonais maior e menor do losango
// devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONAL
// MENOR) / 2.

#include <stdio.h>

int main() {
    float diagonalMaior, diagonalMenor, area;

    // Solicita ao usuário que insira a diagonal maior e a diagonal menor
    printf("Digite o valor da diagonal maior do losango: ");
    scanf("%f", &diagonalMaior);

    printf("Digite o valor da diagonal menor do losango: ");
    scanf("%f", &diagonalMenor);

    // Calcula a área do losango
    area = (diagonalMaior * diagonalMenor) / 2.0;

    // Apresenta a área do losango
    printf("A área do losango é: %.2f\n", area);

    return 0;
}