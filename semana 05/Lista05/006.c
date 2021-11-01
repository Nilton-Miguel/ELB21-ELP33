# include <stdio.h>
# include <stdlib.h>

int main(){

    int vetor[5];
    int vetor_decrescente[5];
    int contador;

    int pares_corretos;
    int backup_para_inverter;

    // leio os valores para um vetor
    for (contador=0; contador<5; contador++){
        scanf("%d", &vetor[contador]);
    }
    // mostro o vetor
    for (contador=0; contador<5; contador++){
        printf("%d ", vetor[contador]);
    }
    printf("\n");

    // inicio o vetor decrescente como uma cópia integral do vetor
    for (contador=0; contador<5; contador++){
        vetor_decrescente[contador] = vetor[contador];
    }

    // agora eu vou efetivamente colocar o vator em ordem decrescente
    while (pares_corretos < 4){

        pares_corretos = 0;
        /*
            se o número num certo índice for menor ou igual ao anterior, 
            esse par está correto em ordem decrescente
        */
        for (contador=1; contador<5; contador++){
            // se já for decrecente, o par está certo
            if (vetor_decrescente[contador] <= vetor_decrescente[contador -1]){
                pares_corretos++;
            }
            // se for crescente, inverte o par
            else{
                backup_para_inverter = vetor_decrescente[contador];
                // o segundo copia o primeiro
                vetor_decrescente[contador] = vetor_decrescente[contador-1];
                // o primeiro copia o segundo
                vetor_decrescente[contador-1] = backup_para_inverter;
            }
        }
    }

    // mostro o vetor decrescente
    for (contador=0; contador<5; contador++){
        printf("%d ", vetor_decrescente[contador]);
    }
    printf("\n");

    // mostro a soma entre cada par de itens
    for (contador=0; contador<5; contador++){
        printf("%d ", vetor_decrescente[contador] + vetor[contador]);
    }
    printf("\n");

    return 0;
}
