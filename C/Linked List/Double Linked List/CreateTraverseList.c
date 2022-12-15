#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head, *last;
void createList(int n);
void displayListFromFirst();
void displayListFromEnd();
int main()
{
    int n, choice;
    head = NULL;
    last = NULL;
    printf("Enter the total nodes you want to create: ");
    scanf("%d", &n);
    createList(n);
    printf("\nPress 1 to display list from first");
    printf("\nPress 2 to display list from end: ");
    scanf("%d", &choice);
    if(choice == 1)
    {
        displayListFromFirst();
    }
    else if(choice == 2)
    {
        displayListFromEnd();
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
void displayListFromFirst()
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
void displayListFromEnd()
{
    struct node *temp;
    int n = 1;
    if(last == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        temp = last;
        printf("\nData in the list is:\n");
        while(temp!=NULL)
        {
            printf("%d->", temp -> data);
            n++;
            temp = temp -> prev;
        }
    }
}