# include <stdio.h>

int main(){

    int numero;
    scanf("%d", &numero);

    switch(numero){

        case 0:
            printf("ZERO");
            break;
        case 1:
            printf("UM");
            break;
        case 2:
            printf("DOIS");
            break;
        case 3:
            printf("TRES");
            break;
        case 4:
            printf("QUATRO");
            break;
        case 5:
            printf("CINCO");
            break;
        case 6:
            printf("SEIS");
            break;
        case 7:
            printf("SETE");
            break;
        case 8:
            printf("OITO");
            break;
        case 9:
            printf("NOVE");
            break;
        default:
            printf("INVALIDO");
    }

    return 0;
}
