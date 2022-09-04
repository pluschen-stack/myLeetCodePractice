#include"../defs.h"

class MyQueue {
private:
    stack<int> stackIn;
    stack<int> stackOut;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if(stackOut.empty()){
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int result = stackOut.top();
        stackOut.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        stackOut.push(result);
        return result;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty();
    }
};