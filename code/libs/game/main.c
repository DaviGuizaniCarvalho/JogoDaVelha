#include <stdlib.h>
#include "../bool/main.c"

typedef struct posicao
{
    int x;
    int y;
} Pos;

typedef struct tabuleiro
{
    char tabuleiro[3][3];
} Tab;

/*
 * Função para criar um novo tabuleiro
 * 
 * return Tab *: se conseguiu criar o tabuleiro
 * return NULL: se não conseguiu criar o tabuleiro
*/
Tab *criarTabuleiro()
{
    return (Tab *) malloc(sizeof(Tab));
}

/*
 * Função para colocar todas as casas do tabuleiro como espaço vazio
 * 
 * param tab: ponteiro para Tab
 * 
 * return true: se conseguiu preencher
 * return false: se não conseguiu preencher
*/
Bool limparTabuleiro(Tab *tab)
{
    if (tab == NULL)
        return false;
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tab -> tabuleiro[i][j] = ' ';
    
    return true;
}

/*
 * Função para jogar X ou O no tabuleiro
 * 
 * param tab: ponteiro para Tab
 * param pos: posicao a ser jogada
 * param jogador: jogador da vez, X = 1, O = 2
 * 
 * return true: se conseguiu preencher a posição
 * return false: se não conseguiu preencher a posição
*/
Bool fazerJogada(Tab *tab, Pos pos, char jogador)
{
    if (tab == NULL)
        return false;

    if (!(jogador == 'X' || jogador == 'x' || jogador == 'O' || jogador == 'o'))
        return false;
    
    if (!(pos.x >= 1 && pos.x <= 3))
        return false;
    
    if (!(pos.y >= 1 && pos.y <= 3))
        return false;
    
    if (tab -> tabuleiro[pos.x - 1][pos.y - 1] == ' ')
        return false;
    
    tab -> tabuleiro[pos.x - 1][pos.y - 1] = (jogador == 'X' || jogador == 'x') ? 'X' : 'O';
    
    return true;
}

/*
 * Função para verificar se o jogo terminou
 * 
 * param tab: ponteiro para Tab
 * 
 * return N: se não acabou
 * return X: se jogador X venceu
 * return O: se jogador O venceu
 * return V: se empatou
*/
char ababou(Tab *tab)
{
    if (tab == NULL)
        return 'N';
    
    if ((tab -> tabuleiro[0][0] == 'X' && tab -> tabuleiro[0][1] == 'X' && tab -> tabuleiro[0][2] == 'X') ||
        (tab -> tabuleiro[1][0] == 'X' && tab -> tabuleiro[1][1] == 'X' && tab -> tabuleiro[1][2] == 'X') ||
        (tab -> tabuleiro[2][0] == 'X' && tab -> tabuleiro[2][1] == 'X' && tab -> tabuleiro[2][2] == 'X') ||
        (tab -> tabuleiro[0][0] == 'X' && tab -> tabuleiro[1][0] == 'X' && tab -> tabuleiro[2][0] == 'X') ||
        (tab -> tabuleiro[0][1] == 'X' && tab -> tabuleiro[1][1] == 'X' && tab -> tabuleiro[2][1] == 'X') ||
        (tab -> tabuleiro[0][2] == 'X' && tab -> tabuleiro[1][2] == 'X' && tab -> tabuleiro[2][2] == 'X') ||
        (tab -> tabuleiro[0][0] == 'X' && tab -> tabuleiro[1][1] == 'X' && tab -> tabuleiro[2][2] == 'X') ||
        (tab -> tabuleiro[0][2] == 'X' && tab -> tabuleiro[1][1] == 'X' && tab -> tabuleiro[2][0] == 'X'))
            return 'X';
    
    if ((tab -> tabuleiro[0][0] == 'O' && tab -> tabuleiro[0][1] == 'O' && tab -> tabuleiro[0][2] == 'O') ||
        (tab -> tabuleiro[1][0] == 'O' && tab -> tabuleiro[1][1] == 'O' && tab -> tabuleiro[1][2] == 'O') ||
        (tab -> tabuleiro[2][0] == 'O' && tab -> tabuleiro[2][1] == 'O' && tab -> tabuleiro[2][2] == 'O') ||
        (tab -> tabuleiro[0][0] == 'O' && tab -> tabuleiro[1][0] == 'O' && tab -> tabuleiro[2][0] == 'O') ||
        (tab -> tabuleiro[0][1] == 'O' && tab -> tabuleiro[1][1] == 'O' && tab -> tabuleiro[2][1] == 'O') ||
        (tab -> tabuleiro[0][2] == 'O' && tab -> tabuleiro[1][2] == 'O' && tab -> tabuleiro[2][2] == 'O') ||
        (tab -> tabuleiro[0][0] == 'O' && tab -> tabuleiro[1][1] == 'O' && tab -> tabuleiro[2][2] == 'O') ||
        (tab -> tabuleiro[0][2] == 'O' && tab -> tabuleiro[1][1] == 'O' && tab -> tabuleiro[2][0] == 'O'))
            return 'O';

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tab -> tabuleiro[i][j] == ' ')
                return 'N';

    return 'V';
}
