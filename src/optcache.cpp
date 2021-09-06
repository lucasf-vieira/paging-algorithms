#include "optcache.hpp"

// Declare the size
OPTCache::OPTCache(int cacheSize) : Cache(cacheSize) {}

int OPTCache::findFarthestRef(std::shared_ptr<std::list<int>> remainingReferences)
{
   if (getCacheSize() == 0)
      return -1;

   std::list<int> foundRefs;
   std::unordered_map<int, std::list<int>::iterator> refKeys;
   bool found = false;

   // Iterate cache
   for (auto it_cache = m_cache.begin(); it_cache != m_cache.end();
        it_cache++)
   {
      found = false;
      // Iterate inside remaining references
      for (auto it_refs = remainingReferences->begin(); it_refs != remainingReferences->end();
           it_refs++)
      {
         if ((*it_refs) == (*it_cache))
         {
            found = true;
            break;
         }
      }

      // Did not find any more references of the element
      if (found == false)
      {
         return (*it_cache);
      }

      if (foundRefs.size() == getCacheSize())
         break;
   }

   // Iterate inside remaining references
   for (auto it_refs = remainingReferences->begin(); it_refs != remainingReferences->end();
        it_refs++)
   {
      // Iterate cache
      for (auto it_cache = m_cache.begin(); it_cache != m_cache.end();
           it_cache++)
      {
         if ((*it_refs) == (*it_cache) && refKeys.find((*it_cache)) == refKeys.end())
         {
            foundRefs.push_front((*it_cache));
            refKeys[(*it_cache)] = foundRefs.begin();
            break;
         }
      }
      if(foundRefs.size() == getCacheSize())
         break;
   }

   return foundRefs.front();
}

// Refers key in the OPT cache
void OPTCache::refer(int key, std::shared_ptr<std::list<int>> remainingReferences)
{
   // Not present in cache
   if (m_cacheKeys.find(key) == m_cacheKeys.end())
   {
      // Cache is full
      if (m_cache.size() == getFrameSize())
      {
         // Delete the farthest element to be referenced
         int elementToRemove = findFarthestRef(remainingReferences);

         // Removes the element
         m_cache.remove(elementToRemove);

         // Erase the element key
         m_cacheKeys.erase(elementToRemove);
      }

      incrementPageFaultCount();
      updateReference(key);
   }

   // If present in cache, no update needed
   incrementReferCount();
}