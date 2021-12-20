# include <stdio.h>
# include <stdlib.h>

int main(){

    int numero_de_parada;
    int variavel_contagem;
    int somatorio = 0;
    scanf("%d", &numero_de_parada);
    for ( variavel_contagem = 1; variavel_contagem <= numero_de_parada; variavel_contagem++){

        somatorio += variavel_contagem;
    }

    printf("%d\n", somatorio);
    return 0;
}
