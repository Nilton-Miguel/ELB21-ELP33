/*
    Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Dada uma árvore binária, verifique se a mesma é uma árvore binária de busca. Lembre que para que uma árvore binária seja de busca, para cada nó todos os valores dos nós em sua subárvore esquerda devem ser menores do que o valor do nó, e todos os valores dos nós em sua subárvore direita devem ser maiores que o valor do nó.
*/

# include <stdio.h>
# include <stdlib.h>

typedef struct node{

    int info;
    struct node * esquerdo;
    struct node * direito;
}Node;

//------------------------------------------------------
Node * insere(Node * root_pont, int info){
    if(root_pont == NULL){

        root_pont = (Node*)malloc(sizeof(Node));
        root_pont -> info = info;
        root_pont -> esquerdo = NULL;
        root_pont -> direito = NULL;
    }
    else if(info > root_pont -> info){
        root_pont -> direito = insere(root_pont -> direito, info);
    }
    else if(info < root_pont -> info){
        root_pont -> esquerdo = insere(root_pont -> esquerdo, info);
    }
    return root_pont;  
}
//------------------------------------------------------
int procura_maior(Node * root_pont, int maior){
    /*
        Vamos atualizar um valor chamado maior com o retorno dessa função, se não mexermos no valor e retornarmos a mesma coisa, não modificamos nada nas chamadas anteriores, se modificarmos, o valor retorna atualizado pras chamadas anteriores.
    */

    // se tem filho à esquerda, verifica lá primeiro
    if(root_pont -> esquerdo != NULL){
        procura_maior(root_pont -> esquerdo, maior);
    }
    // se encontrarmos no nó atual um valor maior, atualizamos o retorno
    if(root_pont -> info > maior){
        maior = root_pont -> info;
    }
    // se tem filho à direita, verifica lá depois
    if(root_pont -> direito != NULL){
        procura_maior(root_pont -> direito, maior);
    }
    // quando chegamos aqui vasculhamos todas as sub árvores de root_pont no escopo desta chamada.

    return maior;
}
//------------------------------------------------------

int main(void){

    Node * root = NULL;
    root = insere(root, 33);

    root = insere(root, 22);
    root = insere(root, 46);

    root = insere(root, 17);
    root = insere(root, 29);
    root = insere(root, 37);
    root = insere(root, 52);

    root = insere(root, 6);
    root = insere(root, 21);
    root = insere(root, 31);
    root = insere(root, 48);
    root = insere(root, 73);

    int maior = procura_maior(root -> esquerdo, root -> esquerdo -> info);

    return 0;
}
