#include <stdio.h>

typedef struct{
    int x,y;
}ponto;

ponto geraPonto(int x, int y){
	ponto ponto_gerado = {x, y};
	return ponto_gerado;
}

ponto somaPontos(ponto p1, ponto p2){
	ponto ponto_resultante = {p1.x + p2.x, p1.y + p2.y};
	return ponto_resultante;
}

int main(){

	ponto pontos[3];

	pontos[0] = geraPonto(2, 1);
	pontos[1] = geraPonto(-1, 5);
	pontos[2] = somaPontos(pontos[0], pontos[1]);

	printf("soma: %d %d", pontos[2].x, pontos[2].y);
	
	return 0;
}
