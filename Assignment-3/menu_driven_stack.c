<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int MAX;


int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int stack[], int value)
{
    if (isFull())
    {
        printf("\nStack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack Underflow! Cannot pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void peek(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack is empty. No top element.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    int stack[MAX];

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            if (isEmpty())
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 4:
            if (isFull())
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 5:
            peek(stack);
            break;
        case 6:
            display(stack);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>

int top = -1;
int MAX;


int isFull()
{
    return (top == MAX - 1);
}

int isEmpty()
{
    return (top == -1);
}

void push(int stack[], int value)
{
    if (isFull())
    {
        printf("\nStack Overflow! Cannot push %d\n", value);
    }
    else
    {
        stack[++top] = value;
        printf("%d pushed into stack.\n", value);
    }
}

void pop(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack Underflow! Cannot pop.\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top--]);
    }
}

void peek(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack is empty. No top element.\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}

void display(int stack[])
{
    if (isEmpty())
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("Enter the size of the stack: ");
    scanf("%d", &MAX);

    int stack[MAX];

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Peek\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(stack, value);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            if (isEmpty())
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 4:
            if (isFull())
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 5:
            peek(stack);
            break;
        case 6:
            display(stack);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
>>>>>>> 1781a33c1b10b5361a91c2198b1f9855e991af9b
