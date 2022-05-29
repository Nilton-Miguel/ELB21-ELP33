/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Dada a raiz de uma árvore binária de busca, escreva uma função que calcule a sua altura - o número de nós da raiz até o nó folha mais distante, onde iremos percorrer o caminho mais longo.
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
int altura(Node * root_pont, int maior_registro, int altura_atual){

    // Se cheguei numa altura maior do que já cheguei em qualquer outra parte da árvore, atualiza o registrador de maior altura
    if(altura_atual > maior_registro)
        maior_registro = altura_atual;

    // Se há algo para a esquerda, vamos acessar algo com uma altura uma unidade maior que a atual
    if(root_pont -> esquerdo != NULL){
        maior_registro = altura(root_pont -> esquerdo, maior_registro, altura_atual + 1);
    }
    if(root_pont -> direito != NULL){
        maior_registro = altura(root_pont -> direito, maior_registro, altura_atual + 1);
    }
    return maior_registro;
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

    // Chamar a função desta forma considera que o nó raiz está na altura 0. Logo, um resultado 3 representa que a maior cadeia possível nessa árvore é de 4 nós.

    // alt1 == 3
    int alt1 = altura(root, 0, 0);

    // ainda nível 3
    root = insere(root, 76);

    // nível 4
    root = insere(root, 77);

    // nível 5
    root = insere(root, 79);

    // alt1 == 5
    int alt2 = altura(root, 0, 0);

    return 0;
}
