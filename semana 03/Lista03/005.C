# include <stdio.h>

int main(){

    char caractere;
    scanf("%c", &caractere);

    if (caractere == 'z' || caractere == 'Z'){

        caractere -= 'z' - 'a';
    }
    else{

        caractere += 1;
    }

    printf("%c", caractere);

    return 0;
}
