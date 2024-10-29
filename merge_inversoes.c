#include <stdio.h>
#include <stdlib.h>

// Function to print an array
void printArray(int A[], int l, int r)
{
    int i;
    for (i = l; i < r+1; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int merge(int arr[], int l, int m, int r)
{
	printArray(arr, l, m);
	printArray(arr, m+1, r);
    int i, j, k, sum = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
	    printf("(%d, %d)\n", L[i], R[j]);
	    sum += (n1 - i);
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    return sum;
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
int mergeSort(int arr[], int l, int r)
{
	int sum = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        sum += mergeSort(arr, l, m);
        sum += mergeSort(arr, m + 1, r);

        return sum + merge(arr, l, m, r);
    }
    return 0;
}

int main(int argc, char **argv){
	int *arr = (int*)malloc(sizeof(int)*(argc-1));
	for (int i = 0; i < (argc-1); i++) {
		arr[i] = atoi(argv[i+1]);
	}
	for (int i = 0; i < (argc-1); i++) {
		printf("%d\n", arr[i]);
	}
	printf("contagem: %d\n", mergeSort(arr, 0, argc-2));
	free(arr);
	return 0;
}
