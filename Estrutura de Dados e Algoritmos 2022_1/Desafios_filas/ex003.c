/* Nilton Miguel Guimarães de Souza - UTFPR - 2022

Neste exercício transformo um número de casas flutuantes lidos em uma sequência de caracteres, depois coloco o equivalente numérico de cada caractere num dos elementos de uma fila. Os primeiros números a saírem da fila são os algarismos mais significativos e vice versa. Os valores variam de acorco com a precisão do número solicitado.
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct elemento_fila{

    int valor;
    struct elemento_fila * calouro;
}Elemento_fila;

typedef struct fila{

    Elemento_fila * entrada;
    Elemento_fila * saida;
}Fila;

Fila * inicia_fila(){

    Fila * nova_fila = (Fila*)malloc(sizeof(Fila));
    nova_fila -> entrada = nova_fila -> saida = NULL;
    return nova_fila;
}

void insere_fila(Fila * fila, int valor){

    Elemento_fila * novo = (Elemento_fila*)malloc(sizeof(Elemento_fila));
    novo -> valor = valor;
    novo -> calouro = NULL;

    if (fila -> entrada == NULL){
        fila -> entrada = fila -> saida = novo;
    }
    else{
        fila -> entrada -> calouro = novo;
        fila -> entrada = novo;
    }
}

// retorna 0 se eu tento esvaziar uma fila já vazia
int retira_fila(Fila * fila){

    int valor = 0;

    if (fila -> entrada != NULL){

        valor = fila -> saida -> valor;
        Elemento_fila * antiga_saida = fila -> saida;

        if (fila -> saida -> calouro == NULL){
            fila -> saida = fila -> entrada = NULL;
        }
        else{
            fila -> saida = fila -> saida -> calouro;
        }
        free(antiga_saida);
    }

    return valor;
}

Fila * desmonta_decimais(float numero){

    Fila * fila = inicia_fila();
    char texto[12] = {0};
    sprintf(texto, "%f", numero);
    // <= 11 porque são 12 caracteres que vou verificar.
    for (int contador = 0; contador <= 11; contador++){

        // não contamos o ponto como algarismo.
        if(texto[contador] != '.'){
            insere_fila(fila, texto[contador] - '0');
        }
    }

    return fila;
}

int main(void){

    Fila * resultado = desmonta_decimais(10.9854);

    // laço para mostrar os valores da fila.
    int valor;
    // <= 10 porque na passagem para pilha saiu o ponto, há um caractere a menos.
    for (int contador = 0; contador <= 10; contador++){

        valor = retira_fila(resultado);
        // prevenir mostragem de lixo.
        if(valor <= 9 && valor >= 0){
            printf("%d   ", valor);
        }
    }

    return 0;
}
