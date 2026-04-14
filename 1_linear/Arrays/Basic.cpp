#include <iostream>

using namespace std;


int main() {

    int i = 0;

    //Declaration and Initiallizaion
    int arr[5]; // declaration
    int arr1[5] = {1, 2, 3, 4, 5}; // initialization

    int nums[10];              // Array of 10 integers
    float prices[5];           // Array of 5 floats
    char vowels[5] = {'a','e','i','o','u'};

    /*
        Array indexing (0-based)
        storing contiguous memory
    */

    //  Memory Representation
        // Each element stored in contiguous memory
        // Base address + offset using:
        arr[i] = *(arr + 1);

    // Array Traversal and Manipulation
        //loop-based traversal(for/while)

        for(int i = 0; i < 5; i++) {
            arr[i] = 2 * arr1[i];
        }

    
    // Array Memory Layout
        // Static Arrays

        // Dynamic Arrays

        // Multidimensional Arrays
            // 2D arrays:
            int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

        // Character Arrays

        // Const Arrays


    // Pointer and arrays
    int arr2[3] = {10 , 20 , 30};
    int *ptr = arr; // arr points to arr[0]

    cout << *(arr2) << endl;
    cout << *(arr2 + 1);
    cout << ptr[2];

        
    return 0;
}