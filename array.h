#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdlib.h>

typedef int Base;

void MergeSortArray(Base * arr, int left, int right);
void Combine(Base * arr, int left, int mid, int right);

#endif