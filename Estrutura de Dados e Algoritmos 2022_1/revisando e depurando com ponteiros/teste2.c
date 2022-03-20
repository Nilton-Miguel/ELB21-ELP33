# include <stdio.h>
# include <stdlib.h>

int main(){

    
    int *p1;
    p1 = (int*)malloc(sizeof(int));
    *p1 = 5;

    // os dois ponteiros estão guardando o mesmo endereço, estão apontando para o mesmo lugar na memória. Alterações em uma também vão causar alterações na outra, igual listas em Python, onde precisamos usar cópias rasas e profundas para evitar links.

    int *p2 = p1;
    (*p1)++;
    (*p2)++;

    free(p1);
    p1 = realloc(NULL, sizeof(int));
    *p1 = 5;

    return 0;
}
