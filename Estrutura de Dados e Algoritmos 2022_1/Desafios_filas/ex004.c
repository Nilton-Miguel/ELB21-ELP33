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

// minha solução é uma função que joga de uma pilha pra outra (apenas se o elemento for par), depois joga de volta pra pilha original. Nesse processo a pilha inverte duas vezes, logo, ela está na ordem original ao fim, a única diferença sendo a ausência dos ímpares.
void retira_impares(Pilha * pilha){

    Pilha * buffer = inicia_pilha();
    int valor;
    do{
        valor = retira_pilha(pilha);
        if(valor % 2 == 0){
            insere_pilha(buffer, valor);
        }
    }while(pilha -> topo != NULL);
    while(buffer -> topo != NULL){
        insere_pilha(pilha, retira_pilha(buffer));
    }
    
}

int main(void){

    Pilha * pilha1 = inicia_pilha();

    insere_pilha(pilha1, 1);
    insere_pilha(pilha1, 2);
    insere_pilha(pilha1, 3);
    insere_pilha(pilha1, 4);
    insere_pilha(pilha1, 5);
    insere_pilha(pilha1, 6);
    insere_pilha(pilha1, 7);
    insere_pilha(pilha1, 8);
    insere_pilha(pilha1, 10);
    insere_pilha(pilha1, 12);

    retira_impares(pilha1);

    return 0;
}
