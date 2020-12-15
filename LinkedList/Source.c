#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct node Node;
struct node {
	int data;
	Node* next;
	Node* prev;
};

void SimpleLinkedList(int num) {
	Node* head = NULL;
	for (int i = 0;i < num;i++) {
		int data;
		printf("Node number %d data: ", i + 1);
		scanf_s("%d", &data);
		Node* temp = malloc(sizeof(Node));
		if (temp)
		{
			if (head == NULL) {
				temp->data = data;
				temp->next = NULL;
				head = temp;
			}
			else {
				temp->data = data;
				temp->next = head;
				head = temp;
			}
		}
		else {
			printf("Malloc Failed to Allocate Memory");
			exit(0);
		}
	}
	simpleLinkListDisplay:
		system("cls");
		printf("Simple Link List \n 1. New Simple Link List\n 2. Display Items in List\n 3. Exit\n");
		int choice = 0;
		int numNodes = 0;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nType: Simple Linked List");
			printf("\nEnter number of nodes: ");
			scanf_s("%d", &numNodes);
			SimpleLinkedList(numNodes);
		case 2:
			printf("\nItems in the linked list are\n");
			Node* currentNode = head;
			while (currentNode != NULL) {
				printf("%d  ", currentNode->data);
				currentNode = currentNode->next;
			}
			_getch();
			break;
		case 3:
			exit(0);
			break;
		default:
			break;
		}
	goto simpleLinkListDisplay;
	return;
}

void DoublyLinkedList(int num) {
	Node* head = NULL;
	Node* tail = NULL;
	for (int i = 0;i < num;i++) {
		int data;
		printf("Node number %d data: ", i + 1);
		scanf_s("%d", &data);
		Node* temp = malloc(sizeof(Node));
		if (head == NULL) {
			temp->data = data;
			temp->next = NULL;
			temp->prev = NULL;
			head = temp;
		}
		else {
			temp->data = data;
			if (head->next == NULL) {
				temp->prev = head;
				head->next = temp;
			}
			else {
				temp->prev = tail;
				tail->next = temp;
			}
			tail = temp;
			tail->next = NULL;
		}
	}
	while (head != NULL) {
		printf("%d  ", head->data);
		head = head->next;
	}
	return;
}
int main() {
	int type;
	int numNodes = 0;
	printf("Linked List of Numbers\nChoose a linked list type: \n 1. Simple Linked List\n 2. Doubly Linked List\n 3. Exit\n");
	scanf_s("%d", &type);
	switch (type) {
	case 1:
		printf("\nType: Simple Linked List");
		printf("\nEnter number of nodes: ");
		scanf_s("%d", &numNodes);
		SimpleLinkedList(numNodes);
		break;
	case 2:
		printf("\nType: Doubly Linked List");
		printf("\nEnter number of nodes: ");
		scanf_s("%d", &numNodes);
		DoublyLinkedList(numNodes);
		break;
	case 3:
		exit(0);
		break;
	}
	return 0;
}