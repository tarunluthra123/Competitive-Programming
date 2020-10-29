//https://www.interviewbit.com/problems/min-stack/
/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
 NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
*/
vector<int> v;
vector<int> minEle;
int minSoFar = INT_MAX;
MinStack::MinStack() {
   v.clear(); 
   minEle.clear();
   minSoFar = INT_MAX;
}

void MinStack::push(int x) {
    v.push_back(x);
    minSoFar = min(minSoFar, x);
    minEle.push_back(minSoFar);
}

void MinStack::pop() {
    if(minEle.size() == 0 || v.size() == 0)
        return ;
    v.pop_back();
    minEle.pop_back();
    if(minEle.size() > 0)
        minSoFar = minEle[minEle.size()-1];
    else 
        minSoFar = INT_MAX;
}

int MinStack::top() {
    if(minEle.size() == 0 || v.size() == 0)
        return -1;
    return v[v.size()-1];
}

int MinStack::getMin() {
    if(minEle.size() == 0 || v.size() == 0)
        return -1;
    return minEle[minEle.size()-1];
}


