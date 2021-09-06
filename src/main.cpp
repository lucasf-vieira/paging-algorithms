#include "lrucache.hpp"
#include "fifocache.hpp"
#include "optcache.hpp"

#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
   std::ifstream file("vsim-gcc.txt");
   std::string linha;

   size_t frames = 64;
   FIFOCache fifocache(frames);
   LRUCache lrucache(frames);
   OPTCache optcache(frames);

   int teste;

   std::list<int> references;
   while (std::getline(file, linha))
   {
      teste = std::stoi(linha);
      references.push_front(teste);
   }
   std::cout << "Done\n"
             << std::flush;
   while (references.size() > 0)
   {
      fifocache.refer(references.front());
      lrucache.refer(references.front());
      optcache.refer(references.front(), references);
      references.pop_front();
      std::cout << "2";
   }

   std::cout << "FIFO: ";
   fifocache.display();
   std::cout << "LRU: ";
   lrucache.display();
   std::cout << "OPT: ";
   optcache.display();

   return 0;
}
