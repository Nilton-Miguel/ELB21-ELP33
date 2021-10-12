# include <stdio.h>

int main(){

    int vitorias, empates;

    scanf("%d %d", &vitorias, &empates);
    printf("Pontuacao: %d", vitorias*3 + empates);

    return 0;
}
