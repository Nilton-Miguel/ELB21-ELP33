# include <stdio.h>

int main(){

    char caractere;

    scanf("%c", &caractere);

    /*
        se eu pegar uma variável que armazena um carctere e imprimir seu conteúdo como se fosse um inteiro
        na verdade ela revela conter um número inteiro. O código ASCII daquele caractere. Bem mais
        fácil achar os caracteres aqui
    */

    printf("%d", caractere);

    return 0;
}
