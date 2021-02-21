// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// file: Array/array.cpp

#include <iostream>
#include <emscripten/emscripten.h>

using std::cout;

// This app does not need a main => the functions will be called in JS.
// 
// int main(int argc, char ** argv) {
//   printf("Hello, World!\n");
// }

// @brief           Print all values in the array
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
//
// EMSCRIPTEN_KEEPALIVE makes sure that LLVM does not eliminate the 
// following function. If the function is added to EXPORTED_FUNCTIONS
// during compilation, the function is exported. The function is 
// wrapped in extern "C" to prevent C++ name mangling.
extern "C" {
    void EMSCRIPTEN_KEEPALIVE print(int* arr, int length){
        for(int i = 0; i < length; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}


// @brief           Find and return the largest number in array
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
// @return the largest value in the array
extern "C" {
    int EMSCRIPTEN_KEEPALIVE find_largest(int* arr, int length) {
        
        // Write your code here
        return 0;
 
    }
}

// @brief           Find and return the sum of the values in the array
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
// @return the sum of the values in the array
extern "C" {
    int EMSCRIPTEN_KEEPALIVE calc_sum(int* arr, int length){
        
        // Write your code here
        return 0;
 
    }
}

// @brief           Double all values in the array
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
// @return a pointer to an array with the values doubled
//
// Note: Emscripten does not allow pass-by-reference, but we can return 
// a pointer to the array, with the values doubled.
extern "C" {
    int* EMSCRIPTEN_KEEPALIVE double_vals(int* arr, int length){
        
        // Write your code here
        return arr;

    }
}

// @brief           Rotate all array elements left by 1 
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
// @return a pointer to an array with the values rotated left
// 
// Shift all elements in the array left by one and move the first 
// element to the back of the array. For example, if arr starts as
// [1,2,3,4,5], the returned array will be [2,3,4,5,1]. 
extern "C" {
    int* EMSCRIPTEN_KEEPALIVE rotate_left(int* arr, int length) {
       
        // Write your code here 
        return arr;

    }
}

// @brief           Check if the array is sorted in increasing order
// @param arr       A pointer to an array of integers
// @param length    Length of the array (number of elements in arr)
// @return true if array is sorted; otherwise, return false
//  (an empty array is considered sorted)
extern "C" {
    bool EMSCRIPTEN_KEEPALIVE is_sorted(int* arr, int length) {
        
        // Write your code here
        return true;

    }
}
