#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char opcao;

    do
    {
        printf("\n +--------------------------------+");
        printf("\n |              MENU              |");
        printf("\n +--------------------------------+");
        printf("\n | 1 |                            |");
        printf("\n | 2 |                            |");
        printf("\n | 3 |                            |");
        printf("\n | 4 |                            |");
        printf("\n | 0 | Sair                       |");
        printf("\n +--------------------------------+");

        do
        {
            opcao = getch();
        } while (!(opcao >= '0' && opcao <= '4'));

        if (opcao == '1')
        {

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
