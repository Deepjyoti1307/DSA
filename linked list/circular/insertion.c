#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to create a circular linked list
void create(struct Node **head, int n)
{
    struct Node *newNode, *temp;
    int data, i;

    if (n <= 0)
        return;

    *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &(*head)->data);
    (*head)->next = *head; // Points to itself

    temp = *head;
    for (i = 2; i <= n; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);
        newNode->next = *head; // Points to head to form a circular link
        temp->next = newNode;
        temp = newNode;
    }
}

// Function to display the circular linked list
void display(struct Node *head)
{
    if (!head)
        return;
    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Function to insert a node at the head
void insertAtHead(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (!*head)
    {
        newNode->next = newNode; // Points to itself if list is empty
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to insert a node after a given node
void insertAfter(struct Node *head, int target, int data)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
        if (temp == head)
            break;
    }
    printf("Node with data %d not found!\n", target);
}

// Function to insert a node before a given node
void insertBefore(struct Node **head, int target, int data)
{
    if (*head == NULL)
        return;

    struct Node *temp = *head;
    if (temp->data == target)
    {
        insertAtHead(head, data); // Insert at head if target is head
        return;
    }

    while (temp->next != *head && temp->next->data != target)
    {
        temp = temp->next;
    }
    if (temp->next == *head)
    {
        printf("Node with data %d not found!\n", target);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node *head, int data)
{
    if (!head)
        return;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

int main()
{
    struct Node *head = NULL;
    int choice, data, target, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(&head, n);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Head\n");
        printf("3. Insert After\n");
        printf("4. Insert Before\n");
        printf("5. Insert at End\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            printf("Enter data to insert at head: ");
            scanf("%d", &data);
            insertAtHead(&head, data);
            break;
        case 3:
            printf("Enter target data and data to insert after: ");
            scanf("%d %d", &target, &data);
            insertAfter(head, target, data);
            break;
        case 4:
            printf("Enter target data and data to insert before: ");
            scanf("%d %d", &target, &data);
            insertBefore(&head, target, data);
            break;
        case 5:
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            insertAtEnd(head, data);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
