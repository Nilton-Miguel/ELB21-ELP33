/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Escreva uma função RECURSIVA que receba como parâmetro uma árvore binária. Essa árvore armazena números inteiros em seus nós. Essa função deverá retornar o resultado da soma de todos os números PARES armazenados na árvore. Não é permitido alocar novos elementos, criar ponteiros nem utilizar laços.
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
int somatorio_pares(Node * root_pont, int somatorio){

    // Verifica na esquerda primeiro, por convenção
    if(root_pont -> esquerdo != NULL){
        somatorio = somatorio_pares(root_pont -> esquerdo, somatorio);
    }

    // Se o valor do nó atual for par altera o retorno com a soma da info
    if(root_pont -> info % 2 == 0)
        somatorio += root_pont -> info;

    // Verifica na direita depois, por convenção
    if(root_pont -> direito != NULL){
        somatorio = somatorio_pares(root_pont -> direito, somatorio);
    }
    return somatorio;
}
//------------------------------------------------------

int main(void){

    Node * root = NULL;
    
    // raiz
    root = insere(root, 55);

    // nível 1
    root = insere(root, 16);
    root = insere(root, 81);

    // nível 2
    root = insere(root, 5);
    root = insere(root, 28);
    root = insere(root, 97);
    root = insere(root, 60);

    // nível 3
    root = insere(root, 24);

    int somatorio = 0;
    somatorio = somatorio_pares(root, somatorio);

    return 0;
}
