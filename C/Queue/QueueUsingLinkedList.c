#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100
typedef struct node
{
    int data;
    struct node *next;
}Queue;
unsigned int size = 0;
int enqueue(Queue **rear, Queue **front, int data);
int dequeue(Queue **front);
int getRear(Queue *rear);
int getFront(Queue *front);
int isEmpty();
int isFull();
int main()
{
    int ch, data;
    Queue *rear, *front;
    rear = NULL;
    front = NULL;
    while(1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Size\n");
        printf("4. Get Rear\n");
        printf("5. Get Front\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                if(enqueue(&rear, &front, data))
                {
                    printf("Element added to the queue!\n");
                }
                else
                {
                    printf("Queue is full!\n");
                }
                break;
            case 2:
                data = dequeue(&front);
                if(data == INT_MIN)
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Data: %d\n", data);
                }
                break;
            case 3:
                if(isEmpty())
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Queue size is: %d\n", size);
                }
                break;
            case 4:
                data = getRear(rear);
                if(data == INT_MIN)
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Rear: %d\n", data);
                }
                break;
            case 5:
                data = getFront(front);
                if(data == INT_MIN)
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Front: %d\n", data);
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}
int enqueue(Queue **rear, Queue **front, int data)
{
    Queue *newNode = NULL;
    if(isFull())
    {
        return 0;
    }
    newNode = (Queue *)malloc(sizeof(Queue));
    newNode -> data = data;
    newNode -> next = NULL;
    if((*rear))
    {
        (*rear) -> next = newNode;
    }
    *rear = newNode;
    if(!(*front))
    {
        *front = *rear;
    }
    size++;
    return 1;
}
int dequeue(Queue **front)
{
    Queue *toDequeue = NULL;
    int data = INT_MIN;
    if(isEmpty())
    {
        return INT_MIN;
    }
    toDequeue = *front;
    data = toDequeue -> data;
    *front = (*front) -> next;
    size--;
    free(toDequeue);
    return data;
}
int getRear(Queue *rear)
{
    return (isEmpty()) ? INT_MIN : rear -> data;
}
int getFront(Queue *front)
{
    return (isEmpty()) ? INT_MIN : front -> data;
}
int isEmpty()
{
    return (size <= 0);
}
int isFull()
{
    return (size > CAPACITY);
}