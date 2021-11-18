#include<stdio.h>

typedef struct{
    char nome[30];
    int idade;
}pessoa;

int main(){
    pessoa p[5];
    int i;

    for(i=0;i<5;i++){
        setbuf(stdin,NULL);
        fgets(p[i].nome,30,stdin);
        scanf("%d",&p[i].idade);
    }
    //
    for(i=0; i<5; i++){
        if(p[i].idade >= 18)
            printf("%s", p[i].nome);
    }
    //
    return 0;
}