#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


typedef struct TreeNode
{
//Definition for a binary tree node.
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createTree()
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
    TreeNode *n6 = n3->right;
    n6->val = 6;
    n6->left = NULL;
    n6->right = NULL;
    return n1;
}

int testTree(TreeNode *root)
{
//check the tree after flatten it
    if (root->val == 1 && root->right->val == 2 && root->right->right->val == 3 &&
        root->right->right->right->val == 4 && root->right->right->right->right->val == 5 &&
        root->right->right->right->right->right->val == 6 )
        return 1;
    else
        return 0;
}

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec - t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
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
    TreeNode *example = createTree();
    double total_time = 0;
    struct timespec start, end;
    FILE *file = fopen("iterative.txt", "a");

    clock_gettime(CLOCK_REALTIME, &start);
    flatten(example);
    clock_gettime(CLOCK_REALTIME, &end);
    total_time = diff_in_second(start, end);
    assert(1 == testTree(example) && "flatten error");

    if (file) {
        fprintf(file, "%f\n", total_time);
        fclose(file);
    } 
    printf("execution time of flatten() : %f sec\n", total_time);
    free(example);
  
    return 0;
}
