//This problem was asked by Uber.

//Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

//For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

//Follow-up: what if you can't use division?

using namespace std;
#include <iostream>

//with division:
int* calcArray(int arr[], int size) {
    int sum = 1;
    static int res[100]; //MUST be static in order for the array to survive outside the stack.
    for (int i=0; i<size;i++) {
        sum = sum * arr[i];
    }

    for (int i=0; i<size; i++) {
        res[i] = sum / arr[i];
        cout << res[i] << endl;
    }
    return res;
}

//without division:
//could do double for loop. go through array and multiply, skip the index we're on.
//

int main () {
    const int size = 5;
    int arr[size] = {1,2,3,4,5};
    
    int *res = calcArray(arr, size);

    cout << "New array values are: " << endl;

    for (int i = 0; i < size; i++) {
        cout << *(res + i) << endl;
    }

    return 0;
}
