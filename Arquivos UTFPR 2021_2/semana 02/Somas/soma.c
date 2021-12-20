# include <stdio.h>

int main(){

    int primeiro_valor, segundo_valor;

    printf("\n");

    while (1){

        printf("Digite o primeiro inteiro: ");
        scanf("%d", &primeiro_valor);
        printf("Digite o segundo inteiro: ");
        scanf("%d", &segundo_valor);
        printf("\n%d + %d = %d\n\n", primeiro_valor, segundo_valor, primeiro_valor + segundo_valor);

    }

    return 0;
}

