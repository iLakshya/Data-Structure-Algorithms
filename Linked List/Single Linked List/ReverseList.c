#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void reverseList();
void displayList();
int main()
{
    int n, choice;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nPress 1 to reverse the order of the linked list:\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        reverseList();
    }
    printf("\nData in the list is:\n");
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
        printf("\nUnable to allocate memory!");
        exit(0);
    }
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
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        temp -> next = newNode;
        temp = temp -> next;
    }
}
void reverseList()
{
    struct node *prevNode, *curNode; 
    if(head!=NULL)
    {
        prevNode = head;
        curNode = head -> next;
        head = head -> next;
        prevNode -> next = NULL;
        while(head!=NULL)
        {
            head = head -> next;
            curNode -> next = prevNode;
            prevNode = curNode;
            curNode = head;
        }
        head = prevNode;
        printf("Data successfully reversed!\n");
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