#ifndef CACHE_HPP
#define CACHE_HPP

#include <list>
#include <unordered_map>
#include <iostream>

class Cache
{
   size_t m_frameSize; // Maximum capacity of cache
   uint m_referCount = 0;
   uint m_pageFaults = 0;

protected:
   // Store pages of cache
   std::list<int> m_cache;

   // Store references of cache keys
   std::unordered_map<int, std::list<int>::iterator> m_cacheKeys;

public:
   Cache(int);
   virtual void refer(int);

   void incrementReferCount();
   void incrementPageFaultCount();
   void displayPageFaults();

   size_t getFrameSize();
   void setFrameSize(int);

   size_t getCacheSize();
   uint getReferCount();
   uint getPageFaults();

   void updateReference(int);
};

#endif