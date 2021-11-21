#include <stdio.h>
#include <string.h>
#define tamanho_nomes 21

typedef struct entrada_cadastro{

    char nome[tamanho_nomes];
    int idade;
    char emprego[30];
}entrada_banco;

entrada_banco cadastrar(entrada_banco ps){
	// essa validação não aceita nomes vazios (apenas o Enter "\n")
	do{
		setbuf(stdin, NULL);
		printf("Nome completo: ");
		fgets(ps.nome, tamanho_nomes, stdin);
		if (ps.nome[(int)strlen(ps.nome)-1] != '\n')
			printf("*Digite um nome com no máximo %d caracteres, por favor\n", tamanho_nomes-1);
	}while((int)strlen(ps.nome) < 2 || ps.nome[(int)strlen(ps.nome)-1] != '\n');
	
	// isso aqui pega o penúltimo caractere (se for um "\n") e troca por um "\0"
	
	if ((int)strlen(ps.nome) < tamanho_nomes-1)
		ps.nome[(int)strlen(ps.nome)-1] = '\0';

	do{
		printf("Idade: ");
		scanf("%d", &ps.idade);
		if (ps.idade <= 0 || ps.idade > 125)
			printf("*Digite uma idade válida, por favor\n");
	}while(ps.idade <= 0 || ps.idade > 125);
	
	return ps;
}

int main(){

	int teste;
	
	scanf("%d", &teste);

	entrada_banco pessoas[5];	
	pessoas[0] = cadastrar(pessoas[0]);
	printf("Nome: %s\n", pessoas[0].nome);
	printf("Idade: %d\n", pessoas[0].idade);
    
    return 0;
}
