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

// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    while (poly1 != NULL || poly2 != NULL)
    {
        if (poly1 != NULL && (poly2 == NULL || poly1->exp > poly2->exp))
        {
            insertTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly2 != NULL && (poly1 == NULL || poly2->exp > poly1->exp))
        {
            insertTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
            {
                insertTerm(&result, sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
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

    // Add polynomials
    struct Node *result = addPolynomials(poly1, poly2);

    // Display result
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
