#ifndef OPTCACHE_H
#define OPTCACHE_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <string>

#include "cache.hpp"

class OPTCache : public Cache
{
public:
   OPTCache(int);
   void refer(int);
   void results();
};

#endif