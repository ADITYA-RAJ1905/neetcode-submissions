class MyStack {
public:
    queue<int> q;
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        while(!q1.empty()){
            q.push(q1.front());
            q1.pop();
        }
        swap(q,q1);
    }
    
    int pop() {
        int ele=q1.front();
        q1.pop();
        return ele;
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