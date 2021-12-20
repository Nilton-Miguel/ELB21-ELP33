#include <ctype.h>
#include <stdio.h>

void contaLetras(char *end_texto){

    int contador = 0;
    int letras[26] = {};

    while( (*(end_texto+contador)) != '\0' ){
        
        if( isalpha(*(end_texto+contador) )){
            letras[toupper(*(end_texto+contador))-'A']++;
        }
        contador++;
    }

    for(int i=0;i<26;i++){
        if (letras[i] != 0){
		    printf("%c: %d\n", 'A' + i, letras[i]);
        }
    }
}

int main(){

	char texto[30] = "Abracadabra";
	contaLetras(texto);	
	return 0;
}
