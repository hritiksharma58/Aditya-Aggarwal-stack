#include <iostream>
using namespace std;

// Function to calculate total trapped rainwater using two-pointer approach
int trapRainWater(int arr[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int totalWater = 0;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax)
                leftMax = arr[left];      // update left max
            else
                totalWater += (leftMax - arr[left]); // water trapped
            left++;
        } 
        else {
            if (arr[right] >= rightMax)
                rightMax = arr[right];    // update right max
            else
                totalWater += (rightMax - arr[right]); // water trapped
            right--;
        }
    }

    return totalWater;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = trapRainWater(arr, n);
    cout << "Total trapped rainwater: " << result << endl;

    return 0;
}
