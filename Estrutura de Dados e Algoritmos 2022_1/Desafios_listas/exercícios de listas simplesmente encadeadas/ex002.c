/*
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função para verificar se uma lista simplesmente encadeada de números inteiros está ordenada (em ordem crescente). Ela deve retornar 1 se esta afirmação for verdadeira e 0 se for falsa. Considere que elementos repetidos podem existir na lista, e isto não invalida a ordem. Por exemplo, uma lista {1,3,5,6,6,8,10} está ordenada.

    Minha abordagem para este exercício foi criar uma variável de referência chamada de "anterior" usá-la para comparar dois valores sucessivos numa Lista (acessados por um ponteiro auxiliar). Se em algum momento o próximo for menor que o atual, a lista não está em ordem crescente e o laço quebra com código de fracasso.
*/

# include <stdio.h>
# include <stdlib.h>

// ---------------------------------------------------------------------------------

typedef struct elemento_simples{
 
    int valor;
    struct elemento_simples * proximo;
}ElementoSimples;

typedef struct lista_simples{

    int tamanho;
    ElementoSimples * inicio;
}ListaSimples;

// ---------------------------------------------------------------------------------

ListaSimples * inicia_lista_simples(void){

    ListaSimples * nova_lista = (ListaSimples*)malloc(sizeof(ListaSimples));
    nova_lista -> inicio = NULL;
    nova_lista -> tamanho = 0;
    return nova_lista;
}

// ---------------------------------------------------------------------------------

int push_simples(ListaSimples * lista, int indice, int valor){

    int resultado = 1;

    if (indice == 0){
        ElementoSimples * novo = (ElementoSimples*)malloc(sizeof(ElementoSimples));
        novo -> proximo = lista -> inicio;
        novo -> valor = valor;
        lista -> inicio = novo;
        lista -> tamanho++;
    }
    else if (indice <= lista -> tamanho && indice > 0){
            ElementoSimples * auxiliar_previo = lista -> inicio;
            ElementoSimples * auxiliar_proximo = NULL;
            ElementoSimples * novo = (ElementoSimples*)malloc(sizeof(ElementoSimples));
            for (int i = 0; i < indice - 1; i++){
                auxiliar_previo = auxiliar_previo -> proximo;
            }
            auxiliar_proximo = auxiliar_previo -> proximo;
            novo -> valor = valor;
            auxiliar_previo -> proximo = novo;
            novo -> proximo = auxiliar_proximo;
            lista -> tamanho++;
    }
    else{
        resultado = 0;
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

int ordenada(ListaSimples * lista){

    int resultado = 1;
    if (lista -> tamanho > 0){
        // cria uma variável para comparação chamada "anterior"
        int anterior = lista -> inicio -> valor;
        ElementoSimples * auxiliar = lista -> inicio;

        while(auxiliar != NULL){
            // por ser ordem crescente, se o próximo for maior, está errado.
            if (auxiliar -> valor < anterior){
                resultado = 0;
                break;
            }
            // atualiza a referência para comparar com o próximo.
            else if(auxiliar -> valor > anterior){
                anterior = auxiliar -> valor;
            }
            auxiliar = auxiliar -> proximo;
        }
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

int main(void){

    ListaSimples * lista = inicia_lista_simples();
    push_simples(lista, 0, 8);
    push_simples(lista, 0, 10);
    push_simples(lista, 0, 8);
    push_simples(lista, 0, 5);
    ordenada(lista);
    return 0;
}