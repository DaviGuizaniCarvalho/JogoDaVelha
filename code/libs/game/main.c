#include <stdlib.h>
#include <stdio.h>
#include "../bool/main.c"

#define TAM_TAB 3

typedef struct placar
{
    unsigned short int x;
    unsigned short int o;
    unsigned short int v;
} Plac;

typedef struct posicao
{
    short int x;
    short int y;
} Pos;

typedef struct tabuleiro
{
    char tabuleiro[TAM_TAB][TAM_TAB];
} Tab;

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
    
    for (int i = 0; i < TAM_TAB; i++)
        for (int j = 0; j < TAM_TAB; j++)
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
    
    if (!(pos.x >= 1 && pos.x <= TAM_TAB))
        return false;
    
    if (!(pos.y >= 1 && pos.y <= TAM_TAB))
        return false;
    
    if (tab -> tabuleiro[pos.x - 1][pos.y - 1] != ' ')
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
char acabou(Tab *tab)
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

    for (int i = 0; i < TAM_TAB; i++)
        for (int j = 0; j < TAM_TAB; j++)
            if (tab -> tabuleiro[i][j] == ' ')
                return 'N';

    return 'V';
}

/*
 * Função para mudar entre jogadores X ou O
 * 
 * param jogador: ponteiro para char (X ou O)
 * 
 * return true: se foi possivel mudar de jogador
 * return false: se não foi possivel mudar
*/
Bool mudarVez(char *jogador)
{
    jogador[0] = (jogador[0] == 'X') ? 'O': 
                 (jogador[0] == 'O') ? 'X': 'N';

    if (jogador[0] == 'N')
        return false;
    
    return true;
}

/*
 * Função para imprimir o tabuleiro do jogo
 * 
 * param tab: ponteiro para Tab
*/
Bool imprimeTabuleiro(Tab *tab)
{
    if (tab == NULL)
        return false;

    printf("\n\n     1   2   3");
    printf("\n   +---+---+---+");

    for (int i = 0; i < TAM_TAB; i++)
    {
        printf("\n %d | %c | %c | %c |", i + 1, tab -> tabuleiro[i][0], tab -> tabuleiro[i][1], tab -> tabuleiro[i][2]);
        printf("\n   +---+---+---+");
    }
    
    return true;
}

/*
 * Função para zerar o placar do jogo
 * 
 * param placar: ponteiro para Plac
 * 
 * return true: se conseguiu zerar o placar
 * return false: se não conseguiu zerar o placar
*/
Bool zerarPlacar(Plac *placar)
{
    if (placar == NULL)
        return false;
    
    placar -> x = 0;
    placar -> o = 0;
    placar -> v = 0;

    return true;
}

/*
 * Função para marcar + 1 ponto no placar
 * 
 * param placar: ponteiro para Plac
 * param jogador: qual jogador marcar o placar
*/
Bool marcarPlacar(Plac *placar, char jogador)
{
    if (placar == NULL)
        return false;
    
    if (!(jogador == 'X' || jogador == 'O' || jogador == 'V'))
        return false;
    
    if (jogador == 'X')
        placar -> x += 1;
    else if (jogador == 'O')
        placar -> o += 1;
    else
        placar -> v += 1;
    
    return true;
}

/*
 * Função para imprimir o placar
 * 
 * param placar: placar do jogo
*/
void imprimePlacar(Plac placar)
{
    printf("\n\n +-----+-----+-----+");
    printf("\n |  X  |  V  |  O  |");
    printf("\n +-----+-----+-----+");
    printf("\n | %03d | %03d | %03d |", placar.x, placar.v, placar.o);
    printf("\n +-----+-----+-----+\n");
}
