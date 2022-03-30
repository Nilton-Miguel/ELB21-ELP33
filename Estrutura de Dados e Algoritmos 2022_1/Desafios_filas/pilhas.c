/* Nilton Miguel Guimarães de Souza - UTFPR - 2022

implementação de uma pilha de elementos encadeados.

*/

# include <stdio.h>
# include <stdlib.h>

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

// retorna 0 se a pilha já estava vazia
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

    Pilha * pilha1 = inicia_pilha();
    insere_pilha(pilha1, 5);
    insere_pilha(pilha1, 6);
    insere_pilha(pilha1, 7);
    retira_pilha(pilha1);
    retira_pilha(pilha1);
    retira_pilha(pilha1);
    retira_pilha(pilha1);

    return 0;
}
