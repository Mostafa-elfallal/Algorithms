#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_
#define MAXQUEUE    10
typedef struct
{
    char a;
    int key;
}Data;
typedef struct 
{
    Data Heap[MAXQUEUE];
    int HeapSize;
}PriorityQueue;
void PriorityQueueInit(PriorityQueue* Q);
int  HeapMaxmum(PriorityQueue* Q, Data* retData);
int HeapExtractMax(PriorityQueue* Q, Data* retData);
int HeapIncreaseKey(PriorityQueue* Q, int Index , int NewKey);
int MaxHeapInsert(PriorityQueue* Q , Data* NewData);
#endif