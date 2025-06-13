#include <stack>
#include <limits.h> // For INT_MAX
using namespace std;

class MinStack {
public:
    stack<long long> st; // Stack to store the values
    long long mini; // Variable to store the minimum value

    MinStack() {
        mini = LLONG_MAX; // Initialize mini to the maximum long long value
    }
    
    void push(int value) {
        long long val = value; // Use the actual value being pushed
        if (st.empty()) {
            mini = val; // Set mini to the first value
            st.push(val);
        } else {
            if (val < mini) {
                // If the new value is less than the current minimum
                st.push(2 * val - mini); // Store a transformed value
                mini = val; // Update the minimum
            } else {
                st.push(val); // Push the value as is
            }
        }
    }
    
    void pop() {
        if (st.empty()) return; // Do nothing if the stack is empty
        long long el = st.top(); // Get the top element
        st.pop(); // Remove the top element

        if (el < mini) {
            // If the popped element is the minimum
            mini = 2 * mini - el; // Restore the previous minimum
        }
    }
    
    int top() {
        if (st.empty()) return -1; // Return -1 if the stack is empty
        long long el = st.top(); // Get the top element
        if (el < mini) return mini; // If the top element is a transformed value, return the minimum
        return el; // Otherwise, return the top element
    }
    
    int getMin() {
        return mini; // Return the minimum value
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
