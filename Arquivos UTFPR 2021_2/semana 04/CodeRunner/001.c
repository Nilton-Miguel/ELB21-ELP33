# include <stdio.h>
# include <stdlib.h>

int main(){

    char entrada_do_usuario;
    int contador_de_as = 0;

    do{

       scanf("%c", &entrada_do_usuario);
       if(entrada_do_usuario == 'a' || entrada_do_usuario == 'A'){

           contador_de_as++;
       }
    }while( entrada_do_usuario != ' ' );

    printf("%d\n", contador_de_as);
    return 0;
}
