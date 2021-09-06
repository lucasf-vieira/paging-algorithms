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

   LRUCache lrucache(std::stoi(argv[1]));
   FIFOCache fifocache(std::stoi(argv[1]));
   OPTCache optcache(std::stoi(argv[1]));

   uint reference = 0;
   auto referenceList = std::make_shared<std::list<int>>();

   std::cin >> reference;
   while (!feof(stdin))
   {
      referenceList->push_front(reference);

      lrucache.refer(reference);
      fifocache.refer(reference);
      std::cin >> reference;
   }

   while (referenceList->size() > 0)
   {
      optcache.refer(referenceList->front(), referenceList);
      referenceList->pop_front();
      optcache.displayPageFaults();
   }

   std::cout << argv[1] << " quadros" << std::endl;
   std::cout << optcache.getReferCount() << " refs" << std::endl;
   std::cout << "FIFO: " << fifocache.getPageFaults() << " PFs" << std::endl;
   std::cout << "LRU: " << lrucache.getPageFaults() << " PFs" << std::endl;
   std::cout << "OPT: " << optcache.getPageFaults() << " PFs" << std::endl;

   return 0;
}
