#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int luhn = 0;

    // Prompt user for credit card number
    long cc = get_long("Number: ");

    // For every other digit starting with second to last
    for (long i = 10; i < cc; i *= 100)
    {
        long digit1 = cc;
        digit1 /= i;
        digit1 %= 10;
        digit1 *= 2;

        // If the result is not one-digit, calculate the sum of the digits
        while (digit1 > 9)
        {
            int b = digit1 % 10;
            digit1 /= 10;
            digit1 += b;
        }
        luhn += digit1;
    }

    // For every other digit starting with last
    for (long y = 1; y < cc; y *= 100)
    {
        long digit2 = cc;
        digit2 /= y;
        digit2 %= 10;

        luhn += digit2;
    }

    // Test for validness
    if (luhn % 10 != 0)
    {
        printf("INVALID\n");
    }

    // Test for AMEX
    else if (cc / 10000000000000 == 34 || cc / 10000000000000 == 37)
    {
        printf("AMEX\n");
    }

    // Test for MASTERCARD
    else if (cc / 100000000000000 > 50 && cc / 100000000000000 < 56)
    {
        printf("MASTERCARD\n");
    }

    // Test for 16-digit VISA
    else if (cc / 1000000000000000 == 4)
    {
        printf("VISA\n");
    }

    // Test for 13-digit VISA
    else if (cc / 1000000000000 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
