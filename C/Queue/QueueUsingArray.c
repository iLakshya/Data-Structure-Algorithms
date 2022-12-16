#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define CAPACITY 100
int queue[CAPACITY];
unsigned int size = 0;
unsigned rear = CAPACITY - 1;
unsigned int front = 0;
int enqueue(int data);
int dequeue();
int isFull();
int isEmpty();
int getRear();
int getFront();
int main()
{
    int ch, data;
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
                if(enqueue(data))
                {
                    printf("Element added to the queue!\n");
                }
                else
                {
                    printf("Queue is full!\n");
                }
                break;
            case 2:
                data = dequeue();
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
                if(isEmpty())
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Rear: %d\n", getRear());
                }
                break;
            case 5:
                if(isEmpty())
                {
                    printf("Queue is empty!\n");
                }
                else
                {
                    printf("Front: %d\n", getFront());
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
int enqueue(int data)
{
    if(isFull())
    {
        return 0;
    }
    rear = (rear + 1) % CAPACITY;
    size++;
    queue[rear] = data;
    return 1;
}
int dequeue()
{
    int data = INT_MIN;
    if(isEmpty())
    {
        return INT_MIN;
    }
    data = queue[front];
    front = (front + 1) % CAPACITY;
    size--;
    return data;
}
int isFull()
{
    return (size == CAPACITY);
}
int isEmpty()
{
    return (size == 0);
}
int getFront()
{
    return (isEmpty()) ? INT_MIN : queue[front];
}
int getRear()
{
    return (isEmpty()) ? INT_MIN : queue[rear];
}