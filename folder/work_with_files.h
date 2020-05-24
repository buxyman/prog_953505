#pragma once
#ifndef WORK_WITH_FILES_H
#define WORK_WITH_FILES_H
#include <stdio.h>
#include "AllStructs.h"
#include <errno.h>
extern void ShowAllFromFile(List* list,FILE* fPtr);
extern void CreateFileWithFlights();
extern void LoadFromFileToList(List* list);
extern void LoadToFile(Flight* flight);
extern void DeleteFromFile(int numinlist);
extern int FItemsGetCount();
#endif // !WORK_WITH_FILES_H
