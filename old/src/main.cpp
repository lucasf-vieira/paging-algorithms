// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
// (iterator) to each key in a hash map.

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "lrucache.hpp"
#include "fifocache.hpp"
#include "optcache.hpp"
#include "argument_parser.hpp"

// Driver Code
int main(int argc, char *argv[])
{
   Parser terminal_parser;

   if (!terminal_parser.checkArguments(argc, argv))
      return -1;

   LRUCache cache(std::stoi(argv[1]));
   double reference = 0;

   std::cin >> reference;
   while (!feof(stdin))
   {
      cache.refer(reference);
      std::cin >> reference;
   }

   cache.results();

   return 0;
}
