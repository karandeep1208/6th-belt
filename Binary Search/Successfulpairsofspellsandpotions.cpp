#include <iostream>
#include <vector>

using namespace std;

// Merge function for Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) 
    L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) 
    R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) 
        arr[k++] = L[i++];
        else 
        arr[k++] = R[j++];
    }

    while (i < n1) 
    arr[k++] = L[i++];
    while (j < n2) 
    arr[k++] = R[j++];
}

// Merge Sort Function
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Binary Search to find the first valid potion index
int binarySearch(vector<int>& potions, long long minPotion) {
    int left = 0, right = potions.size() - 1, ans = potions.size();

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (potions[mid] >= minPotion) {
            ans = mid;  // Store potential answer
            right = mid - 1;  // Move left to find smaller valid index
        } else {
            left = mid + 1;
        }
    }
    return ans;  // First index where potion >= minPotion
}

// Function to find successful pairs
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    mergeSort(potions, 0, potions.size() - 1);  // Sort potions using Merge Sort
    int n = potions.size();
    int m = spells.size();
    
    vector<int> result(m); // Pre-allocate vector to avoid push_back()

    for (int i = 0; i < m; i++) {
        long long minPotion = (success + spells[i] - 1) / spells[i];  // Equivalent to ceil(success / spell)
        int index = binarySearch(potions, minPotion);
        result[i] = n - index;  // Assign directly
    }

    return result;
}

int main() {
    int m, n;
    long long success;

    // Input spells array
    cout << "Enter number of spells: ";
    cin >> m;
    vector<int> spells(m);
    cout << "Enter " << m << " spell strengths: ";
    for (int i = 0; i < m; i++) cin >> spells[i];

    // Input potions array
    cout << "Enter number of potions: ";
    cin >> n;
    vector<int> potions(n);
    cout << "Enter " << n << " potion strengths: ";
    for (int i = 0; i < n; i++) cin >> potions[i];

    // Input success threshold
    cout << "Enter success threshold: ";
    cin >> success;

    // Find successful pairs
    vector<int> result = successfulPairs(spells, potions, success);

    // Output result
    cout << "Successful Pairs: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}