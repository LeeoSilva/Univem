#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#define MAX_ARRAY_SIZE 10 

/**
 * Compare function used to recursively
 * compare two values in a quicksort method.
 * 
 * @static 
 * @param {const void*} a - value to compare A
 * @param {const void*} b - value to compare B
 * @return {int} - 0 if equal, -1 if greater, 1 if lower
 */
static int compare( const void* a, const void* b) {
    int int_a = * ( (int*) a );
    int int_b = * ( (int*) b );

    if ( int_a == int_b ) return 0;
    else if ( int_a < int_b ) return -1;
    else return 1;
}

/**
 * Generates a list of integer numbers,
 * than quicksort the array.
 * 
 * @param {int*} arr - array to be populated
 * @param {const size_t} len - length of the array given 
 * @return {void}
 */
void generateSetOfNumbers(int* arr, const size_t len) {
    for(int i = len-1; i >= 0; --i) arr[i] = rand() % (len * 10);
    qsort(arr, len, sizeof(int), compare);
}

/**
 * Prints every element in the array
 * 
 * @param {const int*} arr - array to be printed
 * @param {const size_t} len - length of the array given 
 * @return {void}
 */
void drawArray(const int* arr, const size_t len){
    for(int i = len-1; i >= 0; --i) printf("%d: %d\n", i ,arr[i]);
}

/**
 * Searchs a given sorted array for a given value 
 * using binary search and returns his
 * position in the space.
 * 
 * @param {const int} target - Value being searched in the array
 * @param {const int*} arr - sorted array for the search
 * @param {const size_t} len - length of the array given 
 * @return {void}
 */
int searchArrayBinary(const int target, const int* arr, const size_t len){
    int i = 0;
    int mid = floor(len * 0.5); 
    if(arr[mid] == target) return mid;
    else if(arr[mid] > target) {
        for(i = mid; i >= 0; --i) if(arr[i] == target) return i;
        return -1;
    }
    else{
        for(i = mid; i <= len; ++i) if(arr[i] == target) return i;
        return -1;
    }
}

/**
 * Print pair elements which has their sum
 * equal to the target
 * 
 * @param {const int} target - pair result
 * @param {const int*} arr - sorted array 
 * @param {const size_t} len - length of the array given 
 * @return {void}
 */
void getPairs(const int target, int* arr, const size_t len){
    int j = len - 1;
    for(unsigned i = 0; i < j;) {
        if(arr[i] + arr[j] == target) {
            printf("[%d, %d]\n", arr[i], arr[j]); 
            arr[i] = -1; // making sure that it
            arr[j] = -1; // doesn't repeat pairs
        }
        (arr[i] + arr[j] < target) ? i++: j--;
    }
} 

int main(void){
    int arr[MAX_ARRAY_SIZE];
    int index = -1;
    srand(time(NULL));
    generateSetOfNumbers(arr, MAX_ARRAY_SIZE);
    index = searchArrayBinary(arr[2], arr, MAX_ARRAY_SIZE);
    getPairs((arr[1] + arr[2]), arr, MAX_ARRAY_SIZE);
    return 0;
}
