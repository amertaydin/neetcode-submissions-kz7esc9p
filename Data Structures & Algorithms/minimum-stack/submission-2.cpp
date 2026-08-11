// What
// I need to create a stack which supports push, pop, top and getMin options

// How
// create one main stack, and second stack to getMin

// Which pattern
// use stack

class MinStack {
        stack<int> st;
        stack<int> minSt;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if (minSt.empty() || minSt.top() >= val)
            minSt.push(val);
    }
    
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
