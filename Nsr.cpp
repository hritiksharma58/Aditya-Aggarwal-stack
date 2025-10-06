/*nearest smallest to right or nearest smallest element*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<long long> nextSmallerElement(vector<long long> nums, int n) {
    stack<long long> stk;
    vector<long long> res(n);

    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() >= nums[i])
            stk.pop();

        if (stk.empty())
            res[i] = -1;
        else
            res[i] = stk.top();

        stk.push(nums[i]);
    }
    return res;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<long long> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<long long> result = nextSmallerElement(nums, n);

    cout << "Next Smaller Elements:\n";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
