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
void imprime(Node * root_pont){

    if(root_pont != NULL){

        if(root_pont -> esquerdo != NULL){
            imprime(root_pont -> esquerdo);
        }
        printf("%d  ", root_pont -> info);
        if(root_pont -> direito != NULL){
            imprime(root_pont -> direito);
        }
    } 
}
//------------------------------------------------------
Node * busca(Node * root_pont, int info){

    Node * retorno = NULL;

    if(root_pont != NULL){

        if(info < root_pont -> info){
            retorno = busca(root_pont -> esquerdo, info);
        }
        else if(info > root_pont -> info){
            retorno = busca(root_pont -> direito, info);
        }
        else{
            retorno = root_pont;
        }
    }
    return retorno;
}
//------------------------------------------------------
Node * retira(Node * root_pont, int info){

    if(root_pont != NULL){

        if(info < root_pont -> info){
            root_pont -> esquerdo = retira(root_pont -> esquerdo, info);
        }
        else if(info > root_pont -> info){
            root_pont -> direito = retira(root_pont -> direito, info);
        }
        else{

            if(root_pont -> direito == NULL && root_pont -> esquerdo == NULL){

                free(root_pont);
                root_pont = NULL;
            }
            else if(root_pont -> direito != NULL && root_pont -> esquerdo != NULL){

                Node * substituto = root_pont -> direito;
                while (substituto -> esquerdo != NULL){
                    substituto = substituto -> esquerdo;
                }
                root_pont -> info = substituto -> info;
                root_pont -> direito = retira(root_pont -> direito, substituto -> info);
            }
            else if(root_pont -> direito != NULL){

                Node * auxiliar = root_pont -> direito;
                free(root_pont);
                root_pont = auxiliar;
            }
            else{

                Node * auxiliar = root_pont -> esquerdo;
                free(root_pont);
                root_pont = auxiliar;
            }
        }
    }
    return root_pont;
}
//------------------------------------------------------

int main(void){

    Node * root = NULL;
    
    root = insere(root, 45); root = insere(root, 48);
    root = insere(root, 33); root = insere(root, 9);
    root = insere(root, 11); root = insere(root, 7);
    root = insere(root, 34); root = insere(root, 50);
    root = insere(root, 98); root = insere(root, 61);
    root = insere(root, 75); root = insere(root, 49);
    root = insere(root, 35);
    imprime(root);
    Node * resultado = busca(root, 11);
    root = retira(root, 50);
    return 0;
}
