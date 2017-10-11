//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "Peon.hpp"

Peon::Peon() : Victim("Peon")
{
    OUT << "Zog zog.\n";
}

Peon::Peon(const STR name) : Victim(name)
{
    OUT << "Zog zog.\n";
}

Peon::Peon(Peon const &f)
{
    this->name = f.name;
    OUT << "Zog zog.\n";
}

Peon::~Peon()
{
    OUT << "Bleuark...\n";
}

Peon &Peon::operator=(Peon &r)
{
    this->name = r.name;
    return *this;
}

void Peon::getPolymorphed() const
{
    OUT << this->name << " has been turned into a pink pony !\n";
}


std::ostream &operator<<(std::ostream &o, Peon const &r)
{
    o << "I'm " << r.name <<  "and I like otters !\n";
    return o;
}
