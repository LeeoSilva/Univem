#include <stdio.h>

/**
 * prints every even number inside a limit recusivelly
 *
 * @function showEven
 * @param {int} lim - limit to be printed 
 * @param {int} val - auxiliar value to be passed around by the function 
 * @return {void}
 */

void showEven(int lim, int val = 0){
    if(val > lim && val >= 0 ){ // making sure that a new line is entered when halting
        return; 
    }
    if((val & 1) == 0) printf(" %d", val); // checking if the value is even
    showEven(lim, ++val);
}


int main(void){
    showEven(0);
    return 0;
}
