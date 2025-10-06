#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> NSL(long long arr[], int n) {
        vector<int> ans;
        stack<int> s; // store indices
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            ans.push_back(s.empty() ? -1 : s.top());
            s.push(i);
        }
        return ans;
    }

    vector<int> NSR(long long arr[], int n) {
        vector<int> ans(n);
        stack<int> s; // store indices
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            ans[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        return ans;
    }

    long long getMaxArea(long long arr[], int n) {
        vector<int> left = NSL(arr, n);
        vector<int> right = NSR(arr, n);
        long long maxArea = 0;
        for (int i = 0; i < n; i++) {
            long long width = right[i] - left[i] - 1;
            maxArea = max(maxArea, width * arr[i]);
        }
        return maxArea;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "\nEnter number of histogram bars: ";
        cin >> n;

        long long arr[n];
        cout << "Enter the heights of histogram bars: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        // Print user input for clarity
        cout << "You entered the histogram heights: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";

        Solution ob;
        long long maxArea = ob.getMaxArea(arr, n);
        cout << "Maximum rectangular area in the histogram is: " << maxArea << "\n";
    }

    return 0;
}
