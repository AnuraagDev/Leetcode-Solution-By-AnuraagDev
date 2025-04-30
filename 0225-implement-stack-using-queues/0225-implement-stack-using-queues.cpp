class MyStack {
public:stack<int>st;
int a;
    MyStack() {
    
    }
    
    void push(int x) {
     st.push(x);   
    }
    
    int pop() {
       int a=st.top();
       st.pop();
       return a;
    }
    
    int top() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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