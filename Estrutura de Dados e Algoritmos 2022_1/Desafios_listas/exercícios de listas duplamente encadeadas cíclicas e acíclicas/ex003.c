/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função que receba uma lista duplamente encadeada não circular e inverta a ordem de seus elementos, SEM ALOCAR NOVOS ELEMENTOS, NEM LIBERAR MEMÓRIA DOS EXISTENTES.

    Minha abordagem para esse exercício foi apenas inverter os ponteiros próximo e anterior de todos os elementos na Lista, percorrendo-a com um auxiliar.
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

    // se o indice estiver no escopo da estrutura
    if(indice <= lista -> tamanho && indice >= 0){

        lista -> tamanho++;
        ElementoDuplo * novo = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
        novo -> valor = valor;

        // inserindo na 0 de uma não circular -------------------------------------
        if(lista -> circularidade == 0 && indice == 0){

            novo -> anterior = NULL;
            novo -> proximo = lista -> referencia;
            lista -> referencia = novo;
            if(lista -> referencia -> proximo != NULL){
                lista -> referencia -> proximo -> anterior = lista -> referencia;
            }
        }

        // inserindo na 0 de uma circular -----------------------------------------
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

        // inserindo numa posição arbitrária --------------------------------------
        else if(indice != 0){

            // usamos o próprio anterior de novo como ponteiro auxiliar
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
    // retorna fracasso para índice inválido
    else{
        resultado = 0;
    }

    return resultado;
}

// ---------------------------------------------------------------------------------

int pop_dupla(ListaDupla * lista, int indice){
    
    int resultado;

    // se o indice estiver dentro do escopo da estrutura.
    if(indice < lista -> tamanho && indice >= 0 && lista -> tamanho > 0){

        lista -> tamanho--;

        // retirar o único elemento da lista, não importa a circularidade.
        if(lista -> tamanho == 0 && indice == 0){

            resultado = lista -> referencia -> valor;
            free(lista -> referencia);
            lista -> referencia = NULL;
        }

        // retirar um elemento arbitrário, independe da circularidade
        else{

            // quero estacionar o ponteiro auxiliar no exato elemento que se quer retirar.
            ElementoDuplo * auxiliar_deletar = lista -> referencia;
            for(int i = 0; i < indice; i++){
                auxiliar_deletar = auxiliar_deletar -> proximo;
            }
            resultado = auxiliar_deletar -> valor;

            // se estou deletando o valor de índice zero preciso atualizar a referência da lista.
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

void inverte_lista(ListaDupla * lista){

    ElementoDuplo * percorredor = lista -> referencia;
    ElementoDuplo * backup = NULL;
    for(int i = 0; i < lista -> tamanho; i++){

        backup = percorredor -> anterior;
        percorredor -> anterior = percorredor -> proximo;
        percorredor -> proximo = backup;
        // o percorredor tem que ir para o anterior, já que o atual anterior era o antigo próximo, exceto para o último elemento porque ainda precisamos atualizar a referência da lista ao fim do processo.
        if(percorredor -> anterior != NULL)
            percorredor = percorredor -> anterior;
    }
    lista -> referencia = percorredor;
}

// ---------------------------------------------------------------------------------

int main(void){

    ListaDupla * lista = inicia_lista_dupla(0);
    push_duplo(lista, 0, 1);
    push_duplo(lista, 1, 7);
    push_duplo(lista, 2, 5);
    push_duplo(lista, 3, 26);
    push_duplo(lista, 4, -15);
    push_duplo(lista, 5, 14);

    inverte_lista(lista);

    return 0;
}