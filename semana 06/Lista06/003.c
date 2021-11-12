# include <stdio.h>
# include <stdlib.h>

int main(){

    int cont;
    char str[50];
    fgets(str, 50, stdin);
    
    for(cont=0; cont<50; cont++){
        if(str[cont]=='\n')
            break;
        else if(str[cont]>='0' && str[cont]<='9')
            printf("'%c': Digito %d\n", str[cont], str[cont]-'0' );
        else if(str[cont]>='a' && str[cont]<='z')
            printf("'%c': Letra %d\n", str[cont], str[cont]-'a'+1);
        else if(str[cont]>='A' && str[cont]<='Z')
            printf("'%c': Letra %d\n", str[cont], str[cont]-'A'+1);
        else 
            printf("'%c': Nao alfanumerico\n", str[cont]);
    }
    return 0;
}