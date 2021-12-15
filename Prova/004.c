#include <stdio.h>
#include <ctype.h>

char desloca_ciclicamente( char original, int deslocamento ){

	char transformado = original + deslocamento;

	if( islower(original) && !islower(transformado) ){
		if( deslocamento > 0){
			transformado -= 26;
		}
		else{
			transformado += 26;
		}
	}
	
	if( isupper(original) && !isupper(transformado) ){
			if( deslocamento > 0){
				transformado -= 26;
			}
			else{
				transformado += 26;
			}
		}
	return transformado;
}

/*
void confab( char *end_texto_entrada, int deslocamento_cifra, char *end_texto_saida ){

	int distancia_percorrida_na_memoria = 0;

	while(1){

		if(!(isalpha(end_texto_entrada[distancia_percorrida_na_memoria]))){
			end_texto_saida[distancia_percorrida_na_memoria] = end_texto_entrada[distancia_percorrida_na_memoria];
			distancia_percorrida_na_memoria++;
			continue;
		}
	
		end_texto_saida[distancia_percorrida_na_memoria] = 
		desloca_ciclicamente( end_texto_entrada[distancia_percorrida_na_memoria], deslocamento_cifra );
		distancia_percorrida_na_memoria++;

		if(end_texto_entrada[distancia_percorrida_na_memoria] == 0){
			end_texto_saida[distancia_percorrida_na_memoria] = 0;
			break;
		}
	}
}
*/

int main(){

	/*
	char out_texto[60];
	char in_texto[60] = "u";
	confab(in_texto, 26, out_texto);
	printf("%s", out_texto);
	*/
	for (int i = -1000; i<1000; i++){
		//for (int c='a'; c<='z'; c++){
		//	printf("%c", desloca_ciclicamente(c, i));	
		//}
		printf("%c", i);
	}
	return 0;
}
