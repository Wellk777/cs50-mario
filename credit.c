#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para strtoll

// Função para obter um long long do usuário, simulando get_long
long long get_long_input(void)
{
    long long number;
    char buffer[100]; // Buffer para ler a entrada como string

    while (1)
    {
        printf("Número: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            // Remover o caractere de nova linha se presente
            buffer[strcspn(buffer, "\n")] = 0;

            // Tentar converter a string para long long
            char *endptr;
            number = strtoll(buffer, &endptr, 10);

            // Verificar se a conversão foi bem-sucedida e se a string inteira foi consumida
            if (endptr == buffer || *endptr != '\0')
            {
                // Entrada não foi um número válido, o loop continua
            }
            else
            {
                return number;
            }
        }
    }
}

// Função para calcular o número de dígitos de um long long
int count_digits(long long n)
{
    int count = 0;
    if (n == 0)
    {
        return 1;
    }
    long long temp = n;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    return count;
}

// Função para implementar o Algoritmo de Luhn
int check_luhn(long long card_number)
{
    int sum = 0;
    int count = 0;
    long long temp_card_number = card_number;

    while (temp_card_number > 0)
    {
        int digit = temp_card_number % 10;
        temp_card_number /= 10;
        count++;

        if (count % 2 == 0) // Cada segundo dígito, começando do penúltimo
        {
            digit *= 2;
            if (digit > 9)
            {
                sum += (digit % 10) + (digit / 10);
            }
            else
            {
                sum += digit;
            }
        }
        else // Dígitos que não foram multiplicados por 2
        {
            sum += digit;
        }
    }
    return (sum % 10 == 0);
}

int main(void)
{
    long long card_number = get_long_input();
    int length = count_digits(card_number);

    // Verificar o Algoritmo de Luhn
    if (!check_luhn(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Verificar o tipo de cartão com base no comprimento e dígitos iniciais
    long long first_two_digits = card_number;
    while (count_digits(first_two_digits) > 2)
    {
        first_two_digits /= 10;
    }

    long long first_digit = first_two_digits / 10;

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
