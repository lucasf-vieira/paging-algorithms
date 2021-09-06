#ifndef FIFOCACHE_H
#define FIFOCACHE_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <string>

#include "cache.hpp"

class FIFOCache : public Cache
{
public:
   FIFOCache() : Cache(4) {};
   void refer(int);
   void results();
};

#endif