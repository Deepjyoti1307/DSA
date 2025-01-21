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

// Function to insert a node at the head
void insertAtHead(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node *head, int target, int value)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != target)
    {
        temp = temp->next;
    }

    if (temp != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Node with value %d not found.\n", target);
    }
}

// Function to insert a node before a given node
void insertBefore(struct Node **head, int target, int value)
{
    if (*head == NULL)
        return;

    if ((*head)->data == target)
    {
        insertAtHead(head, value);
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL && temp->next->data != target)
    {
        temp = temp->next;
    }

    if (temp->next != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        printf("Node with value %d not found.\n", target);
    }
}

// Function to insert a node at the end
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
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

    // Insert at head
    int value;
    printf("Enter value to insert at head: ");
    scanf("%d", &value);
    insertAtHead(&head, value);
    printf("After inserting at head: ");
    display(head);

    // Insert after a node
    int target;
    printf("Enter target value to insert after: ");
    scanf("%d", &target);
    printf("Enter value to insert after %d: ", target);
    scanf("%d", &value);
    insertAfter(head, target, value);
    printf("After inserting after %d: ", target);
    display(head);

    // Insert before a node
    printf("Enter target value to insert before: ");
    scanf("%d", &target);
    printf("Enter value to insert before %d: ", target);
    scanf("%d", &value);
    insertBefore(&head, target, value);
    printf("After inserting before %d: ", target);
    display(head);

    // Insert at end
    printf("Enter value to insert at end: ");
    scanf("%d", &value);
    insertAtEnd(&head, value);
    printf("After inserting at end: ");
    display(head);

    return 0;
}
