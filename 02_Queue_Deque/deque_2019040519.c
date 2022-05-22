#include "deque.h"
#include <stdlib.h>


// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화
void deque_init(LinkedList_Deque* deque)
{
    deque->front = NULL;
    deque->rear = NULL;
}

// --------------------------------------------------------------------


/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
* 3. 발생할 수 있는 모든 예외사항을 처리해주세요. (underflow/overflow)
*/

// --------------------------------------------------------------------
// Deque 구현
// --------------------------------------------------------------------
int dq_size = 0;
// true/false 반환
bool is_empty_deque(LinkedList_Deque* deque)
{
    if(dq_size == 0)
        return true;
    else 
        return false;
}

// true/false 반환
bool is_full_deque(LinkedList_Deque* deque)
{
    if(dq_size == MAX_DEQUE_SIZE)
        return true;
    else
        return false;
}


// Input 성공 : 0 반환 / 실패 : -1 반환
int addfront_deque(LinkedList_Deque* deque, int data)
{
    if(is_full_deque(deque))
        return -1;
    else{
        Node_Deque *new = (Node_Deque *)malloc(sizeof(Node_Deque));
        new->data = data;
        new->next = NULL;
        if(deque->front)
            new->next = deque->front;
        else
            deque->rear = new;
        deque->front = new;
        ++dq_size;
        return 0;
    }
}

int addrear_deque(LinkedList_Deque* deque, int data)
{
    if(is_full_deque(deque))
        return -1;
    else{
        Node_Deque *new = (Node_Deque *)malloc(sizeof(Node_Deque));
        new->data = data;
        new->next = NULL;
        if(deque->rear){
            deque->rear->next = new;
        } 
        else
            deque->front = new;
        deque->rear = new;
        ++dq_size;
        return 0;
    }
}

// Output 성공 : Output 값 반환 / 실패 : -1 반환
int delfront_deque(LinkedList_Deque* deque)
{
    if(is_empty_deque(deque))
        return -1;
    else{
        Node_Deque *delete = deque->front;
        int dq_data = delete->data;
        if(delete == deque->rear){
            deque->front = NULL;
            deque->rear = NULL;
        } 
        else
            deque->front = delete->next;
        --dq_size;
        free(delete);
        return dq_data;
    }
}

int delrear_deque(LinkedList_Deque* deque)
{
    if(is_empty_deque(deque))
        return -1;
    else{
        Node_Deque *delete = deque->rear;
        int dq_data = delete->data;
        if(delete == deque->front){
            deque->front = NULL;
            deque->rear = NULL;
        } 
        else{
            Node_Deque *ptr = deque->front;
            while(ptr->next != delete)
                ptr = ptr->next;
            deque->rear = ptr;
            ptr->next = NULL;
        }
        --dq_size;
        free(delete);
        return dq_data;
    }
}