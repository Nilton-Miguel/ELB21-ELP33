# include <stdio.h>
# include <stdlib.h>

int main(){

    int numero_a_ser_impresso;
    int repeticoes_a_imprimir;
    int numero_para_preencher;
    int matriz[10];
    int contador;

    // leitura padrão
    scanf("%d", &numero_a_ser_impresso);

    // leitura com validação
    do{
        scanf("%d", &repeticoes_a_imprimir);
    }
    while(repeticoes_a_imprimir>10 || repeticoes_a_imprimir<=0);

    // leitura padrão
    scanf("%d", &numero_para_preencher);

    // insere os primeiros números pedidos
    for (contador=0; contador<repeticoes_a_imprimir; contador++){
        matriz[contador] = numero_a_ser_impresso;
    }
    // completa o restante dos números
    for (contador=repeticoes_a_imprimir; contador<10; contador++){
        matriz[contador] = numero_para_preencher;
    }
    // printa a matriz
    for (contador=0; contador<10; contador++){
        printf("%d ", matriz[contador]);
    } 
    printf("\n");

    return 0;
}
