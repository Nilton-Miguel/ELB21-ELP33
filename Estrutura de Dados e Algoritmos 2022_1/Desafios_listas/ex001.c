/* 
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função ListaInt que recebe uma lista simplesmente encadeada de números inteiros, um inteiro “inicioFaixa” e outro inteiro chamado “fimFaixa”. Esta função deve criar uma segunda lista simplesmente encadeada contendo os elementos da lista original cujo valor está contido no intervalo fechado [inicioFaixa, fimFaixa]. Não é permitido utilizar as funções prontas da lista. A lista original não está ordenada, e deve ser preservada. É permitido alocar memória. Não é necessário que os números estejam na lista final na mesma ordem em que estavam na lista original.

    Minha abordagem para este exercício foi utilizar funções prontas de Lista apenas para criar uma lista que usei nos testes, a função requisitada em si não usa subrotinas, foi toda escrita do 0.
    A lógica: Percorrer a Lista original com um ponteiro auxiliar e checar se aquele valor está na faixa de tolerância, se sim, adicioná-lo ao início da Lista que será retornada.
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

ListaSimples * ListaInt(ListaSimples * original, int inicioFaixa, int fimFaixa){

    // cria a lista que será retornada pela função
    ListaSimples * fila_dentro_faixa = (ListaSimples*)malloc(sizeof(ListaSimples));
    fila_dentro_faixa -> tamanho = 0;
    fila_dentro_faixa -> inicio = NULL;

    // prepara o ponteiro auxiliar que percorrerá a lista original
    ElementoSimples * auxiliar = original -> inicio;

    // enquanto não chegar ao fim da lista
    while(auxiliar != NULL){
        // se o valor estiver dentro do intervalo fechado
        if (auxiliar -> valor <= fimFaixa && auxiliar -> valor >= inicioFaixa){
            // só colocar no começo da lista mesmo, já que não import a ordem
            ElementoSimples * novo = (ElementoSimples*)malloc(sizeof(ElementoSimples));
            novo -> valor = auxiliar -> valor;
            novo -> proximo = fila_dentro_faixa -> inicio;
            fila_dentro_faixa -> inicio = novo;
            fila_dentro_faixa -> tamanho++;
        }
        auxiliar = auxiliar -> proximo;
    }
    return fila_dentro_faixa;
}

// ---------------------------------------------------------------------------------

int main(void){

    // usando funções prontas de Lista apenas para criar uma lista de teste
    ListaSimples * lista_original = inicia_lista_simples();
    push_simples(lista_original, 0, 7);
    push_simples(lista_original, 0, 10);
    push_simples(lista_original, 0, 6);
    push_simples(lista_original, 0, 9);
    push_simples(lista_original, 0, 7);
    push_simples(lista_original, 0, 5);
    push_simples(lista_original, 0, 8);
    push_simples(lista_original, 0, 7);
    push_simples(lista_original, 0, 6);
    push_simples(lista_original, 0, 5);
    push_simples(lista_original, 0, 4);
    push_simples(lista_original, 0, 3);
    push_simples(lista_original, 0, 2);
    push_simples(lista_original, 0, 6);
    push_simples(lista_original, 0, 1);
    push_simples(lista_original, 0, 8);

    // a função resposta é esta, e ela não utiliza subrotinas de Lista na sua definição.
    ListaSimples * nova = ListaInt(lista_original, 5, 8);

    return 0;
}