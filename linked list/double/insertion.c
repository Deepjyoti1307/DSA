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

// Function to insert at the head
void insertAtHead(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert after a given node
void insertAfter(struct Node *head, int prevValue, int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != prevValue)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", prevValue);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to insert before a given node
void insertBefore(struct Node **head, int nextValue, int value)
{
    struct Node *temp = *head;
    while (temp != NULL && temp->data != nextValue)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", nextValue);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev)
        temp->prev->next = newNode;
    else
        *head = newNode;
    temp->prev = newNode;
}

// Function to insert at the end
void insertAtEnd(struct Node **head, int value)
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
    int choice, value, refValue;

    while (1)
    {
        printf("1. Create\n2. Insert at Head\n3. Insert After\n4. Insert Before\n5. Insert at End\n6. Display\n7. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to create: ");
            scanf("%d", &value);
            create(&head, value);
            break;
        case 2:
            printf("Enter value to insert at head: ");
            scanf("%d", &value);
            insertAtHead(&head, value);
            break;
        case 3:
            printf("Enter value to insert after: ");
            scanf("%d", &refValue);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAfter(head, refValue, value);
            break;
        case 4:
            printf("Enter value to insert before: ");
            scanf("%d", &refValue);
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertBefore(&head, refValue, value);
            break;
        case 5:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
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
