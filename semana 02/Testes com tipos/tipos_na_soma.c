# include <stdio.h>

int main(){

    while(1){

        // somar um inteiro e um flutuante, faz o inteiro ser convertido 
        // para flutuante e o resultado é um flutuante
        
        int x;
        float y;

        printf("\nDigite um inteiro: ");
        scanf("%d", &x);
        printf("Digite um flutuante: ");
        scanf("%f", &y);

        float s = x + y;

        printf("\n%d + %.2f = %.2f\n\n", x, y, s);

        return 0;

    }
}

