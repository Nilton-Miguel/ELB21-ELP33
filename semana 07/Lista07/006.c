#include<stdio.h>
#include<string.h>

typedef struct{
    char nome[30];
    float cr;
}aluno;

int main(){
    int i;
    aluno a[5];

    //
    int pares_corretos;
    aluno backup;

    for(i=0; i<5; i++){
        setbuf(stdin, NULL);
        fgets(a[i].nome, 30, stdin);
        do{
            scanf("%f", &a[i].cr);
        }while(a[i].cr < 0 || a[i].cr > 1);
    }

    do{
        pares_corretos = 0;

        for(i=1; i<5; i++){
            if(a[i].cr > a[i-1].cr){
                backup.cr = a[i].cr;
                a[i].cr = a[i-1].cr;
                a[i-1].cr = backup.cr;
                strcpy(backup.nome, a[i].nome);
                strcpy(a[i].nome, a[i-1].nome);
                strcpy(a[i-1].nome, backup.nome);
                continue;
            }
            else{
                pares_corretos++;
            }
        }
    }while(pares_corretos != 4);
    //

    for(i=0;i<5;i++)
        printf("%s%.2f\n",a[i].nome,a[i].cr);
    return 0;
}