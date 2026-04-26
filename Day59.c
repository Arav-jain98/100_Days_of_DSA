#include <stdio.h>
#include <stdlib.h>

// Definition of tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree recursively
struct TreeNode* build(
    int* inorder, int inStart, int inEnd,
    int* postorder, int* postIndex,
    int* map
) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = newNode(rootVal);

    int inIndex = map[rootVal];

    // Build right first
    root->right = build(inorder, inIndex + 1, inEnd, postorder, postIndex, map);
    root->left  = build(inorder, inStart, inIndex - 1, postorder, postIndex, map);

    return root;
}

// Preorder traversal
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int* inorder = (int*)malloc(sizeof(int) * n);
    int* postorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    // Map (assuming values <= 10000)
    int* map = (int*)malloc(sizeof(int) * 10001);
    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }

    int postIndex = n - 1;

    struct TreeNode* root = build(inorder, 0, n - 1, postorder, &postIndex, map);

    // Print preorder
    preorder(root);

    // Free memory (optional here but good practice)
    free(inorder);
    free(postorder);
    free(map);

    return 0;
}