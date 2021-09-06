#ifndef CACHE_HPP
#define CACHE_HPP

#include <list>
#include <unordered_map>
#include <iostream>

class Cache
{
   size_t m_cacheSize; // Maximum capacity of cache
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
   void display();

   size_t getCacheSize();
   void setCacheSize(int);

   uint getReferCount();
   uint getPageFaults();

   void updateReference(int);
};

#endif