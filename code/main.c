#include <stdio.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    char opcao;

    do
    {
        printf("+--------------------------------");
        printf("|              MENU              ");
        printf("+--------------------------------");
        printf("| 1 |                            ");
        printf("| 2 |                            ");
        printf("| 3 |                            ");
        printf("| 4 |                            ");
        printf("| 0 | Sair                       ");
        printf("+--------------------------------");

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
