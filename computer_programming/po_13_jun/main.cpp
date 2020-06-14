#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <time.h>

#define MAX_ARRAY_SIZE 100000

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
    for(int i = len-1; i >= 0; --i){
        arr[i] = rand() % (len * 10);
    }
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
    for(unsigned i = len-1; i >= 0; --i) printf("%d: %d\n", i ,arr[i]);
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
    unsigned mid = floor(len * 0.5); 
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
            // printf("[%d, %d]\n", arr[i], arr[j]); 
            arr[i] = -1; // making sure that it
            arr[j] = -1; // doesn't repeat pairs
        }
        (arr[i] + arr[j] < target) ? i++: j--;
    }
} 

/**
 * Compute a number of execution time  
 * tests on searchArrayBinary function
 * and getPairs function and print his 
 * results.
 * 
 * @return {void}
 */
void runTests(){
    const unsigned INCREMENT = 5000; 
    constexpr unsigned NUMBER_OF_TESTS = (MAX_ARRAY_SIZE / INCREMENT);

    unsigned arraySize = 5000;
    double searchArrayBinaryTime = 0f;
    double getPairsTime = 0f;

    for(unsigned testNumber = 0; (testNumber <= NUMBER_OF_TESTS && arraySize <= MAX_ARRAY_SIZE); ++testNumber){
        int arr[arraySize];
        generateSetOfNumbers(arr, arraySize);

        clock_t begin = clock();
        searchArrayBinary(arr[5], arr, arraySize);

        clock_t searchArrayBinaryTimestamp = clock();
        getPairs((arr[5] + arr[6]), arr, arraySize);

        clock_t getPairsTimestamp = clock();
        searchArrayBinaryTime = (double)(searchArrayBinaryTimestamp - begin) / CLOCKS_PER_SEC;
        getPairsTime = (double)(getPairsTimestamp - begin) / CLOCKS_PER_SEC;

        printf("TEST NUMBER %d =========================\n", testNumber);
        printf("ARRAY SIZE: \t\t\t%d\n", arraySize);
        printf("SEARCH ALGORITHM: \t\t%f\n", searchArrayBinaryTime);
        printf("PAIR ALGORITHM: \t\t%f\n", getPairsTime);
        printf("\n");
        arraySize += INCREMENT;
    }
}

int main(void)  {
    srand(time(NULL));
    runTests();
    return 0;
}
