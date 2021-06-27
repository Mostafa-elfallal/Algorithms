/*
 * insertion_sort.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Darsh
 */
#include "insertion_sort.h"
void insertion_sort(int Array[],int Array_size){
	int key,i;							// key carries the member to be inserted.
										// i is the index iterator before catching the place of key.
	for (int counter = 1 ;counter <Array_size ; counter ++){ //assuming the first element is a sorted array
		key = Array[counter];
		i = counter -1;
		while ( i >= 0 && Array[i] > key ){
			Array[i+1]=Array[i];
			i--;
		}
		Array[i+1]=key;							//insert here
	}
}
