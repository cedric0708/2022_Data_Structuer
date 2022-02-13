#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct listnode {
	member data;
	struct listnode* next;
	struct listnode* prev;
}node;

typedef struct l{
	node* head;
	node* crnt;
}list;

typedef struct m{
	int no;
	char name[20];
}member;

//노드를 동적으로 생성
static node* allocnode(void) {
	return calloc(1, sizeof(node));
}

//n이 가리키는 노드의 각 멤버에 값을 설정
static void setnode(node* n, const member* x, const node* next) {
	n->data = *x;
	n->next = next;
}

//연결 리스트를 초기화
void initialize(list* List) {
	List->head = NULL;
	List->crnt = NULL;
}

//compare 함수를 사용해 x 검색
node* search(list* List, const member* x, int compare(const member* x, const member* y)) {
	node* ptr = List->head;
	while (ptr != NULL) {
		if (compare(&ptr->data, x) == 0) {//키 값이 같은 경우
			List->crnt = ptr;
			return ptr;//검색 성공
		}
		ptr = ptr->next;//다음 노드를 선택
	}
	return NULL;//검색 실패
}

//머리에 노드를 삽입하는 함수
void insertfront(list* List, const member* x) {
	node* ptr = List->head;
	List->head = List->crnt = allocnode();
	setnode(List->head, x, ptr);
}

//꼬리에 노드를 삽입하는 함수
void insertrear(list* List, const member* x) {
	if (List->head == NULL)//비어 있는 경우
		insertfront(List, x);//머리에 삽입
	else {
		node* ptr = List->head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = List->crnt = allocnode();
		setnode(ptr->next, x, NULL);
	}
}

//머리 노드를 삭제하는 함수
void removefront(list* List) {
	if (List->head != NULL) {
		node* ptr = List->head->next;//두 번째 노드에 대한 포인터
		free(List->head);//머리 노드를 해제
		List->head = List->crnt = ptr;//새로운 머리 노드
	}
}

//꼬리 노드를 삭제하는 함수
void removerear(list* List) {
	if (List->head != NULL) {
		if ((List->head)->next == NULL)//노드가 1개만 있는 경우
			removefront(List);//머리 노드를 삭제
		else {
			node* ptr = List->head;
			node* pre;
			while (ptr->next != NULL) {
				pre = ptr;
				ptr = ptr->next;
			}
			pre->next = NULL;//pre는 꼬리 노드로부터 두 번째 노드
			free(ptr);//ptr은 꼬리 노드
			List->crnt = pre;
		}
	}
}

//선택한 노드를 삭제하는 함수
void removecurrent(list* List) {
	if (List->head != NULL) {
		if ((List->crnt) == List->head)//머리 노드를 선택한 상태라면
			removefront(List);//머리 노드를 삭제
		else {
			node* ptr = List->head;
			while (ptr->next != List->crnt) {
				ptr = ptr->next;
			}
			ptr->next = List->crnt->next;
			free(List->crnt);
			List->crnt = ptr;
		}
	}
}

//모든 노드를 삭제
void clear(list* List) {
	while (List->head != NULL) {
		removefront(List);
	}
	List->crnt = NULL;
}

//선택한 노드의 데이터를 출력
void printcurrent(const list* List) {
	if (List->crnt == NULL)
		printf("선택한 노드가 없습니다.");
	else
		printcurrent(&List->crnt->data);
}

//선택한 노드의 데이터를 출력(줄 바꿈 문자 포함)
void printlncurrent(const list* List) {
	printcurrent(List);
	putchar('\n');
}

//모든 노드의 데이터를 리스트 순으로 출력하는 함수
void print(const list* List) {
	if (List->head == NULL)
		puts("노드가 없습니다.");
	else {
		node* ptr = List->head;
		puts("<모두 보기>");
		while (ptr != NULL) {
			printlnmember(&ptr->data);
			ptr = ptr->next;//다음 노드를 선택
		}
	}
}

//연결 리스트를 종료하는 함수
void terminate(list* List) {
	clear(List);
}
