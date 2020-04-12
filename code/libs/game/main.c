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

Tab *criarTabuleiro()
{
    return (Tab *) malloc(sizeof(Tab));
}

void limparTabuleiro(Tab *tab)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tab -> tabuleiro[i][j] = ' ';
}

Bool fazerJogada(Tab *tab, Pos pos)
{
    if (!(pos.x >= 1 && pos.x <= 3))
        return false;
}
