#ifndef OPTACHE_HPP
#define OPTCACHE_HPP

#include "cache.hpp"

class OPTCache : public Cache
{
public:
   OPTCache(int);
   void refer(int);
};

#endif