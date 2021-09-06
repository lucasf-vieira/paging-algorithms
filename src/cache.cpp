#include "cache.hpp"

Cache::Cache(int cacheSize) { setFrameSize(cacheSize); }

size_t Cache::getFrameSize() { return m_frameSize; }
void Cache::setFrameSize(int cacheSize) { m_frameSize = cacheSize; }
size_t Cache::getCacheSize() { return m_cache.size(); }
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
void Cache::displayPageFaults()
{
   std::cout << getPageFaults() << " PFs" << std::endl;
}
