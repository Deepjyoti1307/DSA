#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Define a queue structure
struct Queue
{
    int arr[MAX];
    int front, rear;
};

// Function to initialize the queue
void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

// Function to add an element to the queue
void enqueue(struct Queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) // If the queue is empty
        q->front = 0;
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
}

// Function to remove an element from the queue
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->arr[q->front];
    if (q->front == q->rear)
    { // If the queue has only one element
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }
    return data;
}

// Function to display the queue
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d <- ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d <- NULL\n", q->arr[i]);
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
