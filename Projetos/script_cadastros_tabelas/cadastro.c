
#include <stdio.h>

typedef struct cadastro_individual{

    char nome[40];
    int idade;
    char emprego[30];

}cadastro_individual;

int main(){

    cadastro_individual pessoa = {"Antonio Passos", 35, "Pistoleiro"};
    printf("%s |", pessoa.nome);
    printf("%d |", pessoa.idade);
    printf("%s\n", pessoa.emprego);
    return 0;
}
