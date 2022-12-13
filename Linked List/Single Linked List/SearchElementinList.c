#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void displayList();
int search(int key);
int main()
{
    int n, index, keyToSearch;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list is:\n");
    displayList();
    printf("\nEnter the element to search: ");
    scanf("%d", &keyToSearch);
    index = search(keyToSearch);
    if(index >= 0)
    {
        printf("%d is found in the list at position: %d\n", keyToSearch, (index + 1));
    }
    else
    {
        printf("%d not found in the list!\n", keyToSearch);
    }
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
int search(int key)
{
    int index;
    struct node *curNode;
    index = 0;
    curNode = head;
    while(curNode!=NULL && curNode->data!=key)
    {
        index++;
        curNode = curNode -> next;
    }
    return (curNode!=NULL) ? index : -1;
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
            printf("%d-> ", temp -> data);
            temp = temp -> next;
        }
    }
}