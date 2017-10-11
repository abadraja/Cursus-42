//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_PLASMARIFLE_HPP
#define EX01_PLASMARIFLE_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class PlasmaRifle
{
public:
    PlasmaRifle();
    PlasmaRifle(const STR name);
    PlasmaRifle(PlasmaRifle const & f);
    virtual ~PlasmaRifle();

    PlasmaRifle & operator=(PlasmaRifle & r);


	
};
#endif //EX01_PLASMARIFLE_HPP
