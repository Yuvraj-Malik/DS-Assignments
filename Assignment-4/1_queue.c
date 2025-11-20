#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int data[MAX];
    int front, rear;
} Queue;

void init(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return (q->front > q->rear);
}

void enqueue(Queue *q, int x)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->data[q->front++];
}

typedef struct
{
    Queue q;
} Stack;

void initStack(Stack *s)
{
    init(&s->q);
}

void push(Stack *s, int x)
{
    enqueue(&s->q, x);
    int size = s->q.rear - s->q.front;
    for (int i = 0; i < size; i++)
    {
        enqueue(&s->q, dequeue(&s->q));
    }
    printf("%d pushed onto stack\n", x);
}

int pop(Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return dequeue(&s->q);
}

int peek(Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is Empty!\n");
        return -1;
    }
    return s->q.data[s->q.front];
}

void display(Stack *s)
{
    if (isEmpty(&s->q))
    {
        printf("Stack is Empty!\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = s->q.front; i <= s->q.rear; i++)
    {
        printf("%d ", s->q.data[i]);
    }
    printf("\n");
}

int main()
{
    Stack s;
    initStack(&s);

    int choice, value;
    while (1)
    {
        printf("\n--- Stack using One Queue ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;
        case 2:
            value = pop(&s);
            if (value != -1)
                printf("Popped: %d\n", value);
            break;
        case 3:
            value = peek(&s);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;
        case 4:
            display(&s);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
