#include "fifocache.hpp"

// Declare the size
FIFOCache::FIFOCache(int cacheSize) : Cache(cacheSize) {}

// Refers key in the FIFO cache
void FIFOCache::refer(int key)
{
   // Not present in cache
   if (m_cacheKeys.find(key) == m_cacheKeys.end())
   {
      // Cache is full
      if (m_cache.size() == getFrameSize())
      {
         // Delete last element in the list
         int last = m_cache.back();

         // Pops the last element in the list
         m_cache.pop_back();

         // Erase the last element
         m_cacheKeys.erase(last);
      }
      incrementPageFaultCount();
      updateReference(key);
   }

   // If present in cache, no update needed
   incrementReferCount();
}