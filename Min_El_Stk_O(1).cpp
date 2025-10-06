#include <iostream>
#include <stack>
#include <limits> // Required for numeric_limits

// This class implements a special stack that supports
// push, pop, top, and retrieving the minimum element in constant time O(1).
class SpecialStack {
private:
    std::stack<int> s;   // Main stack to store elements.
    int minEle;          // Variable to store the current minimum element.

public:
    // Checks if the stack is empty.
    bool isEmpty() {
        return s.empty();
    }

    // Pushes a new element to the stack.
    // The logic handles how to store elements so that the minimum
    // can always be tracked.
    void push(int x) {
        // If the stack is empty, the new element is the minimum.
        if (s.empty()) {
            s.push(x);
            minEle = x;
            std::cout << x << " pushed to stack." << std::endl;
            return;
        }

        // If the new element is greater than or equal to the current minimum,
        // simply push it onto the stack.
        if (x >= minEle) {
            s.push(x);
        }
        // If the new element is the new minimum.
        else {
            // Push a modified value (a "flag") onto the stack.
            // This flag is always smaller than the new minimum element (x).
            // It will help us retrieve the previous minimum element during pop().
            s.push(2 * x - minEle);
            minEle = x; // Update the minimum element.
        }
        std::cout << x << " pushed to stack." << std::endl;
    }

    // Removes the top element from the stack.
    void pop() {
        if (s.empty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        int topVal = s.top();
        s.pop();

        int poppedElement;

        // If the value at the top of the stack is greater than or equal
        // to minEle, it's a normal element.
        if (topVal >= minEle) {
            poppedElement = topVal;
        }
        // If the value is less than minEle, it means the *actual* minimum
        // element was just popped. We must now update minEle to the
        // previous minimum.
        else {
            poppedElement = minEle;
            // Restore the previous minimum element using the formula.
            minEle = 2 * minEle - topVal;
        }
        std::cout << poppedElement << " popped from stack." << std::endl;
    }

    // Returns the top element of the stack.
    int top() {
        if (s.empty()) {
            return -1; // Indicates stack is empty
        }

        int topVal = s.top();

        // If the stored top value is less than minEle, it's a "flag".
        // The actual top element is the current minEle.
        if (topVal < minEle) {
            return minEle;
        }
        // Otherwise, the stored value is the correct top element.
        else {
            return topVal;
        }
    }

    // Returns the minimum element in the stack.
    int getMin() {
        if (s.empty()) {
            return -1; // Indicates stack is empty
        }
        return minEle;
    }
};


// Main function to drive the program.
int main() {
    SpecialStack s;
    int choice, value;

    // Menu-driven loop for user interaction.
    while (true) {
        std::cout << "\n--- Stack Menu ---" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Top Element" << std::endl;
        std::cout << "4. Get Minimum Element" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Input validation
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear(); // clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            continue;
        }


        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                 if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a number." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else {
                    s.push(value);
                }
                break;
            case 2:
                s.pop();
                break;
            case 3:
                if (s.isEmpty()) {
                    std::cout << "Stack is empty." << std::endl;
                } else {
                    std::cout << "Top element is: " << s.top() << std::endl;
                }
                break;
            case 4:
                if (s.isEmpty()) {
                    std::cout << "Stack is empty." << std::endl;
                } else {
                    std::cout << "Minimum element is: " << s.getMin() << std::endl;
                }
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
