#include "HeapSort.h"

#define     PARENT(i)   (i/2)
#define     LEFT(i)     (2*i)
#define     RIGHT(i)    (2*i+1)

static void Heap_Swap(int Heap[],int const first, int const second)
{
   int temp = Heap[first-1];
   Heap[first-1] = Heap[second-1];
   Heap[second-1]= temp;
}

static void Max_Heapify(int Heap[],int Heap_size,int Index)
{
int L = LEFT(Index);
int R = RIGHT(Index);
int Largest;
if ( L<= Heap_size && Heap[L-1] > Heap[Index-1])
    Largest = L;
else
    Largest = Index; 
if ( R <= Heap_size && Heap[R-1] > Heap[Largest-1])
    Largest = R; 
if ( Largest != Index)
{
    Heap_Swap(Heap,Index,Largest);
    Max_Heapify(Heap,Heap_size,Largest);
}
}

static void BUILD_MAX_HEAP(int Arr[],int Arr_size)
{
    for(int i = (Arr_size)/2 ;i>0 ; i--)
       Max_Heapify(Arr,Arr_size,i); 
}

void HeapSort(int Arr[],int Arr_size)
{
    int Heap_Size = Arr_size;
    BUILD_MAX_HEAP(Arr,Arr_size);
    for ( int i=Arr_size ;i>1;i--)
    {
        Heap_Swap(Arr,1,i);
        Heap_Size--;
        Max_Heapify(Arr,Heap_Size,1);
    }
}