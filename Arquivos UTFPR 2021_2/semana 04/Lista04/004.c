# include <stdio.h>
# include <stdlib.h>

int main(){

    int n;

    do{ scanf("%d", &n); }
    while(n<0);

    printf("%d", n);
    return 0;
}
