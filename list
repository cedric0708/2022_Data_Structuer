# 리스트

### 노드 작업

#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//노드 정의
typedef struct listnode {
	int data;
	struct listnode* next;
	struct listnode* prev;
}node;

//노드 생성
node* createnode(int data) {
	node* newnode = (node*)malloc(sizeof(node));

	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//노드 삭제
void deletenode(node* node) {
	free(node);
}

node* getnodeat(node* head, int index) {
	node* horse = head;
	int count = 0;

	while (horse != NULL) {

		if (count++ == index) {
			return horse;
		}
		horse = horse->next;
	}

	return NULL;
}

int countnode(node* head) {
	int count = 0;
	node* horse = head;

	while (horse != NULL) {
		horse = horse->next;
		count++;
	}

	return count;
}

void addnode(node** head, node* newnode) {

	if ((*head) == NULL) {
		*head = newnode;
	}

	else {
		node* horse = (*head);

		while (horse->next != NULL) {
			horse = horse->next;
		}

		horse->next = newnode;
		newnode->prev = horse;
	}
}

void insertafter(node* current, node* newnode) {

	if (current->prev == NULL && current->next == NULL) {
		current->next = newnode;
		newnode->prev;
	}
	else {
		if (current->next == NULL) {
			current->next = newnode;
			newnode->prev = current;
		}
		else {
			current->next->prev = newnode;
			newnode->prev = current;
			newnode->next = current->next;
			current->next = newnode;
		}
	}
}

void removenode(node** head, node* remove) {

	if (*head == remove) {
		*head = remove->next;
	}

	if (remove->next != NULL) {
		remove->next->prev = remove->prev;
	}

	if (remove->prev != NULL) {
		remove->prev->next = remove->next;
	}

	deletenode(remove);
}
