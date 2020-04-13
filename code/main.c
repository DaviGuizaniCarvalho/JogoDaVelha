#include <stdio.h>
#include <conio.h>
#include "./libs/game/main.c"

int main(int argc, char const *argv[])
{
    char opcao, vez, posXY[2], terminou;
    int jogos = 0;
    Tab *tabuleiro = criarTabuleiro();
    Pos pos;

    if (tabuleiro == NULL)
        return 1;

    do
    {
        printf("\n +--------------------------------+");
        printf("\n |              MENU              |");
        printf("\n +---+----------------------------+");
        printf("\n | 1 | Jogar                      |");
        printf("\n | 2 |                            |");
        printf("\n | 3 |                            |");
        printf("\n | 4 |                            |");
        printf("\n | 0 | Sair                       |");
        printf("\n +---+----------------------------+");

        do
        {
            opcao = getch();
        } while (!(opcao >= '0' && opcao <= '4'));

        if (opcao == '1')
        {
            limparTabuleiro(tabuleiro);
            
            if (jogos % 2 == 0)
                vez = 'X';
            else
                vez = 'O';
            
            do
            {
                imprimeTabuleiro(tabuleiro);

                printf("\n jogador %c sua vez.\n\n posX: ", vez);
                scanf(" %[^\n]s", posXY);
                pos.x = atoi(posXY);

                printf(" posY: ");
                scanf(" %[^\n]s", posXY);
                pos.y = atoi(posXY);

                if (!fazerJogada(tabuleiro, pos, vez))
                    continue;

                mudarVez(&vez);

                terminou = acabou(tabuleiro);
            } while (terminou == 'N');
        }

        else if (opcao == '2')
        {

        }

        else if (opcao == '3')
        {

        }

        else if (opcao == '4')
        {

        }

    } while (opcao != '0');

    return 0;
}
