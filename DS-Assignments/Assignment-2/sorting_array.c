#include <stdio.h>

int main()
{
    int array[50];
    int number;
    int i;
    int j;
    int temp;

    printf("Enter how many elements you would like in the array: ");
    scanf("%d", &number);

    // int array[number];

    printf("Enter the elements: \n");
    for (i = 0; i < number; i++)
    {
        scanf("%d", &array[i]);
    }

    for (i = 0; i < number-1; i++)
    {
        for (j = 0; j < number - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("The sorted array is:   ");

    for (i = 0; i < number; i++)
    {
        printf("%d  ", array[i]);
    }
    return 0;
}
