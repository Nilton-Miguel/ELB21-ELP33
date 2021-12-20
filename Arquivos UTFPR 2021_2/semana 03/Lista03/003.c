# include <stdio.h>

int main(){

    int numero;
    scanf("%d", &numero);

    if (numero % 2 == 1){

        printf("%d", numero*numero*numero);
    }
    else{

        printf("%d", numero*numero);
    }

    return 0;
}
