// sort.c

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10     // array size
#define MOD_SIZE MAX_SIZE     // Modulo size
#define SWAP(x, y, t)  ((t)=(x), (x)=(y), (y)=(t))

void bubble_sort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                SWAP(arr[j], arr[j + 1], temp);
    }
    return;
}

// Selection sort
void selection_sort(int arr[], int n)
{
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        // Check if minIndex value has changed
        // Swap if change occurs
        if (minIndex != i)
            SWAP(arr[minIndex], arr[i], temp);
    }

    return;
}


// Insertion sort
void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        j = i + 1;
        // Move left while the left one is bigger until reaching the first index (0)  
        while (j > 0 && arr[j - 1] > arr[j]) {
            SWAP(arr[j - 1], arr[j], temp);
            j--;
        }
    }

    return;
}


int partition(int arr[], int low, int high) {
    int i, pivot, pIndex, temp;

    pivot = arr[high];       // pivot 값을 배열 마지막 값으로 할당
    pIndex = low;

    for (i = low; i < high; i++) {    // pivot 보다 작은 값들을 scan
        if (arr[i] < pivot) {
            SWAP(arr[i], arr[pIndex], temp);
            pIndex++;
        }
    }
    SWAP(arr[pIndex], arr[high], temp);   // pivot 값을 pIndex 위치로 이동

    return pIndex;
}

void quicksort(int arr[], int low, int high) {
    int pIndex;

    if (low < high) {
        pIndex = partition(arr, low, high);
        quicksort(arr, low, pIndex - 1);
        quicksort(arr, pIndex + 1, high);
    }
    return;
}

void print_arr(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return;
}

int main(void) {
    int i, arr[MAX_SIZE];
    time_t start, end;

    srand(time(NULL));
    for (i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % MOD_SIZE;

    printf("=== BEFORE SORTING: Bubble sort ===\n");
    print_arr(arr, MAX_SIZE);
    start = clock();
    bubble_sort(arr, MAX_SIZE);
    end = clock();
    printf("=== AFTER SORTING: Bubble sort ===\n");
    printf("TIME: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    print_arr(arr, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % MOD_SIZE;

    printf("=== BEFORE SORTING: Selection sort ===\n");
    print_arr(arr, MAX_SIZE);
    start = clock();
    selection_sort(arr, MAX_SIZE);
    end = clock();
    printf("=== AFTER SORTING: Selection sort ===\n");
    printf("TIME: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    print_arr(arr, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % MOD_SIZE;

    printf("=== BEFORE SORTING: Insertion sort ===\n");
    print_arr(arr, MAX_SIZE);
    start = clock();
    insertion_sort(arr, MAX_SIZE);
    end = clock();
    printf("=== AFTER SORTING: Insertion sort ===\n");
    printf("TIME: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    print_arr(arr, MAX_SIZE);

    for (i = 0; i < MAX_SIZE; i++)
        arr[i] = rand() % MOD_SIZE;

    printf("=== BEFORE SORTING: Quicksort ===\n");
    // for (i=0; i<MAX_SIZE; i++)
    //    arr[i] = rand()%MOD_SIZE;    
    print_arr(arr, MAX_SIZE);
    start = clock();
    quicksort(arr, 0, MAX_SIZE - 1);
    end = clock();
    printf("=== AFTER SORTING: Quicksort ===\n");
    printf("TIME: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    print_arr(arr, MAX_SIZE);

    return 0;
}