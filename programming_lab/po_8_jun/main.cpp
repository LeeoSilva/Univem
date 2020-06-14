#include <stdio.h>

/**
 * Check for repeated values within
 * the array and print them.
 *
 * @param {int*} arr - target array.
 * @param {size_t} len - length of the target array.
 * @return {void} 
 */

void printRepeatedNumbers(int* arr, size_t len){
    unsigned i = 0;
    unsigned j = 0;
    unsigned k = 0;
    bool repeated = true;

    for(; i < len; ++i) {
        for(j = i + 1; j < len; ++j) 
            if(arr[i] == arr[j]) 
                for(k = j; k < (len - 1); ++k) arr[k] = arr[k + 1];
        len--;
        j--;
        repeated = false;

        if(repeated) {
            for(j = i; j < len - 1; ++j) arr[j] = arr[j + 1]; 
            --i;
            --len;
        }
    }
    for(i=0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
} 

int* sort(int* arr, const size_t len){
    unsigned i = 0;
    unsigned j = 0;
    int a;
    for (i = 0; i < len; ++i) 
        for (j = i + 1; j < len; ++j) 
            if (arr[i] > arr[j]) {
                a =  arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
    return arr;
}

void printAllUniqueElements_Sorting(int* arrA){
    const size_t len = sizeof(arrA) / sizeof(int);
    arrA = sort(arrA, len);
    int current = arrA[0];
    for (int i = 1; i < len; i++) {
        if(current!=arrA[i]){
            printf("%d ", arrA[i]);
            current = arrA[i];
        }
    }
    printf("\n");
}




int main(void){
    int arr[] = {1, 2, 3, 7, 3, 4, 4};
    printAllUniqueElements_Sorting(arr);
    return 0;
}
