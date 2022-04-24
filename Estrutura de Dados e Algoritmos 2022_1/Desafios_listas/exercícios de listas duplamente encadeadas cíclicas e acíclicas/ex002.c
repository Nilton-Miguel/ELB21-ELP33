/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função que recebe duas listas duplamente encadeadas, lista1 e lista2. Esta função deve retornar uma terceira lista, lista3. Esta lista deve conter, para cada elemento de lista2, o número de vezes que este elemento ocorre em lista1. Por exemplo, considerando lista1={9,4,6,2,2,3,1,5,5,0,7} e lista2={3,2,8,5,0}, a lista retornada pela função deve ter os números {1,2,0,2,1}. NÃO É PERMITIDO UTILIZAR NENHUMA FUNÇÃO PRONTA DA LISTA. É permitido implementar suas próprias funções, ou resolver tudo no corpo da função pedida.

    Para este exercício uso funções prontas de lista apenas para preparar minhas listas de teste, a função requerida em si faço tudo no próprio corpo da função.
    
    ùnica coisa a se destacar é que eu percorro o pool de trás pra frente pois assim eu só preciso inserir elementos pelo índice 0 da lista contagem (que será a saída), assim só preciso recriar metade do código de inserção.
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

ListaDupla * contagem(ListaDupla * principal, ListaDupla * pool){

    ListaDupla * contagem = (ListaDupla*)malloc(sizeof(ListaDupla));
    contagem -> tamanho = 0;
    contagem -> referencia = NULL;

    ElementoDuplo * auxiliar_pool = pool -> referencia;
    ElementoDuplo * auxiliar_principal = principal -> referencia;
    int contador;

    // estaciono o auxiliar pool no final, e venho verificando de trás pra frente, assim eu só preciso inserir elementos no índice 0 da lista contagem e diminuo a quantidade de código para escrever do 0.
    while(auxiliar_pool -> proximo != NULL){
        auxiliar_pool = auxiliar_pool -> proximo;
    }

    // para cada elemento de pool:
    while(auxiliar_pool != NULL){

        // zere o contador e o auxiliar principal
        contador = 0;
        auxiliar_principal = principal -> referencia;

        // percorra a principal
        while (auxiliar_principal != NULL){

            // todo elemento de principal que for igual ao de pool incrementa o contador.
            if(auxiliar_principal -> valor == auxiliar_pool -> valor){
                contador++;
            }
            auxiliar_principal = auxiliar_principal -> proximo;
        }
        // percorrida a principal e salvo o número de ocorrências em contador, vamos colocá-la como valor de um elemento da lista contagem.
        ElementoDuplo * novo = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
        novo -> valor = contador;
        novo -> anterior = NULL;
        novo -> proximo = contagem -> referencia;
        if(novo -> proximo != NULL)
            novo -> proximo -> anterior = novo;
        contagem -> referencia = novo;
        contagem -> tamanho++;

        auxiliar_pool = auxiliar_pool -> anterior;
    }
    return contagem;
}

// ---------------------------------------------------------------------------------

int main(void){

    // uso funções prontas apenas para preparar listas de teste

    ListaDupla * lista_principal = inicia_lista_dupla(0);
    push_duplo(lista_principal, 0, 2);
    push_duplo(lista_principal, 0, 1);
    push_duplo(lista_principal, 0, 2);
    push_duplo(lista_principal, 0, 7);
    push_duplo(lista_principal, 0, 1);
    push_duplo(lista_principal, 0, 5);
    push_duplo(lista_principal, 0, 0);
    push_duplo(lista_principal, 0, 1);
    push_duplo(lista_principal, 0, 7);
    push_duplo(lista_principal, 0, 1);
    // {1, 7, 1, 0, 5, 1, 7, 2, 1, 2}

    ListaDupla * pool = inicia_lista_dupla(0);
    push_duplo(pool, 0, 2);
    push_duplo(pool, 1, 0);
    push_duplo(pool, 2, 1);
    push_duplo(pool, 3, 7);
    push_duplo(pool, 4, 9);
    // {2, 0, 1, 7, 9}

    ListaDupla * saida = contagem(lista_principal, pool);
    // a saída para as listas acima foi {2, 1, 4, 2, 0}

    return 0;
}