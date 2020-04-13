#include <stdio.h>
#include <conio.h>
#include "./libs/game/main.c"

#define limparTela() system("cls")

int main(int argc, char const *argv[])
{
    char opcao, vez, quem_ganhou;
    int jogos = 0;
    Tab tabuleiro;
    Pos pos;
    Plac placar;

    zerarPlacar(&placar);

    do
    {
        printf("\n +--------------------------------+");
        printf("\n |              MENU              |");
        printf("\n +---+----------------------------+");
        printf("\n | 1 | Jogar                      |");
        printf("\n | 2 | Exibir Placar              |");
        printf("\n | 3 | Zerar Placar               |");
        printf("\n | 0 | Sair                       |");
        printf("\n +---+----------------------------+");

        do
        {
            opcao = getch();
        } while (!(opcao >= '0' && opcao <= '4'));

        limparTela();

        if (opcao == '1')
        {
            limparTabuleiro(&tabuleiro);
            
            if (jogos % 2 == 0)
                vez = 'X';
            else
                vez = 'O';
            
            do
            {
                imprimeTabuleiro(&tabuleiro);

                printf("\n\n jogador %c sua vez.\n\n  Linha: ", vez);
                pos.x = getche() - 48;
                printf("\n Coluna: ");
                pos.y = getche() - 48;

                limparTela();

                if (!fazerJogada(&tabuleiro, pos, vez))
                    continue;

                mudarVez(&vez);

                quem_ganhou = acabou(&tabuleiro);
            } while (quem_ganhou == 'N');

            marcarPlacar(&placar, quem_ganhou);

            printf("\n   Fim de Jogo!");
            imprimeTabuleiro(&tabuleiro);
            imprimePlacar(placar);

            jogos += 1;
        }

        else if (opcao == '2')
        {
            imprimePlacar(placar);
        }

        else if (opcao == '3')
        {
            zerarPlacar(&placar);
            imprimePlacar(placar);
        }

    } while (opcao != '0');

    return 0;
}
