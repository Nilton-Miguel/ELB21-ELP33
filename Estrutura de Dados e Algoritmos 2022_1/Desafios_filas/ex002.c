# include <stdio.h>
# include <stdlib.h>

// implementação de fila =======================================

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

// implementação de pilha ======================================

typedef struct elemento_pilha{

    int valor;
    struct elemento_pilha * proximo;
}Elemento_pilha;

typedef struct pilha{

    Elemento_pilha * topo;
}Pilha;

Pilha * inicia_pilha(){

    Pilha * nova_pilha = (Pilha*)malloc(sizeof(Pilha));
    nova_pilha -> topo = NULL;
    return nova_pilha;
}

void insere_pilha(Pilha * pilha, int valor){

    Elemento_pilha * novo = (Elemento_pilha*)malloc(sizeof(Elemento_pilha));
    novo -> valor = valor;
    novo -> proximo = pilha -> topo;
    pilha -> topo = novo;
}

int retira_pilha(Pilha * pilha){

    int valor = 0;
    if (pilha -> topo != NULL){
        valor = pilha -> topo -> valor;
        Elemento_pilha * antigo_topo = pilha -> topo;
        pilha -> topo = pilha -> topo -> proximo;
        free(antigo_topo);
    }
    return valor;
}

int main(void){

    /* fila original: 
    10 é o primeiro a entrar e o primeiro a sair
    40 é o último a entrar e o último a sair
    */

    Fila * fila = inicia_fila();
    insere_fila(fila, 10);
    insere_fila(fila, 20);
    insere_fila(fila, 30);
    insere_fila(fila, 40);

    /* usar uma pilha para inverter:
    10 é o primeiro a entrar e o último a sair
    40 é o último a entrar e o primeiro a sair
    */

    Pilha * pilha = inicia_pilha();
    insere_pilha(pilha, retira_fila(fila));
    insere_pilha(pilha, retira_fila(fila));
    insere_pilha(pilha, retira_fila(fila));
    insere_pilha(pilha, retira_fila(fila));

    /* devolve pra fila:
    10 é o último a entrar e o último a sair
    40 é o primeiro a entrar e o primeiro a sair
    */

    insere_fila(fila, retira_pilha(pilha));
    insere_fila(fila, retira_pilha(pilha));
    insere_fila(fila, retira_pilha(pilha));
    insere_fila(fila, retira_pilha(pilha));

    // a fila está invertida. Para filas maiores usar laços de repetição.

    return 0;
}
