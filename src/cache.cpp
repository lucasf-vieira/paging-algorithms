#include "cache.hpp"

Cache::Cache(int cacheSize) { setCacheSize(cacheSize); }

size_t Cache::getCacheSize() { return m_cacheSize; }
void Cache::setCacheSize(int cacheSize) { m_cacheSize = cacheSize; }
uint Cache::getReferCount() { return m_referCount; }
uint Cache::getPageFaults() { return m_pageFaults; }
void Cache::incrementReferCount() { m_referCount++; }
void Cache::incrementPageFaultCount() { m_pageFaults++; }
void Cache::refer(int) {}

// Updates reference to the key in the hash map
// and pushes page key to the front of the list
void Cache::updateReference(int key)
{
   m_cache.push_front(key);
   m_cacheKeys[key] = m_cache.begin();
}

// Function to display contents of cache
void Cache::display()
{
   std::cout << "References: " << getReferCount() << " PFs: " << getPageFaults() << std::endl;
}
