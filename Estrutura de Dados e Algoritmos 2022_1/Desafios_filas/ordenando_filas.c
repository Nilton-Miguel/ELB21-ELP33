/* Nilton Miguel Guimarães de Souza - UTFPR - 2022

    Neste arquivo busco implementar uma função que ordene de forma não destrutiva uma fila, ou seja, o usuário manterá sua fila original não ordenada enquanto recebe da função um ponteiro para uma nova fila ordenada de forma crescente.

    Para este fim implementei minha função fazendo uso de duas filas e duas pilhas. As duas filas foram nescessárias para que não se sobrescrevesse a fila original do usuário, e as duas pilhas foram usadas no processo de comparação dos valores para construção da ordem.
*/

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

// Aqui está declarada minha função de ordenamento.

Fila * ordem_crescente(Fila * fila_original){

    /* inicializo a fila de saída, a fila cópia, minha pilha principal e buffer.
    
        "fila" vai receber uma cópia de fila_original e ao final da função vai receber os elementos ordenados, portanto, também a fila de retorno.

        "buffer_copia" é uma fila que vamos usar para poder recuperar os valores da fila_original e deixá-la intacta para o usuário.

        "pilha" é nossa pilha principal, onde vamos empilhando os valores em ordem crescente do topo até o fundo.

        "buffer" é a pilha auxiliar que vamos usar para "colocar de lado" elementos menores enquanto procuramos por elementos maiores para manter nossa pilha principal em ordem crescente.
    */
    Fila * fila = inicia_fila();
    Fila * buffer_copia = inicia_fila();

    Pilha * pilha = inicia_pilha();
    Pilha * buffer = inicia_pilha();

    int valor;
    // para todo valor na fila original, jogamos uma cópia no buffer de cópia  e outrana fila que vamos ordenar.
    while(fila_original -> entrada != NULL){
        valor = retira_fila(fila_original);
        insere_fila(buffer_copia, valor);
        insere_fila(fila, valor);
    }
    // agora devolvemos os valores do buffer de cópia à fila original.
    while(buffer_copia -> entrada != NULL){
        insere_fila(fila_original, retira_fila(buffer_copia));
    }
    // terminando esse processo temos o buffer de cópia vazio, enquanto que "fila" é uma cópia perfeita de "fila_original", assim o usuário mantém sua fila original não ordenada e podemos ordenar uma cópia, dando o caráter não destrutivo à função.
    while(fila -> entrada != NULL){

        // lê o valor de saída da fila
        int valor_lido = retira_fila(fila);

        // se o valor da fila for o primeiro na pilha, ou menor que o valor do topo, insere.
        if(pilha -> topo == NULL || valor_lido <= pilha -> topo -> valor){
            insere_pilha(pilha, valor_lido);
        }
        // se não for, tira os elementos da pilha (para um buffer) até achar um maior ou igual, insere e devolva os elementos pra pilha.
        else{
            while(pilha -> topo != NULL && valor_lido > pilha -> topo -> valor){
                insere_pilha(buffer, retira_pilha(pilha));
            }
            insere_pilha(pilha, valor_lido);
            while(buffer -> topo != NULL){
                insere_pilha(pilha, retira_pilha(buffer));
            }
        }
    }

    // temos uma pilha organizada em ordem crescente do topo para o fundo, logo passamos para uma fila que está ordenada crescente da entrada à saída.
    while (pilha -> topo != NULL ){
        insere_fila(fila, retira_pilha(pilha));
    }

    return fila;
}

int main(void){

    // crio uma fila e povoo ela com valores arbitrários armazenados em um vetor.
    Fila * fila = inicia_fila();
    //int val[20] = {99, 25, 1, 3, 2, 8, 8, 7, 8, 13, 89, 87, 88, 73, 63, 1, 2, 3, 19, 5};
    int val[5] = {99, 25, 1, 3, 2};
    for(int contador = 0; contador < 5; contador++){
        insere_fila(fila, val[contador]);
    }
    // crio uma nova fila que receba o retorno de minha função de ordenação crescente.
    Fila * sorted = ordem_crescente(fila);

    return 0;
}
