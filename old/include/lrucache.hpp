#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <string>

#include "cache.hpp"

class LRUCache : public Cache
{
public:
   LRUCache(int);
   void refer(int);
   void results();
};

#endif