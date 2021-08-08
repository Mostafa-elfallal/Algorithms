/*
 * QuickSort.c
 *
 *  Created on: Aug 8, 2021
 *      Author: Darsh
 */
static void Swap(int Arr[],int first , int second){
	int temp = Arr[first];
	Arr[first ] = Arr[second ];
	Arr[second ] = temp;
}
int static Partition(int Arr[],int p , int r)
{
	int pivot = Arr[r];
	int i = p-1;
	for (int j = p ; j < r ; j++){
		if(Arr[j] <= pivot){
			i++;
			Swap(Arr,i,j);
		}
	}
	Swap(Arr,i+1,r);
	return i+1;
}
void QuickSort(int Arr[],int p , int r)
{
	if(p<r)
	{
		int q = Partition(Arr,p , r);
		QuickSort(Arr,p,q-1);
		QuickSort(Arr,q+1,r);
	}
}
