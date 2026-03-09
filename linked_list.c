#include <stdio.h>
#include <stdlib.h>


struct Node{
    int data;
    struct Node*next;
};

struct Node* createNode(int x){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode-> data =x;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteHead(struct Node *head){
    if (head == NULL){
        return NULL;
    }
    struct Node* temp = head;
    head = head-> next;
    free(temp);
    return head;
}

void printList(struct Node* curr){
    while(curr != NULL) {
        printf("%d", curr->data);
        if (curr->next != NULL){
            printf(" ->");

        }
        curr = curr ->next;
    }
    printf("\n");
}

int main() {
    struct Node*head= createNode(8);
    head->next = createNode(21);
    head->next->next = createNode(3);
    head->next->next->next = createNode(21);
    head->next->next->next->next = createNode(7);

    head = deleteHead(head);
    printList(head);
    return 0;
}