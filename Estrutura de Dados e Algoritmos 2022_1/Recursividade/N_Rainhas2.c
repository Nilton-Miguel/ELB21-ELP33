# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# define ordem 3

void atualiza_tentativa(int tentativa[ordem+1], int coluna){

    tentativa[0]++;
    tentativa[coluna]++;

    if(tentativa[coluna] == ordem){
        tentativa[coluna] = 0;
        tentativa[0]--;
        atualiza_tentativa(tentativa, coluna + 1);
    }
}

void zera_tabuleiro(int tabuleiro[ordem][ordem], int linha, int coluna){

    tabuleiro[linha][coluna] = 0;
    coluna++;
    if(coluna == ordem){
        coluna = 0;
        linha++;
    }
    if(linha != ordem){
        zera_tabuleiro(tabuleiro, linha, coluna);
    }
}

void posiciona(int tabuleiro[ordem][ordem], int tentativa[ordem+1], int coluna){
    
    tabuleiro[tentativa[coluna]][coluna] = 1;
    if(coluna != ordem - 1)
        posiciona(tabuleiro, tentativa, coluna+1);
}

int main(void){

    int tentativa[ordem+1] = {};
    int tabuleiro[ordem][ordem] = {};
    posiciona(tabuleiro, tentativa, 0);

    return 0;
}
