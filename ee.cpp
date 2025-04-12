# exponential
#include <iostream>
using namespace std;

// Binary Search Implementation for Exponential Search
int binarySearch(int arr[], int low, int high, int target) 
{
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) 
        {
            return mid; // Target found
        } else if (arr[mid] < target) 
        {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

// Exponential Search
int exponentialSearch(int arr[], int size, int target) 
{
    if (arr[0] == target) 
    {
        return 0; // If the target is the first element
    }

    int bound = 1;
    while (bound < size && arr[bound] < target) 
    {
        bound *= 2; // Double the bound
    }

    // Perform binary search between the found range
    int high = (bound < size) ? bound : size - 1;
    return binarySearch(arr, bound / 2, high, target);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = exponentialSearch(arr, size, target);
    if (result != -1) 
    {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
    #hashing

#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;
    int size;

    // Simple hash function
    int hashFunction(int key) 
    {
        return key % size;
    }

public:
    HashTable(int s) : size(s) 
    {
        table = new int[size];
        for (int i = 0; i < size; i++) 
        {
            table[i] = -1; // Initialize table with -1 (indicating empty)
        }
    }

    ~HashTable() 
    {
        delete[] table; // Free the allocated memory
    }

    void insert(int key) 
    {
        int index = hashFunction(key);
        while (table[index] != -1) 
        { // Linear probing for collision resolution
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    int search(int key) 
    {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) 
        {
            if (table[index] == key) 
            {
                return index; // Key found
            }
            index = (index + 1) % size;
            if (index == startIndex) 
            {
                break; // Full loop around the table
            }
        }

        return -1; // Key not found
    }
};

int main() {
    HashTable hashTable(10); // Create a hash table of size 10

    // Insert elements
    hashTable.insert(1);
    hashTable.insert(3);
    hashTable.insert(5);
    hashTable.insert(7);
    hashTable.insert(9);

    // Search for a target
    int target = 7;
    int result = hashTable.search(target);

    if (result != -1) 
    {
        cout << "Target found at index: " << result << endl;
    } else 
    {
        cout << "Target not found in the hash table." << endl;
    }

    return 0;
}
#jump
#include <iostream>
#include <cmath> // For sqrt
using namespace std;

// Jump Search
int jumpSearch(int arr[], int size, int target) 
{
    int step = sqrt(size); // Define block size
    int prev = 0;

    // Jump ahead to find the block where the target may be
    while (arr[min(step, size) - 1] < target) 
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size) {
            return -1; // Target not found
        }
    }

    // Perform linear search within the block
    for (int i = prev; i < step && i < size; i++) 
    {
        if (arr[i] == target) {
            return i; // Target found
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = jumpSearch(arr, size, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}