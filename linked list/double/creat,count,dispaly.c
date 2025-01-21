#include <stdio.h>
#include <stdlib.h>

// Define the doubly linked list node
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node and append it to the list
void create(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to count nodes in the list
int count(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the list
void reverse(struct Node **head)
{
    struct Node *temp = NULL, *current = *head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *head = temp->prev;
}

// Function to display the list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("1. Create\n2. Count\n3. Reverse\n4. Display\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to add: ");
            scanf("%d", &value);
            create(&head, value);
            break;
        case 2:
            printf("Number of nodes: %d\n", count(head));
            break;
        case 3:
            reverse(&head);
            printf("List reversed.\n");
            break;
        case 4:
            display(head);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
