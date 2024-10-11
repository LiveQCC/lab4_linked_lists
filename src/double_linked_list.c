#include<stdlib.h>
#include<limits.h>
#include"double_linked_list.h"
#include<stdio.h>



int addElementDoubleLinkedList(struct doubleLinkedList* list, int value){

  struct doubleLinkedListElement* newElement = malloc(sizeof(struct doubleLinkedListElement));
  if(newElement == NULL){
    return INT_MIN;
  }
  newElement->data = value;
  newElement->next = NULL;
  newElement->previous = NULL;
  if(list->first == NULL){
    list->first = newElement;
    list->last = newElement;
    return value;
  }
  struct doubleLinkedListElement* current = list->first;
  struct doubleLinkedListElement* previous = NULL;
  while(current != NULL && current->data < value){
    previous = current;
    current = current->next;
  }
  if(previous == NULL){
    newElement->next = list->first;
    list->first->previous = newElement;
    list->first = newElement;
  } else {
    previous->next = newElement;
    newElement->next = current;
    newElement->previous = previous;
    if(current != NULL){
      current->previous = newElement;
    } else {
      list->last = newElement;
    }
  }
  return value;
} 


void initDoubleLinkedList(struct doubleLinkedList* list) {
  list->first = NULL;
  list->last = NULL;
}


int removeFirstElementDoubleLinkedList(struct doubleLinkedList* list){
  if(list->first == NULL){
    return INT_MIN;
  }
  struct doubleLinkedListElement* temp = list->first;
  list->first = list->first->next;
  if(list->first != NULL){
    list->first->previous = NULL;
  } else {
    list->last = NULL;
  }
  int data = temp->data;
  free(temp);
  return data;
} 


int removeLastElementDoubleLinkedList(struct doubleLinkedList* list) {
  if(list->first == NULL){
    return INT_MIN;
  }
  struct doubleLinkedListElement* current = list->first;
  struct doubleLinkedListElement* previous = NULL;
  while(current->next != NULL){
    previous = current;
    current = current->next;
  }
  int data = current->data;
  free(current);
  if(previous == NULL){
    list->first = NULL;
    list->last = NULL;
  } else {
    previous->next = NULL;
    list->last = previous;
  }
  return data;
}

void printDoubleLinkedList(struct doubleLinkedList* list){
  struct doubleLinkedListElement* current = list->first;
  while(current != NULL){
    printf("%d", current->data);
    if(current->next != NULL){
      printf(" -> ");
    }
    current = current->next;
  }
  printf("\n");
}






