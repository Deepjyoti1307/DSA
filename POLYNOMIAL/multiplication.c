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
    if (*head == NULL || (*head)->exp < exp)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL && temp->next->exp > exp)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
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

// Function to multiply two polynomials
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2;

    while (temp1 != NULL)
    {
        temp2 = poly2;
        while (temp2 != NULL)
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertTerm(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return result;
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    int terms, coeff, exp;

    // Input first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly1, coeff, exp);
    }

    // Input second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly2, coeff, exp);
    }

    // Multiply polynomials
    struct Node *result = multiplyPolynomials(poly1, poly2);

    // Display result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
