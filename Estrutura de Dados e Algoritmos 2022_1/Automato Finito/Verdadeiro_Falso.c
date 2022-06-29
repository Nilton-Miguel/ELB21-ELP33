# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define NONE -1
# define ID_SIZE 2

/* Estruturas ------------------------------------------------------------------------*/

// 0.0. nó da lista de caracteres
typedef struct node_alfabeto{

    char valor;

    struct node_alfabeto * proximo;
}node_alfabeto;

// 0.1. nó da lista de estados
typedef struct node_estados{

    char id[ID_SIZE];
    int indice;
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
int insere_estado(machine * machine, int aceita, char id[ID_SIZE], int indice){

    int resultado = 1;

    if(aceita == 0 || aceita == 1){

        machine -> estados -> tamanho++;

        node_estados * novo = (node_estados*)malloc(sizeof(node_estados));
        strcpy(novo -> id, id);
        novo -> aceita = aceita;
        novo -> proximo = NULL;
        novo -> adjacente = NULL;
        novo -> indice_alfabeto = NONE;
        novo -> indice = indice;

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
        node_estados * auxiliar_horizontal = auxiliar_vertical;

        auxiliar_vertical = machine -> estados -> inicio;
        indice_auxiliar_vertical = 0;

        while(indice_auxiliar_vertical != state2){
            auxiliar_vertical = auxiliar_vertical -> proximo;
            indice_auxiliar_vertical++;
        }
        node_estados * novo = (node_estados*)malloc(sizeof(node_estados));
        novo -> aceita = auxiliar_vertical -> aceita;
        novo -> indice = auxiliar_vertical -> indice;
        novo -> proximo = NULL;
        novo -> adjacente = NULL;
        novo -> indice_alfabeto = caractere;
        strcpy(novo -> id, auxiliar_vertical -> id);

        if(auxiliar_horizontal -> adjacente == NULL){
            auxiliar_horizontal -> adjacente = novo;
        }
        else{
            while(auxiliar_horizontal -> adjacente != NULL && auxiliar_horizontal -> adjacente -> indice_alfabeto < caractere){
                auxiliar_horizontal = auxiliar_horizontal -> adjacente;
            }
            if(auxiliar_horizontal -> adjacente != NULL && auxiliar_horizontal -> adjacente -> indice_alfabeto == caractere){
                novo -> adjacente = auxiliar_horizontal -> adjacente -> adjacente;
                auxiliar_horizontal -> adjacente = novo;
            }
            else{
                novo -> adjacente = auxiliar_horizontal -> adjacente;
                auxiliar_horizontal -> adjacente = novo;
            }
        }
    }
    return resultado;
}
// 1.6. processamento de uma cadeia de texto
int processa(machine * mach, char * texto, int indice, node_estados * estado_atual){

    int resultado = 1;

    // quando chegar no caractere \0, não há mais texto para processar
    if(texto[indice] != '\0'){
        
        // 1 converte o caractere do texto para um índice do alfabeto da máquina
        int indice_solicitado = 0;
        node_alfabeto * tradutor = mach -> alfabeto -> inicio;
        while(tradutor != NULL && tradutor -> valor != texto[indice]){

            tradutor = tradutor -> proximo;
            indice_solicitado++;
        }
        // se o caractere no texto não faz parte do alfabeto, a máquina não o conhece
        if(tradutor == NULL){
            // recursivamente retorna 0
            resultado = 0;
        }
        // 1 -------------------------------------------------------------------

        //  Se eu sair do estado_atual em qual outro estado eu chego com esse caractere ?
        while(estado_atual != NULL && estado_atual -> indice_alfabeto != indice_solicitado){
            estado_atual = estado_atual -> adjacente;
        }
        // não achou nenhum estado com esse caractere como transição, máquina caiu no estado morto
        if(estado_atual == NULL){
            // recursivamente devolve 0
            resultado = 0;
        }
        //  se achou o estado, anota o índice dele e posiciona o ponteiro nessa linha para a próxima call recursiva
        else{
            int indice_proximo = estado_atual -> indice;
            estado_atual = mach -> estados -> inicio;
            while(estado_atual != NULL && estado_atual -> indice != indice_proximo){
                estado_atual = estado_atual -> proximo;
            }
            // fez a transição, agora o resultado depende da próxima
            resultado = processa(mach, texto, indice+1, estado_atual);
        }
    }
    // se o caractere no texto for um \0, vamos testar qual a aceitação do estado em que o ponteiro está atualmente estacionado, se não for de aceitação, a máquina não aceita.
    else if(estado_atual -> aceita == 0){
        resultado = 0;
    }
    return resultado;
}
// -----------------------------------------------------------------------------------

int main(void){

    /*  Uma máquina que só aceita cadeias de texto em que o
        número seja formado do alfabeto "0 1 2" e seja par */

    machine * mach1 = novo_automato();

    // alfabeto de mach1 ( Algarismos aceitos )
    insere_caractere(mach1, 'V');
    insere_caractere(mach1, 'F');

    // coleção de estados de mach1
    insere_estado(mach1, 0, "in", 0);
    insere_estado(mach1, 0, "1_", 1);
    insere_estado(mach1, 0, "2_", 2);
    insere_estado(mach1, 0, "3_", 3);
    insere_estado(mach1, 1, "sc", 4);

    // 0010 = VVFV que é o gabarito da questão
    link(mach1, 0, 0, 1);
    link(mach1, 1, 0, 2);
    link(mach1, 2, 1, 3);
    link(mach1, 3, 0, 4);

    node_estados * inicial = mach1 -> estados -> inicio;
    
    int n0 = processa(mach1, "\0", 0, inicial);

    int n1 = processa(mach1, "VVVV\0", 0, inicial);
    int n2 = processa(mach1, "FFFF\0", 0, inicial);
    int n3 = processa(mach1, "VFVF\0", 0, inicial);
    int n4 = processa(mach1, "VVFV\0", 0, inicial);

    return 0;
}
