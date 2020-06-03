#include <stdio.h>
#define X 14 
#define Y 69 

// Compiled with: gcc (Arch Linux 9.3.0-1) 9.3.0

/**
 * Check if another iteration is necessary to calculate the MMC 
 *
 * @function checkIfFound 
 * @param {int} x - first parameter 
 * @param {int} y - second parameter
 * @param {int} val - auxiliar value to be passed around by the function 
 * @return {bool} - If the value needs another iteration or no
 */

constexpr bool checkIfFound(int x, int y, int val) {
    return ((val % x != 0) && (val % y != 0));
} 

/**
 * Computes the MMC of a two given parameters
 *
 * @function mmcIt 
 * @param {int} x - first parameter 
 * @param {int} y - second parameter
 * @param {int} val - auxiliar value to be passed around by the function 
 * @return {int} - MMC calculated. 
 */

int mmcIt(int x, int y){
    int val = 0;
    while(checkIfFound(x, y, val)){
        val += (x > y) ? (y) : (x);
    }
    return val;
}

int mmcTR(int a, int b, int m=0) {
    if(a > b) return mmcTR(b, a);
    m += b;

    if((m % a == 0) && (m % b == 0)) return m;
    else return mmcTR(a, b, m);
}

int main(void){
    int recursiveValue = mmcTR(X, Y);
    int iterativeValue = mmcIt(X, Y);
    printf("Recursive value: %d\n", recursiveValue);
    printf("Iterative Value: %d\n", recursiveValue); 
    return 0;
}

