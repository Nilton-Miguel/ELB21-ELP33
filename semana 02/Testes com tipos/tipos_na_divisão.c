# include <stdio.h>

int main(){

    while(1){

        // dividir dois inteiros resulta num truncamento ( arredondamento pra próximo de 0 ) 
        
        int x;
        int y;

        while(1){

            printf("=======================================================================\n");

            printf("Digite um inteiro: ");
            scanf("%d", &x);
            printf("Digite outro inteiro: ");
            scanf("%d", &y);

            int q = x / y;
            float r = ( 1.0*x ) / y;

            printf("\n[ não convertendo %d para %.3f ]         %d / %d = %d\n",x, 1.0*x, x, y, q);
            printf("[ convertendo %d para %.3f ]             %d / %d = %.3f\n",x, 1.0*x, x, y, r);
        }
        return 0;
    }
}

