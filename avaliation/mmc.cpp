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

int milena(int x, int y, int z=0) {
    int indice = 2, aux_indice = 0;
    while(true) {
        if(true != (y >= indice)){
            break;
        }
        aux_indice = indice * x;
        if((aux_indice % y) == 0) {
            z = aux_indice;
            indice = y + 1;
        }
        ++indice;
    }
    return z;
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
    int mi = milena(X, Y);
    printf("Recursive value: %d\n", recursiveValue);
    printf("Iterative Value: %d\n", recursiveValue); 
    printf("Milena: %d\n", mi); 
    return 0;
}

