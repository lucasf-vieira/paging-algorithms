#ifndef LRUCACHE_HPP
#define LRUCACHE_HPP

#include "cache.hpp"

class LRUCache : public Cache
{
public:
   LRUCache(int);
   void refer(int);
};

#endif