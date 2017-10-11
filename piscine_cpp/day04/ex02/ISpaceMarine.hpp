//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_ISPACEMARINE_HPP
#define EX02_ISPACEMARINE_HPP

#include <iostream>
#include <string>

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class ISpaceMarine
{
public:
    virtual ~ISpaceMarine() {}
    virtual ISpaceMarine* clone() const = 0;
    virtual void battleCry() const = 0;
    virtual void rangedAttack() const = 0;
    virtual void meleeAttack() const = 0;
	
};

#endif //EX02_ISPACEMARINE_HPP
