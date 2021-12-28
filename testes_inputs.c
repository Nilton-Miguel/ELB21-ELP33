#include <stdio.h>
#include <string.h>

/*
	Essa função foi projetada para recolher caracteres do buffer de entrada, um a um.

	A princípio achei que isso poderia prevenir os meus problemas com buffer de entrada,porém,
não funcionou como esperado. Enquanto o usuário tiver total liberdade para digitar o que quiser,
tudo que ele digitar vai parar de algum jeito no buffer e vai ser eventualmente lido, realmente 
é preciso achar uma forma de limpar esses buffers, mas ainda não sei como.
*/

void receber_string(char* endereco_primeira_letra, int comprimento_string){

	for(int i=0; i<comprimento_string-1; i++){
		*(endereco_primeira_letra + i) = getchar();
		if(*(endereco_primeira_letra + i) == '\n'){
			break;
			*(endereco_primeira_letra + i +1) = '\0';
		}
	}
}

int main(){

	char texto1[6];
	char texto2[6];
	
	receber_string(texto1, 6);
	puts(texto1);
	receber_string(texto2, 6);
	puts(texto2);

	return 0;
}
