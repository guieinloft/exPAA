#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void repivot(int *arr, int l, int h, int pivot){
    int i;
    switch(pivot){
        case 0:
            i = l;
            break;
        case 1:
            i = h;
            break;
        case 2:
            i = (h+l)/2;
            break;
        case 3:
            i = rand()%(h-l)+l;
            break;
        case 4:
            //TODO
            i = h;
            break;
    }
    swap(&arr[i], &arr[h]);
}

int partition(int *arr, int l, int h, int *comp){
    int i = l, j = l;
    for (j = l; j < h; j++){
        if (arr[j] <= arr[h]) {
            swap(&arr[i], &arr[j]);
            i++;
        }
        (*comp)++;
    }
    swap(&arr[i], &arr[h]);
    return i;
}

int quicksort(int *arr, int l, int h, int pivot){
    if (l >= h || l < 0) return 0;
    int comp = 0;
    repivot(arr, l, h, pivot);
    int p = partition(arr, l, h, &comp);
    comp += quicksort(arr, l, p-1, pivot);
    comp += quicksort(arr, p+1, h, pivot);
    return comp;
}

int main(){
    int arr[] = {3, 4, 5, 6, 1, 2, 9, 8, 7, 0};
    int comp = quicksort(arr, 0, 9, 1);
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n%d\n", comp);
    return 0;
}
