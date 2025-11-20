<<<<<<< HEAD
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }

    printf("Lowercase character: %c\n", ch);
    return 0;
}
=======
#include <stdio.h>

int main()
{
    char ch;

    printf("Enter an uppercase character: ");
    scanf("%c", &ch);

    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + 32;
    }

    printf("Lowercase character: %c\n", ch);
    return 0;
}
>>>>>>> 1781a33c1b10b5361a91c2198b1f9855e991af9b
