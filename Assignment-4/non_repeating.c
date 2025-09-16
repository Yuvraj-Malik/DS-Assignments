#include <stdio.h>
#include <string.h>
#define MAX 256

char queue[MAX];
int front = 0, rear = 0;

int isEmpty()
{
    return (front == rear);
}

void enqueue(char c)
{
    queue[rear] = c;
    rear = (rear + 1) % MAX;
}

void dequeue()
{
    if (!isEmpty())
        front = (front + 1) % MAX;
}

int main()
{
    char str[100];
    printf("Enter characters (space separated): ");
    fgets(str, sizeof(str), stdin);

    int freq[256] = {0};
    int len = strlen(str);

    front = rear = 0;

    for (int i = 0; i < len; i++)
    {
        char ch = str[i];
        if (ch == ' ' || ch == '\n')
            continue;

        freq[(int)ch]++;
        enqueue(ch);

        while (!isEmpty() && freq[(int)queue[front]] > 1)
        {
            dequeue();
        }

        if (isEmpty())
            printf("-1 ");
        else
            printf("%c ", queue[front]);
    }

    return 0;
}
