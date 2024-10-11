#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include"single_linked_list.h"
#include<stdio.h>



int addElementSingleLinkedList(struct singleLinkedList* list, int value){
  struct singleLinkedListElement* newElement = malloc(sizeof(struct singleLinkedListElement));
  if(newElement == NULL){
    return INT_MIN;
  }
  newElement->data = value;
  newElement->next = NULL;
  if(list->first == NULL){
    list->first = newElement;
    return value;
  }
  struct singleLinkedListElement* current = list->first;
  struct singleLinkedListElement* previous = NULL;
  while(current != NULL && current->data < value){
    previous = current;
    current = current->next;
  }
  if(previous == NULL){
    newElement->next = list->first;
    list->first = newElement;
  } else {
    previous->next = newElement;
    newElement->next = current;
  }
  return value;
} 

void initSingleLinkedList(struct singleLinkedList* list) {
  list->first = NULL;
}

int removeFirstElementSingleLinkedList(struct singleLinkedList* list){
  if(list->first == NULL){
    return INT_MIN;
  }
  struct singleLinkedListElement* temp = list->first;
  list->first = list->first->next;
  int data = temp->data;
  free(temp);
  return data;  
  
} 


int removeLastElementSingleLinkedList(struct singleLinkedList* list){
  if(list->first == NULL){
    return INT_MIN;
  }
  struct singleLinkedListElement* current = list->first;
  struct singleLinkedListElement* previous = NULL;
  while(current->next != NULL){
    previous = current;
    current = current->next;
  }
  int data = current->data;
  free(current);
  if(previous == NULL){
    list->first = NULL;
  } else {
    previous->next = NULL;
  }
  return data;
} 

void printSingleLinkedList(struct singleLinkedList* list) {
    struct singleLinkedListElement* current = list->first;
  while(current != NULL){
    printf("%d", current->data);
    if(current->next != NULL){
      printf(" -> ");
    }
    current = current->next;
  }
  printf("\n");
}
