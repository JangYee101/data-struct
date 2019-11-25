//二叉树

#include <stdio.h>
#include <stdlib.h>

int data[100]={1,2,3,0,0,4,0,0,5,6,0,0,7,0,0}, data_length=15, index_for_data=0;

struct TreeNode
{
    int val;
    struct TreeNode * right_node;
    struct TreeNode * left_node;
};

void createTree(struct TreeNode **root)
{
    if(data[index_for_data] == 0 || index_for_data >= data_length)
    {
        index_for_data++;
        *root =  NULL;
        return ;
    }
    *root = calloc(1, sizeof(struct TreeNode));
    if(*root == NULL)
    {
        printf("calloc faild! exit.........\n");
        exit(1);
    }
    (*root)->val = data[index_for_data];
    index_for_data++;
    createTree(&((*root)->left_node));
    createTree(&((*root)->right_node));
    return ;
}

void travers_first(struct TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d\n", root->val);
    travers_first(root->left_node);
    travers_first(root->right_node);
    return;
}

void travers_middle(struct TreeNode * root)
{
    if(root == NULL)
        return;
    travers_middle(root->left_node);
    printf("%d\n", root->val);
    travers_middle(root->right_node);
    return;
}

void travers_last(struct TreeNode * root)
{
    if(root == NULL)
        return;
    travers_last(root->left_node);
    travers_last(root->right_node);
    printf("%d\n", root->val);
    return;
}

int main()
{
    struct TreeNode * root;
    createTree(&root);
    travers_first(root);
    printf("-------------------------\n");
    travers_middle(root);
    printf("-------------------------\n");
    travers_last(root);
    printf("-------------------------\n");
    return 0;
}
