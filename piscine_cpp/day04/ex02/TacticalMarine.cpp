//
// Created by Alen BADRAJAN on 7/25/17.
//

#include <string>
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
 OUT << "Tactical Marine ready for battle\n";
}

TacticalMarine::TacticalMarine(const std::string name) {
    OUT << "Tactical Marine "<< name << "ready for battle\n";
}

//TacticalMarine::TacticalMarine(const TacticalMarine &f)
//{
//    OUT << "Tactical Marine ready for battle\n";
//}

TacticalMarine::~TacticalMarine() {
    OUT << "Aaargh ...\n";
}

//TacticalMarine &TacticalMarine::operator=(TacticalMarine &r)
//{
//    return *this;
//}

ISpaceMarine *TacticalMarine::clone()
{
    TacticalMarine& t = *this;

    return (ISpaceMarine *) &t;
}

void TacticalMarine::battleCry() {
    OUT << "For the holy PLOT !\n";
}

void TacticalMarine::rangedAttack() {
    OUT << "* attacks with bolter *\n";
}

void TacticalMarine::meleeAttack() {
    OUT << "* attacks with chainsword *\n";
}
