#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

void Init(List* plist)
{
    plist->numOfData = 0;
    plist->curPosition = -1;
}

void Insert(List* plist, Data data)
{
    if (plist->numOfData >= ARRAY_LEN)
    {
        puts("저장 불가능");
        return;
    }

    plist->arr[plist->numOfData] = data;
    (plist->numOfData)++;
}

int First(List* plist, Data* pdata)
{
    if (plist->numOfData == 0)
        return FALSE;

    (plist->curPosition) = 0;
    *pdata = plist->arr[plist->numOfData];
    return TRUE;
}
int Next(List* plist, Data* pdata)
{
    if (plist->curPosition >= plist->numOfData - 1)
        return FALSE;

    (plist->curPosition)++;
    *pdata = plist->arr[plist->numOfData];
    return TRUE;
}

Data Remove(List* plist)
{
    int rpos = plist->curPosition;
    int num = plist->numOfData;
    Data rdata = plist->arr[rpos];

    for (int i = rpos; i < num - 1; i++)
        plist->arr[i] = plist->arr[i + 1];

    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}

int Count(List* plist)
{
    return plist->numOfData;
}