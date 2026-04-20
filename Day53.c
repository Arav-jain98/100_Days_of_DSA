#include <stdio.h>
#include <stdlib.h>

// Tree Node
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

// Build tree from level order
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct TreeNode* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    // queue for BFS (node + hd)
    struct TreeNode* nodeQ[1000];
    int hdQ[1000];

    int front = 0, rear = 0;

    nodeQ[rear] = root;
    hdQ[rear++] = 0;

    // map: HD range [-1000, 1000]
    int map[2001][100];
    int colSize[2001] = {0};

    int minHD = 1000, maxHD = -1000;

    while (front < rear) {
        struct TreeNode* node = nodeQ[front];
        int hd = hdQ[front];
        front++;

        int idx = hd + 1000;

        map[idx][colSize[idx]++] = node->val;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (node->left) {
            nodeQ[rear] = node->left;
            hdQ[rear++] = hd - 1;
        }

        if (node->right) {
            nodeQ[rear] = node->right;
            hdQ[rear++] = hd + 1;
        }
    }

    // print result
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 1000;
        for (int j = 0; j < colSize[idx]; j++) {
            printf("%d ", map[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}