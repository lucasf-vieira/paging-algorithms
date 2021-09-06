#include "fifocache.hpp"

// Declare the size
FIFOCache::FIFOCache(int cacheSize) : Cache(cacheSize) {}

// Refers key in the FIFO cache
void FIFOCache::refer(int key)
{
   // Not present in cache
   if (m_cache.find(key) == m_cache.end())
   {
      // Cache is full
      if (m_cacheKeys.size() == getCacheSize())
      {
         // Delete last element in the list
         int last = m_cacheKeys.back();

         // Pops the last element in the list
         m_cacheKeys.pop_back();

         // Erase the last element
         m_cache.erase(last);
      }
      incrementPageFaultCount();
      updateReference(key);
   }

   // If present in cache, no update needed
   incrementReferCount();
}