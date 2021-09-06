#include "lrucache.hpp"

// Declare the size
LRUCache::LRUCache(int cacheSize) : Cache(cacheSize) {}

// Refers key in the LRU cache
void LRUCache::refer(int key)
{
   // not present in cache
   if (m_cache.find(key) == m_cache.end())
   {
      // cache is full
      if (m_cacheKeys.size() == getCacheSize())
      {
         // delete least recently used element
         int last = m_cacheKeys.back();

         // Pops the last element
         m_cacheKeys.pop_back();

         // Erase the last
         m_cache.erase(last);
      }
      incrementPageFaultCount();
   }

   // present in cache
   else
      m_cacheKeys.erase(m_cache[key]);

   updateReference(key);
   incrementReferCount();
}