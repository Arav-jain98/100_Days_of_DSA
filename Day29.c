#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate list right by k places
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    struct ListNode* temp = head;
    int n = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    // Make it circular
    temp->next = head;

    // Handle k > n
    k = k % n;
    int steps = n - k;

    // Find new tail
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // Set new head
    struct ListNode* newHead = temp->next;
    temp->next = NULL;

    return newHead;
}

// Function to print the list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, x, k;

    scanf("%d", &n);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* newNode = createNode(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}