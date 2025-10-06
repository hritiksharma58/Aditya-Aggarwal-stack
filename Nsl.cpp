/*nearest smallest to left or nearest smallest element*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> nearestSmallestLeft(vector<int> input)
{
    vector<int> output;
    stack<int> s;
    for (int i = 0; i < input.size(); i++)
    {
        while (!s.empty() and s.top() >= input[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            output.push_back(-1);
        }
        else if (s.size() > 0 and s.top() < input[i])
        {
            output.push_back(s.top());
        }

        s.push(input[i]);
    }

    return output;
}
int main()
{
    vector<int> input = {2, 7, 3, 5, 4, 6, 8};

    vector<int> result = nearestSmallestLeft(input);
    for (int i : result)
    {
        cout << i << ' ';
    }

    return 0;
}