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
	Node* tail = NULL;
	for (int i = 0;i < num;i++) {
		int data;
		printf("Node number %d data: ", i + 1);
		scanf_s("%d", &data);
		Node* temp = malloc(sizeof(Node));
		if (head == NULL) {
			temp->data = data;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else {
			temp->data = data;
			if (head->next == NULL) {
				head->next = temp;
			}
			else {
				tail->next = temp;
			}
			tail = temp;
			tail->next = NULL;
		}
	}
	simpleLinkListDisplay:
		system("cls");
		printf("Simple Link List \n 1. New Simple Link List\n 2. Display Items in List\n 3. Insert element\n 4. Return\n ");
		int choice = 0;
		int numNodes = 0;
		int element = 0;
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
			printf("\n 1. Insert element from head\n 2. Insert element from tail \n 3. Insert element to index \n");
			scanf_s("%d", &choice);
			switch (choice) {
			case 1:
				printf("\n Enter element to insert from head: ");
				scanf_s(" %d", &element);
				Node* temp = malloc(sizeof(Node));
				temp->data = element;
				temp->next = head;
				head->prev = temp;
				head = temp;
				printf("\n Element successfully added");
				_getch();
				goto simpleLinkListDisplay;
			}
			break;
		case 4:
			return;
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
	Node* currentNode = NULL;
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
			tail = temp;
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
doublyLinkListDisplay:
	system("cls");
	printf("Doubly Link List \n 1. New Doubly Link List\n 2. Display Items in List From Head\n 3. Display Items in List From Tail\n 4. Insert element\n 5. Return\n ");
	int choice = 0;
	int element = 0;
	int numNodes = 0;
	int count = 0;
	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nType: Doubly Linked List");
		printf("\nEnter number of nodes: ");
		scanf_s("%d", &numNodes);
		SimpleLinkedList(numNodes);
	case 2:
		printf("\nItems in the linked list from the head are\n ");
		currentNode = head;
		while (currentNode != NULL) {
			printf("%d  ", currentNode->data);
			currentNode = currentNode->next;
		}
		_getch();
		break;
	case 3:
		printf("\nItems in the linked list from the tail are\n ");
		currentNode = tail;
		while (currentNode != NULL) {
			printf("%d  ", currentNode->data);
			currentNode = currentNode->prev;
		}
		_getch();
		break;
	case 4:
		printf("\n 1. Insert element from head\n 2. Insert element from tail \n 3. Insert element to index \n");
		scanf_s("%d", &choice);
		switch (choice) {
		case 1:
			printf("\n Enter element to insert from head: ");
			scanf_s(" %d", &element);
			Node* temp = malloc(sizeof(Node));
			temp->data = element;
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
			printf("\n Element successfully added");
			_getch();
			goto doublyLinkListDisplay;
		}
		break;
	case 5:
		return;
		break;
	default:
		break;
	}
	goto doublyLinkListDisplay;
	return;
}
int main() {
	int type;
	int numNodes;
start:
	numNodes = 0;
	system("cls");
	printf("Linked List of Numbers\nChoose a linked list type: \n 1. Simple Linked List\n 2. Doubly Linked List\n 3. Exit\n ");
	scanf_s("%d", &type);
	switch (type) {
	case 1:
		printf("\nType: Simple Linked List");
		printf("\nEnter number of nodes: ");
		scanf_s("%d", &numNodes);
		SimpleLinkedList(numNodes);
		goto start;
		break;
	case 2:
		printf("\nType: Doubly Linked List");
		printf("\nEnter number of nodes: ");
		scanf_s("%d", &numNodes);
		DoublyLinkedList(numNodes);
		goto start;
		break;
	case 3:
		exit(0);
		break;
	}
	return 0;
}