/* Purpose: Function Pointer Sort
 * Author: Ian Morrison
 * Date: December 6, 2022
 * References: Lab06, Ian Morrison
 */

#include "lab10b.h"

// The function below compares two String struct elements by word length.
// The function returns:
//  -1 if e1 is shorter than e2
// 0 if e1 is the same length as e2
// 1 if e1 is longer than e2
int comp_length(String e1, String e2) {

    if (e1.length > e2.length) {
        return 1;
    }

    else if (e1.length < e2.length) {
        return -1;
    }

    return 0;
}


// The function below compares two String struct elements by alphabetical order.
// The function returns:
//  -1 if e1 comes before e2 in alphabetical order
// 0 if e1 is the same word as e2
// 1 if e1 comes after e2 in alphabetical order
int comp_alphabetical(String e1, String e2) {
    // Returns the comparison of the two strings
    return(strcmp(e1.word, e2.word));
}


// The function below merge sorts an array of String struct elements.
// - arr is an array of String struct elements
// - l and r are the left and right positions in the array
// - comp is a pointer to some comparison function as in the above
void msort(String arr[], int l, int r, int (*comp)(String e1, String e2)) {
    
    int middle = (l + r) / 2;           // We need the middle of the array to divide our arrays
    if (l < r) {
        msort(arr, l, middle, comp);        // Lower half of array
        msort(arr, (middle + 1), r, comp);  // Upper half of array
    }

    // This section merges our sorted arrays

    int i, j, k;                    // Indexes for arrays
    int end1 = (middle - l + 1);    // End of temp array 1
    int end2 = (r - middle);        // End of temp array 2
        
    String temp1[end1], temp2[end2]; // Temp arrays

    // These for loops populate temp arrays
    for (i = 0; i < end1; i++) {
        temp1[i] = arr[l + i];
    }
    for (i = 0; i < end2; i++) {
        temp2[i] = arr[middle + i + 1];
    }

    i = 0;
    j = 0;
    k = l;  // Current position in array

    // This merges our two arrays into one sorted array
    while ((i < end1) && (j < end2)) {
        
        if ((*comp)(temp1[i], temp2[j]) < 0 || (*comp)(temp1[i], temp2[j]) == 0) { // If the value in temp1 is lower than the value in temp2, put it into the array.
            arr[k] = temp1[i];
            i++;
        }
        else  {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    
    // These while loops grab the last elements of our temp arrays and appends them to the end of our sorted array.
    while (i < end1) {
        arr[k] = temp1[i];
        i++;
        k++;
    }
    while (j < end2) {
        arr[k] = temp2[j];
        j++;
        k++;
    }

    return;
}
