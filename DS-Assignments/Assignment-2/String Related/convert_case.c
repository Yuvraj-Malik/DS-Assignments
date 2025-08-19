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
