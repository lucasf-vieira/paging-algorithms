#include "lrucache.hpp"
#include "fifocache.hpp"
#include "optcache.hpp"

int main(int argc, char *argv[])
{
   //FIFOCache cache(4);
   LRUCache cache(4);

   cache.refer(1);
   cache.refer(2);
   cache.refer(3);
   cache.refer(1);
   cache.refer(4);
   cache.refer(5);
   cache.refer(8);
   cache.refer(3);
   cache.display();

   return 0;
}
