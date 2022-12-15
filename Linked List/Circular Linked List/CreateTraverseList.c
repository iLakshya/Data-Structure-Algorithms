#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void displayList();
int main()
{
    int n, data, choice = 1;
    head = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Display the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in the list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice!");
        }
        printf("\n\n");
    }
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head -> data = data;
        head -> next = NULL;
        prevNode = head;
        for(i=2;i<=n;i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data of node %d: ", i);
            scanf("%d", &data);
            newNode -> data = data;
            newNode -> next = NULL;
            prevNode -> next = newNode;
            prevNode = newNode;
        }
        prevNode -> next = head;
        printf("\nLinked List created successfully!\n");
    }
}
void displayList()
{
    struct node *current;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        current = head;
        printf("\nData in the list is:\n");
        do
        {
            printf("%d->", current -> data);
            current = current -> next;
            n++;
        }
        while(current!=head);
    }
}