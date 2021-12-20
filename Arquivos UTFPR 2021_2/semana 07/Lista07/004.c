#include<stdio.h>
#include<stdlib.h>

struct horario{
    int h,m,s;
};

int main(){
    int seg;
    struct horario hms;
    //
    do{
        scanf("%d", &seg);
    }while(seg<0);

    hms.h = seg/3600;
    hms.m = (seg - hms.h * 3600)/60;
    hms.s = (seg - hms.h*3600 - hms.m*60);
    //
    printf("Valor digitado: %d segundos\n",seg);
    printf("Valor convertido: %d horas %d minutos e %d segundos\n",hms.h ,hms.m, hms.s);

    return 0;
}