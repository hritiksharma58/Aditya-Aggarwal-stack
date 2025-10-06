#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for reverse()

using namespace std;

// Function to find Nearest Greater to Right (NGR)
vector<int> ngr(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> vect;

    for (int i = n - 1; i >= 0; i--)
    {
        // Pop smaller or equal elements
        while (!st.empty() && arr[i] >= st.top())
            st.pop();

        // If stack is empty → no greater element to the right
        if (st.empty())
            vect.push_back(-1);
        else
            vect.push_back(st.top());

        // Push current element to stack
        st.push(arr[i]);
    }

    // Reverse because we traversed from right to left
    reverse(vect.begin(), vect.end());

    return vect;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = ngr(arr, n);

    cout << "\nNearest Greater to Right: ";
    for (int val : result)
        cout << val << " ";

    cout << endl;

    return 0;
}
