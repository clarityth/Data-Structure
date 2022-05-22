#include "stack_linkedlist.h"
#include <stdlib.h>

// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

int size = 0; // 스택의 원소 개수 저장 변수

// 스택 초기화
void stack_init_ls(LinkedList_Stack* stack)
{
    stack->top = NULL;
}

// --------------------------------------------------------------------

/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
*/

// --------------------------------------------------------------------
// 기초 스택 구현 - 모두 구현 B
// --------------------------------------------------------------------

// 스택이 비어있는지 확인, true/false 반환
bool is_empty_ls(LinkedList_Stack* stack)
{
    if (stack -> top == NULL)
        return true;
    else 
        return false;
}


/*
* 스택이 가득찼는지 확인, true/false 반환
* 스택의 최대 원소의 개수는 MAX_STACK_SIZE
*/
bool is_full_ls(LinkedList_Stack* stack)
{
    if (size == MAX_STACK_SIZE)
        return true;
    else
        return false;
}


// 스택에 원소 삽입
void push_ls(LinkedList_Stack* stack, int data)
{
    Node* new = (Node *)malloc(sizeof(Node));
    if (!is_full_ls(stack)){
        new -> data = data;
        new -> next = stack -> top;
        stack -> top = new;
        size++;
    }
}


// 스택의 최상위 원소(top)를 삭제하고 반환
int pop_ls(LinkedList_Stack* stack)
{
    Node* temp = stack -> top;
    if (!is_empty_ls(stack)){
        int data = temp -> data;
        stack -> top = temp -> next;
        size--;
        free(temp);
        return data;
    }
}


// --------------------------------------------------------------------
// 심화 스택 구현
// --------------------------------------------------------------------

// 현재 스택 원소 개수 반환
int get_stack_size_ls(LinkedList_Stack* stack)
{
    return size;
}


// 스택의 최상위 원소(top) 값 반환
int get_top_ls(LinkedList_Stack* stack)
{
    return stack -> top -> data;
}


/*
* 스택의 최상위 원소부터 순서대로 출력 (pop X)
* top ... bottom
* ex) 5 10 12 4 3
*/
void print_stack_ls(LinkedList_Stack* stack)
{
    Node* ptr = stack -> top;
    while (ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
}

