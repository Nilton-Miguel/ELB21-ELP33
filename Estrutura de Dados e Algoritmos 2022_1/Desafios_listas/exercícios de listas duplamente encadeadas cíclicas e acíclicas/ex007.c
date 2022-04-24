/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função para verificar a integridade de uma lista duplamente encadeada circular.

    Minha abordagem para este exercício foi usar um laço for com número de ciclos igual ao tamanho da lista circular e para um dos elementos checar se os ponteiros dos vizinhos estão de acordo:

        Para todo elemento (x) da lista, o anterior do próximo elemento deve ser (x) e o próximo do elemento anterior deve ser também (x). Se em algum lugar da lista um desses testes falhar, a função está quebrada e, portanto, comprometida. 
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

int avalia_integridade(ListaDupla * lista_dupla){

    int resultado = 1;

    ElementoDuplo * auxiliar = lista_dupla -> referencia;
    if(lista_dupla -> circularidade == 1){
        for(int i = 0; i < lista_dupla -> tamanho; i++){
            if(auxiliar -> proximo -> anterior != auxiliar || auxiliar -> anterior -> proximo != auxiliar){
                resultado = 0;
                break;
            }
            auxiliar = auxiliar -> proximo;
        }
    }
    else{
        resultado = 0;
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

int main(void){

    // crio, primeiro, uma lista íntegra
    ListaDupla * lista = inicia_lista_dupla(1);
    push_duplo(lista, 0, 0);
    push_duplo(lista, 1, 1);
    push_duplo(lista, 2, 2);

    // avaliação positiva
    avalia_integridade(lista);

    ElementoDuplo * desvio = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
    ElementoDuplo * auxiliar = lista -> referencia;
    for(int i = 0; i < 2; i++){
        auxiliar = auxiliar -> proximo;
    }
    // desvio um dos ponteiros para algum endereço fora da lista
    auxiliar -> proximo = desvio;

    // agora tenho fracasso na avaliação pois a integridade foi comprometida
    avalia_integridade(lista);

    return 0;
}
