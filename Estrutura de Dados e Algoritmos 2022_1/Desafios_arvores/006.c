/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Escreva uma função RECURSIVA que receba uma árvore binária e imprima em ordem decrescente todos os nós que NÃO são folhas.
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
void imprime_decrescente_excludente(Node * root_pont){

    if(root_pont != NULL){
        
        // Começa analisando os maiores
        if(root_pont -> direito != NULL){
            imprime_decrescente_excludente(root_pont -> direito);
        }
        // Se o atual tiver pelo menos um filho, imprime seu valor
        if(root_pont -> esquerdo != NULL || root_pont -> direito != NULL){
            printf("%d ", root_pont -> info);
        }
        // Termina analisando os menores
        if(root_pont -> esquerdo != NULL){
            imprime_decrescente_excludente(root_pont -> esquerdo);
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
    root = insere(root, 60);

    // nível 3
    root = insere(root, 24);
    root = insere(root, 76);

    // nível 4
    root = insere(root, 77);

    // nível 5
    root = insere(root, 79);

    // imprime exatamente o que deveria
    imprime_decrescente_excludente(root);

    return 0;
}
