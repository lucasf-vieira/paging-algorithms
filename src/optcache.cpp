#include "optcache.hpp"

// Declare the size
OPTCache::OPTCache(int cacheSize) : Cache(cacheSize) {}

int OPTCache::findFarthestRef(std::list<int> remainingReferences)
{
   std::list<int> foundRefs;

   // Iterate inside remaining references
   for (auto it_refs = remainingReferences.begin(); it_refs != remainingReferences.end();
        it_refs++)
   {
      // Iterate cache
      for (auto it_cache = m_cache.begin(); it_cache != m_cache.end();
           it_cache++)
      {
         if ((*it_refs) == (*it_cache))
         {
            foundRefs.push_front(*it_cache);
            break;
         }
      }

      if (foundRefs.size() == getCacheSize())
         break;
   }
   return foundRefs.front();
}

// Refers key in the OPT cache
void OPTCache::refer(int key, std::list<int> remainingReferences)
{
   // Not present in cache
   if (m_cacheKeys.find(key) == m_cacheKeys.end())
   {
      // Cache is full
      if (m_cache.size() == getCacheSize())
      {
         // Delete the farthest element to be referenced
         m_cache.remove(findFarthestRef(remainingReferences));
      }
      incrementPageFaultCount();
      updateReference(key);
   }

   // If present in cache, no update needed
   incrementReferCount();
}