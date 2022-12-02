#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void deleteLastNode();
void displayList();
int main()
{
    int n, data, choice;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nPress 1 to delete the last node: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        deleteLastNode();
    }
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
void deleteLastNode()
{
    struct node *toDelete, *secondLastNode;
    if(head == NULL)
    {
        printf("\nList is already emoty!");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;
        while(toDelete->next!= NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete -> next;
        }
        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode -> next = NULL;
        }
        free(toDelete);
        printf("\nData deleted successfully!");
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