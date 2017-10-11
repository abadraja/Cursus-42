//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX02_ASSAULTTERMINATOR_HPP
#define EX02_ASSAULTTERMINATOR_HPP

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class AssaultTerminator : virtual public ISpaceMarine
{
public:

    using ISpaceMarine::rangedAttack;
    using ISpaceMarine::clone;
    using ISpaceMarine::battleCry;
    using ISpaceMarine::meleeAttack;

    AssaultTerminator();
//    AssaultTerminator(const STR name);
//    AssaultTerminator(AssaultTerminator const & f);
    virtual ~AssaultTerminator();

    void battleCry();
    void rangedAttack();
    virtual void meleeAttack();
//    AssaultTerminator & operator=(AssaultTerminator & r);
};


#endif //EX02_ASSAULTTERMINATOR_HPP
