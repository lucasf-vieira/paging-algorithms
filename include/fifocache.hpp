#ifndef FIFOCACHE_HPP
#define FIFOCACHE_HPP

#include "cache.hpp"

class FIFOCache : public Cache
{
public:
   FIFOCache(int);
   void refer(int);
};

#endif