# include <stdio.h>
# include <stdlib.h>

int main(){

    char caractere;
    int iteracoes;
    int v_contador;

    scanf("%c %d", &caractere, &iteracoes);

    for (v_contador = 0; v_contador < iteracoes; v_contador++){

        printf("%c ", caractere);
    }
    printf("\n");
    return 0;
}
