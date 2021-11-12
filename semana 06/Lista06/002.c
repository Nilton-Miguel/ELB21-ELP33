#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int cont;
    int pos_na_string = 0;
    char str[50];
    fgets(str, 50, stdin);

    for (cont=0; cont<50; cont++){
        if (str[cont] >= '0' && str[cont] <= '9'){
            pos_na_string = ++cont;
            break;
        }
        /* 
        isso aqui encerra a leitura no caractere nulo para
        impedir de ler um dígito que na verdade era lixo
        */
        else if (str[cont] == '\0'){
            break;
        }
    }
    printf("%d\n", pos_na_string);
    return 0; 
}