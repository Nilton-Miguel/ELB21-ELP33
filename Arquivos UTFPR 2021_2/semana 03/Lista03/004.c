# include <stdio.h>

int main(){

    int salario, emprestimo;
    scanf("%d %d", &salario, &emprestimo);

    if (emprestimo > salario*0.2){

        printf("REPROVADO");
    }
    else{

        printf("APROVADO");
    }

    return 0;
}
