# include <stdio.h>

int main(){

    int primeiro_inteiro;
    float primeiro_flutuante;
    int segundo_inteiro;
    float segundo_flutuante;

    printf("\n");

    while (1){

        printf("Digite o primeiro valor como inteiro: ");
        scanf("%d", &primeiro_inteiro);
        printf("Digite o primeiro valor como flutuante: ");
        scanf("%f", &primeiro_flutuante);
        printf("Digite o segundo valor como inteiro: ");
        scanf("%d", &segundo_inteiro);
        printf("Digite o segundo valor como flutuante: ");
        scanf("%f", &segundo_flutuante);

        // divisão entre inteiros resulta num número inteiro, logo
        // se o resultado tiver uma parte fracional, ela é descartada, só fica a inteira
        printf("\n%d / %d = %d\n", primeiro_inteiro, segundo_inteiro, primeiro_inteiro/segundo_inteiro );

        // se pelo menos um dos valores for flutuante, o valor é um flutuante
        printf("%f / %d = %f\n", primeiro_flutuante, segundo_inteiro, primeiro_flutuante/segundo_inteiro );
        printf("%d / %f = %f\n", primeiro_inteiro, segundo_flutuante, primeiro_inteiro/segundo_flutuante );
        printf("%f / %f = %f\n\n", primeiro_flutuante, segundo_flutuante, primeiro_flutuante/segundo_flutuante );

        // coisas estranhas acontecem se você formata um inteiro como um flutuante no printf, não sei explicar ainda

    }

    return 0;
}

