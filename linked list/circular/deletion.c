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

// Function to delete node at the head
void deleteAtHead(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    if (*head == (*head)->next)
    { // Only one node
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
    }
}

// Function to delete node at the end
void deleteAtEnd(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    if (head->next == head)
    { // Only one node
        free(head);
        return;
    }
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    struct Node *last = temp->next;
    temp->next = head;
    free(last);
}

// Function to delete a node by position
void deleteByPosition(struct Node **head, int pos)
{
    if (*head == NULL || pos <= 0)
        return;
    struct Node *temp = *head;
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    for (int i = 1; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
        if (temp == *head)
            return;
    }
    if (temp == NULL || temp->next == *head)
        return;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to delete a node by value
void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    if (temp->data == value)
    {
        deleteAtHead(head);
        return;
    }
    while (temp->next != *head && temp->next->data != value)
    {
        temp = temp->next;
    }
    if (temp->next == *head)
        return; // Value not found
    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

int main()
{
    struct Node *head = NULL;
    int choice, data, pos, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(&head, n);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Delete at Head\n");
        printf("3. Delete at End\n");
        printf("4. Delete by Position\n");
        printf("5. Delete by Value\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display(head);
            break;
        case 2:
            deleteAtHead(&head);
            printf("Node deleted at head.\n");
            break;
        case 3:
            deleteAtEnd(head);
            printf("Node deleted at end.\n");
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteByPosition(&head, pos);
            printf("Node deleted at position %d.\n", pos);
            break;
        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            printf("Node with value %d deleted.\n", data);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
