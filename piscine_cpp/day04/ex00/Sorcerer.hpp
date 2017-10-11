//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX00_SORCERER_HPP
# define EX00_SORCERER_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL


class Sorcerer
{
public:
    STR     name;
    STR     title;

    /* ========= Methods ========= */
    Sorcerer();
    Sorcerer(STR const n, STR const t);
    Sorcerer(Sorcerer const & f);
    virtual ~Sorcerer();

    Sorcerer & operator=(Sorcerer & r);
    /* ======= END Methods ======= */

    void polymorph(Victim const &v) const;

};

std::ostream & operator<<(std::ostream & o, Sorcerer const & r);

#endif //EX00_SORCERER_HPP
