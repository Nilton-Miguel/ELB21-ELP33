/*
    Nilton Miguel guimarães de Souza - UTFPR - 2022.1

    Escreva uma função RECURSIVA que receba uma árvore binária, imprima todos os nós FOLHA, e retorne a quantidade de nós folha contidos nesta árvore. Se a árvore for composta por apenas um nó, este também conta como folha.
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
int imprime_conta_folhas(Node * root_pont, int contagem){

    // se achar um nó folha
    if(root_pont -> esquerdo == NULL && root_pont -> direito == NULL){
        // imprime e atualiza (único caso que atualizamos a contagem)
        printf("%d ", root_pont -> info);
        contagem++;
    }
    else{
        // Se tem algo à direita ou esquerda, verifica lá
        if(root_pont -> esquerdo != NULL)
            contagem = imprime_conta_folhas(root_pont -> esquerdo, contagem);

        if(root_pont -> direito != NULL)
            contagem = imprime_conta_folhas(root_pont -> direito, contagem);
    }
    // Se o nó no escopo da chamada não for folha, contagem é devolvida igual e nada muda
    return contagem;
}

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

    int contagem = 0;
    contagem = imprime_conta_folhas(root, contagem);

    return 0;
}
