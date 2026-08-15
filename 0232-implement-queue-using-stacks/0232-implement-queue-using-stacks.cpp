class MyQueue {
public:
stack<int>a;
stack<int>b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(!a.empty()){

        b.push(a.top());
        a.pop();
        }
        int x=b.top();
        b.pop();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return x;
    }
    
    int peek() {
        while(!a.empty()){

        b.push(a.top());
        a.pop();
        }
        int x=b.top();
         while(!b.empty()){
            a.push(b.top());
            b.pop();
        } return x;
    }
    
    bool empty() {
        return a.empty();
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