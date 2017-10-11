//
// Created by Alen BADRAJAN on 7/25/17.
//

#ifndef EX01_AWEAPON_HPP
#define EX01_AWEAPON_HPP

#include <iostream>
#include <string>

# define STR std::string
# define OUT std::cout
# define IN std::cin
# define ENDL std::endl
# define SEPARATOR OUT << ENDL << "==================================================================\n" << ENDL

class AWeapon
{
public:

    AWeapon();
    AWeapon(const STR name);
    AWeapon(AWeapon const & f);
    virtual ~AWeapon();

    AWeapon & operator=(AWeapon & r);

};
#endif //EX01_AWEAPON_HPP
