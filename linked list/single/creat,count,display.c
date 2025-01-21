#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a linked list from user input
void create(struct Node **head)
{
    int n, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to count the number of nodes
int count(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Function to reverse the linked list
void reverse(struct Node **head)
{
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to display the linked list
void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    // Create linked list
    create(&head);

    // Display the list
    printf("Linked List: ");
    display(head);

    // Count nodes
    printf("Node Count: %d\n", count(head));

    // Reverse the list and display
    reverse(&head);
    printf("Reversed List: ");
    display(head);

    return 0;
}
