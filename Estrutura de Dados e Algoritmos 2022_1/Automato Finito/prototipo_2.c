# include <stdio.h>
# include <stdlib.h>
# define NONE -1

// Estruturas ------------------------------------------------------------------------

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

// Funções ---------------------------------------------------------------------------

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

    // se o alfabeto está vazio, apenas adicione o novo símbolo e retorne sucesso
    if(machine -> alfabeto -> inicio == NULL){

        machine -> alfabeto -> inicio = novo_node;
        machine -> alfabeto -> tamanho++;
    }
    // se já houver símbolos
    else{

        node_alfabeto * auxiliar = machine -> alfabeto -> inicio;
        // siga até achar o último nó, ou até achar um caractere repetido
        while(auxiliar -> proximo != NULL && auxiliar -> valor != novo_simbolo){

            auxiliar = auxiliar -> proximo;
        }
        // se chegou até aqui, ou é o último nó, ou é caractere repetido
        if(auxiliar -> valor != novo_simbolo){
            // se for o último nó, insere o novo como próximo deste
            auxiliar -> proximo = novo_node;
            machine -> alfabeto -> tamanho++;
        }
        // se for valor repetido, não adicione o nó e retorne fracasso
        else{

            resultado = 0;
        }
    }
    return resultado;
}
// -----------------------------------------------------------------------------------

int main(void){

    machine * mach1 = novo_automato();
    insere_caractere(mach1, 'a');
    insere_caractere(mach1, 'b');
    insere_caractere(mach1, 'c');
    insere_caractere(mach1, 'd');

    machine * mach2 = novo_automato();
    insere_caractere(mach2, '8');
    insere_caractere(mach2, '9');

    return 0;
}
