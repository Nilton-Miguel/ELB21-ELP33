# include <stdio.h>
# include <stdlib.h>

int main(){
    char frase[150];
    char caracter;
    int repeticoes = 0;
    int cont;

    fgets(frase, 150, stdin);
    scanf("%c", &caracter);

    for(cont=0; cont<150; cont++){
        // prevenir leitura de lixo
        if (frase[cont]=='\n')
            break;
        // se o caracter for minúsculo, ele vai checar se
        // a letra é igual a ele, ou, ao maiúsculo (mais atrás na ascii)
        if (caracter >= 'a' && caracter <= 'z'){
            if(frase[cont] == caracter || frase[cont] == caracter - ('a' - 'A')){
                repeticoes++;
            }
        }
        // se o caracter for maiúsculo, ele vai checar se
        // a letra é igual a ele, ou, ao minúsculo (mais à frente na ascii)
        else if(caracter >= 'A' && caracter <= 'Z'){
            if(frase[cont] == caracter || frase[cont] == caracter + ('a' - 'A')){
                repeticoes++;
            }
        }
    }
    printf("O caractere '%c' aparece %d vezes.\n", caracter, repeticoes);
    return 0;
}