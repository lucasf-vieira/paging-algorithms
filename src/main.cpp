#include "lrucache.hpp"
#include "fifocache.hpp"
#include "optcache.hpp"

int main(int argc, char *argv[])
{
   std::list<int> references = {0,2,1,3,5,4,6,3,7,4,7,3,3};
   //FIFOCache cache(references.size());
   //LRUCache cache(references.size());
   OPTCache cache(references.size());

   while(references.size() > 0)
   {
      cache.refer(references.front(), references);
      references.pop_front();
   }
   cache.display();

   return 0;
}
