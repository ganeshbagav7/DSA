#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    //createBinar yTree
} tnode;

tnode *head = NULL;

tnode *createNode(int data)
{

    tnode *newNode = malloc(sizeof(tnode));
    newNode->data=data;
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
int findIndex(int data , int arr[] , int size ){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==data)
        {
            return i;
        }
        
    }
    
    return -1;
}

tnode * createTreeUsingInAndPreOrderArray( int inOrderArray[] , int preOrderArray[] , int start , int end  , int size ){

    if(start > end ){
        return NULL;
    }
    static int nodeNo=0;
    int index = findIndex( preOrderArray[nodeNo] , inOrderArray , size );
    nodeNo++;

    tnode * newNode = createNode(inOrderArray[index]);

    newNode->left = createTreeUsingInAndPreOrderArray(inOrderArray ,preOrderArray , start , index-1 , size);
    newNode->right = createTreeUsingInAndPreOrderArray(inOrderArray, preOrderArray , index+1 , end , size);

    return newNode;

}

tnode * createTreeUsingInAndPostOrderArray( int inOrderArray[] , int preOrderArray[] , int start , int end  , int size){
    
    if(start > end ){
        return NULL;
    }
    static int nodeNo=1;
    int index = findIndex( preOrderArray[size-nodeNo] , inOrderArray , size );
    nodeNo++;

    tnode * newNode = createNode(inOrderArray[index]);
    
    newNode->right = createTreeUsingInAndPostOrderArray(inOrderArray ,preOrderArray ,index+1  , end , size);
    newNode->left = createTreeUsingInAndPostOrderArray(inOrderArray, preOrderArray , start , index-1 , size);

    return newNode;

}

void main()
{
    int size;

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

    head = createTreeUsingInAndPreOrderArray(inOrderArray ,preOrderArray , 0 , size-1 , size);
    printf("\n In-order : \n");
    print_in_order(head);
    printf("\n Pre-order : \n");
    print_pre_order(head);

    head = createTreeUsingInAndPostOrderArray(inOrderArray ,postOrderArray , 0 , size-1 , size);

    printf("\n\nIn-order : \n");
    print_in_order(head);
    printf("\n Post-order : \n");
    print_post_order(head);

}