# include <stdio.h>
# include <stdlib.h>

int main(){

    int menor_momentaneo = 0;
    int entrada_do_usuario;

    /* 
        Menor_momentaneo começa como zero, já que quando 0 aparecer como input vai ser um encerramento 
        e não um valor a ser computado.

        O valor de "menor_momentaneo" só será atualizado se:
            ele ainda for zero (logo, o primeiro input vai ser automaticamente o menor)
                OU
            o input recente for menor que o que está salvo na variável
                E   (em conjunção com as duas últimas)
            a entrada do usuário não for 0 (isso garante que 0 não vai entrar como menor antes do fim do laço)
    */
    do{

        scanf("%d", &entrada_do_usuario);

        if ((menor_momentaneo == 0 || entrada_do_usuario < menor_momentaneo) && entrada_do_usuario != 0)
            menor_momentaneo = entrada_do_usuario;
    }
    while(entrada_do_usuario != 0);

    if (menor_momentaneo != 0)
        printf("Menor = %d\n", menor_momentaneo);

    return 0;
}
