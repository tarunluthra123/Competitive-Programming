class MyStack {
    queue<int> *p,*q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        p = new queue<int>();
        q = new queue<int>();
    }

    /** Push element x onto stack. */
    void push(int x) {
        q->push(x);
        while(!p->empty()){
            q->push(p->front());
            p->pop();
        }
        swap(p,q);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = p->front();
        p->pop();
        return ans;
    }

    /** Get the top element. */
    int top() {
        return p->front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return p->size()+q->size()==0;
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
