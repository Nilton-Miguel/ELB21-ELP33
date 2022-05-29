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

    // se tem filho à esquerda, procura um maior lá primeiro
    if(root_pont -> esquerdo != NULL){
        maior = procura_maior(root_pont -> esquerdo, maior);
    }
    // se encontrarmos no nó atual um valor maior, atualizamos o retorno
    if(root_pont -> info > maior){
        maior = root_pont -> info;
    }
    // se tem filho à direita, procura um maior lá agora
    if(root_pont -> direito != NULL){
        maior = procura_maior(root_pont -> direito, maior);
    }
    // quando chegamos aqui vasculhamos todas as sub árvores de root_pont no escopo desta chamada.

    return maior;
}
//------------------------------------------------------
int procura_menor(Node * root_pont, int menor){
    /*
        Vamos atualizar um valor chamado menor com o retorno dessa função, se não mexermos no valor e retornarmos a mesma coisa, não modificamos nada nas chamadas anteriores, se modificarmos, o valor retorna atualizado pras chamadas anteriores.
    */

    // se tem filho à esquerda, procura um menor lá primeiro
    if(root_pont -> esquerdo != NULL){
        menor = procura_menor(root_pont -> esquerdo, menor);
    }
    // se encontrarmos no nó atual um valor menor, atualizamos o retorno
    if(root_pont -> info < menor){
        menor = root_pont -> info;
    }
    // se tem filho à direita, procura um menor lá agora
    if(root_pont -> direito != NULL){
        menor = procura_menor(root_pont -> direito, menor);
    }
    // quando chegamos aqui vasculhamos todas as sub árvores de root_pont no escopo desta chamada.

    return menor;
}
//------------------------------------------------------
int verificar_coerencia(Node * root_pont){
    /*
        Essa função retorna 1 se o nó passado é raiz de uma árvore binária de busca e 0 caso contrário.
    */
    int resultado = 1;

    if(root_pont -> esquerdo != NULL){
        /*
            Duas perguntas são feitas:

                1   A raiz é maior que todo e qualquer valor à sua esquerda ?
                2   O que está à esquerda é, também, uma árvore binária de busca ?
            
            Se alguma desses testes falha, o nó não é raiz de uma árvore binária de busca
        */
        int maior_na_esquerda = procura_maior(root_pont -> esquerdo, root_pont -> esquerdo -> info);
        if(verificar_coerencia(root_pont -> esquerdo) == 0 || maior_na_esquerda > root_pont -> info){
            resultado = 0;
        }
    }
    // Testes para a direita, análogos aos da esquerda. Não precisa executar se o da esquerda já falhou
    if(root_pont -> direito != NULL && resultado == 1){

        int menor_na_direita = procura_menor(root_pont -> direito, root_pont -> direito -> info);
        if(verificar_coerencia(root_pont -> direito) == 0 || menor_na_direita < root_pont -> info){
            resultado = 0;
        }
    }
    // Se não há nada nem à esquerda nem à direita (nó folha) então retorna 1.
    return resultado;
}
//------------------------------------------------------

int main(void){

    // Árvore binária de busca criada adequadamente --------------------------------------
    Node * root = NULL;
    
    // raiz
    root = insere(root, 33);

    // nível 1
    root = insere(root, 22);
    root = insere(root, 46);

    // nível 2
    root = insere(root, 17);
    root = insere(root, 29);
    root = insere(root, 37);
    root = insere(root, 52);

    // nível 3
    root = insere(root, 6);
    root = insere(root, 21);
    root = insere(root, 31);
    root = insere(root, 48);
    root = insere(root, 73);

    // retorna verdadeiro, como deveria retornar
    int yay1 = verificar_coerencia(root);
    
    // Árvore binária não de busca usada de exemplo no enunciado --------------------------

    // raiz
    root = (Node*)malloc(sizeof(Node));
    root -> info = 5;
    
    // nível 1
    root -> esquerdo = (Node*)malloc(sizeof(Node));
    root -> esquerdo -> info = 2;
 
    root -> direito = (Node*)malloc(sizeof(Node));
    root -> direito -> info = 7;
    root -> direito -> direito = NULL;
    root -> direito -> esquerdo = NULL;

    // nível 2
    root -> esquerdo -> esquerdo = (Node*)malloc(sizeof(Node));
    root -> esquerdo -> esquerdo -> info = 1;
    root -> esquerdo -> esquerdo -> esquerdo = NULL;
    root -> esquerdo -> esquerdo -> direito = NULL;
 
    root -> esquerdo -> direito = (Node*)malloc(sizeof(Node));
    root -> esquerdo -> direito -> info = 6;
    root -> esquerdo -> direito -> esquerdo = NULL;
    root -> esquerdo -> direito -> direito = NULL;

    // retorna falso, como deveria retornar
    int yay2 = verificar_coerencia(root);

    return 0;
}
