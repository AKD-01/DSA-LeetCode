class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()) {
            int top=output.top();
            output.pop();
            return top;
        }
        else {
            while(!input.empty()){
                int top=input.top();
                input.pop();
                output.push(top);
            }
            int top=output.top();
            output.pop();
            return top;
        }
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        else {
            while(!input.empty()){
                int top=input.top();
                input.pop();
                output.push(top);
            }
            return output.top();
        }
    }
    
    bool empty() {
        if(output.empty()&&input.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */