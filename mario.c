#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int altura;

    // Solicitar ao usuário a altura da pirâmide
    do
    {
        printf("Tamanho: ");
        scanf("%d", &altura);

        // Limpar o buffer de entrada em caso de entrada inválida
        if (altura < 1 || altura > 8)
        {
            // Limpar o buffer se houver caracteres não numéricos
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (altura < 1 || altura > 8);

    // Imprimir a pirâmide
    for (int i = 1; i <= altura; i++)
    {
        // Imprimir espaços
        for (int j = 0; j < altura - i; j++)
        {
            printf(" ");
        }

        // Imprimir hashes
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Quebra de linha
        printf("\n");
    }

    return 0;
}
