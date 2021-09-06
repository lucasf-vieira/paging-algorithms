#include "cache.hpp"

Cache::Cache(int cacheSize) { setCacheSize(cacheSize); }

size_t Cache::getCacheSize() { return m_cacheSize; }
void Cache::setCacheSize(int cacheSize) { m_cacheSize = cacheSize; }
uint Cache::getReferCount() { return m_referCount; }
uint Cache::getPageFaults() { return m_pageFaults; }
void Cache::incrementReferCount() { m_referCount++; }
void Cache::incrementPageFaultCount() { m_pageFaults++; }

// Updates reference to the key in the hash map
void Cache::updateReference(int key)
{
   m_cacheKeys.push_front(key);
   m_cache[key] = m_cacheKeys.begin();
}

// Function to display contents of cache
void Cache::display()
{
   // Iterate in the list and print
   // all the elements in it
   for (auto it = m_cacheKeys.begin(); it != m_cacheKeys.end();
        it++)
      std::cout << (*it) << " ";

   std::cout << "References: " << getReferCount() << " PFs: " << getPageFaults() << std::endl;
}