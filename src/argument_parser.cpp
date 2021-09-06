#include "argument_parser.hpp"

Parser::Parser(){}

bool Parser::isNumber(const std::string &str)
{
   return str.find_first_not_of("0123456789") == std::string::npos;
}

bool Parser::checkArguments(int num_arguments, char **arguments)
{
   switch (num_arguments)
   {
   case 1:
      std::cout << "Erro: Numero de quadros nao especificado. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;

   case 2:
      break;

   default:
      std::cout << "Erro: Numero de argumentos excedeu o limite (Limite de 1 argumento)" << std::endl;
      return false;
   }

   std::string argument = arguments[1];

   if (!isNumber(argument))
   {
      std::cout << "Erro: Argumento nao e um inteiro positivo. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;
   }

   if (std::stoi(argument) == 0)
   {
      std::cout << "Erro: Argumento nao pode ser zero. Utilizacao: ./bin/paging-simulation.o [numero de quadros da simulacao]" << std::endl;
      return false;
   }

   return true;
}