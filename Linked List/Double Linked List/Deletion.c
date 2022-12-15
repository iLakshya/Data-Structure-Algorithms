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
void deleteFromBeginning();
void deleteFromEnd();
void deleteFromN(int position);
int main()
{
    int n, data, choice = 1;
    head = NULL;
    last = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Delete node from the beginning of the list\n");
        printf("3. Delete node from the end of the list\n");
        printf("4. Delete node from any position\n");
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
                deleteFromBeginning();
                break;
            case 3:
                deleteFromEnd();
                break;
            case 4:
                printf("Enter the position from where you want to delete new node: ");
                scanf("%d", &n);
                deleteFromN(n);
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
void deleteFromBeginning()
{
    struct node *toDelete;
    if(head == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        toDelete = head;
        head = head -> next;
        if(head!=NULL)
        {
            head -> prev = NULL;
        }
        free(toDelete);
        printf("Node successfully deleted from the beginning of the list!\n");
    }
}
void deleteFromEnd()
{
    struct node *toDelete;
    if(last == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        toDelete = last;
        last = last ->  prev;
        if(last!=NULL)
        {
            last -> next = NULL;
        }
        free(toDelete);
        printf("Node successfully deleted from the end of the list!\n");
    }
}
void deleteFromN(int position)
{
    struct node *current;
    int i;
    current = head;
    for(i=1;i<position && current!=NULL;i++)
    {
        current = current -> next;
    }
    if(position == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current!=NULL)
    {
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;
        free(current);
        printf("Node successfully deleted from the position %d\n", position);
    }
    else
    {
        printf("Invalid position!\n");
    }
}