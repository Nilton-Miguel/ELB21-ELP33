#include <stdio.h>

int main(){

	int identificador = 10;
	int *ponteiro = &identificador;

	int a = 5;
	int b = 3;
	int c = a + b ;
	
	/* 
		Os identificadores são apelidos para um endereço, 
		com '&' podemos explicitar esse endereço. Ou seja
		identificadores têm associados a si o endereço que
		apelidam, você pode descobrir o endereço com:
		&(identificador)

		Se identificadores podem ser usados para descobrir
		o endereço, por que ter um ponteiro ? Ele não é 
		redundante? Não exatamente.

		Da mesma forma como podemos passar implicitamente
		a soma de dois valores: a + b para alguma função, 
		podemos criar uma variável que receba explicitamente
		esse valor: c = a + b. O mesmo vale para ponteiros.
		Podemos passar implicitamente: %identificador ou
		explicitamente *ponteiro = &identificador.

		Temos que usar o asterisco para declarar o ponteiro:
		
		int *ponteiro = &identificador; 
		
		Por exemplo. Mas o ponteiro em si só chamamos de 
		ponteiro. Para ler o valor que está no endereço 
		guardado pelo ponteiro usamos outro asterisco:
		
		printf("%d", *ponteiro);
		printf("%d", *&identificador);
		
	*/
	
	printf("%p equivale a: ", &identificador);
	printf("%p\n", ponteiro);

	printf("%d equivale a: ", a + b);
	printf("%d\n", c);

	printf("%d equivale a: ", *&identificador);
	printf("%d\n", *ponteiro);
	
	return 0;
}
