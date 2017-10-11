//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_SUPERMUTANT_HPP
#define EX01_SUPERMUTANT_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class SuperMutant
{
public:
    SuperMutant();
    SuperMutant(const STR name);
    SuperMutant(SuperMutant const & f);
    virtual ~SuperMutant();

    SuperMutant & operator=(SuperMutant & r);

	
};
#endif //EX01_SUPERMUTANT_HPP
