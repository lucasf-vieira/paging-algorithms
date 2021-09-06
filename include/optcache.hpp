#ifndef OPTACHE_HPP
#define OPTCACHE_HPP

#include "cache.hpp"

#include <memory>

class OPTCache : public Cache
{
public:
   OPTCache(int);
   void refer(int, std::shared_ptr<std::list<int>>);
   int findFarthestRef(std::shared_ptr<std::list<int>>);
};

#endif