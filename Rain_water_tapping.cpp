#include <iostream>
#include <vector>
#include <algorithm>  // for reverse

using namespace std;

// Function to find the largest element to the right of each element
vector<int> findLargestAtRight(int arr[], int n) {
    vector<int> rightMax(n);
    int maxSoFar = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            // Last element has no element to its right
            rightMax[i] = -1;
            maxSoFar = arr[i];
        } else {
            rightMax[i] = maxSoFar;
            if (arr[i] > maxSoFar)
                maxSoFar = arr[i];
        }
    }
    return rightMax;
}

// Function to find the largest element to the left of each element
vector<int> findLargestAtLeft(int arr[], int n) {
    vector<int> leftMax(n);
    int maxSoFar = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            // First element has no element to its left
            leftMax[i] = -1;
            maxSoFar = arr[i];
        } else {
            leftMax[i] = maxSoFar;
            if (arr[i] > maxSoFar)
                maxSoFar = arr[i];
        }
    }
    return leftMax;
}

// Function to calculate trapped rainwater
int sumRainTrap(vector<int>& left, vector<int>& right, int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (left[i] != -1 && right[i] != -1) {
            int trapped = min(left[i], right[i]) - arr[i];
            if (trapped > 0)
                sum += trapped;
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    vector<int> leftMax = findLargestAtLeft(array, n);
    vector<int> rightMax = findLargestAtRight(array, n);

    int result = sumRainTrap(leftMax, rightMax, array, n);

    cout << "Total trapped rainwater: " << result << endl;

    return 0;
}
