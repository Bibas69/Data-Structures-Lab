#include<stdio.h>
#include<stdlib.h>

//Structure of a node.
struct Node{
	int data;
	struct Node *next;
};

//Insert an element at the beginning of the list.
void insertAtBeginning(struct Node **pointerToHead, int x){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode -> data = x;
	newNode -> next = *pointerToHead;
	*pointerToHead = newNode;
}

//Insert an element at the end of the list.
void insertAtEnd(struct Node **pointerToHead, int x){
	struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode -> data = x;
	if(*pointerToHead == NULL){
		newNode -> next = *pointerToHead;
		*pointerToHead = newNode;
		return;
	}
	struct Node *current = *pointerToHead;
	while(current -> next != NULL){
		current = current -> next;
	}
	newNode -> next = current -> next;
	current -> next = newNode;
}

//Insert an element at a specific position in the list.
void insertAt(struct Node **pointerToHead, int pos, int x){
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode -> data = x;
	if(pos == 1){
		newNode -> next = *pointerToHead;
		*pointerToHead = newNode;
		return;
	}
	struct Node *current = *pointerToHead;
	for(int i=1; i<pos-1; i++){
		current = current -> next;
	}
	
	if(current == NULL){
		printf("Invalid position\n");
		free(newNode);
		return;
	}
	
	newNode -> next = current -> next;
	current -> next = newNode;
}

//Delete an element from the beginning of the list.
void deleteFromBeginning(struct Node **pointerToHead){
	if(*pointerToHead == NULL){
		printf("List is empty\n");
		return;
	}
	struct Node *temp = *pointerToHead;
	*pointerToHead = temp -> next;
	free(temp);
}

//Delete an element from the end of the list.
void deleteFromEnd(struct Node **pointerToHead){
	if(*pointerToHead == NULL){
		printf("List is empty\n");
		return;
	}
	struct Node *current = *pointerToHead;
	if((*pointerToHead) -> next == NULL){
		*pointerToHead = NULL;
		free(current);
		return;
	}
	while(current -> next -> next != NULL){
		current = current -> next;
	}
	struct Node *endNode = current -> next;
	current -> next = NULL;
	free(endNode);
}

//Delete an element from a specific position of the list.
void deleteFrom(struct Node **pointerToHead, int pos){
	if(*pointerToHead == NULL){
		printf("List is empty\n");
		return;
	}
	struct Node *current = *pointerToHead;
	if(pos == 1){
		*pointerToHead = current -> next;
		free(current);
		return;
	}
	for(int i=1; i<pos-1; i++){
		current = current -> next;
	}
	if(current == NULL || current -> next == NULL){
		printf("Invalid position\n");
		return;
	}
	struct Node *temp = current -> next;
	current -> next = temp -> next;
	free(temp);
}

//Transverse and display the list.
void Print(struct Node *head){
	while(head != NULL){
		printf("%d\t", head -> data);
		head = head -> next;
	}
	printf("\n");
}

//Reverse the original list.
void reverseList(struct Node **pointerToHead){
	struct Node *prev, *current, *next;
	prev = NULL;
	current = *pointerToHead;
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*pointerToHead = prev;
}

//Reverse the original list using recursion.
void Reverse(struct Node **pointerToHead, struct Node *p){
	if(p -> next == NULL){
		*pointerToHead = p;
		return;
	}
	Reverse(pointerToHead, p -> next);
	struct Node *next = p -> next;
	next -> next = p;
	p -> next = NULL;
}

//Print reversed list using recursion.
void printReverse(struct Node *head){
	if(head == NULL){
		printf("\n");
		return;
	}
	printReverse(head -> next);
	printf("%d\t", head -> data);
}

int main(){
	struct Node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 70);
	insertAtBeginning(&head, 80);
	insertAtBeginning(&head, 90);
	Print(head);
	Reverse(&head, head);
	Print(head);
	return 0;
}
