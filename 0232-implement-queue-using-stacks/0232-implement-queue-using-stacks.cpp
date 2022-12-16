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
        if(!output.empty()){
            int top=output.top();
            output.pop();
            return top;
        }
        else {
            while(!input.empty()) {
                int top=input.top();
                input.pop();
                output.push(top);
            }
            int front=output.top();
            output.pop();
            return front;
        }
    }
    
    int peek() {
         if(!output.empty()){
            int top=output.top();
            return top;
        }
        else {
            while(!input.empty()) {
                int top=input.top();
                input.pop();
                output.push(top);
            }
            int front=output.top();
            return front;
        }
    }
    
    bool empty() {
        if(input.empty() && output.empty()) return true;
        else return false;
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