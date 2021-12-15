//inclua APENAS a definição da struct e a implementação da função! 
// As bibliotecas e a parte principal do programa (main) NÃO DEVEM SER INCLUÍDOS AQUI.

#include <stdio.h>

typedef struct pessoa{
    char nome[30];
    int idade;
}pessoa;

pessoa* encontraMaisVelha(pessoa *end_vetor_pessoas, int n){

    typedef struct lembrar{
        int idade;
        pessoa *pos_no_vetor_pessoas;
    }lembrar;

    lembrar mais_velha;

    mais_velha.idade = (*(end_vetor_pessoas)).idade;
    mais_velha.pos_no_vetor_pessoas = end_vetor_pessoas;

    for( int contador = 0 ; contador < n ; contador++ ){
        if ((*(end_vetor_pessoas + contador)).idade > mais_velha.idade ){
            mais_velha.idade = (*(end_vetor_pessoas + contador)).idade;
            mais_velha.pos_no_vetor_pessoas = end_vetor_pessoas + contador;
        }
    }
    return mais_velha.pos_no_vetor_pessoas;
}

int main(){

	pessoa pessoas[3] = {{"Julio", 10}, {"Ana", 12}, {"Maria", 13}};
	printf("%s", ((*encontraMaisVelha(pessoas, 3)).nome));
	
	return 0;
}
