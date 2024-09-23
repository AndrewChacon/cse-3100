#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void initList(IntList* list)
{
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void freeList(IntList* list)
{
  ILNode* current = list->head;
    ILNode* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}

void pushBackList(IntList* list, int number)
{
  ILNode* newNode = (ILNode*)malloc(sizeof(ILNode));
    newNode->number = number;
    newNode->next = NULL;

    if (list->len == 0) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->len++;
}

int popBackList(IntList* list)
{
  assert(list->head && list->tail && list->len > 0);
    ILNode* current = list->head;
    int value;

    if (list->len == 1) {

        value = list->head->number;
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    } else {

        while (current->next != list->tail) {
            current = current->next;
        }

        value = list->tail->number;
        free(list->tail);
        current->next = NULL;
        list->tail = current;
    }

    list->len--;
    return value;
}

void pushFrontList(IntList* list, int number)
{
  ILNode* newNode = (ILNode*)malloc(sizeof(ILNode));
    newNode->number = number;
    newNode->next = list->head;

    if (list->len == 0) {
        list->tail = newNode;
    }

    list->head = newNode;
    list->len++;
}

int popFrontList(IntList* list)
{
  assert(list->head && list->tail && list->len > 0);
    ILNode* temp = list->head;
    int value = temp->number;

    if (list->len == 1) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = list->head->next;
    }

    free(temp);
    list->len--;

    return value;
}

void sortedInsert(IntList* sortedList, ILNode* nodeToInsert){
  ILNode* current;

    if (sortedList->head == NULL || sortedList->head->number >= nodeToInsert->number) {

        nodeToInsert->next = sortedList->head;
        sortedList->head = nodeToInsert;
        if (sortedList->tail == NULL) {
            sortedList->tail = nodeToInsert; 
        }
    } else {

        current = sortedList->head;
        while (current->next != NULL && current->next->number < nodeToInsert->number) {
            current = current->next;
        }
        nodeToInsert->next = current->next;
        current->next = nodeToInsert;

        if (nodeToInsert->next == NULL) {
            sortedList->tail = nodeToInsert; 
        }
    }

    sortedList->len++;
}

void sortList(IntList* list)
{
  IntList newList = {NULL,NULL};
  ILNode* next = NULL;
  ILNode* cur = list->head;
  while(cur){
    next = cur->next;
    sortedInsert(&newList, cur);
    cur = next;
  }
  *list = newList;
}

int lengthList(IntList* list)
{
  return list->len;
}

void printList(IntList* list)
{
   printf("(");
   ILNode* node = list->head;
   while (node) {
      printf("%d ", node->number);
      node = node->next;
   }
   printf(")\n");
}
