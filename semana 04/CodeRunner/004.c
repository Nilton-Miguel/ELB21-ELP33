# include <stdio.h>
# include <stdlib.h>

int main(){

    int maior;
    int entrada_do_usuario;
    
    // primeiro scan eu já jogo pra "maior", melhor que iniciar 
    // manualmente "maior" como um valor qualquer e dar problema depois

    scanf("%d", &entrada_do_usuario);
    maior = entrada_do_usuario;

    do{

        scanf("%d", &entrada_do_usuario);
        if (entrada_do_usuario > maior && entrada_do_usuario != 0){

            maior = entrada_do_usuario;
        }  
    }
    while(entrada_do_usuario != 0);

    if (maior != 0)
        printf("Maior = %d\n", maior);

    return 0;
}
