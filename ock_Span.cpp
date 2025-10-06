#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span
vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans;    // To store indices of previous greater elements
    stack<int> s;       // Stack to store indices

    for (int i = 0; i < n; i++)
    {
        // Pop smaller or equal elements from the stack
        while (!s.empty() && price[s.top()] <= price[i])
        {
            s.pop();
        }

        // If stack is empty, no previous greater element
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(s.top());
        }

        // Push current index onto the stack
        s.push(i);
    }

    // Convert indices to span values
    for (int i = 0; i < n; i++)
    {
        ans[i] = i - ans[i];
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int price[n];
    cout << "Enter stock prices for " << n << " days:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    vector<int> result = calculateSpan(price, n);

    cout << "\nStock Span for each day:\n";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
