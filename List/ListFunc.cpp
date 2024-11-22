#include "list.h"
void InitList(list_t* list)
{
    list->size = 0;
    list->capacity = LIST_SIZE;
    list->head = POIZON_INDEX;
    list->tail = POIZON_INDEX;
    list->free = 0;
    list->position = 0;
    list->data = (int*)calloc(list->capacity, sizeof(int));
    list->prev = (int*)calloc(list->capacity, sizeof(int));
    list->next = (int*)calloc(list->capacity, sizeof(int));
}

/*void ReadInputFile(list_t* list)
{
    FILE *input = fopen("data.txt", "r");
    assert(input == NULL);

    for(int i = 0; i < list->capacity; i++)
        list->size += fscanf(input, "d", &list->data[i]);

    fclose(input);
}*/

void DtorList(list_t* list)
{
    free(list->data);
    free(list->next);
    free(list->prev);
    list->size = 0;
    list->capacity = 0;
    list->head = POIZON_INDEX;
    list->tail = POIZON_INDEX;
    list->free = 0;
    list->position = 0;
}

void FindFree(list_t* list)
{
    for(int i = list->free; i < list->capacity; i++)
    {
        if(list->prev[i] == -1 && list->next[i] == POIZON_INDEX && i != list->head && i != list->tail)
        {
            list->free = i;
        }
    }   

}


void DumpList(list_t* list)
{
    //---------------принт в консоль------------------
    int current = list->head;
    while (current != POIZON_INDEX)
    {
        printf("%d ", list->data[current]);
        current = list->next[current];
    }
    printf("\n");
    //------------------------------------------------
    //лее мой братка за меня пишет ежи бля
}

void AddElem(list_t* list, int value, int position)
{
    FindFree(list);
    list->data[list->free] = value;
                                                                                                                             /*без 1 ифа для ч сл*/
    int current = list->head;
    for(int i = 0; i < position; i++)
    {
        current = list->next[current];
    }

    list->prev[list->free] = list->prev[current];
    list->next[list->free] = current;

    list->prev[current] = list->free;
    list->size ++;

}                                                                                                       

void RemoveElem(list_t* list, int position)
{
    int current = list->head;
    for(int i = 0; i < position; i++)
    {
        current = list->next[current];  /*убрать цикл использованием позишна?*/
    }

    list->head = list->next[current];
    list->tail = list->prev[current];

    list->prev[current] = -1;
    list->next[current] = -1;
    list->size--;
/*при доб элем стирается но если поиск впихнуть сюда то мб можно оптимизировать*/         /*одно присваивание в другом месте в потенциале может ускорить поиск*/
    list->free = current;
}