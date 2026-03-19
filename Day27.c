#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Insert at end
Node* insertEnd(Node* head, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;

    return head;
}

// Get length of list
int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

// Find intersection (by value, as per problem example)
int findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    Node* p1 = head1;
    Node* p2 = head2;

    // Step 1: Align both lists
    int diff = abs(len1 - len2);
    if (len1 > len2) {
        while (diff--) p1 = p1->next;
    } else {
        while (diff--) p2 = p2->next;
    }

    // Step 2: Traverse together
    while (p1 && p2) {
        if (p1->data == p2->data) {
            return p1->data; // first common value
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return -1; // no intersection
}

int main() {
    int n, m, x;

    // First list
    scanf("%d", &n);
    Node* head1 = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    // Second list
    scanf("%d", &m);
    Node* head2 = NULL;
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}