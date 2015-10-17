#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct TreeNode
{
//Definition for a binary tree node.
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *create()
{
//q3: the example tree
    TreeNode *n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n1->val = 1;
    n1->left = (TreeNode *)malloc(sizeof(TreeNode));
    n1->right = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n2 = n1->left;
    n2->val = 2;
    n2->left = (TreeNode *)malloc(sizeof(TreeNode));
    n2->right = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n3 = n1->right;
    n3->val = 5;
    n3->left = NULL;
    n3->right = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *n4 = n2->left;
    n4->val = 3;
    n4->left = NULL;
    n4->right = NULL;
    TreeNode *n5 = n2->right;
    n5->val = 4;
    n5->left = NULL;
    n5->right = NULL;
    TreeNode *n7 = n3->right;
    n7->val = 6;
    n7->left = NULL;
    n7->right = NULL;
    return n1;
}

void printTree(TreeNode *tree)
{
    if (tree->left) {
        printTree(tree->left);
    }
    printf("%d\n", tree->val);
    if (tree->right) {
        printTree(tree->right);
    }
}

void flatten(TreeNode *root)
{
//each node's right child points to the next node of a pre-order traversal.
    struct TreeNode* L;
    while (root != NULL) {
        if (root->left != NULL) {
            L = root->left;
            while (L->right != NULL) {
                L = L->right;
            }
            L->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

int main()
{
//creat the binary tree
    TreeNode *test = create();
    double total_time;
    clock_t start, end;
    FILE *file = fopen("iterative.txt", "a");

    printf("Inorder Traversal:\n");
    printTree(test);
    start = clock();
    flatten(test);
    end = clock();
    printf("Inorder Traversal after flatten():\n");
    printTree(test);

    if (file) {
	    total_time = (double)(end - start) / CLOCKS_PER_SEC;
        fprintf(file, "%f\n", total_time);
        fclose(file);
    } 
    printf("execution time of flatten() : %f sec\n", total_time);  
    return 0;
}
