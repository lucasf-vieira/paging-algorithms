#ifndef CACHE_H
#define CACHE_H

#include <list>
#include <unordered_map>
#include <iostream>
#include <string>

class Cache
{
protected:
   std::size_t m_frameSize; // Maximum capacity of cache
   int m_pageFaults = 0;
   int m_references = 0;

   // Store keys of cache
   std::list<int> m_pageFrames;

   // Store references of key in cache
   std::unordered_map<int, std::list<int>::iterator> m_pageKeys;

public:
   Cache(const int);
   virtual void refer(const int);
   virtual void results();
   void display();
};

#endif