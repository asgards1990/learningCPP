#include "MinStack.h"

MinStack::MinStack(): intVec(),minVec()
    {
        //ctor

    }

    MinStack::~MinStack()
    {
        //dtor
    }

void  MinStack::push(int x) {
        intVec.push_back(x);
        if (minVec.empty() || x <= minVec.back())
        {
            minVec.push_back(x);
        }

    }

    void MinStack::pop() {
        if (intVec.empty())
            return;
        int lastElement(intVec.back());
        intVec.pop_back();
        if (lastElement == minVec.back())
            minVec.pop_back();

    }

    int  MinStack::top() {
        return intVec.back();

    }

    int  MinStack::getMin() {
        return minVec.back();
    }

