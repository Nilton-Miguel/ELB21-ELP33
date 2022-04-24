/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função que recebe uma lista duplamente encadeada contendo números float, e que retorne uma segunda lista duplamente encadeada contendo a diferença entre os números da primeira lista. Por exemplo, ao receber uma lista contendo {8; 5; 7; 3; 2; 10; 5}, a lista retornada conteria {-3; 2; -4; 1; 8; -5}. Não é permitido utilizar nenhuma função das listas, apenas manipulá-las diretamente pelos ponteiros dos elementos.

    Para este exercício uso funções prontas de lista apenas para preparar minhas listas de teste, a função requerida em si faço tudo no próprio corpo da função.
*/

# include <stdio.h>
# include <stdlib.h>

// ---------------------------------------------------------------------------------

// Minhas listas duplas têm uma propriedade circularidade que permite que as funções para listas funcionem indiscretamente com qualquer lista, se adequando à sua circularidade.

typedef struct elemento_duplo{

    float valor;
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

int push_duplo(ListaDupla * lista, int indice, float valor){
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

ListaDupla * dif(ListaDupla * original){

    ListaDupla * resultados = (ListaDupla*)malloc(sizeof(ListaDupla));
    resultados -> tamanho = 0;
    resultados -> referencia = 0;
    float dif;

    // estaciono um auxiliar no último elemento da original, fazendo de trás pra frente economizo código na inserção
    ElementoDuplo * auxiliar = original -> referencia;
    while(auxiliar -> proximo != NULL){
        auxiliar = auxiliar -> proximo;
    }
    // para cada elemento da original (verificando de trás pra frente)
    while(auxiliar -> anterior != NULL){
        
        // tiro a diferença entre auxiliar e seu anterior e insiro no índice 0 da lista de saída.
        dif = auxiliar -> valor - auxiliar -> anterior -> valor;
        ElementoDuplo * novo = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
        novo -> valor = dif;
        novo -> anterior = NULL;
        novo -> proximo = resultados -> referencia;
        if(novo -> proximo != NULL)
            novo -> proximo -> anterior = novo;
        resultados -> referencia = novo;
        resultados -> tamanho++;

        auxiliar = auxiliar -> anterior;
    }

    return resultados;
}

// ---------------------------------------------------------------------------------

int main(void){

    // uso as funções prontas apenas para preparar minhas listas teste
    ListaDupla * original = inicia_lista_dupla(0);
    push_duplo(original, 0, 5.5);
    push_duplo(original, 1, 2);
    push_duplo(original, 2, 7);
    push_duplo(original, 3, 6.25);
    push_duplo(original, 4, 6.25);
    push_duplo(original, 5, -9);
    push_duplo(original, 6, 0);
    // original = {5.5, 2, 7, 6.25, 6.25, -9, 0}

    ListaDupla * resultados = dif(original);
    // resultados = {-3.5, 5, -0.75, 0, -15.25, 9}

    return 0;
}