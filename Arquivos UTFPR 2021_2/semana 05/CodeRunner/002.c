# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define dimensao_matriz 7

int main(){

    int contador_i;    
    int contador_j;
    int matriz[dimensao_matriz][dimensao_matriz];
    bool existe_diferente_de_zero_acima_da_diagonal = 0;

    // lê valores para a matriz
    for (contador_i=0; contador_i<dimensao_matriz; contador_i++){
        for (contador_j=0; contador_j<dimensao_matriz; contador_j++){
            scanf("%d", &matriz[contador_i][contador_j]);
        }
    }

    // printa os valores da matriz
    for (contador_i=0; contador_i<dimensao_matriz; contador_i++){
        for (contador_j=0; contador_j<dimensao_matriz; contador_j++){
            printf("%d ", matriz[contador_i][contador_j]);
        }
        printf("\n");
    }

    // confere os itens acima da diagonal principal
    for (contador_i=0; contador_i<dimensao_matriz; contador_i++){
        for (contador_j=0; contador_j<dimensao_matriz; contador_j++){
            if (contador_i < contador_j && matriz[contador_i][contador_j] != 0){
                existe_diferente_de_zero_acima_da_diagonal = 1;
                break;
            }
        }
    }

    if (existe_diferente_de_zero_acima_da_diagonal){
        printf("NAO\n");
    }
    else{
        printf("SIM\n");
    }

    return 0;
}
