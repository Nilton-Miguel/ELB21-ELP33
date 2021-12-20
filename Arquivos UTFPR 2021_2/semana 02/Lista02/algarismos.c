# include <stdio.h>

int main(){

    int numero;
    int centena, dezena, unidade;

    scanf("%d", &numero);

    /*
        centena
            vou usar a divisão inteira para ficar apenas com a centena:
                587/100 = 5
            depois disso vou subtrair a parte da centena do número:
                587 - (centena * 100) = 87
        
        dezena
            vou usar a divisão inteira de novo para ficar apenas com a dezena:
                87/10 = 8
            depois vou subtrair a parte da dezena de novo:
                87 - (dezena * 10) = 7
        
        unidade
            após a última operação eu já tenho a unidade

    */

    centena = numero/100;
    numero -= centena*100;

    dezena = numero/10;
    numero-= dezena*10;

    unidade = numero;

    printf("%d\n", centena);
    printf("%d\n", dezena);
    printf("%d", unidade);

    return 0;
}
