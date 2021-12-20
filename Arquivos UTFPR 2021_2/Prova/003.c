#include <stdio.h>

int calcNumQuadrados( int graos_exigidos ){

	int quantidade_quadrados_necessarios = 1;
	int graos_aculmulados = 1;
	int equivalente_em_graos_do_atual_quadrado = 1;

	while( graos_aculmulados<graos_exigidos ){
		quantidade_quadrados_necessarios++;
		equivalente_em_graos_do_atual_quadrado*=2;
		graos_aculmulados+=equivalente_em_graos_do_atual_quadrado;
	}

	return quantidade_quadrados_necessarios;
}

int main(){

	printf("%d quadrados", calcNumQuadrados(4));

	return 0;
}
