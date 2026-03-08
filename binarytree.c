#include <stdlib.h>

void inorderHelper(struct TreeNode* root, int* result, int* returnSize) {
    if (!root) return;

    inorderHelper(root->left, result, returnSize);

    result[*returnSize] = root->val;
    (*returnSize)++;

    inorderHelper(root->right, result, returnSize);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* result = (int*)malloc(100 * sizeof(int)); // max 100 nodes
    *returnSize = 0;
    inorderHelper(root, result, returnSize);
    return result;
}
