# include <stdio.h>

int main(){

    int numero;

    while (1){

        printf("\nDigite um número inteiro: ");

        //na scanf eu preciso indicar: tipo e onde guardar o valor de input do terminal
        scanf( "%d", &numero );

        printf( "O número digitado foi: %d\n", numero );

    }

}

