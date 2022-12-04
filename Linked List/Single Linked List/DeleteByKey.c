#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void deleteFirstByKey(int key);
void displayList();
int main()
{
    int n, key;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nEnter element to delete with key: ");
    scanf("%d", &key);
    deleteFirstByKey(key);
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
        printf("\nUnable to allocate memory!");
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
void deleteFirstByKey(int key)
{
    struct node *prev, *cur;
    while(head!=NULL && head->data==key)
    {
        prev = head;
        head = head -> next;
        free(prev);
        return;
    }
    prev = NULL;
    cur = head;
    while(cur!=NULL)
    {
        if(cur->data == key)
        {
            if(prev!=NULL)
            {
                prev -> next = cur -> next;
            }
            free(cur);
            return;
        }
        prev = cur;
        cur = cur -> next;
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