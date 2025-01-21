#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    return 0;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void infixToPostfix(char *infix, char *postfix, int *index)
{
    if (*infix == '\0')
        return;

    if (isalnum(*infix))
    {
        postfix[*index] = *infix;
        (*index)++;
    }
    else if (*infix == '(')
    {
        infixToPostfix(infix + 1, postfix, index);
    }
    else if (*infix == ')')
    {
        while (*index > 0 && postfix[*index - 1] != '(')
            (*index)--;
    }
    else if (isOperator(*infix))
    {
        while (*index > 0 && precedence(postfix[*index - 1]) >= precedence(*infix))
        {
            (*index)--;
        }
        postfix[*index] = *infix;
        (*index)++;
    }

    infixToPostfix(infix + 1, postfix, index);
}

void infixToPrefix(char *infix, char *prefix, int *index)
{
    if (*infix == '\0')
        return;

    if (isalnum(*infix))
    {
        prefix[*index] = *infix;
        (*index)++;
    }
    else if (*infix == '(')
    {
        infixToPrefix(infix + 1, prefix, index);
    }
    else if (*infix == ')')
    {
        while (*index > 0 && prefix[*index - 1] != '(')
            (*index)--;
    }
    else if (isOperator(*infix))
    {
        while (*index > 0 && precedence(prefix[*index - 1]) >= precedence(*infix))
        {
            (*index)--;
        }
        prefix[*index] = *infix;
        (*index)++;
    }

    infixToPrefix(infix + 1, prefix, index);
}

int main()
{
    char infix[MAX], postfix[MAX], prefix[MAX];
    int index = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix, &index);
    printf("Postfix: %s\n", postfix);

    index = 0;
    infixToPrefix(infix, prefix, &index);
    printf("Prefix: %s\n", prefix);

    return 0;
}
