/*
 * CountSort.c
 *
 *  Created on: Aug 12, 2021
 *      Author: Mostafa ElFallal
 */
#include "CountSort.h"
#include "stdlib.h"
#include "stdio.h"
void CountingSort(int A[],int B[],int k,int A_Size)
{
	int * C = (int *) calloc((k+1),sizeof(int));

	for(int i=0; i < A_Size ; i++){
		C[A[i]]++;
	}

	for(int i = 1; i<=k;i++){
		C[i] += C[i-1];
	}
	for(int i =A_Size-1 ; i>=0;i-- )
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}
