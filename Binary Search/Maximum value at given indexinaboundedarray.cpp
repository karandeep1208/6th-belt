#include <iostream>
using namespace std;

class Solution {
public:
    // Helper function to calculate sum of elements on the left
    long sumLeft(int index, int x) {
        if (x > index) 
            return (long)(x - index + x - 1) * index / 2;
        return (long)(x - 1 + 1) * x / 2 + (index - x);
    }

    // Helper function to calculate sum of elements on the right
    long sumRight(int index, int x, int n) {
        int rightCount = n - index - 1;
        if (x > rightCount) 
            return (long)(x - rightCount + x - 1) * rightCount / 2;
        return (long)(x - 1 + 1) * x / 2 + (rightCount - x);
    }

    // Function to find the maximum possible value at index
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, result = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long totalSum = sumLeft(index, mid) + sumRight(index, mid, n) + mid;

            if (totalSum <= maxSum) {
                result = mid;  // Store the valid value
                left = mid + 1;  // Try increasing the value
            } else {
                right = mid - 1; // Reduce the value
            }
        }
        return result;
    }
};

int main() {
    int n, index, maxSum;
    
    // Taking user input
    cout << "Enter the size of the array (n): ";
    cin >> n;
    
    cout << "Enter the index position: ";
    cin >> index;
    
    cout << "Enter the maximum allowed sum: ";
    cin >> maxSum;

    // Creating an instance of Solution class
    Solution sol;
    int result = sol.maxValue(n, index, maxSum);

    // Display the result
    cout << "Maximum value at index " << index << ": " << result << endl;
    
    return 0;
}

//

#include <iostream>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, result = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long leftSum = 0, rightSum = 0, el = mid - 1;

            int emptyL = index;         // Elements on the left
            int emptyR = n - index - 1; // Elements on the right

            // Find left sum
            if (emptyL <= el)
                leftSum = (el * (el + 1)) / 2 - ((el - emptyL) * (el - emptyL + 1)) / 2;
            else
                leftSum = (el * (el + 1)) / 2 + (emptyL - el);

            // Find right sum
            if (emptyR <= el)
                rightSum = (el * (el + 1)) / 2 - ((el - emptyR) * (el - emptyR + 1)) / 2;
            else
                rightSum = (el * (el + 1)) / 2 + (emptyR - el);

            // Compute total sum
            long totalSum = leftSum + mid + rightSum;

            if (totalSum <= maxSum) {
                result = mid;  // Store valid value
                left = mid + 1; // Try increasing the value
            } else {
                right = mid - 1; // Reduce the value
            }
        }
        return result;
    }
};

int main() {
    int n, index, maxSum;

    // Taking user input
    cout << "Enter the size of the array (n): ";
    cin >> n;
    
    cout << "Enter the index position: ";
    cin >> index;
    
    cout << "Enter the maximum allowed sum: ";
    cin >> maxSum;

    // Creating an instance of Solution class
    Solution sol;
    int result = sol.maxValue(n, index, maxSum);

    // Display the result
    cout << "Maximum value at index " << index << ": " << result << endl;

    return 0;
}