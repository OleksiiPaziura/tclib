#ifndef TC_ARR_H
#define TC_ARR_H

#include <stdlib.h>
#include <stdio.h>

int* tc_makearr(int size);                      // Make an array
void tc_pbarr(int arr[], int* size, int value); // Push back to the array
void tc_pfarr(int arr[], int* size, int value); // Push front to the array
void tc_delarr(int* array);                     // Delete the array

#endif //TC_ARR_H
