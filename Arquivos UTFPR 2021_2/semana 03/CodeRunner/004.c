# include <stdio.h>

int main(){

    int tarifa, idade;
    float valor_cobrado;

    scanf("%d %d", &tarifa, &idade);

    if (idade < 2){

        valor_cobrado = 0.0;
    }
    else if (idade < 6){

        valor_cobrado = 0.5*tarifa;
    }
    else{

        valor_cobrado = 1.0*tarifa;
    }

    printf("%.2f", valor_cobrado);

    return 0;
}
