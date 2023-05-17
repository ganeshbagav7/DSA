#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} tnode;

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

tnode *createNode()
{

    tnode *newNode = malloc(sizeof(tnode));
    if (newNode == NULL)
    {
        return NULL;
    }

    printf(" Enter Data : ");
    scanf("%d", &newNode->data);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

tnode *head = NULL;

void addNode(tnode *root)
{

    if (head == NULL)
    {
        printf("\n # Tree is empty \n adding a root node...\n");

        head = createNode();
        root = head;
    }

    if (root->left == NULL && root->right == NULL)
    {
        int ch = 1;
        printf("\n\n****** At node : %d ******\n\n", root->data);

        printf(" # At this node left and right both are null : \n");
        printf(" +L add node left       : press 1\n");
        printf(" +R add node right      : press 2\n");
        printf(" ^P back to parent node : press 3\n Enter : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            root->left = createNode();
            printf("\n +L Node added to left...\n\n");
        }
        else if (ch == 2)
        {
            root->right = createNode();
            printf("\n +R Node added to right...\n\n");
        }
        else
        {
            if (root == head)
            {
                printf("\n ^P Exiting tree...\n\n");
            }
            else
            {
                printf("\n ^P Back to parent node...\n\n");
            }
            return;
        }
    }

    if (root->left == NULL)
    {
        int ch = 1;
        while (ch == 1 || ch == 2)
        {
            printf("\n****** At node : %d ******\n\n", root->data);
            printf(" # Move to right or add node to left :\n");
            printf(" >R Move to right       : press 1\n");
            printf(" +L add node to left    : press 2\n");
            printf(" ^P back to parent node : press 3\n Enter : ");
            scanf("%d", &ch);

            if (ch == 1)
            {
                printf("\n >R Moving to right...\n\n");
                addNode(root->right);
            }
            else if (ch == 2)
            {
                root->left = createNode();
                printf("\n +L Node added to left...\n\n");
                break;
            }
            else
            {
                if (root == head)
                {
                    printf("\n ^P Exiting tree...\n\n");
                }
                else
                {
                    printf("\n ^P Back to parent node...\n\n");
                }
                return;
            }
        }
    }
    if (root->right == NULL)
    {
        int ch = 1;
        while (ch == 1 || ch == 2)
        {
            printf("\n\n****** At node : %d ******\n\n", root->data);
            printf(" # Move to left or add node to right :\n");
            printf(" <L move to left         : press 1\n");
            printf(" +R add node to right    : press 2\n");
            printf(" ^P back to parent node  : press 3\n Enter : ");
            scanf("%d", &ch);

            if (ch == 1)
            {
                printf("\n <L Moving to left...\n\n");
                addNode(root->left);
            }
            else if (ch == 2)
            {
                root->right = createNode();
                printf("\n +R Node added to right...\n\n");
                break;
            }
            else
            {
                if (root == head)
                {
                    printf("\n ^P Exiting tree...\n\n");
                }
                else
                {
                    printf("\n ^P Back to parent node...\n\n");
                }
                return;
            }
        }
    }

    int ch = 1;
    while (ch == 1 || ch == 2)
    {
        printf("\n\n*****At node : %d*******\n\n", root->data);
        printf(" #  Move to left or Move to right :\n");
        printf(" <L Move to left        : press 1\n");
        printf(" >R Move to right       : press 2\n");
        printf(" ^P back to parent node : press 3\n Enter : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("\n <L Moving to left...\n\n");
            addNode(root->left);
        }
        else if (ch == 2)
        {
            printf("\n >R Moving to right...\n\n");
            addNode(root->right);
        }
        else
        {
            if (root == head)
            {
                printf("\n ^P Exiting tree...\n\n");
            }
            else
            {
                printf("\n ^P Back to parent node...\n\n");
            }
            return;
        }
    }
}

int sum_of_tree_nodes(tnode * root)
{
    if (root == NULL)
        return 0;

    return root->data + sum_of_tree_nodes(root->left) + sum_of_tree_nodes(root->right);
}

int count_node_of_tree( tnode * root ){
    if(root==NULL)
        return 0;
    return 1+count_node_of_tree(root->left)+count_node_of_tree(root->right);
}

int hight_of_tree( tnode * root){
    
    if (root==NULL)
    {
        return -1;
    }

    int lsize = hight_of_tree(root->left);
    int rsize = hight_of_tree(root->right);

    if (lsize>rsize)
    {
        return 1+lsize;
    }
    
    return 1+rsize; 
    
}

void print_in_order_iterative(){

}

void main()
{
    int ch = 1;

    while (ch == 1)
    {
        printf("Enter operation :\n");
        printf("add node             : 1\n");
        printf("print pre order      : 2 \n");
        printf("print in order       : 3 \n");
        printf("print post order     : 4 \n");
        printf("sum of tree nodes    : 5 \n");
        printf("Enter : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addNode(head);
            break;
        case 2:
            if (head == NULL)
            {
                printf("Tree is empty...\n");
            }
            else
            {

                print_pre_order(head);
            }
            printf("\n");
            break;
        case 3:
            if (head == NULL)
            {
                printf("Tree is empty...\n");
            }
            else
            {
                print_in_order(head);
            }
            printf("\n");
            break;
        case 4:
            if (head == NULL)
            {
                printf("Tree is empty...\n");
            }
            else
            {

                print_post_order(head);
            }
            printf("\n");
            break;

        case 5:
            if (head == NULL)
            {
                printf("Tree is empty...\n");
            }
            else
            {
                printf("\n sum of tree node is  %d ",sum_of_tree_nodes(head));
            }
            printf("\n");
            break;
        default:
            printf("Wrong choice\n");
            break;
        }

        printf("\n Do you want to continue '1' to continue : ");
        scanf("%d", &ch);
    }
}
