#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Check if Complete Binary Tree
int isCBT(struct Node* root) {
    if (!root) return 1;

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int seenNull = 0;

    while (front < rear) {
        struct Node* curr = queue[front++];

        if (curr == NULL) {
            seenNull = 1;
        } else {
            if (seenNull) return 0;

            queue[rear++] = curr->left;
            queue[rear++] = curr->right;
        }
    }
    return 1;
}

// Check Min Heap property
int isMinHeap(struct Node* root) {
    if (!root) return 1;

    if (root->left) {
        if (root->val > root->left->val) return 0;
    }

    if (root->right) {
        if (root->val > root->right->val) return 0;
    }

    return isMinHeap(root->left) && isMinHeap(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build tree from level order
    struct Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (2*i + 1 < n)
            nodes[i]->left = nodes[2*i + 1];
        if (2*i + 2 < n)
            nodes[i]->right = nodes[2*i + 2];
    }

    struct Node* root = nodes[0];

    if (isCBT(root) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}