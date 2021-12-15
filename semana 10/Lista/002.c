#include <stdio.h>

#include <stdio.h>

int validaCPF(char *end_cpf){

    int validade = 1;
    int contador = 0;

    // vou usar essa na verificação de todos os números iguais
    int caracteres_aculmulativos[11] = {};
    
    //vou usar essas nas outras checagens
    int somatorio = 0;
    int resto = 0;
    

    //=========================================================
    
    for(contador = 0 ; contador < 11 ; contador++ ){
        /*
        'n' - '0' = n
            se *(end_cpf + contador) == num, então
            caracteres_aculmulativos[num] += 1
            se x caracteres forem iguais a num
            caracteres_aculmulativos[num] == x
        */
        caracteres_aculmulativos[*(end_cpf + contador)-'0']++;
    }
    for(contador = 0 ; contador < 11 ; contador++ ){
        if (caracteres_aculmulativos[contador] == 11){
            validade = 0;
            break;
        }
    }
    
    //=========================================================
    
    for(contador=0 ; contador < 9 ; contador++ ){
        somatorio += (*(end_cpf + contador)-'0')*(10-contador);
    }
	resto = (10*somatorio)%11;

	if (!((resto == *(end_cpf + 9)-'0')||(resto-10 == *(end_cpf + 9)-'0'))){
		validade = 0;
	}
	somatorio = 0;
    
    //=========================================================
    
    for(contador=0 ; contador < 10 ; contador++ ){
           somatorio += (*(end_cpf + contador)-'0')*(11-contador);
    }
   	resto = (10*somatorio)%11;
   
   	if (!((resto == *(end_cpf + 10)-'0')||(resto-10 == *(end_cpf + 10)-'0'))){
   		validade = 0;
   	}
   	somatorio = 0;
   
    //=========================================================

    return validade;
}


int main(){

	printf("%d", validaCPF("52998224725"));

	return 0;
}
