//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_POWERFIST_HPP
#define EX01_POWERFIST_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class PowerFist
{
public:
    PowerFist();
    PowerFist(const STR name);
    PowerFist(PowerFist const & f);
    virtual ~PowerFist();

    PowerFist & operator=(PowerFist & r);

	
};
#endif //EX01_POWERFIST_HPP
