#include "lrucache.hpp"

// Declare the size
LRUCache::LRUCache(int cache_size)
{
   m_frameSize = cache_size;
}

// Refers key within the LRU cache
void LRUCache::refer(int page_key)
{
   // Not present in cache
   if (m_pageKeys.find(page_key) == m_pageKeys.end())
   {
      m_pageFaults++;

      // Cache is full
      if (m_pageFrames.size() == m_frameSize)
      {
         // Delete least recently used element
         int last = m_pageFrames.back();

         // Pops the last element
         m_pageFrames.pop_back();

         // Erase the last
         m_pageKeys.erase(last);
      }
   }

   // Present in cache
   else
      m_pageFrames.erase(m_pageKeys[page_key]);

   // Update reference
   m_pageFrames.push_front(page_key);
   m_pageKeys[page_key] = m_pageFrames.begin();

   m_references++; // Increment reference count
}

// Function to show the results of the simulation.
void LRUCache::results()
{
   std::cout << "LRU: " << m_pageFaults << " PFs" << std::endl;
}