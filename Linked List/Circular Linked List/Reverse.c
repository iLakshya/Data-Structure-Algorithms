#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createList(struct node **head, int n);
void displayList(struct node *head);
void reverseList(struct node **head);
int main()
{
    int n, choice, index;
    struct node *head = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Display the list\n");
        printf("3. Reverse the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in the list: ");
                scanf("%d", &n);
                createList(&head, n);
                break;
            case 2:
                displayList(head);
                getchar();
                getchar();
                break;
            case 3:
                reverseList(&head);
                printf("List reversed!\n");
                getchar();
                getchar();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Invalid choice!");
        }
        printf("\n\n");
    }
    return 0;
}
void createList(struct node **head, int n)
{
    int i, data;
    struct node *prevNode, *newNode;
    prevNode = NULL;
    newNode = NULL;
    for(i=1;i<=n;i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        if(prevNode!=NULL)
        {
            prevNode -> next = newNode;
        }
        prevNode = newNode;
        if(*head == NULL)
        {
            *head = newNode;
        }
    }
    prevNode -> next = *head;
    printf("\nLinked List created successfully!\n");
}
void displayList(struct node *head)
{
    struct node *current;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    current = head;
    printf("Data in the list is:\n");
    do
    {
        printf("%d->", current -> data);
        current = current -> next;
        n++;
    }
    while(current!=head);
}
void reverseList(struct node **head)
{
    struct node *prev, *cur, *next, *last;
    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    last = *head;
    prev = *head;
    cur = (*head) -> next;
    *head = (*head) -> next;
    while(*head!=last)
    {
        *head = (*head) -> next;
        cur -> next = prev;
        prev = cur;
        cur = *head;
    }
    cur -> next = prev;
    *head = prev;
}