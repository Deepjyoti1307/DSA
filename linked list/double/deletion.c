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
    newNode->prev = NULL;
    if (*head == NULL)
    {
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

// Function to delete at the head
void deleteAtHead(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    if (*head)
        (*head)->prev = NULL;
    free(temp);
}

// Function to delete at the end
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    if (temp->prev)
        temp->prev->next = NULL;
    else
        *head = NULL;
    free(temp);
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < position; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Position out of range.\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp == *head)
        *head = temp->next;
    free(temp);
}

// Function to delete a node with a specific value
void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value not found.\n");
        return;
    }
    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    if (temp == *head)
        *head = temp->next;
    free(temp);
}

// Function to display the list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, value, position;

    while (1)
    {
        printf("1. Create\n2. Delete at Head\n3. Delete at End\n4. Delete by Position\n5. Delete by Value\n6. Display\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to create: ");
            scanf("%d", &value);
            create(&head, value);
            break;
        case 2:
            deleteAtHead(&head);
            break;
        case 3:
            deleteAtEnd(&head);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deleteAtPosition(&head, position);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(&head, value);
            break;
        case 6:
            display(head);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
