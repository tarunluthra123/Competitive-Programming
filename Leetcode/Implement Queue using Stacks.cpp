class MyQueue {
    stack<int> *s,*t;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        s = new stack<int>();
        t = new stack<int>();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(!s->empty()){
            t->push(s->top());
            s->pop();
        }
        t->push(x);
        while(!t->empty()){
            s->push(t->top());
            t->pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = s->top();
        s->pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return s->top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s->size()+t->size()==0;
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
