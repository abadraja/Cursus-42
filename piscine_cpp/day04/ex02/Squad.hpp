//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_SQUAD_HPP
#define EX02_SQUAD_HPP

#include <iostream>
#include <string>
#include "ISquad.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class Squad : public ISquad
{
public:
    static int      nr_atributes;
    ISpaceMarine *s;

    using ISquad::getCount;
    using ISquad::getUnit;
    using ISquad::push;

    Squad();
//    Squad(const STR name);
//    Squad(Squad const & f);
    virtual ~Squad();

//    Squad & operator=(Squad & r);

    int     getCount();
    ISpaceMarine getUnit(int);
    int push(ISpaceMarine*);
	
};
#endif //EX02_SQUAD_HPP
