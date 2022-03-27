# include <stdio.h>
# include <stdlib.h>

int main(){

    float num1, num2, soma;

    printf("Escreva um número: ");
    scanf("%f", &num1);
    printf("Escreva outro número: ");
    scanf("%f", &num2);

    soma = num1 + num2;

    printf("Soma = %.2f\n", soma);

    return 0;
}
