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

// subrotina para checar o balanceamento de delimitadores: retorna 1 se correto e 0 caso incorreto.
int averiguar_delimitadores(Pilha * p, char * texto){

    // resultado começa em -1.
    int resultado = -1;
    int indice = 0;

    while (texto[indice] != 0){

        // letras, operadores e espaços não passam nesse teste (só precisamos avaliar delimitadores).
        if (texto[indice] == '(' || texto[indice] == '[' || texto[indice] == '{' || texto[indice] == ')' || texto[indice] == ']' || texto[indice] == '}'){

            // se for uma abertura, insere.
            if (texto[indice] == '(' || texto[indice] == '{' || texto[indice] == '['){
                insere_na_pilha(p, texto[indice]);
            }
            // se for um fechamento e a pilha está vazia, erro.
            else if ((texto[indice] == ')' || texto[indice] == '}' || texto[indice] == ']') && p -> topo == NULL){
                resultado = 0;
                break;
            }
            // 3 casos de pares corretos.
            else if (texto[indice] == ')' && p -> topo -> caractere == '('){
                retira_da_pilha(p);
            }
            else if (texto[indice] == '}' && p -> topo -> caractere == '{'){
                retira_da_pilha(p);
            }
            else if (texto[indice] == ']' && p -> topo -> caractere == '['){
                retira_da_pilha(p);
            }
            // se não passou em nenhum dos testes até agora, posso afirmar com certeza que é um fechamento errado.
            else{
                resultado = 0;
                break;
            }
        }
        indice++;
    }

    // se o resultado não for mais -1, algum fechamento já apresentou erro durante a leitura da string e resultado agora é 0.
    if (p -> topo == NULL && resultado == -1){
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
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, "(a + b)\0"));
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, ")a + b)\0"));
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, "(a + b}\0"));
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, "a + b)\0"));
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, "[{(a + b)}]\0"));
    printf("%d\n", averiguar_delimitadores(buffer_delimitadores, "a + b\0"));

    return 0;
}
