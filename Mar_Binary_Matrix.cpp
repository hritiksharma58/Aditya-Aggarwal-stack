#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Function to find Maximum Area Histogram (MAH)
int MAH(vector<int> v, int n) {
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> s;
    int mx = 0;

    // Calculate left limits
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    // Clear stack for right limits
    while (!s.empty()) s.pop();

    // Calculate right limits
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && v[s.top()] >= v[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    // Compute max rectangle area in histogram
    for (int i = 0; i < n; ++i) {
        int width = right[i] - left[i] - 1;
        mx = max(mx, v[i] * width);
    }
    return mx;
}

// Function to find maximal rectangle of 1s in binary matrix
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &a, int n, int m) {
    vector<int> v(m, 0);
    int mx = 0;

    // Initialize with first row
    for (int i = 0; i < m; ++i)
        v[i] = a[0][i];

    mx = max(mx, MAH(v, m));

    // Process remaining rows
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            v[j] = (a[i][j] == 0) ? 0 : v[j] + 1;
        }
        mx = max(mx, MAH(v, m));
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cout << "Enter number of rows and columns of the matrix: ";
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    int maxArea = maximalAreaOfSubMatrixOfAll1(matrix, n, m);
    cout << "\nMaximum area of sub-matrix of all 1s is: " << maxArea << "\n";

    return 0;
}
