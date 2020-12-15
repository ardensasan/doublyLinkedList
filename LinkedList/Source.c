#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

int main() {
	Node* head = NULL;
	Node* tail = NULL;
	int num;
	printf("Enter number of nodes: ");
	scanf_s("%d", &num);
	for (int i = 0;i < num;i++) {
		int data;
		printf("Node number %d data: ", i + 1);
		scanf_s("%d", &data);
		Node* temp = (Node*)malloc(sizeof(Node));
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
		printf("%d", head->data);
		head = head->next;
	}
}