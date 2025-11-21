<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10][50], temp[50];
    int i, j, n;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
    {
        gets(str[i]);
    }

   
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}
=======
#include <stdio.h>
#include <string.h>

int main()
{
    char str[10][50], temp[50];
    int i, j, n;

    printf("Enter number of strings: ");
    scanf("%d", &n);
    getchar();

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++)
    {
        gets(str[i]);
    }

   
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    printf("\nStrings in alphabetical order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }
    return 0;
}
>>>>>>> 8b15ef0 (Assignment-6 Done)
