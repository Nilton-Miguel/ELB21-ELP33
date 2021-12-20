# include <stdio.h>
# include <stdlib.h>

int main(){

    int entrada_do_usuario;

    do{

        scanf("%d", &entrada_do_usuario);
    }
    while(entrada_do_usuario % 2 == 1 || entrada_do_usuario > 100 || entrada_do_usuario < 10);

    printf("%d\n", entrada_do_usuario);
    return 0;
}
