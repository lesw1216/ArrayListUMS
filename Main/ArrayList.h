#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__
#include "Login.h"

#define TRUE    1;
#define FALSE   0;

#define ARRAY_LEN   100

typedef Login Data;

typedef struct _arrayList
{
    Data arr[ARRAY_LEN];
    int numOfData;
    int curPosition;
}ArrayList;

typedef ArrayList List;

void Init(List* plist);

void Insert(List* plist, Data data);

int First(List* plist, Data* data);
int Next(List* plist, Data* data);

Data Remove(List* plist);

int Count(List* plist);

#endif // !__ARRAY_LIST_H__
