#include "array.h"

void MergeSortArray(Base * arr, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right) {
		MergeSortArray(arr, left, mid);	MergeSortArray(arr, mid + 1, right);
		Combine(arr, left, mid, right);
	}
}

void Combine(Base * arr, int left, int mid, int right)
{
	int i = left;
	int lL = left, rL = mid + 1;
	Base * tempArr = (Base *)malloc(sizeof(Base)*(right+1));

	while (lL <= mid && rL <= right)
	{
		if (arr[lL] <= arr[rL])
			tempArr[i] = arr[lL++];
		else
			tempArr[i] = arr[rL++];
		
		i++;
	}

	if (lL <= mid)
		while (i <= right)
			tempArr[i++] = arr[lL++];
	else
		while (i <= right)
			tempArr[i++] = arr[rL++];

	for (i = left; i <= right; i++)
		arr[i] = tempArr[i];

	free(tempArr);
}

int main()
{
	int arr[] = { 3, 9, 12, 4, 5, 8, 10, 13, 2, 1, 6, 11, 7 };
	int i;

	MergeSortArray(arr, 0, 12);

	for (i = 0; i < 13; i++)
		printf("%4d", arr[i]);

	puts("");

	return 0;
}