//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_ENEMY_HPP
#define EX01_ENEMY_HPP

#include <iostream>
#include <string>


# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class Enemy
{
public:
    Enemy();
    Enemy(const STR name);
    Enemy(Enemy const & f);
    virtual ~Enemy();

    Enemy & operator=(Enemy & r);


	
};
#endif //EX01_ENEMY_HPP
