/*
Nilton Miguel Guimarães de Souza - UTFPR - 2022.1

Infelizmente essa lógica só é capaz de resolver tabuleiros de ordem 4, 5 ou 7. Ele perde muitas oportunidades de acertar por sempre posicionar rainhas no primeiro ponto seguro que encontra, ele acertaria se pulasse uma possibilidade, por exemplo. Preciso de uma lógica que primeiro posicione as rainhas e só depois verifique a segurança do tabuleiro. Assim ele vai eventualmente achar pelo menos uma resposta correta.
*/

# include <stdio.h>
# include <stdlib.h>
# define ordem 5

void atualiza_tabuleiro(int tabuleiro[ordem][ordem], int linha, int coluna, int rainha_linha, int rainha_coluna, int tarefa){

    // a tarefa 1 serve para marcar as áreas de ataque das rainhas com um algarismo 2
    if(tarefa == 1){
        if(linha <= (ordem-1) && coluna <= (ordem-1)){

            // calcula os módulos de linha e coluna, usados para reconhecer diagonais
            int mod_linha = linha - rainha_linha;
            if (mod_linha < 0)
                mod_linha *= -1;

            int mod_coluna = coluna - rainha_coluna;
            if (mod_coluna < 0)
                mod_coluna *= -1;

            // atualiza toda linha e coluna da rainha
            if((mod_linha == 0 || mod_coluna == 0) && tabuleiro[linha][coluna] == 0){
                tabuleiro[linha][coluna] = 2;
            // atualiza todas as diagonais da rainha
            }
            else if((mod_linha == mod_coluna) && mod_coluna != 0 && mod_linha != 0){
                tabuleiro[linha][coluna] = 2;
            }
            // código para percorrer todo o tabuleiro
            if(coluna < ordem-1){
                coluna++;
            }
            else{
                coluna = 0;
                linha++;
            }
            // chama a atualização da próxima célula
            atualiza_tabuleiro(tabuleiro, linha, coluna, rainha_linha, rainha_coluna, 1);
        }
    }
    // a tarefa 0 serve para zerar todo o tabuleiro, útil para quando for testar nova combinação de rainhas na função recursiva
    else if(tarefa == 0){
        if(linha <= (ordem-1) && coluna <= (ordem-1)){
            tabuleiro[linha][coluna] = 0;

            if(coluna < ordem-1){
                coluna++;
            }
            else{
                coluna = 0;
                linha++;
            }
            // chama a atualização da próxima célula
            atualiza_tabuleiro(tabuleiro, linha, coluna, 0, 0, 0);
        }
    }
    // a tarefa 2 limpa as marcações de área de ataque e deixa só as rainhas
    else if(tarefa == 2){
        if(linha <= (ordem-1) && coluna <= (ordem-1)){
            if(tabuleiro[linha][coluna] == 2){
                tabuleiro[linha][coluna] = 0;
            }

            if(coluna < ordem-1){
                coluna++;
            }
            else{
                coluna = 0;
                linha++;
            }
            // chama a atualização da próxima célula
            atualiza_tabuleiro(tabuleiro, linha, coluna, 0, 0, 2);
        }
    }
}

void resolve_tabuleiro(int tabuleiro[ordem][ordem], int linha_primeira_rainha, int linha, int coluna){

    // na primeira coluna coloque indiscretamente na linha solicitada
    if(coluna == 0){
        tabuleiro[linha_primeira_rainha][0] = 1;
        atualiza_tabuleiro(tabuleiro, 0, 0, linha_primeira_rainha, coluna, 1);
        coluna += 1;
        linha = 0;
        resolve_tabuleiro(tabuleiro, linha_primeira_rainha, linha, coluna);
    }
    // se numa coluna arbitrária a célula pedida já for 0, coloque uma rainha
    else if(tabuleiro[linha][coluna] == 0){
        tabuleiro[linha][coluna] = 1;
        atualiza_tabuleiro(tabuleiro, 0, 0, linha, coluna, 1);
        coluna += 1;
        linha = 0;
        // se for a última coluna, encerra a pilha de chamadas e a resolução foi um sucesso, caso ainda não seja a última, tenta resolver pra próxima coluna
        if(coluna < ordem){
            resolve_tabuleiro(tabuleiro, linha_primeira_rainha, linha, coluna);
        }
    }
    // se a célula for 2 mas ainda houverem linhas para baixo, desça uma linha
    else if(tabuleiro[linha][coluna] == 2 && linha < ordem - 1){
        linha += 1;
        resolve_tabuleiro(tabuleiro, linha_primeira_rainha, linha, coluna);
    }
    // se não houverem mais linhas abaixo, chame a função de novo, começando com outra linha
    else{
        linha_primeira_rainha += 1;
        atualiza_tabuleiro(tabuleiro, 0, 0, 0, 0, 0);
        // só tenta uma nova linha se ainda houverem linhas iniciais para tentar, se já esgotou as possibilidades, apenas devolve o tabuleiro zerado mesmo.
        if(linha_primeira_rainha < ordem){
            resolve_tabuleiro(tabuleiro, linha_primeira_rainha, 0, 0);
        }
    }
}

int main(void){

    int tabuleiro[ordem][ordem] = {};
    resolve_tabuleiro(tabuleiro, 0, 0, 0);
    atualiza_tabuleiro(tabuleiro, 0, 0, 0, 0, 2);

    return 0;
}   
