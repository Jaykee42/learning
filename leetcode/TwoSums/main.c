/**
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

 You may assume that each input would have exactly one solution, and you may not use the same element twice.

 You can return the answer in any order.
 
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>

int testArray[5] = {2,3,5,1,6};

int main() {
   
    int arrayMax = sizeof(testArray) / sizeof(testArray[0]);
    printf("%d", arrayMax);
}