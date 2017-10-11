//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_TACTICALMARINE_HPP
#define EX02_TACTICALMARINE_HPP

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class TacticalMarine : virtual public ISpaceMarine
{
public:
    using ISpaceMarine::rangedAttack;
    using ISpaceMarine::clone;
    using ISpaceMarine::battleCry;
    using ISpaceMarine::meleeAttack;

    TacticalMarine();
    TacticalMarine(const STR name);
//    TacticalMarine(TacticalMarine const & f);
    virtual ~TacticalMarine();

//    TacticalMarine & operator=(TacticalMarine & r);

    ISpaceMarine* clone();
    void battleCry();
    void rangedAttack();
    virtual void meleeAttack();
};

#endif //EX02_TACTICALMARINE_HPP
