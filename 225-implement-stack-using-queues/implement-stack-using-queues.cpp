#include <queue>

class MyStack {
private:
    std::queue<int> q1, q2; // Two queues

public:
    MyStack() {
    }
    
    void push(int x) {
        q2.push(x);  // Push element to q2
        while (!q1.empty()) {
            q2.push(q1.front()); // Move all elements from q1 to q2
            q1.pop();
        }
        std::swap(q1, q2); // Swap q1 and q2
    }
    
    int pop() {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */