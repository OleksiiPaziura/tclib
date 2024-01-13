#include "tcarr.h"

// Make an array
int* tc_makearr(int size)
{
    /* Make an array */
    return (int*) calloc(size, sizeof(int));
}

// Push back to the array
void tc_pbarr(int arr[], int *size, int value)
{
    /* Reallocation an instance array */
    arr = (int*) realloc(arr, (*size + 1) * sizeof(int));

    /* Assign a value to the end */
    arr[*size] = value;

    /* Update size */
    ++(*size);
}

// Push front to the array
void tc_pfarr(int arr[], int* size, int value)
{
    /* Reallocation an instance array */
    arr = (int*) realloc(arr, (*size + 1) * sizeof(int));

    /* Shift all elements to the right */
    for (int i = *size; i >= 1; --i)
        arr[i] = arr[i - 1];

    /* Assign a value to the beginning */
    arr[0] = value;

    /* Update size */
    ++(*size);
}

// Delete the array
inline void tc_delarr(int* array)
{ free(array); }
