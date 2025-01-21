#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node
{
    int data;
    struct Node *next;
};

// Define a queue structure
struct Queue
{
    struct Node *front, *rear;
};

// Function to create a new node
struct Node *newNode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to initialize the queue
void initQueue(struct Queue *q)
{
    q->front = q->rear = NULL;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int data)
{
    struct Node *temp = newNode(data);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node *temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;
}

// Function to display the queue
void display(struct Queue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Queue q;
    initQueue(&q);
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            value = dequeue(&q);
            if (value != -1)
                printf("Dequeued: %d\n", value);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
