# include <stdio.h>
# include <stdlib.h>

int main(){

    float media = 0;
    float matriz[10];
    int contador;

    for (contador=0; contador<10; contador++){
        scanf("%f", &matriz[contador]);
        media += matriz[contador];
    }
    media/=10;
    printf("Media = %.2f\nAbaixo da media:\n", media);
    for (contador=0; contador<10; contador++){
        if (matriz[contador] < media){
            printf("%.1f\n", matriz[contador]);
        }
    }

    return 0;
}
