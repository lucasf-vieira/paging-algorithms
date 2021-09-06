#include "lrucache.hpp"

// Declare the size
LRUCache::LRUCache(int cacheSize) : Cache(cacheSize) {}

// Refers key in the LRU cache
void LRUCache::refer(int key)
{
   // not present in cache
   if (m_cacheKeys.find(key) == m_cacheKeys.end())
   {
      // cache is full
      if (m_cache.size() == getCacheSize())
      {
         // delete least recently used element
         int last = m_cache.back();

         // Pops the last element
         m_cache.pop_back();

         // Erase the last
         m_cacheKeys.erase(last);
      }
      incrementPageFaultCount();
   }

   // present in cache
   else
      m_cache.erase(m_cacheKeys[key]);

   updateReference(key);
   incrementReferCount();
}