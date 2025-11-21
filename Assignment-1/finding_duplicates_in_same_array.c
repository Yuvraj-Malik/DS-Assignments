#include <stdio.h>

int main()
{
    int n1;
    int i;
    int j;
    int k;
    int temp;

    printf("Enter how many elements you want in array: ");
    scanf("%d", &n1);

    int array[n1]; // Declaring first array and the size

    printf("Enter the elements of array: \n");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &array[i]);
    }

    

    // Traversing through array and checking for duplicates

    printf("The duplicate elements are: \n");


    for (i = 0; i < n1; i++)
    {
        for (j = i + 1; j < n1; j++)
        {
            if (array[j] == array[i])
            {
                printf("%d\n",array[i]);
                for (k = j; k < n1 - 1; k++)
                {
                    array[k] = array[k + 1];
                }
                n1--;
                j--;
            }
        }
    }

    printf("The array after deletion of duplicate values are: ");


    for(i=0; i<n1; i++)
    {
        printf("%d  ", array[i]);
    }

    return 0;
}

