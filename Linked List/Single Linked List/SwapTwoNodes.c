#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void createList(int n);
void displayList();
int count(struct node *list);
int swap(struct node *list, int pos1, int pos2);
int main()
{
    int n, pos1, pos2;
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
    printf("Data in the list before swapping:\n");
    displayList();
    printf("\nEnter first node position to swap: ");
    scanf("%d", &pos1);
    printf("\nEnter second node positon to swap: ");
    scanf("%d", &pos2);
    if(swap(head, pos1, pos2) == 1)
    {
        printf("\nData swapped successfully!\n");
        printf("Data in the list after swapping %d node with %d node is: \n", pos1, pos2);
        displayList();
    }
    else
    {
        printf("Invalid position entered!\n");
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
int count(struct node *list)
{
    int nodes = 0;
    while(list!=NULL)
    {
        nodes++;
        list = list -> next;
    }
    return nodes;
}
int swap(struct node *list , int pos1, int pos2)
{
    struct node *node1, *node2, *prev1, *prev2, *temp;
    int i;
    const int maxPos = (pos1 > pos2) ? pos1 : pos2;
    const int totalNodes = count(list);
    if((pos1<=0 || pos1>totalNodes) || (pos2<=0 || pos2>totalNodes))
    {
        return -1;
    }
    if(pos1 == pos2)
    {
        return 1;
    }
    i = 1;
    temp = list;
    prev1 = NULL;
    prev2 = NULL;
    while(temp!=NULL && (i<=maxPos))
    {
        if(i == (pos1 - 1))
        {
            prev1 = temp;
        }
        if(i == pos1)
        {
            node1 = temp;
        }
        if(i == (pos2 - 1))
        {
            prev2 = temp;
        }
        if(i == pos2)
        {
            node2 = temp;
        }
        temp = temp -> next;
        i++;
    }
    if(node1!=NULL && node2!=NULL)
    {
        if(prev1!=NULL)
        {
            prev1 -> next = node2;
        }
        if(prev2!=NULL)
        {
            prev2 -> next = node1;
        }
        temp = node1 -> next;
        node1 -> next = node2 -> next;
        node2 -> next = temp;
        if(prev1 == NULL)
        {
            head = node2;
        }
        else if(prev2 == NULL)
        {
            head = node1;
        }
    }
    return 1;
}