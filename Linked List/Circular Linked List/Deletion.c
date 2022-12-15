#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void createList(struct node **head, int n);
void displayList(struct node **head);
void deleteAll(struct node **head, int key);
int main()
{
    int n, key, data, choice;
    struct node *head = NULL;
    while(choice!=0)
    {
        printf("1. Create List\n");
        printf("2. Display the list\n");
        printf("3. Delete all elements by key\n");
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
                displayList(&head);
                break;
            case 3:
                printf("Enter the data of first node: ");
                scanf("%d", &key);
                deleteAll(&head, key);
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
    for(i=1;i<=n;i++)
    {
        newNode = malloc(sizeof(struct node));
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);
        newNode -> data = data;
        newNode -> next = NULL;
        if(prevNode!=NULL)
        {
            prevNode -> next = newNode;
        }
        if(*head == NULL)
        {
            *head = newNode;
        }
        prevNode = newNode;
    }
    prevNode -> next = *head;
    printf("\nLinked List created successfully!\n");
}
void displayList(struct node **head)
{
    struct node *current;
    int n= 1;
    if(*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    current = *head;
    printf("Data in the list is:\n");
    do
    {
        printf("%d->", current -> data);
        current = current -> next;
        n++;
    }
    while(current!=*head);
}
void deleteAll(struct node **head, int key)
{
    int i, count;
    struct node *prev, *cur;
    if(*head == NULL)
    {
        printf("List is empty");
        return;
    }
    count = 0;
    cur = *head;
    prev = cur;
    while(prev->next!=*head)
    {
        prev = prev -> next;
        count++;
    }
    i = 0;
    while(i <= count)
    {
        if(cur -> data == key)
        {
            if(cur->next!=cur)
            {
                prev -> next = cur -> next;
            }
            else
            {
                prev -> next = NULL;
            }
            if(cur == *head)
            {
                *head = prev -> next;
            }
            free(cur);
            if(prev!=NULL)
            {
                cur = prev -> next;
            }
            else
            {
                cur = NULL;
            }
        }
        else
        {
            prev = cur;
            cur = cur -> next;
        }
        i++;
    }
}