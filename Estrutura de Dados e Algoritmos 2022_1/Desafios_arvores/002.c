/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Escreva uma função RECURSIVA que receba uma árvore binária e imprima todos os valores contidos nela em ordem DECRESCENTE.
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
void imprime_decrescente(Node * root_pont){

    if(root_pont != NULL){

        // Verifica primeiro pelos valores maiores
        if(root_pont -> direito != NULL){
            imprime_decrescente(root_pont -> direito);
        }
        // Imprime o meio
        printf("%d  ", root_pont -> info);
        // E por fim verifica os valores menores
        if(root_pont -> esquerdo != NULL){
            imprime_decrescente(root_pont -> esquerdo);
        }
    } 
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

    imprime_decrescente(root);
    
    return 0;
}
