#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the deque

// Define a deque structure
struct Deque
{
    int arr[MAX];
    int front, rear;
};

// Function to initialize the deque
void initDeque(struct Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the deque is full
int isFull(struct Deque *dq)
{
    return (dq->front == 0 && dq->rear == MAX - 1) || dq->front == dq->rear + 1;
}

// Function to check if the deque is empty
int isEmpty(struct Deque *dq)
{
    return dq->front == -1;
}

// Function to add an element at the front
void insertFront(struct Deque *dq, int data)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1)
    { // If the deque is empty
        dq->front = dq->rear = 0;
    }
    else if (dq->front == 0)
    { // Wrap around
        dq->front = MAX - 1;
    }
    else
    {
        dq->front--;
    }
    dq->arr[dq->front] = data;
}

// Function to add an element at the rear
void insertRear(struct Deque *dq, int data)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1)
    { // If the deque is empty
        dq->front = dq->rear = 0;
    }
    else if (dq->rear == MAX - 1)
    { // Wrap around
        dq->rear = 0;
    }
    else
    {
        dq->rear++;
    }
    dq->arr[dq->rear] = data;
}

// Function to remove an element from the front
int deleteFront(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = dq->arr[dq->front];
    if (dq->front == dq->rear)
    { // Only one element in the deque
        dq->front = dq->rear = -1;
    }
    else if (dq->front == MAX - 1)
    { // Wrap around
        dq->front = 0;
    }
    else
    {
        dq->front++;
    }
    return data;
}

// Function to remove an element from the rear
int deleteRear(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return -1;
    }
    int data = dq->arr[dq->rear];
    if (dq->front == dq->rear)
    { // Only one element in the deque
        dq->front = dq->rear = -1;
    }
    else if (dq->rear == 0)
    { // Wrap around
        dq->rear = MAX - 1;
    }
    else
    {
        dq->rear--;
    }
    return data;
}

// Function to display the deque
void display(struct Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return;
    }
    int i = dq->front;
    while (i != dq->rear)
    {
        printf("%d <- ", dq->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("%d\n", dq->arr[dq->rear]);
}

int main()
{
    struct Deque dq;
    initDeque(&dq);
    int choice, value;

    while (1)
    {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertFront(&dq, value);
            break;
        case 2:
            printf("Enter value to insert at rear: ");
            scanf("%d", &value);
            insertRear(&dq, value);
            break;
        case 3:
            value = deleteFront(&dq);
            if (value != -1)
                printf("Deleted from front: %d\n", value);
            break;
        case 4:
            value = deleteRear(&dq);
            if (value != -1)
                printf("Deleted from rear: %d\n", value);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
