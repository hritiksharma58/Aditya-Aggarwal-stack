#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Constructor
    MinStack() {}

    // Push operation
    void push(int val) {
        if (mainStack.empty()) {
            minStack.push(val);
        } else if (!minStack.empty() && minStack.top() >= val) {
            minStack.push(val);
        }
        mainStack.push(val);
    }

    // Pop operation
    int pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return -1;
        }
        int topVal = mainStack.top();
        mainStack.pop();

        if (topVal == minStack.top()) {
            minStack.pop();
        }
        return topVal;
    }

    // Get minimum element
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty. No minimum element.\n";
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    MinStack m;
    int choice, value;

    cout << "------ MinStack Operations ------\n";
    cout << "1. Push\n2. Pop\n3. Get Minimum\n4. Exit\n";

    while (true) {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                m.push(value);
                cout << value << " pushed to stack.\n";
                break;

            case 2:
                value = m.pop();
                if (value != -1)
                    cout << value << " popped from stack.\n";
                break;

            case 3:
                value = m.getMin();
                if (value != -1)
                    cout << "Current minimum: " << value << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
