#include "PriorityQueue.h"

#define     PARENT(i)   (i/2)
#define     LEFT(i)     (2*i)
#define     RIGHT(i)    (2*i+1)

static void Heap_Swap(PriorityQueue* Q,int const first, int const second)
{
   Data temp = Q->Heap[first-1];
   Q->Heap[first-1] = Q->Heap[second-1];
   Q->Heap[second-1]= temp;
}

static void Max_Heapify(PriorityQueue* Q,int Index)
{
int L = LEFT(Index);
int R = RIGHT(Index);
int Largest;
if ( L<= Q->HeapSize && Q->Heap[L-1].key > Q->Heap[Index-1].key)
    Largest = L;
else
    Largest = Index; 
if ( R <= Q->HeapSize && Q->Heap[R-1].key > Q->Heap[Largest-1].key)
    Largest = R; 
if ( Largest != Index)
{
    Heap_Swap(Q,Index,Largest);
    Max_Heapify(Q,Largest);
}
}

void PriorityQueueInit(PriorityQueue* Q)
{
    Q->HeapSize=0;
}
int  HeapMaxmum(PriorityQueue* Q, Data* retData)
{
    if(Q->HeapSize < 1)
        return 0;
    *retData = Q->Heap[0];
    return 1;
}
int HeapExtractMax(PriorityQueue* Q, Data* retData)
{
    if(Q->HeapSize < 1)
        return 0;
    *retData = Q->Heap[0];
    Q->Heap[0]=Q->Heap[Q->HeapSize -1];
    Q->HeapSize--;
    Max_Heapify(Q,1);
    return 1;
}
int HeapIncreaseKey(PriorityQueue* Q, int Index , int NewKey)
{
    if(NewKey < Q->Heap[Index-1].key)
        return 0;
    Q->Heap[Index-1].key = NewKey;
    while (Index > 1 && Q->Heap[PARENT(Index)-1].key < Q->Heap[Index-1].key)
    {
        Heap_Swap(Q,Index,PARENT(Index));
        Index=PARENT(Index);
    }
    return 1;
}
int MaxHeapInsert(PriorityQueue* Q , Data* NewData)
{
    if(Q->HeapSize >= MAXQUEUE )
        return 0;
    Q->HeapSize++;
    Q->Heap[Q->HeapSize-1]=*NewData;
    HeapIncreaseKey(Q,Q->HeapSize,NewData->key);
    return 1;
}
