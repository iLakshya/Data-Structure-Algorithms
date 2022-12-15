#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head, *last;
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtN(int data, int position);
int main()
{
    int n, data, choice = 1;
    head = NULL;
    last = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Insert node at the beginning of the list\n");
        printf("3. Insert node at the end of the list\n");
        printf("4. Insert node at any position\n");
        printf("5. Display the list\n");
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
                printf("Enter the data of first node: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter the data of last node: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter the position where you want to insert the new node: ");
                scanf("%d", &n);
                printf("Enter the data of node %d: ", n);
                scanf("%d", &data);
                insertAtN(data, n);
                break;
            case 5:
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
    struct node *newNode;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        if(head!=NULL)
        {
            printf("Enter the data of node 1: ");
            scanf("%d", &data);
            head -> data = data;
            head -> prev = NULL;
            head -> next = NULL;
            last = head;
            for(i=2;i<=n;i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                if(newNode!=NULL)
                {
                    printf("Enter the data of node %d: ", i);
                    scanf("%d", &data);
                    newNode -> data = data;
                    newNode -> prev = last;
                    newNode -> next = NULL;
                    last -> next = newNode;
                    last = newNode;
                }
                else
                {
                    printf("Unable to allocate memory!");
                    break;
                }
            }
            printf("\nLinked List created successfully!\n");
        }
        else
        {
            printf("Unable to allocate memory!");
        }
    }
}
void displayList()
{
    struct node *temp;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp = head;
        printf("\nData in the list is:\n");
        while(temp!=NULL)
        {
            printf("%d->", temp -> data);
            n++;
            temp = temp -> next;
        }
    }
}
void insertAtBeginning(int data)
{
    struct node *newNode;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = data;
        newNode -> next = head;
        newNode -> prev = NULL;
        head -> prev = newNode;
        head = newNode;
        printf("Node inserted successfully at beginning of the list!\n");
    }
}
void insertAtEnd(int data)
{
    struct node *newNode;
    if(last == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode -> data = data;
        newNode -> next = NULL;
        newNode -> prev = last;
        last -> next = newNode;
        last = newNode;
        printf("Node inserted successfully at end of the list!\n");
    }

}
void insertAtN(int data, int position)
{
    int i;
    struct node *newNode, *temp;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        temp = head;
        i = 1;
        while(i<position-1 && temp!=NULL)
        {
            temp = temp -> next;
            i++;
        }
        if(position == 1)
        {
            insertAtBeginning(data);
        }
        else if(temp == last)
        {
            insertAtEnd(data);
        }
        else if(temp!=NULL)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            newNode -> data = data;
            newNode -> next = temp -> next;
            newNode -> prev = temp;
            if(temp->next!=NULL)
            {
                temp -> next -> prev = newNode;
            }
            temp -> next = newNode;
            printf("Node successfully inserted at the position %d\n", position);
        }
        else
        {
            printf("Invalid position!\n");
        }
    }
}