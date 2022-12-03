#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void deleteMiddleNode(int position);
void displayList();
int main()
{
    int n, data, position;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &position);
    deleteMiddleNode(position);
    printf("\nUpdated data in the list is:\n");
    displayList();
    return 0;
}
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("Unable to allocate memory!");
        exit(0);
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head -> data = data;
        head -> next = NULL;
        temp = head;
        for(i=2;i<=n;i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            if(newNode == NULL)
            {
                printf("\nUnable to allocate memory!");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode -> data = data;
                newNode -> next = NULL;
                temp -> next = newNode;
                temp = temp -> next;
            }
        }
        printf("Linked List Created Successfully!\n");
    }
}
void deleteMiddleNode(int position)
{
    int i;
    struct node *toDelete, *prevNode;
    if(head == NULL)
    {
        printf("\nList is already emoty!");
    }
    else
    {
        toDelete = head;
        prevNode = head;
        for(i=2;i<=position;i++)
        {
            prevNode = toDelete;
            toDelete = toDelete -> next;
            if(toDelete==NULL)
            {
                break;
            }
        }
        if(toDelete!=NULL)
        {
            if(toDelete == head)
            {
                head = head -> next;
            }
            prevNode -> next = toDelete -> next;
            toDelete -> next = NULL;
            free(toDelete);
            printf("\nData deleted successfully!");
        }
        else
        {
            printf("Invalid position unable to delete!");
        }
    }
}
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        temp = head;
        while(temp!=NULL)
        {
            printf("%d->", temp -> data);
            temp = temp -> next;
        }
    }
}