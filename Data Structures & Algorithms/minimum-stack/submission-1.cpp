class MinStack {
private:
    std::stack<int> stack;
    std::stack<int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
        //will get pushed to both to maintain equilibrium
    }
    
    void pop() {
        stack.pop();
        minStack.pop();
        //popping from both to maintain equilibrium
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
