#include <stdio.h>
#include <stdlib.h>

#define HASH_MAX_LENGTH 1000
typedef struct{
    int value;
}HASH_Data_t;
typedef struct node{
    int key;
    HASH_Data_t data;
    struct node* next;
}node_t;
typedef struct Linked_list{
    node_t* node;
}Linked_list;

Linked_list* HASH[HASH_MAX_LENGTH];

void HASH_Create(void){
    for(int i =0;i<HASH_MAX_LENGTH;i++)
    {
        HASH[i]=malloc(sizeof(Linked_list));;
        HASH[i]->node = NULL;
    }
}
int HASH_hash(int key)
{
   return key%HASH_MAX_LENGTH;
}
void HASH_Add(HASH_Data_t* Data,int key){
    int hash=HASH_hash(key);
    if(HASH[hash]->node == NULL)
    {
        HASH[hash]->node = malloc(sizeof(node_t));
        HASH[hash]->node->key=key;
        HASH[hash]->node->data=*Data;
        HASH[hash]->node->next=NULL;
        return;
    }
    node_t* Node= (HASH[hash]->node);
    while(Node->next != NULL)
    {
        Node = Node->next;
    }
    Node->next = malloc(sizeof(node_t));
    Node = Node->next;
    Node->key=key;
    Node->data=*Data;
    Node->next=NULL;
}
int HASH_Search(int key,HASH_Data_t* Data){
    int hash=HASH_hash(key);
    node_t* Node= (HASH[hash]->node);
    
    while(Node != NULL)
    {
        if(Node->key == key){
            *Data = Node->data;
            return 1;
        }
        Node = Node->next;
    }
    return 0;
}
