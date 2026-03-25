//5.Write a C program to convert a given infix expression (A+B*(C^D-E)^(F+G*H)-I) into its corresponding postfix expression (ABCD^E-FGH*+^*+I-) using a stack implemented with
// arrays#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX] = "A+B*(C^D-E)^(F+G*H)-I";
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {

        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(') {
            push(infix[i]);
        }

        else if (infix[i] == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }

        else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
