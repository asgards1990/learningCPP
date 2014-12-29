#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <list>
#include <utility>
#include <unordered_map>


using namespace std;

class LRUCache
{
    public:
        LRUCache(int capacity);
        virtual ~LRUCache();

        int get(int key);
        void set(int key, int value);
    protected:
    private:
        int m_capacity;
        list<pair<int, int>> m_keyValues;
        unordered_map<int,list<pair<int, int>>::iterator> m_map;
};

#endif // LRUCACHE_H
