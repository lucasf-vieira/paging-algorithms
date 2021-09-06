#include "cache.hpp"

// Declare the size
Cache::Cache(const int cacheSize)
{
   m_frameSize = cacheSize;
}

// Function to display contents of cache
void Cache::display()
{
   // Iterate in the deque and print
   // all the elements in it
   for (auto it = m_pageFrames.begin(); it != m_pageFrames.end(); it++)
      std::cout << (*it) << " ";

   std::cout << std::endl;
}