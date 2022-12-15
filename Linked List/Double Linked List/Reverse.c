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
void reverseList();
int main()
{
    int n, data, choice = 1;
    head = NULL;
    last = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Reverse the list\n");
        printf("3. Display the list\n");
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
                reverseList();
                break;
            case 3:
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
void reverseList()
{
    struct node *current,  *temp;
    current = head;
    while(current!=NULL)
    {
        temp = current -> next;
        current -> next = current -> prev;
        current -> prev = temp;
        current = temp;
    }
    temp = head;
    head = last;
    last = temp;
    printf("List reversed successfully!\n");
}