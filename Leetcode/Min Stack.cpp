class MinStack {
    private:
        vector<int> s, m;

    public:
        /** initialize your data structure here. */
        MinStack() {
            s.clear();
            m.clear();
        }

        void push(int x) {
            s.push_back(x);
            if(m.size() >= 1)
                m.push_back(min(x, m.back()));
            else
                m.push_back(x);
        }

        void pop() {
            s.pop_back();
            m.pop_back();
        }

        int top() {
            return s.back();
        }

        int getMin() {
            return m.back();
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
