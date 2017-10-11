//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX00_VICTIM_HPP
# define EX00_VICTIM_HPP

#include <iostream>
#include <string>

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class Victim
{
public:
    STR name;

    Victim();
    Victim(const STR name);
    Victim(Victim const & f);
    virtual ~Victim();

    Victim & operator=(Victim & r);

    virtual void getPolymorphed() const;
};

std::ostream & operator<<(std::ostream & o, Victim const & r);

#endif //EX00_VICTIM_HPP
