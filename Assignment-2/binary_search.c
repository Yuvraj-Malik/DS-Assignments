#include <stdio.h>

int main()
{
    int n1;
    int i;
    int mid;
    int searching_element;
    int position = -1;

    printf("Enter the elements you want in array: ");
    scanf("%d", &n1);

    int array[n1];

    printf("Enter the elements of array in a sorted way: \n");

    for (i = 0; i < n1; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Which element you would like to find: ");
    scanf("%d",&searching_element);

    int first = 0;
    int last = n1 - 1;

    while (first <= last)
    {

        mid = (first + last) / 2;

        if (array[mid] == searching_element)
        {
            printf("Element %d found at position: %d",searching_element,mid + 1);
            position = mid;
            break;
        }

        else if(array[mid] > searching_element) {
            last = mid-1;
        }

        else {
            first = mid+1;
        }
    }

    if (position == -1)
    {
        printf("Element %d not found!",searching_element);
    }

    return 0;
}