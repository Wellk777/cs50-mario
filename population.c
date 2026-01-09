#include <stdio.h>

int main(void)
{
    // TODO: Solicite o valor inicial ao usuário
    int start_size;
    do
    {
        printf("Start size: ");
        // Usar scanf para ler o inteiro
        if (scanf("%d", &start_size) != 1)
        {
            // Limpar o buffer de entrada se a entrada não for um número
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            start_size = 0; // Definir como 0 para forçar a repetição do loop
        }
    } while (start_size < 9);

    // TODO: Solicite o valor final ao usuário
    int end_size;
    do
    {
        printf("End size: ");
        // Usar scanf para ler o inteiro
        if (scanf("%d", &end_size) != 1)
        {
            // Limpar o buffer de entrada se a entrada não for um número
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            end_size = 0; // Definir como 0 para forçar a repetição do loop
        }
    } while (end_size < start_size);

    // TODO: Calcule o número de anos até o limite
    int years = 0;
    if (start_size == end_size)
    {
        years = 0;
    }
    else
    {
        while (start_size < end_size)
        {
            start_size = start_size + (start_size / 3) - (start_size / 4);
            years++;
        }
    }

    // TODO: Imprima o número de anos
    printf("Years: %d\n", years);

    return 0;
}
