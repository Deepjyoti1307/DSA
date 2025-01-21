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

// Function to count nodes in the circular linked list
int count(struct Node *head)
{
    if (!head)
        return 0;
    int count = 1;
    struct Node *temp = head->next;
    while (temp != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display circular linked list
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

// Function to reverse a circular linked list
void reverse(struct Node **head)
{
    if (!*head || (*head)->next == *head)
        return; // Empty or single-node list

    struct Node *prev = NULL, *current = *head, *next = NULL;
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != *head);

    (*head)->next = prev; // Update head's next
    *head = prev;         // Update head
}

int main()
{
    struct Node *head = NULL;
    int choice, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    create(&head, n);

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Count Nodes\n");
        printf("2. Display List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Node count: %d\n", count(head));
            break;
        case 2:
            display(head);
            break;
        case 3:
            reverse(&head);
            printf("List reversed.\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
