#include <stdio.h>

void serie_harmonica( void ){

	float somatorio = 0;
	int valor_parada;

	do{
		scanf("%d", &valor_parada);	
	}while( valor_parada <= 0 );

	for( int i=1; i<=valor_parada; i++ ){
		somatorio += (1.0/i);
	}
	printf("%.3f", somatorio);

}

int main(){

	serie_harmonica();

	return 0;
}
