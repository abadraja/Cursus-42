//
// Created by Alen BADRAJAN on 7/25/17.
//
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    OUT << "* teleports from space *\n";
}

//AssaultTerminator::AssaultTerminator(AssaultTerminator const &f)
//{
//    OUT <<" ~  <<"* teleports from space *\n";
//
//}

AssaultTerminator::~AssaultTerminator()
{
    OUT << "I’ll be back ...\n";
}

//AssaultTerminator::AssaultTerminator(const STR name)
//{
//    OUT << "* teleports from space *\n";
//
//}
//
//AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator &r)
//{
//    return *this;
//}

void AssaultTerminator::battleCry() {
    OUT << "This code is unclean. PURIFY IT !\n";
}

void AssaultTerminator::rangedAttack() {
    OUT << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() {
    OUT << "* attacks with chainfists *\n";
}
