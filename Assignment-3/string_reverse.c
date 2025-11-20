#include <stdio.h>
#include <string.h>
#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void push(struct Stack *s, char c) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = c;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

int main() {
    struct Stack s;
    s.top = -1;

    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    printf("Reversed string: ");
    for (int i = 0; i < len; i++) {
        printf("%c", pop(&s));
    }

    return 0;
}