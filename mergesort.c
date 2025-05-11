#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
    } else {
        struct Node* temp = *headRef;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}
void splitList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
struct Node* sortedMerge(struct Node* a, struct Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;
    if (a->data <= b->data) {
        result = a;
        result->next = sortedMerge(a->next, b);
    } else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
}
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    if (head == NULL || head->next == NULL)
        return;

    struct Node *a, *b;
    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}
void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    append(&head, 40);
    append(&head, 20);
    append(&head, 10);
    append(&head, 30);

    printf("Original List: ");
    display(head);

    mergeSort(&head);

    printf("Sorted List (Merge Sort): ");
    display(head);

    return 0;
}
