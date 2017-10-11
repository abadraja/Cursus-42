//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_RADSCORPION_HPP
#define EX01_RADSCORPION_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class RadScorpion
{
public:
    RadScorpion();
    RadScorpion(const STR name);
    RadScorpion(RadScorpion const & f);
    virtual ~RadScorpion();

    RadScorpion & operator=(RadScorpion & r);


	
};
#endif //EX01_RADSCORPION_HPP
