# include <stdio.h>
# include <stdlib.h>

typedef struct node{

    int info;
    struct node * esquerdo;
    struct node * direito;
}Node;

//------------------------------------------------------
Node * insere(Node * root_pont, int info){
    /* 
        1. Essa função devolve um endereço para atualizar uma relação na árvore. Se ela acha um espaço vazio, ela insere o que precisa inserir e deolve um endereço novo pra que uma relação que não existia seja feita.

        2. Se ela não acha um espaço vazio, precisa retornar o mesmo endereço para que a relação que já existe com esse espaço não seja destruída. Mas antes ela chama a mesma função para atualizar um de seus filhos.
    */
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
    /* 
        Essa função tenta imprimir o que está à esquerda de um nó, depois o próprio nó, depois o que está à sua direita.

        Se eu tentar printar uma árvore vazia, ela não passa no primeiro teste.
    */
    if(root_pont != NULL){
        // Se tem um nó à esquerda, tenta printar lá primeiro.
        if(root_pont -> esquerdo != NULL){
            imprime(root_pont -> esquerdo);
        }
        printf("%d  ", root_pont -> info);
        // Se tem um nó à direita, tenta printar lá agora.
        if(root_pont -> direito != NULL){
            imprime(root_pont -> direito);
        }
        // Encerra a função.
    } 
}
//------------------------------------------------------
Node * busca(Node * root_pont, int info){
    /*
        Essa função tenta achar um certo valor. Baseado no valor do nó atual, ela tenta procurar na esquerda, na direita ou em si mesma.

        Se eventualmente ela acha, uma chamada retorna pra outra até que a primeira chamada retorne o endereço que queríamos. Se evenatualmente todos os 3 testes falharem, uma chamada retorna NULL pra outra até que a primeira chamada retorne NULL.
    */
    Node * retorno = NULL;
    // Se cairmos num beco sem saída não mudamos o valor padrão que é NULL.
    if(root_pont != NULL){
        // Se for menor olha na esquerda.
        if(info < root_pont -> info){
            retorno = busca(root_pont -> esquerdo, info);
        }
        // Se for maior olha na direita.
        else if(info > root_pont -> info){
            retorno = busca(root_pont -> direito, info);
        }
        // Se for igual retorna o próprio endereço.
        else{
            retorno = root_pont;
        }
    }
    return retorno;
}
//------------------------------------------------------
Node * retira(Node * root_pont, int info){
    /*
        Seguindo a mesma lógica da função de inserção, se modificarmos root_pont numa chamada da função, modificaremos o link do nó anterior com o atual. Se não modificarmos nada, o ponteiro é retornado igual e nada muda.
    */
    if(root_pont != NULL){
        // Pra esses dois casos não mexemos em root_pont, só chamamos a função pros filhos e possivelmente mudamos os links com o que vem depois, mas não com o que vem antes.
        if(info < root_pont -> info){
            root_pont -> esquerdo = retira(root_pont -> esquerdo, info);
        }
        else if(info > root_pont -> info){
            root_pont -> direito = retira(root_pont -> direito, info);
        }
        // achou o valor desejado, agora sim devolvemos um ponteiro diferente para alterar nossa árovre.
        else{

            // Nó sem filhos, liberamos a memória e devolvemos um ponteiro nulo pra chamada anterior, assim o nó superior perdeu esse filho.
            if(root_pont -> direito == NULL && root_pont -> esquerdo == NULL){

                free(root_pont);
                root_pont = NULL;
            }
            // Se tiver 2 filhos, optei por colocar no lugar o menor da sub árvore direita
            else if(root_pont -> direito != NULL && root_pont -> esquerdo != NULL){

                // posicionar um auxiliar no menor elemento da subárvore direita e atualizar o valor de root_pont pra ele.
                Node * substituto = root_pont -> direito;
                while (substituto -> esquerdo != NULL){
                    substituto = substituto -> esquerdo;
                }
                root_pont -> info = substituto -> info;
                root_pont -> direito = retira(root_pont -> direito, substituto -> info);
            }
            // Nós com filho único, o filho entra no lugar dele. Então colocamos um auxiliar pro filho, limpamos o atual e devolvemos o endereço do filho para a chamada anterior, assim o nó anterior cria um link com o filho do nó deletado.
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
    // Se root_pont já for nulo, ele retorna nulo mesmo, não muda nada dos links com os nós anteriores.
    return root_pont;
}
//------------------------------------------------------

int main(void){

    Node * root = NULL;
    // inserções funcionam
    root = insere(root, 45); root = insere(root, 48);
    root = insere(root, 33); root = insere(root, 9);
    root = insere(root, 11); root = insere(root, 7);
    root = insere(root, 34); root = insere(root, 50);
    root = insere(root, 98); root = insere(root, 61);
    root = insere(root, 75); root = insere(root, 49);
    root = insere(root, 35);
    // impressão funciona
    imprime(root);
    // buscas funcionam
    Node * resultado = busca(root, 11);
    // remoção funciona também
    root = retira(root, 50);
    return 0;
}
