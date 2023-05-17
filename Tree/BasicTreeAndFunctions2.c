#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct stack
{
    struct tree *data;
    struct stack *next;
};
struct stack *top = NULL;
bool isEmpty()
{
    if (top == NULL)
        return true;
    return false;
}
void push(struct tree* temp){

    struct stack* stackframe = malloc(sizeof(struct stack));
    stackframe->data=temp;
    stackframe->next=top;
    top=stackframe;
}
struct tree* pop(){
    if(top==NULL)
        return NULL;
    struct tree* item = top->data;
    struct stack* temp= top;
    top=top->next;
    free(temp);
    return item;
}
void preOrder(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct tree *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct tree *root)
{

    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void iterativeInorder(struct tree *root)
{

    struct tree* temp = root;
    while (!isEmpty()||temp!=NULL){
        if(temp){
            push(temp);
            temp=temp->left;
        }else{
            temp=pop();
            printf("%d ",temp->data);
            temp=temp->right;
        }
    }
}
void printTree(struct tree *root)
{
    int k = 1;
    do
    {
        printf("1.PreOrder\n");
        printf("2.InOrder\n");
        printf("3.PostOrder\n");
        printf("4.iterativeInorder\n");
        printf("5.Exit\n");
        int ch;
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("PreOrder : ");
            preOrder(root);
            printf("\n");
            break;
        }
        case 2:
        {
            printf("InOrder : ");
            inOrder(root);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("PostOrder : ");
            postOrder(root);
            printf("\n");
            break;
        }
        case 4:
        {
            printf("IterativeInOrder : ");
            iterativeInorder(root);
            printf("\n");
            break;
        }
        case 5:
        {
            k = 0;
        }
        break;
        default:
            printf("Enter valid choice\n");
            break;
        }

    } while (k == 1);
}
struct tree *createnode(int level)
{
    level += 1;
    struct tree *root = malloc(sizeof(struct tree));
    printf("Enter Data : ");
    scanf("%d", &root->data);
    getchar();
    char ch;
    printf("Input to left of %d of level %d ?(y/Y) : ", root->data, level);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        root->left = createnode(level);
    else
        root->left = NULL;
    getchar();
    printf("Input to right of %d of level %d ?(y/Y) : ", root->data, level);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        root->right = createnode(level);
    else
        root->right = NULL;
    return root;
}

void main()
{

    struct tree *root = malloc(sizeof(struct tree));
    printf("Enter Data : ");
    scanf("%d", &root->data);
    printf("Tree Rooted witd %d\n", root->data);
    getchar();
    char ch;
    printf("Input to left of root node %d ?(y/Y) : ", root->data);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        root->left = createnode(0);
    else
        root->left = NULL;
    getchar();
    printf("Input to right of root node %d ?(y/Y) : ", root->data);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
        root->right = createnode(0);
    else
        root->right = NULL;

    printTree(root);
}