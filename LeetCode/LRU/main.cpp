#include <iostream>
#include "LRUCache.h"
using namespace std;

int main()
{
    LRUCache test(1);
    test.set(2,1);
    cout << test.get(1) << endl;

    return 0;
}
