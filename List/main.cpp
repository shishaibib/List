#include "list.h"

int main()
{
    list_t list = {};
    
    InitList(&list);
//------------------------------
    AddElem(&list, 10, 0); 
    AddElem(&list, 20, 1); 
    AddElem(&list, 30, 1); 
    DumpList(&list); 

    RemoveElem(&list, 1); 
    DumpList(&list); 
// я капша и потому капшу капшой

//------------------------------
    DtorList(&list);

}