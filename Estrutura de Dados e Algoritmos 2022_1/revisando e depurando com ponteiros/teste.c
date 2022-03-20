# include <stdio.h>
# include <stdlib.h>

int main(){

    // a depuração para nas linhas abaixo porque ocorre inicialização das variáveis.
    int a = 1;
    int b = 1;
    int c = 1;
    // o depurador pula a linha abaixo porque nela só ocorre uma declaração e essas já foram levadas em conta na compilação. As variáveis criadas de forma estática já estão alocadas, não tem necessidade de executar essa linha de novo.
    int d;
    d = 1;
    // a linha 14 também é ignorada por só haver declaração.
    int *p1;
    // um bloco é alocado dinamicamente, o depurador vai parar aqui porque alocação dinâmica não foi feita ainda, ela ocorre em tempo de execução.
    p1 = (int*)malloc(sizeof(int));
    *p1 = 1;
    // desalocação também é feita em tempo de execução, o depurador vai parar aqui.
    p1 = (int*)realloc(p1, 0);

    // extra: realloc com tamanho 0 equivale a free em parte das implementações do C

    return 0;
}
