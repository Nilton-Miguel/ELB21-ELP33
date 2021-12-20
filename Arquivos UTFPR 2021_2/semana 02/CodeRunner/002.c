# include <stdio.h>

int main(){

    int X, Y;
    
    /* 
        posso escrever um scanf com 2 leituras num comando só:
        
            scanf("%d %d", &a, &b)

        poderia escrever dois scanf seguidos com uma leitura em cada:

            scanf("%d", &a)
            scanf("%d", &b)
        
        nesse último caso eu poderia usar quaisquer caracteres de espaçamento pra ir de uma leitura pra outra,
        tanto Enter, espaço, Tab, enfim, seguem exemplos de como seria no terminal:

            >a
            >b

            >a b

            >a                    b
        
        todos esses resultam em cada variável com sua respectiva leitura
    */

    scanf("%d %d", &X, &Y);
    printf("%d", X-Y);
    
    return 0;
}
