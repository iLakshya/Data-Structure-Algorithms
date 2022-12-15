#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtN(int data, int position);
int main()
{
    int n, data, choice = 1;
    head = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Display the list\n");
        printf("3. Insert node at the beginning of the list\n");
        printf("4. Insert node at any position\n");
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
            case 3:
                printf("Enter the data of first node: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter the position where you want to insert the new node: ");
                scanf("%d", &n);
                printf("Enter the data of node %d: ", n);
                scanf("%d", &data);
                insertAtN(data, n);
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
void insertAtBeginning(int data)
{
    struct node *newNode, *current;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = data;
        newNode -> next = head;
        current = head;
        while(current->next!=head)
        {
            current = current -> next;
        }
        current -> next = newNode;
        head = newNode;
        printf("Node inserted successfully at the beginning of the list!\n");
    }
}
void insertAtN(int data, int position)
{
    struct node *newNode, *current;
    int i;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else if(position == 1)
    {
        insertAtBeginning(data);
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = data;
        current = head;
        for(i=2;i<=position-1;i++)
        {
            current = current -> next;
        }
        newNode -> next = current -> next;
        current -> next = newNode;
        printf("Node inserted successfully at the position %d!\n", position);
    }
}