// Name: Aidan Cowan
// Date: 9/13/23
// Program: ECGR 3180 - Homework 3: Recursive Binary Search 
// Description:
// 
// Write a recursive function that takes an input a sorted vector of integers, and a number to be searched.
// It returns the index of the number if it exists, and -1 if it does not.
// Important: Your implementation needs to be recursive.
// 
// -----Be sure to take of edge cases-----
// 1. The element might not exist in the array.
// 2. The target value could be in the rightmost or left most side of the array
// 3. The target value could be the initial, middle element
// 4. Duplicate entries could exist in the array

#include <iostream>
#include <vector>

using namespace std;

int recursiveSearch(vector<int> vec, int target, int start, int end) {
    if (start > end) {
        return -1;
    }
    int middle = (start + end) / 2;

    if (vec.at(middle) == target) {
        return middle;
    }
    else if (vec.at(middle) > target) {
        return recursiveSearch(vec, target, start, middle - 1);
    }
    else {
        return recursiveSearch(vec, target, middle + 1, end);
    }
}
int binarySearch(vector<int> vec, int target) {
    return recursiveSearch(vec, target, 0, (vec.size() - 1));
}


int main()
{
    vector<int> v1{ 2, 4, 6 }; // Left Edge Test
    vector<int> v2{ 1, 2, 3 }; // Middle Test
    vector<int> v3{ 0, 1, 2 }; // Right Edge Test
    vector<int> v4{ 1, 3, 5 }; // DNE Test

    int target = 2;

    cout << "Target: " << target << " ... Found at index: " << binarySearch(v1, target) << endl;
    cout << "Target: " << target << " ... Found at index: " << binarySearch(v2, target) << endl;
    cout << "Target: " << target << " ... Found at index: " << binarySearch(v3, target) << endl;
    cout << "Target: " << target << " ... Found at index: " << binarySearch(v4, target) << endl;
    
}
