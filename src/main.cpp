#include "lrucache.hpp"
#include "fifocache.hpp"
#include "optcache.hpp"

int main(int argc, char *argv[])
{
   std::list<int> references = {0,2,1,3,5,4,6,3,7,4,7,3,3, 9, 0,5,2,1,3,4,5,6,3,2,1,1,1,2,3,6};
   FIFOCache cache(4);
   //LRUCache cache(4);
   //OPTCache cache(4);

   while(references.size() > 0)
   {
      cache.refer(references.front());
      references.pop_front();
   }
   cache.display();

   return 0;
}
