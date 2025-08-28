#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    if (top < MAX - 1)
    {
        stack[++top] = x;
    }
}

char pop()
{
    if (top != -1)
    {
        return stack[top--];
    }
    return -1;
}

char peek()
{
    if (top != -1)
    {
        return stack[top];
    }
    return -1;
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        
        else
        {
            while (top != -1 && precedence(peek()) >= precedence(ch))
            {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
