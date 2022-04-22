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

// retorna 1 para inserção bem sucedida e 0 para o oposto
int push_simples(ListaSimples * lista, int indice, int valor){

    int resultado = 1;

    // se for inserir no início, é praticamente o mesmo processo da pilha
    if (indice == 0){
        ElementoSimples * novo = (ElementoSimples*)malloc(sizeof(ElementoSimples));
        novo -> proximo = lista -> inicio;
        novo -> valor = valor;
        lista -> inicio = novo;
        lista -> tamanho++;
    }
    /* 
    O indice desejado precisa estar dentro das margens aceitas pela estrutura 
        indice = 0 ......................... inserir no início
        0 < indice < lista -> tamanho ......... inserir no meio   
        indice = lista -> tamanho ............ inserir no final
    */
    else if (indice <= lista -> tamanho && indice > 0){
            // cria o novo e ambosa ponteiros auxiliares
            ElementoSimples * auxiliar_previo = lista -> inicio;
            ElementoSimples * auxiliar_proximo = NULL;
            ElementoSimples * novo = (ElementoSimples*)malloc(sizeof(ElementoSimples));

            // posiciona o auxiliar prévio no que será o anterior ao inserido e o próximo no que será o posterior ao inserido
            for (int i = 0; i < indice - 1; i++){
                auxiliar_previo = auxiliar_previo -> proximo;
            }
            auxiliar_proximo = auxiliar_previo -> proximo;
            // atualiza os ponteiros e o tamanho da estrutura
            novo -> valor = valor;
            auxiliar_previo -> proximo = novo;
            novo -> proximo = auxiliar_proximo;
            lista -> tamanho++;
    }
    // se o índice estiver fora de escopo, retorna fracasso
    else{
        resultado = 0;
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

// retorna o valor removido se bem sucedida e retorna 0 se fracasso
int pop_simples(ListaSimples * lista, int indice){

    int resultado = 0;
    if (indice == 0 && lista -> tamanho != 0){
        resultado = lista -> inicio -> valor;

        ElementoSimples * auxiliar_proximo = lista -> inicio -> proximo;
        free(lista -> inicio);
        lista -> inicio = auxiliar_proximo;
        lista -> tamanho--;
    }
    // aqui o limite do índice precisa ser menor que o tamanho, pois na posição tamanho temos apenas o NULL, não há elementos para retirar.
    else if(indice < lista -> tamanho && lista -> tamanho != 0 && indice > 0){
        resultado = lista -> inicio -> valor;

        ElementoSimples * auxiliar_previo = lista -> inicio;
        ElementoSimples * auxiliar_deletar = NULL;

        // posiciona o auxiliar prévio no elemento anterior ao que será deletado e o auxiliar deletar no próprio elemento a ser cancelado.
        for(int i = 0; i < indice - 1; i++){
            auxiliar_previo = auxiliar_previo -> proximo;
        }
        auxiliar_deletar = auxiliar_previo -> proximo;

        auxiliar_previo -> proximo = auxiliar_deletar -> proximo;
        free(auxiliar_deletar);
        lista -> tamanho--;
    }
    return resultado;
}

// ---------------------------------------------------------------------------------

int main(void){

    ListaSimples * lista = inicia_lista_simples();
    return 0;
}
