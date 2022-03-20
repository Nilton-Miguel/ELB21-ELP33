/*
UTFPR 17/03/2022

Esse software foi criado para avaliar tolerências num caso bastante isolado, a replicabilidade é bem baixa fora das condições do exercício específico para o qual foi escrito. Está excessivamente documentado para fins didáticos.
*/

# include <math.h>
# include <stdio.h>
# include <stdlib.h>

float calcula_tolerancia(float valor_medido){

    // como nesse exercício só foram medidos resistores com valores iguais às potências de 10, eu considerei apenas potências de 10 com 30% de margem para auto classificação (em grupos de valor nominal) dos resistores.

    double potencia_de_10 = 0;

    float tolerancia;
    float valor_medido_margem_de_erro_floor;
    float valor_medido_margem_de_erro_roof;

    int valor_nominal;

    // o valor medido pode estar numa faixa de 30% acima ou abaixo de alguma potência de 10.

    valor_medido_margem_de_erro_floor = 0.6 * pow(10, potencia_de_10);
    valor_medido_margem_de_erro_roof = 1.4 * pow(10, potencia_de_10);

    // agora vamos testar para todas as faixas de 30% acima e abaixo de potências de 10 até acharmos a correta. Enquanto não acontecer de o valor medido estar dentro da faixa, continuar procurando outra potência de 10

    while (!(valor_medido <= valor_medido_margem_de_erro_roof) && valor_medido > valor_medido_margem_de_erro_floor){

        // se o valor medido não está dentro dessa faixa, vamos olhar na faixa da próxima potência de 10.
        potencia_de_10++;
        valor_medido_margem_de_erro_floor = 0.6 * pow(10, potencia_de_10);
        valor_medido_margem_de_erro_roof = 1.4 * pow(10, potencia_de_10);
    }

    // os valores nominais nesse exercício são todos potências de 10, só precisamos achar o expoente.
    valor_nominal = pow(10, potencia_de_10);
    // fórmula da tolerância de acordo com o exercício.
    tolerancia = (1 - valor_medido/valor_nominal) * 100;

    return tolerancia;
}

int main(){

    do {
        float input;
        printf("valor_medido(no máximo 40%% de erro): ");
        scanf("%f", &input);
        printf("tolerancia: %.1f%\n", calcula_tolerancia(input));
    }while(1);

    return 0;
}
