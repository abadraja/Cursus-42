//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX00_PEON_HPP
# define EX00_PEON_HPP

#include <iostream>
#include <string>
#include "Victim.hpp"

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class Peon : virtual public Victim
{
public:
    Peon();
    Peon(const STR name);
    Peon(Peon const & f);
    virtual ~Peon();

    Peon & operator=(Peon & r);

    void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & o, Peon const & r);

#endif //EX00_PEON_HPP
