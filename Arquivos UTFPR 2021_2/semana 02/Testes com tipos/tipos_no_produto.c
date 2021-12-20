# include <stdio.h>

int main(){

    while(1){

        // multiplicar um inteiro e um flutuante, faz o inteiro ser convertido 
        // para flutuante e o resultado é um flutuante
        
        int x;
        float y;

        printf("\nDigite um inteiro: ");
        scanf("%d", &x);
        printf("Digite um flutuante: ");
        scanf("%f", &y);

        float p = x * y;

        printf("\n%d x %.2f = %.2f\n\n", x, y, p);

        return 0;
    }
}

