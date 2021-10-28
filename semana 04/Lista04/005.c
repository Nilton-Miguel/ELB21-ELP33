# include <stdio.h>
# include <stdlib.h>

int main(){

    /*
        ( v.2 ) Para economizar uma variável

        A quantidade mínima pedida vai ser tratada como uma dívida que precisa ser abatida

        Vamos descontar dessa dívida uma certa quantidade de grãos a cada ciclo do while

        O primeiro abate já é feito automaticamente (de um grão) e consideramos necessário 
        no mínimo 1 quadrado. O ultimo abate fica salvo como 1. A partir daí a cada quadrado
        o último abate dobra e abatemos esse valor da dívida. Eventualmente a dívida vai estar
        em zero ou negativa, o que significa estar quitada. Encerramos o loop.
    
    */

    int graos_que_ainda_falta_entregar;
    int quadrados_necessarios = 1;
    int ultimo_abatimento = 1;

    scanf("%d", &graos_que_ainda_falta_entregar);
    graos_que_ainda_falta_entregar --;

    while(graos_que_ainda_falta_entregar > 0){

        quadrados_necessarios++;
        ultimo_abatimento *= 2;
        graos_que_ainda_falta_entregar -= ultimo_abatimento;
    }    
    printf("%d\n", quadrados_necessarios);

    return 0;
}
