/* Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

    Escreva uma função que recebe uma lista duplamente encadeada não circular, E um número inteiro X. A função deve “cortar” a lista na posição X, de forma que a lista original tenha todos os membros das posições menores que X, e retornar uma lista que contenha todos os membros da lista original a partir posição X (inclusive). NÃO É PERMITIDO ALOCAR NOVAS ESTRUTURAS, NEM UTILIZAR FUNÇÕES PRONTAS. Obs.: Assuma que a posição pedida é sempre válida, isto é, não-negativa e menor que o tamanho da lista.

    Para este exercício uso funções prontas de lista apenas para preparar minhas listas de teste, a função requerida em si faço tudo no próprio corpo da função.

    A abordagem para este foi bem simples, só posicionar um auxiliar no elemento onde se deseja começar o corte, daí, desconectamos o anterior dele, e desconcetamos ele do anterior, depois fazemos nosso endereço apontado pelo auxiliar ser apontado pela referência de uma lista e assim temos uma nova lista composta de tudo que foi tirado da anterior. Não alteramos nenhum endereço, nem criamos estruturas novas, apenas alteramos 4 ponteiros.
*/

# include <stdio.h>
# include <stdlib.h>

// ---------------------------------------------------------------------------------

// Minhas listas duplas têm uma propriedade circularidade que permite que as funções para listas funcionem indiscretamente com qualquer lista, se adequando à sua circularidade.

typedef struct elemento_duplo{

    int valor;
    struct elemento_duplo * proximo;
    struct elemento_duplo * anterior;    
}ElementoDuplo;

typedef struct lista_dupla{

    struct elemento_duplo * referencia;
    int circularidade;
    int tamanho;
}ListaDupla;

// ---------------------------------------------------------------------------------

// Circularidade 0 ou 1 cria listas duplamente encadeadas abertas ou cíclicas respectivamente, em caso de ser um valor de circularidade inválido, o ponteiro é retornado vazio.

ListaDupla * inicia_lista_dupla(int circularidade){

    ListaDupla * nova_lista = (ListaDupla*)malloc(sizeof(ListaDupla));
    nova_lista -> referencia = NULL;
    if (circularidade == 0 || circularidade == 1)
        nova_lista -> circularidade = circularidade;
    else
        nova_lista = NULL;
    return nova_lista;
}

// ---------------------------------------------------------------------------------

int push_duplo(ListaDupla * lista, int indice, int valor){
    int resultado = 1;

    if(indice <= lista -> tamanho && indice >= 0){

        lista -> tamanho++;
        ElementoDuplo * novo = (ElementoDuplo*)malloc(sizeof(ElementoDuplo));
        novo -> valor = valor;

        if(lista -> circularidade == 0 && indice == 0){

            novo -> anterior = NULL;
            novo -> proximo = lista -> referencia;
            lista -> referencia = novo;
            if(lista -> referencia -> proximo != NULL){
                lista -> referencia -> proximo -> anterior = lista -> referencia;
            }
        }

        else if(lista -> circularidade == 1 && indice == 0){

            if(lista -> referencia == NULL){

                novo -> proximo = novo;
                novo -> anterior = novo;
                lista -> referencia = novo;
            }
            else{

                novo -> proximo = lista -> referencia;
                novo -> anterior = lista -> referencia -> anterior;
                novo -> anterior -> proximo = novo;
                novo -> proximo -> anterior = novo;
                lista -> referencia = novo;
            }
        }

        else if(indice != 0){

            novo -> anterior = lista -> referencia;
            for(int i = 0; i < indice - 1; i++){
                novo -> anterior = novo -> anterior -> proximo;
            }
            novo -> proximo = novo -> anterior -> proximo;
            novo -> anterior -> proximo = novo;
            if(novo -> proximo != NULL)
                novo -> proximo -> anterior = novo;
        }
    }
    else{
        resultado = 0;
    }

    return resultado;
}

// ---------------------------------------------------------------------------------

ListaDupla * cortar(ListaDupla * original, int altura){

    // aloquei memória apenas para a lista de saída
    ListaDupla * restante = (ListaDupla*)malloc(sizeof(ListaDupla));
    ElementoDuplo * corte = original -> referencia;
    for(int i = 0; i < altura; i++){
        corte = corte -> proximo;
    }
    // o ponteiro corte está estacionado no primeiro elemento da lista restante, agora só preciso desconectar os ponteiros e tornar os elementos de corte para frente elementos de restante.
    corte -> anterior -> proximo = NULL;
    corte -> anterior = NULL;
    restante -> referencia = corte;

    restante -> tamanho = original -> tamanho - altura;
    original -> tamanho = altura;

    return restante;
}

// ---------------------------------------------------------------------------------

int main(void){

    // uso funções prontas apenas para criar minhas listas de teste
    ListaDupla * original = inicia_lista_dupla(0);
    push_duplo(original, 0, 2);
    push_duplo(original, 1, 7);
    push_duplo(original, 2, 25);
    push_duplo(original, 3, 17);
    push_duplo(original, 4, -9);
    // original = {2, 7, 25, 17, -9} tamanho 5

    ListaDupla * resto = cortar(original, 2);
    // original = {2, 7} tamanho 2
    // resto = {25, 17, -9} tamanho 3

    return 0;
}