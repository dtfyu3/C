#include <cs50.h>
#include <stdio.h>

int check_luhn(long number);
int main(void)
{
    long number;
    number = get_long("Number: ");
    int res = check_luhn(number);
    switch (res)
    {
        case 0:
            printf("INVALID\n");
            break;
        case 1:
            printf("AMEX\n");
            break;
        case 2:
            printf("MASTERCARD\n");
            break;
        case 3:
            printf("VISA\n");
            break;
        default:
            break;
    }
}

int check_luhn(long number)
{
    int sum = 0;
    long n;
    int parity = number % 2;
    n = number;
    int counter = 0;
    int len = 0;
    int array[2];
    do
    {
        n /= 10;
        len++;
    }
    while (n > 9);
    n = number;
    int digit;
    int i = 1;
    do
    {
        digit = n % 10;
        if (counter > (len - 2))
        {
            array[i--] = digit;
        }

        if (counter % 2 == 1)
        {
            digit = digit * 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
        counter++;
        n /= 10;
    }
    while (n > 0);
    if ((sum % 10) == 0)
    {
        if (len < 12 || len > 15)
            return 0;
        if (len == 14 && (array[0] == 3 && (array[1] == 4 || array[1] == 7))) // AE
            return 1;
        else if (array[0] == 5 && (array[1] == 1 || array[1] == 2 || array[1] == 3 ||
                                   array[1] == 4 || array[1] == 5))
            return 2; // MC
        else if (array[0] == 4 && (len == 15 || len == 12))
            return 3; // Visa
        else
            return 0;
    }
    else
        return 0;
}
