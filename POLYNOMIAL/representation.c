#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in the polynomial
void insertTerm(struct Node **head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);
    newNode->next = *head;
    *head = newNode;
}

// Function to display the polynomial
void displayPolynomial(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->coeff > 0 && temp != head)
            printf("+ ");
        printf("%dx^%d ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *polynomial = NULL;
    int terms, coeff, exp;

    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &terms);

    for (int i = 0; i < terms; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&polynomial, coeff, exp);
    }

    printf("Polynomial: ");
    displayPolynomial(polynomial);

    return 0;
}
