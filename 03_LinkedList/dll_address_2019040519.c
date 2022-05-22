#include "dll_address.h"
#include <string.h>
#include <stdlib.h>

// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화	--- 변경금지
void list_init(DoublyLinkedList* list)
{
	list->head = NULL;
	list->tail = NULL;
}

// 주소록 출력	--- 변경금지
void print_list(DoublyLinkedList* list)
{
	if (is_empty_list(list))
		printf("XXXXXXXXX 빈 주소록 XXXXXXXXXX\n");
	else
	{
		printf("--------------------------\n");
		printf("---- 주소록 출력 시작 ----\n");
		printf("--------------------------\n");
		printf("  학번 \t\t 이름\n");
		printf("--------------------------\n");
		Node* tmp = list->head;
		while (tmp != NULL)
		{
			printf("%d\t%s\n", tmp->id, tmp->name);
			tmp = tmp->next;
		}

		printf("\n\n");
	}
}
// --------------------------------------------------------------------
int dll_size = 0;
/*
* is_empty
* return true/false
*/
bool is_empty_list(DoublyLinkedList* list)
{
	if(dll_size == 0)
		return true;
	else
		return false;
}

/*
* is_full
* return true/false
*/
bool is_full_list(DoublyLinkedList* list)
{
	if(dll_size == MAX_ADDRESS_SIZE)
		return true;
	else
		return false;
}

/*
* 학번 중복 예외처리 *
* 이미 있는 학번이 입력되었다면
* 해당 학번 노드를 찾아 새로 입력된 이름으로 업데이트
*/

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int insert_head(DoublyLinkedList* list, char* name, int id)
{
	if(is_full_list(list))
		return -1;
	else {
		Node *new = (Node *)malloc(sizeof(Node));
		new->id = id;
		strcpy(new->name, name);
		new->prev = NULL;
		new->next = NULL;
		if(list->head){
				new->next = list->head;
				list->head->prev = new;
		}
		else 
			list->tail = new;
		list->head = new;
		++dll_size;
		return 0;
	}
}

/*
* insert_head
* 리스트 뒤에 삽입
* return 성공 0 / 실패 -1
*/
int insert_tail(DoublyLinkedList* list, char* name, int id)
{
	if(is_full_list(list))
		return -1;
	else {
		Node *new = (Node *)malloc(sizeof(Node));
		new->id = id;
		strcpy(new->name, name);
		new->prev = NULL;
		new->next = NULL;
		if(list->tail){
			new->prev = list->tail;
			list->tail->next = new;
		}
		else 
			list->head = new;
		list->tail = new;
		++dll_size;
		return 0;
	}
}

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int delete_head(DoublyLinkedList* list) 
{
	if(is_empty_list(list))
		return -1;
	else {
		Node *delete = list->head;
		if(delete == list->tail){
			list->head = NULL;
			list->tail = NULL;
		}else {
			delete->next->prev = NULL;
			list->head = delete->next;
		}
		free(delete);
		--dll_size;
		return 0;
	}
}

/*
* insert_head
* 리스트 앞에 삽입
* return 성공 0 / 실패 -1
*/
int delete_tail(DoublyLinkedList* list)
{
	if(is_empty_list(list))
		return -1;
	else {
		Node *delete = list->tail;
		if(delete == list->head){
			list->head = NULL;
			list->tail = NULL;
		}else {
			delete->prev->next = NULL;
			list->tail = delete->prev;
		}
		free(delete);
		--dll_size;
		return 0;
	}
}

// ------------- 심화 ---------------
/*
* 학번으로 검색
* printf 출력 "이름"
* return 성공 0 / 실패 -1
*/
int search_name(DoublyLinkedList* list, int id)
{
	Node* temp = list->head;
	int flag = 0;
	while(temp != NULL){
		if(temp->id == id){
			flag = 1;
			printf("%s ", temp->name);
		}
		temp = temp->next;
	}
	/*
	* ppt에 "성공 0 / 실패 -1 출력"하라고 기재되어 있어, 출력과 함께 리턴
	*/
	if(flag == 1){
		printf("0\n");
		return 0;
	}
	else {
		printf("-1\n");
		return -1;
	}
}

/*
* 이름으로 검색 
* printf 출력 "학번" (해당이름 모든 학번 출력)
* return 성공 0 / 실패 -1
*/
int search_id(DoublyLinkedList* list, char* name)
{
	Node* temp = list->head;
	int flag = 0;
	while(temp != NULL){
		if(!strcmp(temp->name, name)){
			flag = 1;
			printf("%d ", temp->id);
		}
		temp = temp->next;
	}
	/*
	* ppt에 "성공 0 / 실패 -1 출력"하라고 기재되어 있어, 출력과 함께 리턴
	*/
	if(flag == 1){
		printf("0\n");
		return 0;
	}
	else {
		printf("-1\n");
		return -1;
	}
}