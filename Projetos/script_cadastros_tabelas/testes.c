#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	char texto[5];

	//o primeiro setbuf funciona, ele limpa o que tem depois de Mare
	fgets(texto, 5, stdin);
	setbuf(stdin, NULL);

	//se ele pedir pra eu digitar alguma coisa, não tem nada lá no buffer
	getchar();

	fgets(texto, 5, stdin);
	setbuf(stdin, NULL);
	setbuf(stdout, NULL);
	
	//se ele pedir pra eu digitar alguma coisa, não tem nada lá no buffer
	getchar();
	
	return 0;
}
