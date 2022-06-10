# include <stdio.h>
# include <stdlib.h>

// Estruturas ------------------------------------------------------------------------

// nó da lista de caracteres
typedef struct node_alfabeto{

    char valor;
    struct node_alfabeto * proximo;
}node_alfabeto;

// nó da lista de estados
typedef struct node_estados{

    int aceita;
    int indice_alfabeto;
    struct node_estados * proximo;
}node_estados;

// lista de caracteres
typedef struct alfabeto{

    int tamanho;
    node_alfabeto * inicio;
}alfabeto;

// lista de estados
typedef struct estados{

    int tamanho;
    node_estados * inicio;
}estados;

// automato finito
typedef struct machine{

    alfabeto * alfabeto;
    estados * estados;
}machine;

// Funções ---------------------------------------------------------------------------

// criação de um novo alfabeto
alfabeto * novo_alfabeto(){

    alfabeto * novo = (alfabeto*)malloc(sizeof(alfabeto));
    novo -> inicio = NULL;
    novo -> tamanho = 0;
    return novo;
}
// criação de uma nova lista de estados
estados * novos_estados(){

    estados * novo = (estados*)malloc(sizeof(estados));
    novo -> inicio = NULL;
    novo -> tamanho = 0;
    return novo;
}
// criação de um novo autômato
machine * novo_automato(alfabeto * alfabeto, estados * estados){

    machine * novo = (machine*)malloc(sizeof(machine));
    novo -> alfabeto = alfabeto;
    novo -> estados = estados;
}
// -----------------------------------------------------------------------------------

int main(void){

    alfabeto * alfa1 = novo_alfabeto();
    estados * est1 = novos_estados();
    machine * mach1 = novo_automato(alfa1, est1);

    return 0;
}
