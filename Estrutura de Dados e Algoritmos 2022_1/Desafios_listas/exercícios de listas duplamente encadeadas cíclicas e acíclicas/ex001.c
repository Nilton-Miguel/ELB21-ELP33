/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função que recebe uma lista duplamente encadeada não circular e a transforme em lista duplamente encadeada circular, SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.

    Minhas listas duplamente encadeadas já têm uma propriedade chamada circularidade que permite que as funções funcionem para qualquer lista. Minha abordagem para este exercício foi apenas mudar o valor dessa propriedade, percorrer a função com um ponteiro auxiliar até chegar no último elemento e conectá-los com os ponteiros próximo e anterior.
*/

# include <stdio.h>
# include <stdlib.h>

// ---------------------------------------------------------------------------------

// Minhas listas duplas têm uma propriedade circularidade que permite que as funções para listas funcionem indiscretamente com qualquer lista, se adequando à sua circularidade.

typedef struct elemento_duplo{

    int valor;
    struct elemento_duplo * proximo;
    struct elemento_duplo * anterior;    
}ElementoDuplo;

typedef struct lista_dupla{

    struct elemento_duplo * referencia;
    int circularidade;
    int tamanho;
}ListaDupla;

// ---------------------------------------------------------------------------------

// Circularidade 0 ou 1 cria listas duplamente encadeadas abertas ou cíclicas respectivamente, em caso de ser um valor de circularidade inválido, o ponteiro é retornado vazio.

ListaDupla * inicia_lista_dupla(int circularidade){

    ListaDupla * nova_lista = (ListaDupla*)malloc(sizeof(ListaDupla));
    nova_lista -> referencia = NULL;
    if (circularidade == 0 || circularidade == 1)
        nova_lista -> circularidade = circularidade;
    else
        nova_lista = NULL;
    return nova_lista;
}

// ---------------------------------------------------------------------------------

int push_duplo(ListaDupla * lista, int indice, int valor){
    int resultado = 1;
    
    if(indice <= lista -> tamanho && indice >= 0){

        lista -> tamanho++;
        ElementoDuplo * novo = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
        novo -> valor = valor;

        if(lista -> circularidade == 0 && indice == 0){

            novo -> anterior = NULL;
            novo -> proximo = lista -> referencia;
            lista -> referencia = novo;
            if(lista -> referencia -> proximo != NULL){
                lista -> referencia -> proximo -> anterior = lista -> referencia;
            }
        }

        else if(lista -> circularidade == 1 && indice == 0){

            if(lista -> referencia == NULL){

                novo -> proximo = novo;
                novo -> anterior = novo;
                lista -> referencia = novo;
            }
            else{

                novo -> proximo = lista -> referencia;
                novo -> anterior = lista -> referencia -> anterior;
                novo -> anterior -> proximo = novo;
                novo -> proximo -> anterior = novo;
                lista -> referencia = novo;
            }
        }

        else if(indice != 0){

            novo -> anterior = lista -> referencia;
            for(int i = 0; i < indice - 1; i++){
                novo -> anterior = novo -> anterior -> proximo;
            }
            novo -> proximo = novo -> anterior -> proximo;
            novo -> anterior -> proximo = novo;
            if(novo -> proximo != NULL)
                novo -> proximo -> anterior = novo;
        }
    }
    else{
        resultado = 0;
    }

    return resultado;
}

// ---------------------------------------------------------------------------------

int pop_dupla(ListaDupla * lista, int indice){
    
    int resultado;

    if(indice < lista -> tamanho && indice >= 0 && lista -> tamanho > 0){

        lista -> tamanho--;

        if(lista -> tamanho == 0 && indice == 0){

            resultado = lista -> referencia -> valor;
            free(lista -> referencia);
            lista -> referencia = NULL;
        }

        else{

            ElementoDuplo * auxiliar_deletar = lista -> referencia;
            for(int i = 0; i < indice; i++){
                auxiliar_deletar = auxiliar_deletar -> proximo;
            }
            resultado = auxiliar_deletar -> valor;

            if(indice == 0){
                lista -> referencia = auxiliar_deletar -> proximo;
            }

            if(auxiliar_deletar -> anterior != NULL){
                auxiliar_deletar -> anterior -> proximo = auxiliar_deletar -> proximo;
            }
            if(auxiliar_deletar -> proximo != NULL){
                auxiliar_deletar -> proximo -> anterior = auxiliar_deletar -> anterior;
            }
            free(auxiliar_deletar);
        }
    }
    else{
        resultado = 0;
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

// Função que torna uma lista duplamente encadeada aberta em circular.

void torna_circular(ListaDupla * original){

    if(original -> circularidade == 0){

        original -> circularidade = 1;

        // estaciona um auxiliar no último elemento e configura os ponteiros para tornar circular.
        ElementoDuplo * auxiliar = original -> referencia;
        while(auxiliar -> proximo != NULL){
            auxiliar = auxiliar -> proximo;
        }
        auxiliar -> proximo = original -> referencia;
        original -> referencia -> anterior = auxiliar;
    }
}

// ---------------------------------------------------------------------------------

int main(void){

    ListaDupla * lista = inicia_lista_dupla(0);
    push_duplo(lista, 0, 3);
    push_duplo(lista, 0, 2);
    push_duplo(lista, 0, 1);
    torna_circular(lista);

    return 0;
}
