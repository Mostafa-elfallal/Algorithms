/*
 * adv_insertion_sort.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Darsh
 */

#include "adv_insertion_sort.h"
#include "stdlib.h"
static void elementcpy(void * dist,void * source,int element_size){
	for(int i=0;i<element_size;i++){
		((char *)dist)[i] = ((char *)(source))[i];
	}
}

void adv_insertion_sort(void * VArray,int element_size,int Array_size,int cmp(void *first,void * second)){
	void * key = malloc(element_size*sizeof(char));
	int i;
	for (int counter = 1 ;counter <Array_size ; counter ++){
		elementcpy(key,(char*)VArray+counter*element_size,element_size);
		i = counter -1;
		while ( i >= 0 && ( cmp(VArray+i*element_size,key) == 1) ){
			elementcpy((char*)VArray+(i+1)*element_size, (char*)VArray+i*element_size,element_size);
			i--;
		}
		elementcpy((char*)VArray+(i+1)*element_size,key,element_size);
	}
	free(key);
}
