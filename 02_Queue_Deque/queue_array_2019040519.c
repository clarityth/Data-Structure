#include "queue_array.h"

// --------------------------------------------------------------------
// 변경 금지
// --------------------------------------------------------------------

// 초기화
void queue_init_aq(Array_Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
}

// --------------------------------------------------------------------


/*
* 구현시 유의사항
* 1. 함수명과 매개변수는 수정하시지 마세요.
* 2. 반환값 정확하게 구현해주세요. (bool, int)
* 3. 발생할 수 있는 모든 예외사항을 처리해주세요.  (underflow/overflow)
*/

// --------------------------------------------------------------------
// Queue 구현
// --------------------------------------------------------------------

// true/false 반환
bool is_empty_aq(Array_Queue* queue)
{
    if(queue->front == queue->rear)
        return true;
    else 
        return false;
}

// true/false 반환
bool is_full_aq(Array_Queue* queue)
{
    if((queue->rear+1) % MAX_QUEUE_SIZE_ARR == queue->front)
        return true;
    else
        return false;
}

// Enqueue 성공 : 0 반환 / 실패 : -1 반환
int enqueue_aq(Array_Queue* queue, int data)
{
    if(is_full_aq(queue))
        return -1;
    else {
        queue->rear = (queue->rear+1) % MAX_QUEUE_SIZE_ARR;
        queue->array[queue->rear] = data;
        return 0;
    }
}

// Dequeue 성공 : Dequeue 값 반환 / 실패 : -1 반환
int dequeue_aq(Array_Queue* queue)
{
    if(is_empty_aq(queue))
        return -1;
    else {
        queue->front = (queue->front+1) % MAX_QUEUE_SIZE_ARR;
        return queue->array[queue->front];
    }
}

