#include <priority_queue>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        stk.push(value);
        if (minStk.empty() || value <= minStk.top()) minStk.push(value);
    }
    
    void pop() {
        if (minStk.top() == stk.top()) minStk.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
