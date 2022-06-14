# include <stdio.h>
# include <stdlib.h>
# define NONE -1

/* Estruturas ------------------------------------------------------------------------*/

// 0.0. nó da lista de caracteres
typedef struct node_alfabeto{

    char valor;

    struct node_alfabeto * proximo;
}node_alfabeto;

// 0.1. nó da lista de estados
typedef struct node_estados{

    int aceita;
    int indice_alfabeto;

    struct node_estados * proximo;
    struct node_estados * adjacente;
}node_estados;

// 0.2. lista de caracteres
typedef struct alfabeto{

    int tamanho;

    node_alfabeto * inicio;
}alfabeto;

// 0.3. lista de estados
typedef struct estados{

    int tamanho;

    node_estados * inicio;
}estados;

// 0.4. automato finito
typedef struct machine{

    alfabeto * alfabeto;
    estados * estados;
}machine;

/* Funções ---------------------------------------------------------------------------*/

// 1.0. criação de um novo alfabeto
alfabeto * novo_alfabeto(){

    alfabeto * novo = (alfabeto*)malloc(sizeof(alfabeto));
    novo -> inicio = NULL;
    novo -> tamanho = 0;
    return novo;
}
// 1.1. criação de uma nova lista de estados
estados * novos_estados(){

    estados * novo = (estados*)malloc(sizeof(estados));
    novo -> inicio = NULL;
    novo -> tamanho = 0;
    return novo;
}
// 1.2. criação de um novo autômato
machine * novo_automato(){

    machine * novo = (machine*)malloc(sizeof(machine));
    novo -> alfabeto = novo_alfabeto();
    novo -> estados = novos_estados();
    return novo;
}
// 1.3. adição de um novo caractere ao alfabeto de uma máquina
int  insere_caractere(machine * machine, char novo_simbolo){

    int resultado = 1;
    
    node_alfabeto * novo_node = (node_alfabeto*)malloc(sizeof(node_alfabeto));
    novo_node -> valor = novo_simbolo;
    novo_node -> proximo = NULL;

    if(machine -> alfabeto -> inicio == NULL){
        machine -> alfabeto -> inicio = novo_node;
        machine -> alfabeto -> tamanho++;
    }
    else{
        node_alfabeto * auxiliar = machine -> alfabeto -> inicio;

        while(auxiliar -> proximo != NULL && auxiliar -> valor != novo_simbolo){
            auxiliar = auxiliar -> proximo;
        }
        if(auxiliar -> valor != novo_simbolo){
            auxiliar -> proximo = novo_node;
            machine -> alfabeto -> tamanho++;
        }
        else{
            resultado = 0;
        }
    }
    return resultado;
}
// 1.4. adição de um novo estado a uma máquina
int insere_estado(machine * machine, int aceita){

    int resultado = 1;

    if(aceita == 0 || aceita == 1){

        machine -> estados -> tamanho++;

        node_estados * novo = (node_estados*)malloc(sizeof(node_estados));
        novo -> aceita = aceita;
        novo -> proximo = NULL;
        novo -> adjacente = NULL;
        novo -> indice_alfabeto = NONE;

        if(machine -> estados -> inicio == NULL){
            machine -> estados -> inicio = novo;
        }
        else{
            node_estados * auxiliar = machine -> estados -> inicio;

            while(auxiliar -> proximo != NULL){
                auxiliar = auxiliar -> proximo;
            }
            auxiliar -> proximo = novo;
        }
    }
    else{
        resultado = 0;
    }
    return resultado;
}
// 1.5. criação dos links entre estados
int link(machine * machine, int state1, int caractere, int state2){

    int resultado = 1;

    int comp1 = (caractere < machine -> alfabeto -> tamanho);
    int comp2 = (state1 < machine -> estados -> tamanho);
    int comp3 = (state2 < machine -> estados -> tamanho);

    if(comp1 == 0 || comp2 == 0 || comp3 == 0){
        resultado = 0;
    }
    else{
        node_estados * auxiliar_vertical = machine -> estados -> inicio;
        int indice_auxiliar_vertical = 0;

        while(indice_auxiliar_vertical != state1){
            auxiliar_vertical = auxiliar_vertical -> proximo;
            indice_auxiliar_vertical++;
        }
        /*
            já tenho um ponteiro no estado inicial na lista de estados
            Só falta criar a lógica de inserir estados adjacentes a ele
            sempre em ordem crescente e verificando se não estou inserindo
            um estado adjacente com caractere repetido. Dada uma mesma 
            transição e um mesmo estado inicial, não posso ter dois estados
            resultantes diferentes.
        */
    }
    return resultado;
}
// -----------------------------------------------------------------------------------

int main(void){

    // -------------------------------------------------------
    machine * mach1 = novo_automato();

    insere_caractere(mach1, 'a');
    insere_caractere(mach1, 'b');
    insere_caractere(mach1, 'c');
    insere_caractere(mach1, 'd');

    insere_estado(mach1, 1);
    insere_estado(mach1, 1);
    insere_estado(mach1, 1);

    //int resu1 = link(mach1, 2, 0, 0);

    // -------------------------------------------------------
    machine * mach2 = novo_automato();

    insere_caractere(mach2, '8');
    insere_caractere(mach2, '9');

    insere_estado(mach2, 0);
    insere_estado(mach2, 1);
    insere_estado(mach2, 1);

    return 0;
}
