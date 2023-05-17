#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} node;

node *head = NULL;

node *createNode()
{
    node *newNode = malloc(sizeof(node));
    printf("Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

bool addLast()
{
    if (head == NULL)
    {
        head = createNode();
        return true;
    }

    node *newNode = createNode();
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return true;
}
bool addFirst()
{
    node *newNode = createNode();
    newNode->next = head;
    head = newNode;
    return true;
}
bool addAtPositionInLimit()
{

    int pos = -1;

    while (pos < 0)
    {
        printf("Enter Index (Index starts from 0 )");
        scanf("%d", &pos);

        if (pos < 0 || pos > countNode())
        {
            printf("Invalid Index (Re-enter) : ");
            pos = -1;
        }
    }
    if (pos == countNode())
    {
        return addLast();
    }
    if (pos == 0)
    {
        return addFirst();
    }
    node *temp = head;
    while (pos - 1)
    {
        temp = temp->next;
        pos--;
    }
    node *newNode = createNode();
    newNode->next = temp->next;
    newNode->prev = temp->next->prev;
    temp->next = newNode;
    newNode->next->prev = newNode;
    return true;
}
int delFirst()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    node *temp = head;
    head = head->next;
    int data = temp->data;
    free(temp);
    return data;
}
int delLast()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return 0;
    }

    if (head->next == NULL)
    {
        int data = head->data;
        free(head);
        head = NULL;
        return data;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    int data = temp->next->data;
    free(temp->next);
    temp->next = NULL;
    return data;
}
int delAtPosition()
{

    if (head == NULL)
    {
        return 0;
    }

    int pos = -1;
    while (pos < 0)
    {
        printf("Enter Index (Index starts from 0 )");
        scanf("%d", &pos);

        if (pos < 0 || pos >= countNode())
        {
            printf("Invalid Index (Re-enter) : ");
            pos = -1;
        }
    }

    if (countNode() == pos + 1)
    {
        return delLast();
    }
    if (pos == 0)
    {
        return delFirst();
    }

    node *temp = head;
    while (pos!=0)
    {   
        printf("while\n");
        temp = temp->next;
        pos--;
    }

        printf("out while\n");
        printf("%d\n",temp->data);
    
    temp->prev->next  = temp->next;
    temp->next->prev = temp->prev;

    int data = temp->data;
        printf("change \n");
    free(temp);

    return data;
}
int countNode()
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void printList()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            printf("| %d |", temp->data);
        }
        else
        {
            printf("| %d |->", temp->data);
        }
        temp = temp->next;
    }
}

int search()
{   
    int n;
    printf("Enter Number to search : ");
    scanf("%d",&n);

    node * temp = head;
    int i=-1;
    int flag=0;
    while (temp!=NULL)
    {   i++;
        if (temp->data == n )
        {   flag=1;
            break;
        }
        temp=temp->next;
        
    }
    if (flag==1)
    {
        printf(" Number present at index %d \n",i);
        return i;
    }else{
        printf(" Number is not present \n");
        return -1;
    }
    
}
void main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n 5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            addFirst();
            break;
        case 2:
            addLast();
            break;
        case 3:
            addAtPositionInLimit();
            break;
        case 4:
            delFirst();
            break;
        case 5:
            delLast();
            break;
        case 6:
            delAtPosition();
            break;
        case 7:
            search();
            break;
        case 8:
            printList();
            break;
        case 9:
            return ;
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
