#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int number)
{
    node *i = root;
    if (root == NULL)
    {
        i = (node *)malloc(sizeof(node));
        if (i != NULL)
        {
            i->element = number;
        }
    }
    else if (root->element > number)
    {
        root->left = insert(root->left, number);
    }
    else if (root->element < number)
    {
        root->right = insert(root->right, number);
    }
    else
    {
        printf("Tree does not accept same number values\n");
        return NULL;
    }

    return i;
}

int find(node *root, int number)
{
    int res = 0;
    if (root != NULL)
    {
        if (root->element == number)
        {
            res = 1;
        }
        else if (root->element > number)
        {
            res = res || find(root->left, number);
        }
        else
        {
            res = res || find(root->right, number);
        }
    }
    return res;
}

void printOrder(node *root)
{
    if (root != NULL)
    {
        printOrder(root->left);
        printf("%d ", root->element);
        printOrder(root->right);
    }
}

void printDetailed(node *root)
{
    if (root != NULL)
    {
        printDetailed(root->left);
        printf("Element at node: %d\n", root->element);
        printDetailed(root->right);
    }
    else
    {
        printf("Root is null.. returning\n");
    }
}

int treeHeight(node *root, int height)
{
    int res = height;
    if (root != NULL)
    {
        int left = treeHeight(root->left, height + 1);
        int right = treeHeight(root->right, height + 1);

        res = (left >= right) ? left : right;
    }
    else
    {
        res = res - 1;
    }

    return res;
}

void cleanUp(node *root)
{
    if (root != NULL)
    {
        cleanUp(root->left);
        cleanUp(root->right);
        // printf("Cleaning node: %d\n", root->element);
        free(root);
    }
    else
    {
        // printf("Root is null.. returning\n");
    }
}

int isBinaryTree(node *root)
{
    int res = 1;

    if (root != NULL)
    {
        if (root->left != NULL)
        {
            res = res && (root->left->element < root->element);
        }

        if (root->right != NULL)
        {
            res = res && (root->right->element > root->element);
        }

        if (res)
        {
            res = res && isBinaryTree(root->left) && isBinaryTree(root->right);
        }
    }
    else
    {
        res = 1;
    }

    return res;
}

int isBinaryTreeV2(node *root, int min, int max)
{
    int res = 1;
    if (root != NULL)
    {
        res = res && (root->element > min && root->element < max);
        res = res && isBinaryTreeV2(root->left, min, root->element);
        res = res && isBinaryTreeV2(root->right, root->element, max);
    }

    return res;
}


int isBinaryTreeV3(node *root)
{
    int res = 1;
    if (root != NULL)
    {
        //TODO: ACK
    }

    return res;
}

void findKNumber(node *root, int *k, int *resp)
{
    if (root != NULL && k > 0)
    {
        findKNumber(root->left, k, resp);
        *(k)--;

        if (*(k) == 0)
        {
            *(resp) = root->element;
        }

        findKNumber(root->right, k, resp);
    }
}

int main()
{

    node *root;

    node *notTree = (node *)malloc(sizeof(node));
    notTree->element = 3;
    notTree->right = (node *)malloc(sizeof(node));
    notTree->right->element = 2;

    node *weridTree = (node *)malloc(sizeof(node));
    weridTree->element = 1;
    weridTree->right = (node *)malloc(sizeof(node));
    weridTree->right->element = 2;

    printOrder(root);
    printf("\n");

    root = insert(root, 2);

    printOrder(root);
    printf("\n");

    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 8);

    printOrder(root);
    printf("\n");

    int k = 3;
    int kResp = -1;
    findKNumber(root, &k, &kResp);
    printf("the 3rd number in tree is (root): %d\n", kResp);


    // if (find(root, 5))
    // {
    //     printf("Found\n");
    // }
    // else
    // {
    //     printf("Not Found\n");
    // }

    // printf("Total tree height: %d\n", treeHeight(root, 0));

    // printf("Is binary tree (root): %d\n", isBinaryTree(root));
    // printf("Is binary tree (notTree): %d\n", isBinaryTree(notTree));
    // printf("Is binary tree (weirdTree): %d\n", isBinaryTree(weridTree));

    // printf("Is binary tree (root): %d\n", isBinaryTreeV2(root, 0x80000000, 0x7fffffff));
    // printf("Is binary tree (notTree): %d\n", isBinaryTreeV2(notTree, 0x80000000, 0x7fffffff));
    // printf("Is binary tree (weirdTree): %d\n", isBinaryTreeV2(weridTree, 0x80000000, 0x7fffffff));



    cleanUp(root);
    cleanUp(notTree);
    cleanUp(weridTree);

    return 0;
}