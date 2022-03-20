/*
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

implementação de pilhas que aceitem apenas elementos de mesma paridade. Por consequência das condições para aceitar um novo elemento, todos os inteiros postos na pilha terão a mesma paridade, portanto a comparação de paridade para aceitar uma nova inserção pode ser feita com qualquer um dos elementos já inseridos, inclusive o topo.

*/

# include <stdio.h>
# include <stdlib.h>

// todos os elementos postos em pilhas serão instâncias deste tipo.
typedef struct elemento{
    int valor;
    struct elemento * proximo;
}Elemento;

// todas as pilhas serão instâncias deste tipo.
typedef struct pilha{
    Elemento * topo;
}Pilha;

// subrotina: retorna 0 para paridades opostas e 1 para mesma paridade.
int paridade(int a, int b){

    int resultado = 0;

    if (a % 2 == b % 2){
        resultado = 1;
    }
    return resultado;
}

// subrotina que retorna um ponteiro para uma nova pilha vazia.
Pilha * nova_pilha(){

    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p -> topo = NULL;
    return p;
}

// subrotina que insere um elemento na pilha apenas se sua paridade estiver de acordo com elementos já postos na pilha.
int insere_na_pilha(Pilha * p, int valor){

    int resultado = -1;
    int mesma_paridade = 0;

    // se a pilha não for vazia, testa a paridade entre o novo valor pretendido e o valor do topo.
    if (p -> topo != NULL && paridade(valor, p -> topo -> valor) == 1){
        mesma_paridade = 1;
    }
    // insere um novo elemento se a pilha está vazia OU se a paridade estiver de acordo.
    if (p -> topo == NULL || mesma_paridade){
        Elemento * novo = (Elemento*)malloc(sizeof(Elemento));
        novo -> valor = valor;
        novo -> proximo = p -> topo;
        p -> topo = novo;
        resultado = 0;
    }
    return resultado;
}

int main(void){

    Pilha * p1 = nova_pilha();
    Pilha * p2 = nova_pilha();

    insere_na_pilha(p1, 5);
    insere_na_pilha(p1, 6);
    insere_na_pilha(p1, 7);
    insere_na_pilha(p1, 8);
    insere_na_pilha(p1, 9);
    insere_na_pilha(p1, 10);
    insere_na_pilha(p1, 11);

    insere_na_pilha(p2, 6);
    insere_na_pilha(p2, 7);
    insere_na_pilha(p2, 8);
    insere_na_pilha(p2, 9);
    insere_na_pilha(p2, 10);
    insere_na_pilha(p2, 11);
    insere_na_pilha(p2, 12);

    return 0;
}
