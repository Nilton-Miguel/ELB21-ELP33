# include <stdio.h>
# include <stdlib.h>
# define N 3
# define W 2
//---------------------------------------------------------------------------------
typedef struct node{

    int aceita;
    struct node * proximo;
}node;
//---------------------------------------------------------------------------------
typedef struct grafo{

    int tamanho;
    int len_alfabeto;
    char alfabeto[W];
    char matriz_adjacencia[N][N];
    node * inicial;
}grafo;
//---------------------------------------------------------------------------------
grafo * maquina(void){

    grafo * novo_grafo = (grafo*)malloc(sizeof(grafo));
    novo_grafo -> inicial = NULL;

    for(int linha = 0; linha < N; linha++){
        for(int coluna = 0; coluna < N; coluna++){
            novo_grafo -> matriz_adjacencia[linha][coluna] = 0;
        }
    }
    return novo_grafo;
}
//---------------------------------------------------------------------------------
int link(grafo * machine, int partida, int chegada, int indice_alfabeto){

    int resultado = 1;

    int limite1 = machine -> tamanho;
    int limite2 = machine -> len_alfabeto;

    if(partida >= limite1 || chegada >= limite1 || indice_alfabeto >= limite2) 
        resultado = 0;
    else
        machine -> matriz_adjacencia[partida][chegada] = machine -> alfabeto[indice_alfabeto];
    
    return resultado;
}
//---------------------------------------------------------------------------------
int alfabeto(grafo * machine, char * alfabeto, int len_alfabeto){

    int resultado = 1;

    if(len_alfabeto <= W){

        for(int i = 0; i < len_alfabeto; i++){

            if(alfabeto[i] != 0){
                machine -> alfabeto[i] = alfabeto[i];
            }
            else{
                resultado = 0;
                break;
            }
        }
        machine -> len_alfabeto = len_alfabeto;
    }
    else{
        resultado = 0;
    }
    return resultado;
}
//---------------------------------------------------------------------------------
int state(grafo * machine, int aceita){

    int resultado = 1;

    if(machine -> tamanho == N)
        resultado = 0;
    else{

        node * novo = (node*)malloc(sizeof(node));
        novo -> aceita = aceita;
        novo -> proximo = NULL;

        machine -> tamanho ++;

        if(machine -> inicial == NULL)
            machine -> inicial = novo;
        else{

            node * auxiliar = machine -> inicial;
            while(auxiliar -> proximo != NULL){
                auxiliar = auxiliar -> proximo;
            }
            auxiliar -> proximo = novo;
        }
    }
    return resultado;
}
//---------------------------------------------------------------------------------
int main(void){

    grafo * machine = maquina();

    state(machine, 0);
    state(machine, 0);
    state(machine, 1);

    char alfa[2] = {'a', 'b'};

    alfabeto(machine, alfa, 2);

    link(machine, 0, 0, 0);
    link(machine, 0, 1, 1);

    link(machine, 1, 0, 1);
    link(machine, 1, 1, 0);
    link(machine, 1, 2, 1);

    link(machine, 2, 2, 0);
    link(machine, 2, 2, 1);

    return 0;
}
