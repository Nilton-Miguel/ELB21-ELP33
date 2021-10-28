# include <stdio.h>
# include <stdlib.h>

int main(){

    int entrada_do_usuario;
    int contagem;
    scanf("%d", &entrada_do_usuario);
    for (contagem = 1; contagem <= entrada_do_usuario; contagem++){

        printf("%d\n", contagem*contagem*contagem);
    }
    return 0;
}
