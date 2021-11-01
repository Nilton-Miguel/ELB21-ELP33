# include <stdio.h>
# include <stdlib.h>

int main(){

    int vet[10] = {};

    int entrada_usuario;

    while (1){
        scanf("%d", &entrada_usuario);
        if (entrada_usuario < 10 && entrada_usuario >= 0){
            printf("%d\n", vet[entrada_usuario]);
        }
        else{
            break;
        }
    }

    return 0;
}
