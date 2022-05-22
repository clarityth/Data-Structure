#include "stack_linkedlist.h"
#include <stdlib.h>

// --------------------------------------------------------------------
// ���� ����
// --------------------------------------------------------------------

int size = 0; // ������ ���� ���� ���� ����

// ���� �ʱ�ȭ
void stack_init_ls(LinkedList_Stack* stack)
{
    stack->top = NULL;
}

// --------------------------------------------------------------------

/*
* ������ ���ǻ���
* 1. �Լ���� �Ű������� �����Ͻ��� ������.
* 2. ��ȯ�� ��Ȯ�ϰ� �������ּ���. (bool, int)
*/

// --------------------------------------------------------------------
// ���� ���� ���� - ��� ���� B
// --------------------------------------------------------------------

// ������ ����ִ��� Ȯ��, true/false ��ȯ
bool is_empty_ls(LinkedList_Stack* stack)
{
    if (stack -> top == NULL)
        return true;
    else 
        return false;
}


/*
* ������ ����á���� Ȯ��, true/false ��ȯ
* ������ �ִ� ������ ������ MAX_STACK_SIZE
*/
bool is_full_ls(LinkedList_Stack* stack)
{
    if (size == MAX_STACK_SIZE)
        return true;
    else
        return false;
}


// ���ÿ� ���� ����
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


// ������ �ֻ��� ����(top)�� �����ϰ� ��ȯ
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
// ��ȭ ���� ����
// --------------------------------------------------------------------

// ���� ���� ���� ���� ��ȯ
int get_stack_size_ls(LinkedList_Stack* stack)
{
    return size;
}


// ������ �ֻ��� ����(top) �� ��ȯ
int get_top_ls(LinkedList_Stack* stack)
{
    return stack -> top -> data;
}


/*
* ������ �ֻ��� ���Һ��� ������� ��� (pop X)
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

