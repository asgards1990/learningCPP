#ifndef MINSTACK_H
#define MINSTACK_H
#include <deque>


using namespace std;


class MinStack {
    public:
       MinStack();
       ~MinStack();
       void push(int x);
       void pop();
       int top();
       int getMin();


    private:
        deque<int> intVec;
        deque<int> minVec;

};

#endif // MINSTACK_H
