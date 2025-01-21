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

// Function to delete a node at the head
void deleteAtHead(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node at the end
void deleteAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;
    while (temp->next && temp->next->next)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a given position
void deleteByPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Position not valid.\n");
        return;
    }

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Function to delete a node by its value
void deleteByValue(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = *head;
    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        printf("Value not found.\n");
        return;
    }

    struct Node *toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Function to display the linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

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

    // Delete at head
    deleteAtHead(&head);
    printf("After deleting at head: ");
    display(head);

    // Delete at end
    deleteAtEnd(&head);
    printf("After deleting at end: ");
    display(head);

    // Delete by position
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    deleteByPosition(&head, pos);
    printf("After deleting at position %d: ", pos);
    display(head);

    // Delete by value
    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);
    deleteByValue(&head, value);
    printf("After deleting value %d: ", value);
    display(head);

    return 0;
}
