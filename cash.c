#include <stdio.h>
#include <math.h>

int main(void)
{
    float troco_float;
    int centavos;
    int moedas = 0;

    // Solicitar ao usuário o valor do troco até que seja um valor não negativo
    do
    {
        printf("Troca devida: ");
        // Usar scanf para ler o float
        if (scanf("%f", &troco_float) != 1)
        {
            // Limpar o buffer de entrada se a entrada não for um número
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            troco_float = -1.0; // Definir como negativo para forçar a repetição do loop
        }
    } while (troco_float < 0);

    // Converter o valor em centavos e arredondar para evitar imprecisão de ponto flutuante
    centavos = round(troco_float * 100);

    // Algoritmo guloso para calcular o número mínimo de moedas

    // Moedas de 25 centavos
    moedas += centavos / 25;
    centavos %= 25;

    // Moedas de 10 centavos
    moedas += centavos / 10;
    centavos %= 10;

    // Moedas de 5 centavos
    moedas += centavos / 5;
    centavos %= 5;

    // Moedas de 1 centavo
    moedas += centavos / 1;

    // Imprimir o número total de moedas
    printf("%d\n", moedas);

    return 0;
}
