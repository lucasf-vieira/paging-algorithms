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
   // Store keys of cache
   std::list<int> m_cacheKeys;

   // Store references of key in cache
   std::unordered_map<int, std::list<int>::iterator> m_cache;

public:
   Cache(int);
   virtual void refer(int) = 0;
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