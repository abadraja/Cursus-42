//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_ISQUAD_HPP
#define EX02_ISQUAD_HPP

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class ISquad
{
public:

    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int) const = 0;
    virtual int push(ISpaceMarine*) = 0;
	
};
#endif //EX02_ISQUAD_HPP
