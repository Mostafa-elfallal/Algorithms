/*
 * main.c
 *
 *  Created on: Jun 29, 2021
 *      Author: Darsh
 */


#include "MergeSort.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
	int arr[100];
	int x =0x7FFFFFFF;
	printf("%d\n",x);
	printf("=========== Before sorting ==========\n");
	for(int i=0;i<100;i++){
		arr[i]=100-i;
		printf("%d ",arr[i]);
	}
	MergeSort(arr,0,99);
	printf("\n=========== After sorting ==========\n");
	for(int i=0;i<100;i++){
		printf("%d ",arr[i]);
	}
}
