#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct list_t
{
    int size;
    int capacity;
    int head;
    int tail;
    int free;
    int position;
    int* data;
    int* prev;
    int* next;
};

enum ListConstants
{
    LIST_SIZE = 8,
    POIZON_INDEX = -1
};

void InitList (list_t* list);
void DtorList (list_t* list);
void DumpList (list_t* list);
void FindFree(list_t* list);
void AddElem(list_t* list, int value, int position);
void RemoveElem(list_t* list, int position);
void ReadInputFile(list_t* list);

