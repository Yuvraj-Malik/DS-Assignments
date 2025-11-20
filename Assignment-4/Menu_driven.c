#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

int isEmpty()
{
    return (front == -1 || front > rear);
}

int isFull()
{
    return (rear == MAX - 1);
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow! Nothing to delete\n");
    }
    else
    {
        printf("%d removed from queue\n", queue[front]);
        front++;
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty! No front element\n");
    }
    else
    {
        printf("Front element is: %d\n", queue[front]);
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            if (isEmpty())
                printf("Queue is Empty\n");
            else
                printf("Queue is not Empty\n");
            break;
        case 6:
            if (isFull())
                printf("Queue is Full\n");
            else
                printf("Queue is not Full\n");
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Choice! Try again.\n");
        }
    }
    return 0;
}
