//This problem was asked by Uber.

//Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

//For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

//Follow-up: what if you can't use division?

using namespace std;
#include <iostream>

//with division:
int* calcArray(int arr[], int size) {
    int product = 1;
    static int res[100]; //MUST be static in order for the array to survive outside the stack.
    for (int i=0; i<size;i++) {
        product = product * arr[i];
    }

    for (int i=0; i<size; i++) {
        res[i] = product / arr[i];
        cout << res[i] << endl;
    }
    return res;
}

//without division:
//could do double for loop. go through array and multiply, skip the index we're on.
//multiply left to right until elemnt. then second pass through multiply right to left.

int* calcArrayNoDiv(int arr[], int size) {
    static int res[100];
    int product = 1;

    for (int i = 0; i<size; i++) {
        res[i] = product;
        product = product * arr[i];
        cout << res[i] << endl;
    }

    product = 1;
    for(int i = size; i>=0; i--) {
        res[i] = res[i] * product;
        product = product * arr[i];
        cout << res[i] << endl;
    }

    return res;
}


int main () {
    const int size = 5;
    int arr[size] = {1,2,3,4,5};
    
    int *res = calcArrayNoDiv(arr, size);

    cout << "New array values are: " << endl;

    for (int i = 0; i < size; i++) {
        cout << *(res + i) << endl;
    }

    return 0;
}
