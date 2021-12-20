# include <stdio.h>

int main(){

    int leitura;
    scanf("%d", &leitura);

    if (leitura == 0){

        printf("NULO");
    }

    else {

        if (leitura < 0){

            printf("NEGATIVO");
        }

        else{

            printf("POSITIVO");
        }
    }

    return 0;
}
