#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices in the graph

// Queue structure for BFS
typedef struct
{
    int items[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return value;
}

// BFS function
void bfs(int graph[MAX][MAX], int vertices, int start)
{
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS Traversal: ");
    while (!isEmpty(&q))
    {
        int current = dequeue(&q);
        printf("%d ", current);

        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int graph[MAX][MAX] = {0};
    int vertices, edges, start, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(graph, vertices, start);

    return 0;
}
