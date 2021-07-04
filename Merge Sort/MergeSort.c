/*
 * MergeSort.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Darsh
 */
#include <stdlib.h>
static void Merge(int Array[], int start ,int middle , int end ){
	int n1 = middle - start +1;
	int n2 = end - middle ;
	int i,j;
	int *Left= (int*)malloc((n1+1)*sizeof(int));
	int *Right=(int *)malloc((n2+1)*sizeof(int));
	for(i =0;i<n1;i++){
		Left[i] = Array[start+i];
	}
	for(j=0;j<n2;j++){
		Right[j] = Array[middle+j+1];
	}
	Left[n1]=0x7FFFFFFF;
	Right[n2]=0x7FFFFFFF;
	i=0;
	j=0;
	for(int k=start;k<end+1;k++){
		if(Left[i]<=Right[j]){
			Array[k]=Left[i];
			i++;
		}
		else{
			Array[k]=Right[j];
			j++;
		}
	}
	free(Left);
	free(Right);
}
void MergeSort(int Array[], int start,int end){
	if(start < end){
		int middle = (start + end)/2;   //floor by default
		MergeSort(Array,start,middle);
		MergeSort(Array,middle+1,end);
		Merge(Array,start,middle,end);
	}
}
