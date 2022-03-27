/*
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

'+' para soma
'-' para subtração
'x' para produto
'/' para divisão convencional

*/

# include <stdio.h>
# include <stdlib.h>

// todos os elementos postos em pilhas serão instâncias deste tipo.
typedef struct elemento{
    float valor;
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
void insere_na_pilha(Pilha * p, float valor){

    Elemento * novo = (Elemento*)malloc(sizeof(Elemento));
    novo -> valor = valor;
    novo -> proximo = p -> topo;
    p -> topo = novo;
}

// subrotina que retorna um caractere, depois o retira da pilha, retorna \0 se a pilha já estiver vazia.
float retira_da_pilha(Pilha * p){

    float valor = 0;
    Elemento * antigo_topo;

    if (p -> topo != NULL){
        valor = p -> topo -> valor;
        antigo_topo = p -> topo;
        p -> topo = p -> topo -> proximo;
        free(antigo_topo);
    }
    return valor;
}

// calculadora rpn funcional. Essa função não tem funcionalidade para detecção de erros.
float calcula(Pilha * p, char * expressao){

    int indice = 0;
    float resultado = 0;

    while (expressao[indice] != 0){

        if( expressao[indice] >= '0' && expressao[indice] <= '9'){
            insere_na_pilha(p, (int)(expressao[indice]) - '0');
        }
        else if( expressao[indice] == '+'){
            float segundo_argumento = retira_da_pilha(p);
            float primeiro_argumento = retira_da_pilha(p);
            insere_na_pilha( p, primeiro_argumento + segundo_argumento );
        }
        else if( expressao[indice] == '-'){
            float segundo_argumento = retira_da_pilha(p);
            float primeiro_argumento = retira_da_pilha(p);
            insere_na_pilha( p, primeiro_argumento - segundo_argumento );
        }
        else if( expressao[indice] == 'x'){
            float segundo_argumento = retira_da_pilha(p);
            float primeiro_argumento = retira_da_pilha(p);
            insere_na_pilha( p, primeiro_argumento * segundo_argumento );
        }
        else if( expressao[indice] == '/'){
            float segundo_argumento = retira_da_pilha(p);
            float primeiro_argumento = retira_da_pilha(p);
            insere_na_pilha( p, primeiro_argumento / segundo_argumento );
        }
        indice++;
    }
    resultado = p -> topo -> valor;

    // limpeza do buffer
    retira_da_pilha(p);
    return resultado;
}

int main(void){

    Pilha * buffer = nova_pilha();
    printf("%.3f\n", calcula(buffer, "73-52/x\0"));
    printf("%.3f\n", calcula(buffer, "45-92/x7+\0"));
    printf("%.3f\n", calcula(buffer, "25/43+x28x-\0"));
    printf("%.3f\n", calcula(buffer, "44x33x/52x+\0"));

    return 0;
}
