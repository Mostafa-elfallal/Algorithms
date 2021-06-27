/*
 * adv_insertion_sort.h
 *
 *  Created on: Jun 27, 2021
 *      Author: Darsh
 */

#ifndef ADV_INSERTION_SORT_H_
#define ADV_INSERTION_SORT_H_
/***********************************
 * Description : insertion sort of void array
 * Input :
 * 1- the array itself
 * 2- the element size in bytes
 * 3- the number of elements
 * 4- a function that takes 2 void pointers of array elements and returns 1 if the first element key is greater than
 * 			the second element key
 *
 */
void adv_insertion_sort(void * VArray,int element_size,int Array_size,int cmp(void *first,void * second));

#endif /* ADV_INSERTION_SORT_H_ */
