#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    // createBinar yTree
} tnode;

tnode *head = NULL;

tnode *createNode(int data)
{

    tnode *newNode = malloc(sizeof(tnode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void print_pre_order(tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    print_pre_order(root->left);
    print_pre_order(root->right);
}
void print_in_order(tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    print_in_order(root->left);
    printf(" %d ", root->data);
    print_in_order(root->right);
}
void print_post_order(tnode *root)
{
    if (root == NULL)
    {
        return;
    }
    print_post_order(root->left);
    print_post_order(root->right);
    printf(" %d ", root->data);
}
int findIndex(int data, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }

    return -1;
}


tnode *createTreeUsingInAndPreOrderArray(int inOrderArray[], int preOrderArray[], int start, int end, int size)
{

    if (start > end)
    {
        return NULL;
    }
    static int nodeNo = 0;
    printf("%d\n", nodeNo);
    int index = findIndex(preOrderArray[nodeNo], inOrderArray, size);
    nodeNo++;

    tnode *newNode = createNode(inOrderArray[index]);

    newNode->left = createTreeUsingInAndPreOrderArray(inOrderArray, preOrderArray, start, index - 1, size);
    newNode->right = createTreeUsingInAndPreOrderArray(inOrderArray, preOrderArray, index + 1, end, size);
    if (nodeNo == size - 1)
    {
        nodeNo = nodeNo - nodeNo;
    }
    return newNode;
}

tnode *createTreeUsingInAndPostOrderArray(int inOrderArray[], int preOrderArray[], int start, int end, int size)
{

    if (start > end)
    {
        return NULL;
    }
    static int nodeNo = 1;
    int index = findIndex(preOrderArray[size - nodeNo], inOrderArray, size);
    nodeNo++;

    tnode *newNode = createNode(inOrderArray[index]);

    newNode->right = createTreeUsingInAndPostOrderArray(inOrderArray, preOrderArray, index + 1, end, size);
    newNode->left = createTreeUsingInAndPostOrderArray(inOrderArray, preOrderArray, start, index - 1, size);
    if (nodeNo == size)
    {
        nodeNo = nodeNo - nodeNo;
    }
    return newNode;
}

tnode *createBT1(int inOrder[], int preOrder[], int inStart, int inEnd, int preStart, int preEnd)
{

    if (inStart > inEnd)
    {
        return NULL;
    }

    int rootData = preOrder[preStart];

    int idx;
    for (idx = inStart; idx <= inEnd; idx++)
    {
        if (inOrder[idx] == rootData)
        {
            break;
        }
    }
    int l = idx - inStart;
    tnode *newNode = malloc(sizeof(tnode));
    newNode->data = rootData;
    newNode->left = createBT1(inOrder, preOrder, inStart, idx - 1, preStart + 1, preStart + l);
    newNode->right = createBT1(inOrder, preOrder, idx + 1, inEnd, preStart + l + 1, preEnd);

    return newNode;
}

tnode *createBT2(int inOrder[], int postOrder[], int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    int rootData = postOrder[postEnd];
    int idx;
    for (idx = inStart; idx <= inEnd; idx++)
    {
        if (inOrder[idx] == rootData)
        {
            break;
        }
    }

    int l = inEnd - idx;

    tnode *newNode = malloc(sizeof(tnode));
    newNode->data = rootData;
    newNode->left = createBT2(inOrder, postOrder, inStart, idx - 1, postStart , postEnd-l-1);
    newNode->right = createBT2(inOrder, postOrder, idx + 1, inEnd, postEnd-l , postEnd-1 );

    return newNode;
}

void main()
{
    int size; 
    while (1)
    {
        /* code */

        printf("Enter Array size : ");
        scanf("%d", &size);

        int inOrderArray[size];
        int preOrderArray[size];
        int postOrderArray[size];

        printf(" Enter Data in In-order array : \n");
        for (int i = 0; i < size; i++)
        {
            printf(" Enter Data : ");
            scanf("%d", &inOrderArray[i]);
        }
        printf(" Enter Data in pre-order array : \n");
        for (int i = 0; i < size; i++)
        {
            printf(" Enter Data : ");
            scanf("%d", &preOrderArray[i]);
        }

        printf(" Enter Data in post-order array : \n");
        for (int i = 0; i < size; i++)
        {
            printf(" Enter Data : ");
            scanf("%d", &postOrderArray[i]);
        }

        // head = createTreeUsingInAndPreOrderArray(inOrderArray ,preOrderArray , 0 , size-1 , size);
        head = createBT1(inOrderArray, preOrderArray, 0, size - 1, 0, size - 1);
        printf("\n In-order : \n");
        print_in_order(head);
        printf("\n Pre-order : \n");
        print_pre_order(head);

        // head = createTreeUsingInAndPostOrderArray(inOrderArray ,postOrderArray , 0 , size-1 , size);
        head = createBT2(inOrderArray, postOrderArray, 0, size - 1, 0, size - 1);

        printf("\n\nIn-order : \n");
        print_in_order(head);
        printf("\n Post-order : \n");
        print_post_order(head);
    }
}