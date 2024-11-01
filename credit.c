#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long creditCardNumber;
    do
    {
        creditCardNumber = get_long("Enter your credit card number: ");
    }
    while (creditCardNumber <= 0);

    //list of variables
    long newCardNumber;
    int sum = 0;
    int count = 0;
    long divisor = 10;

    //storing creditCardNumber in a new variable because it's going to be modified alot.
    newCardNumber = creditCardNumber;

    //checksum 1: adds the last digits and every other number of the credit card number.
    while (newCardNumber > 0)
    {
        int lastDigit = newCardNumber % 10;
        sum = sum + lastDigit;
        newCardNumber = newCardNumber / 100;
    }

    //checksum 2: multiplies the second to the last digits and every other number, and adds them together.
    newCardNumber = creditCardNumber / 10;
    while (newCardNumber > 0)
    {
        int lastDigit = newCardNumber % 10;
        //incase of double digits, adds them togther.
        int doubleDigits = lastDigit * 2;
        sum = sum + (doubleDigits % 10) + (doubleDigits / 10);
        newCardNumber = newCardNumber / 100;
    }

    //determines the number of digits in the credit card number.
    newCardNumber = creditCardNumber;
    while (newCardNumber != 0)
    {
        newCardNumber = newCardNumber / 10;
        count++;
    }

    //determines the first digits and the first two digits
    newCardNumber = creditCardNumber;
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstDigit = newCardNumber / divisor;
    int firstTwoDigits = newCardNumber / (divisor / 10);

    //prints the type of credit card.
    if (sum % 10 == 0)
    {
        if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else if ((firstTwoDigits  == 34 || firstTwoDigits == 37) && count == 15)
        {
            printf("AMEX\n");
        }
        else if ((50 < firstTwoDigits && firstTwoDigits < 56) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}