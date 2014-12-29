#include "LRUCache.h"



LRUCache::LRUCache(int capacity): m_capacity(capacity)
{
    //ctor

}

LRUCache::~LRUCache()
{
    //dtor
}

int LRUCache::get(int key)
{

    int result(-1);
    auto iter(m_map.find(key));
//    Meaning the element is found and iter points to it:
    if (iter != m_map.end())
    {
        result = iter->second->second;
        m_keyValues.erase(iter->second);
        m_keyValues.push_front(make_pair(key,result));
        m_map[key] = m_keyValues.begin();
    }
    return result;

}


void LRUCache::set(int key, int value)
{
    auto iter = m_map.find(key);
    if (iter != m_map.end()) {
        m_keyValues.erase(iter->second);
    }
    m_keyValues.push_front(make_pair(key,value));
    m_map[key] = m_keyValues.begin();
    if (m_map.size() > m_capacity)
    {
        int rKey = m_keyValues.rbegin()->first;
        m_keyValues.pop_back();
        m_map.erase(rKey);


    }
}
