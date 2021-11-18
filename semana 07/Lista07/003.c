#include<stdio.h>

typedef struct{
    int x,y;
}ponto;

ponto pontos[2];
ponto p = {0, 0};
int i;

int main(){

    for (i=0; i<2; i++){
        scanf("%d", &pontos[i].x);
        p.x += pontos[i].x;
        scanf("%d", &pontos[i].y);
        p.y += pontos[i].y;
    }
    printf("%d %d\n", p.x, p.y);
    return 0;
}