#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;

void solve(ll ar[], int n) {
    stack<ll> st;
    vector<ll> ans(n, -1); // Initialize ans with -1

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= ar[i]) {
            st.pop();
        }
        if (!st.empty())
            ans[i] = st.top();

        st.push(ar[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ar[i] << " -> " << ans[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    ll ar[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    cout << "\nNearest Greater to Left:\n";
    solve(ar, n);

    return 0;
}
