#include <stdio.h>

void c(int arg){
	printf("\x1b[34ma dentro da terceira função: %p\n", &arg);
}

void b(int arg){
	printf("\x1b[32ma dentro da segunda função: %p\n", &arg);
	c(arg);
	printf("\x1b[32ma dentro da segunda função: %p\n", &arg);
}

void a(int arg){
	printf("\x1b[35ma dentro da primeira função: %p\n", &arg);
	b(arg);
	printf("\x1b[35ma dentro da primeira função: %p\n", &arg);
}

int main(){

	/*
	Programa para mostrar como o mesmo identificador em 
	diferentes escopos pode se referir a diferentes
	endereços, de acordo com as pilhas de indentificador.
	*/

	int var = 10;

	printf("\x1b[31ma na main: %p\n", &var);
	a(var);
	printf("\x1b[31ma na main: %p\n", &var);

	return 0;
}
