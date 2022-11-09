#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void insertInBetween(int data, int position);
void displayList();
int main()
{
    int n, data, position;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nEnter data to insert in between the list: ");
    scanf("%d", &data);
    printf("Enter the position you want to insert the node: ");
    scanf("%d", &position);
    insertInBetween(data, position);
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
                printf("Unable to allocate memory!");
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
void insertInBetween(int data, int position)
{
    int i;
    struct node *newNode, *temp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("Unable to allocate memory!");
    }
    else
    {
        newNode -> data = data;
        newNode -> next = NULL;
        temp = head;
        for(i=2;i<=position;i++)
        {
            temp = temp -> next;
            if(temp == NULL)
            {
                break;
            }
        }
        if(temp!=NULL)
        {
            newNode -> next = temp -> next;
            temp -> next = newNode;
            printf("Data Inserted Successfully!");
        }
        else
        {
            printf("Unable to insert the data at the given position!");
        }
    }
}
void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty!");
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