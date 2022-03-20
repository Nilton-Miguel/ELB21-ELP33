/*
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

implementação de uma função que averigua o balanceamento de delimitadores em expressões. Para alcançar esse resultado a função usa uma pilha. À pilha só são acrescentados delimitadores. Letras, números, sinais ficam todos de fora. A ideia é inserir na pilha delimitadores de abertura e retirá-los quando houver delimitadores de fechamento correspondentes, se a expressão for balanceada, a pilha estará vazia ao final da averiguação. Qualquer coisa que fuja do comportamento esperado faz com que a pilha não esteja vazia ao final do processo.

*/

# include <stdio.h>
# include <stdlib.h>

// todos os elementos postos em pilhas serão instâncias deste tipo.
typedef struct elemento{
    char caractere;
    struct elemento * proximo;
}Elemento;

// todas as pilhas serão instâncias deste tipo.
typedef struct pilha{
    Elemento * topo;
}Pilha;

// subrotina que retorna um ponteiro para uma nova pilha vazia.
Pilha * nova_pilha(){

    Pilha * p = (Pilha*)malloc(sizeof(Pilha));
    p -> topo = NULL;
    return p;
}

// subrotina que apenas insere caracteres na pilha, sem condicionais.
void insere_na_pilha(Pilha * p, char caractere){

    Elemento * novo = (Elemento*)malloc(sizeof(Elemento));
    novo -> caractere = caractere;
    novo -> proximo = p -> topo;
    p -> topo = novo;
}

// subrotina que retorna um caractere, depois o retira da pilha, retorna \0 se a pilha já estiver vazia.
char retira_da_pilha(Pilha * p){

    char caractere = '\0';
    Elemento * antigo_topo;

    if (p -> topo != NULL){
        caractere = p -> topo -> caractere;
        antigo_topo = p -> topo;
        p -> topo = p -> topo -> proximo;
        free(antigo_topo);
    }
    return caractere;
}

// subrotina que testa se dois delimitadores se balanceiam, retorna 0 para não e 1 para sim.
int balanceia(char abertura, char fechamento){

    int resultado = 0;

    if ((abertura == '(' && fechamento == ')') || (abertura == '[' && fechamento == ']') || (abertura == '{' && fechamento == '}')){
        resultado = 1;
    }
    return resultado;
};

// subrotina para verificar se o caractere é um dos delimitadores: 0 para não, 1 para abertura e 2 para fechamento.
int delimitador(char caractere){

    int resultado = 0;

    if (caractere == '(' || caractere == '{' || caractere == '['){
        resultado = 1;
    }
    else if (caractere == ')' || caractere == '}' || caractere == ']'){
        resultado = 2;
    }
    return resultado;
}

// subrotina para checar o balanceamento de delimitadores: retorna 1 se correto e 0 caso incorreto.
int averiguar_delimitadores(Pilha * p, char * texto){

    int resultado = 0;
    int indice = 0;

    while(texto[indice] != '\0'){

        int tipo_de_caractere = delimitador(texto[indice]);

        if (tipo_de_caractere != 0){

            // caso a pilha esteja vazia, insere o delimitador não importando qual seja.
            if (p -> topo == NULL){
                insere_na_pilha(p, texto[indice]);
            }
            // se o delimitador for uma abertura, é inserido na pilha.
            else if (tipo_de_caractere == 1){
                insere_na_pilha(p, texto[indice]);
            }
            // se o delimitador for um fechamento há 2 casos:
            else if (tipo_de_caractere == 2){
                // se o fechamento balancear o delimitador no topo da pilha, retira-se quem já está na pilha, como se eles tivessem se "cancelado".
                if (balanceia(p -> topo -> caractere, texto[indice])){
                    retira_da_pilha(p);
                }
                // para outros casos, apenas insira o delimitador na pilha.
                else{
                    insere_na_pilha(p, texto[indice]);
                }
            }
        }
        indice++;
    }

    // se a pilha já está vazia ao final do processo, então os delimitadores estão balanceados.
    if (p -> topo == NULL){
        resultado = 1;
    }
    // se a pilha não está vazia, isso pode interferir nos próximos usos da função, fazer então uma "limpeza de buffer", para que no próximo uso a pilha esteja zerada.
    else{
        while(p -> topo != NULL){
            retira_da_pilha(p);
        }
    }
    return resultado; 
}

int main(void){

    Pilha * buffer_delimitadores = nova_pilha();
    averiguar_delimitadores(buffer_delimitadores, "()[]{}\0");
    averiguar_delimitadores(buffer_delimitadores, ")(}{][\0");
    averiguar_delimitadores(buffer_delimitadores, "(] {] []\0");
    averiguar_delimitadores(buffer_delimitadores, "[({})]\0");
    averiguar_delimitadores(buffer_delimitadores, "[(){}[]\0");

    return 0;
}
