#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

#include <iostream>
#include <string>

class Parser
{
public:
   Parser();
   bool checkArguments(int, char **);
   bool isNumber(const std::string &);
};

#endif