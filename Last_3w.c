/*
 File:           Last 3 weeks of CPSC 259 Summary
 Author:         Mehmet Berke Karadayi and Idil Bil
 */

#include <stdio.h>
#include <stdlib.h>

// Last 3 weeks coding for final exam


// Binary Search Tree (BST)

-	Tree nodes contain data and two pointers to nodes

	BNode* leftchild	data		BNode* rightchild


// Search implementation

int search(BNode* nd, int key) {
	if (nd == NULL)	return FALSE;
	else if (nd == key)	return TRUE;
	else {
		if (key < nd->data)
			return search(nd->left, key);
		else
			return search(nd->right, key);
	}
}

-------------------------------------------------------------------------------------------------------------------------------

// insert implementation

BNode * insert(BNode* nd, int key) {
	if (nd == NULL) {
		BNode* newnode = (BNode*)malloc(sizeof(BNode));
		newnode->data = key;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	else {
		if (key < nd->data)
			nd->left = insert(nd->left, key);
		else
			nd->right = insert(nd->right, key);
		return nd;
	}
}

----------------------------------------------------------------------------------------------------------------------------
// find min

int findMin(BNode* nd) {
	BNode* curr = nd;
	if (nd == NULL)
		return -1;
	else {
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
}
--------------------------------------------------------------------------------------------------------------------------
// Binary heap


// heap implementation

typedef struct MinHeap {
	int size;     // number of stored elements
	int capacity; // maximum capacity of array
	int* arr;     // array in dynamic memory
} MinHeap;
void initializeMinHeap(MinHeap* h, int initcapacity) {
	h->size = 0;
	h->capacity = initcapacity;
	h->arr = (int*)malloc(h->capacity * sizeof(int));
}

------------------------------------------------------------------------------------------------------------------------------
// selection sort implementation

void selectionSort(int arr[], int size)
{
	int i; // next index to be set to minimum
	int min_pos; // index of minimum element
	for (i = 0; i < size - 1; i++) {
		min_pos = minPosition(arr, i, size - 1)
			if (min_pos != i)
				swap(&arr[min_pos], &arr[i]);
	}
}

int minPosition(int arr[], int start, int end)
{
	int min_pos = start;
	int j;
	for (j = start + 1; j <= end; j++) {
		if (arr[j] < arr[min_pos])
			min_pos = j;
	}
	return min_pos;
}

--------------------------------------------------------------------------------------------------------------------------

// insertion sort implementation

void insertionSort(int arr[], int size)
{
	int i, temp, position;
	for (i = 1; i < size; i++)
	{
		temp = arr[i];
		position = i;
		// Shuffle up all sorted items > arr[i]
		while (position > 0 && arr[position - 1] > temp)
		{
			arr[position] = arr[position – 1];
			position--;
		}
		// Insert the current item
		arr[position] = temp;
	}
}


--------------------------------------------------------------------------------------------------------------------------
// merge sort implementation

void merge(int arr[], int low, int mid, int high) {
	int i = low, j = mid + 1, index = 0;
	int* temp = (int*)malloc((high – low + 1) * sizeof(int));
	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j])
			temp[index++] = arr[i++];
		else
			temp[index++] = arr[j++];
	}
	if (i > mid) {
		while (j <= high)
			temp[index++] = arr[j++];
	}
	else {
		while (i <= mid)
			temp[index++] = arr[i++];
	}
	for (index = 0; index < high - low; index++)
		arr[low + index] = temp[index];
	free(temp);
}

void msort(int arr[], int low, int high) {
	int mid;
	if (low < high) {
		// subarray has more than 1 element
		mid = (low + high) / 2;
		msort(arr, low, mid);
		msort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}


void mergeSort(int arr[], int size) {
	msort(arr, 0, size - 1);
}

--------------------------------------------------------------------------------------------------------------------------------
