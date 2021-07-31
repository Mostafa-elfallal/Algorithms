#include "PriorityQueue.h"
#include "stdio.h"

int main()
{
    PriorityQueue MyQueue;
    PriorityQueueInit(&MyQueue);
    Data temp;
    for(int i = 0;i<20;i++){
        temp.a='z'-i;
        temp.key=i;
        if(MaxHeapInsert(&MyQueue,&temp))\
        {
            printf("%d : Inserting done\n",i+1);
        }
        else{
            printf("%d : Inserting failed\n",i+1);
        }
    }
    for(int i = 0;i<20;i++){
        if(HeapExtractMax(&MyQueue,&temp))
        {
            printf("%d : Extracting done\n",i+1);
            printf("Element : %c & key : %d \n",temp.a,temp.key);

        }
        else{
            printf("%d : Extracting failed\n",i+1);
        }
    }

}
