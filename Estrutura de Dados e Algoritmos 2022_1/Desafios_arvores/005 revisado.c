/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Implementação de uma nova função verificadora de altura usando uma lógica mais simples que a anterior.
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
int nova_altura(Node * root_pont){

    int altura;

    // altura do vazio é 0
    if(root_pont == NULL){
        altura = 0;
    }
    // altura de nó folha é 1
    else if(root_pont -> direito == NULL && root_pont -> esquerdo == NULL){
        altura = 1;
    }
    // nos outros casos a altura de um nó é uma unidade maior que a altura do seu filho mais alto
    else{
        if(nova_altura(root_pont -> direito) >= nova_altura(root_pont -> esquerdo)){
            altura = 1 + nova_altura(root_pont -> direito);
        }
        else{
            altura = 1 + nova_altura(root_pont -> esquerdo);
        }
    }
    return altura;
}
//------------------------------------------------------
int main(void){

    Node * root = NULL;

    // nível 1
    root = insere(root, 55);

    // nível 2
    root = insere(root, 16);
    root = insere(root, 81);

    // nível 3
    root = insere(root, 5);
    root = insere(root, 28);
    root = insere(root, 97);
    root = insere(root, 60);

    // nível 4
    root = insere(root, 24);

    // até agora o maior nível foi 4, então: 
    // alt1 == 4
    int alt1 = nova_altura(root);

    // nível 4
    root = insere(root, 76);

    // nível 5
    root = insere(root, 77);

    // nível 6
    root = insere(root, 79);

    // agora o maior nível é 6, então: 
    // alt1 == 6
    int alt2 = nova_altura(root);

    return 0;
}
