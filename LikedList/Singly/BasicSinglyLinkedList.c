#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;

} node;

node *head = NULL;

node *createNode(int data)
{

    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

bool addLast()
{

    int data;

    printf("Enter Data : ");
    scanf("%d", &data);

    node *newNode = createNode(data);

    if (newNode == NULL)
    {
        printf("node not added\n");
        return false;
    }

    if (head == NULL)
    {
        head = newNode;
        return true;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;

    return true;
}

bool addFirst()
{

    int data;

    printf("Enter Data : ");
    scanf("%d", &data);

    node *newNode = createNode(data);

    if (newNode == NULL)
    {
        printf("node not added\n");
        return false;
    }

    if (head == NULL)
    {
        head = newNode;
        return true;
    }

    newNode->next = head;
    head = newNode;

    return true;
}

int countNode()
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

bool addAtPositionInLimit()
{

    int data, pos = -1;

    printf("Enter data : ");
    scanf("%d", &data);

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

    node *newNode = createNode(data);

    if (newNode == NULL)
    {
        printf("node not added\n");
        return false;
    }

    if (pos == countNode())
    {
        if (head == NULL)
        {
            head = newNode;
            return true;
        }

        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        return true;
    }

    if (pos == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            return true;
        }

        newNode->next = head;
        head = newNode;

        return true;
    }

    node *temp = head;
    while (pos - 1)
    {
        temp = temp->next;
        pos--;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return true;
}
void printAllNodes()
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

int deleteAtPosition()
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

    while (pos - 1)
    {
        temp = temp->next;
        pos--;
    }

    node * temp2 = temp->next;
    int data = temp2->data;
    temp = temp->next->next;
    free(temp2);

    return data;
}

int delFirst()
{
    if (head == NULL)
    {
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
        return 0;
    }

    if (head->next == NULL)
    {
        return delFirst();
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
void main()
{

    addLast();
    addLast();
    addLast();
    addFirst();
    addFirst();
    addAtPositionInLimit();
    addAtPositionInLimit();
    printAllNodes();
}
