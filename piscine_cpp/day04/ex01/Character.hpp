//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_CHARACTER_HPP
#define EX01_CHARACTER_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class Character
{
public:
    Character();
    Character(const STR name);
    Character(Character const & f);
    virtual ~Character();

    Character & operator=(Character & r);


	
	
};
#endif //EX01_CHARACTER_HPP
