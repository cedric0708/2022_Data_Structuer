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
	//노드 초기화
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

//(메모리 상에서만)노드 삭제
void deletenode(node* node) {
	free(node);
}

//노드 가져오기
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

//리스트 개수 반환
int countnode(node* head) {
	int count = 0;
	node* horse = head;

	while (horse != NULL) {
		horse = horse->next;
		count++;
	}

	return count;
}

//노드 추가(append)
void addnode(node** head, node* newnode) {
	//리스트가 존재하지 않는 경우
	if ((*head) == NULL) {
		*head = newnode;
	}
	//리스트가 존재하는 경우
	else {
		node* horse = (*head);

		while (horse->next != NULL) {
			horse = horse->next;
		}

		horse->next = newnode;
		newnode->prev = horse;
	}
}

//노드 삽입
void insertafter(node* current, node* newnode) {
	//Headlist로 삽입하는 경우
	if (current->prev == NULL && current->next == NULL) {
		current->next = newnode;
		newnode->prev;
	}
	else {  //Taillist로 삽입하는 경우
		if (current->next == NULL) {
			current->next = newnode;
			newnode->prev = current;
		}
		else {  //중간에 삽입하는 경우
			current->next->prev = newnode;
			newnode->prev = current;
			newnode->next = current->next;
			current->next = newnode;
		}
	}
}

//노드 삭제
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
