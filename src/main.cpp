#include <unordered_map>
#include <list>
#include <iostream>

class LRUCache {
    // store keys of cache
    std::list<int> m_cacheKeys;
 
    // store references of key in cache
    std::unordered_map<int, std::list<int>::iterator> m_cache;
    size_t m_cacheSize; // maximum capacity of cache
 
public:
    LRUCache(int);
    void refer(int);
    void display();
};
 
// Declare the size
LRUCache::LRUCache(int cacheSize)
{
    m_cacheSize = cacheSize;
}
 
// Refers key in the LRU cache
void LRUCache::refer(int key)
{
    // not present in cache
    if (m_cache.find(key) == m_cache.end()) {
        // cache is full
        if (m_cacheKeys.size() == m_cacheSize) {
            // delete least recently used element
            int last = m_cacheKeys.back();
 
            // Pops the last element
            m_cacheKeys.pop_back();
 
            // Erase the last
            m_cache.erase(last);
        }
    }
 
    // present in cache
    else
        m_cacheKeys.erase(m_cache[key]);
 
    // update reference
    m_cacheKeys.push_front(key);
    m_cache[key] = m_cacheKeys.begin();
}
 
// Function to display contents of cache
void LRUCache::display()
{
    // Iterate in the list and print
    // all the elements in it
    for (auto it = m_cacheKeys.begin(); it != m_cacheKeys.end();
         it++)
        std::cout << (*it) << " ";
 
    std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    LRUCache ca(4);
 
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
 
    return 0;
}
