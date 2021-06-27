/*

 * main.c
 *
 *  Created on: Jun 27, 2021
 *      Author: Darsh
 */

#include "adv_insertion_sort.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
typedef struct {
	int price;
	char name[30];
}vehicle;

int cmp(void *first,void * second){
	if( ((vehicle*)first) ->price > ((vehicle*)second) ->price ){
		return 1;
	}
	return 0;
}

int main(){
	vehicle cars[20];
	for(int i =0;i<20;i++){
		cars[i].price = rand()%20 ;
		strcpy(cars[i].name , "car");
	}
	printf("========================== Before Sorting ============================\n");
	for(int i =0;i<20;i++){
		printf("name of car %d : ",i+1);
		fflush(stdin);fflush(stdout);
		printf("%s\n",cars[i].name);
		fflush(stdin);fflush(stdout);
		printf("price of car %d : ",i+1);
		fflush(stdin);fflush(stdout);
		printf("%d\n",cars[i].price);
		fflush(stdin);fflush(stdout);
	}
	adv_insertion_sort(cars ,sizeof(cars[0]), sizeof(cars)/sizeof(cars[0]),cmp);
	printf("========================== after Sorting ============================\n");
	for(int i =0;i<20;i++){
		printf("name of car %d : ",i+1);
		fflush(stdin);fflush(stdout);
		printf("%s\n",cars[i].name);
		fflush(stdin);fflush(stdout);
		printf("price of car %d : ",i+1);
		fflush(stdin);fflush(stdout);
		printf("%d\n",cars[i].price);
		fflush(stdin);fflush(stdout);
	}
}
