//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        all.emplace(x);
        if (mins.empty() || x <= mins.top()) {
            mins.emplace(x);
        }
    }
    
    void pop() {
        if (all.empty()) return;
        if (mins.top() == all.top()) {
            mins.pop();
        }
        all.pop();
    }
    
    int top() {
        if (all.empty()) return -1;
        return all.top();
    }
    
    int getMin() {
        if (mins.empty()) return -1;
        return mins.top();
    }
    stack<int> all, mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
