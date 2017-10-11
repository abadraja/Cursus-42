//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "Victim.hpp"

Victim::Victim() : name("Victim")
{
    OUT << "Some random victim called " << this->name << " just popped !\n";
}

Victim::Victim(Victim const &f)
{
    this->name = f.name;
    OUT << "Some random victim called " << this->name << " just popped !\n";
}

Victim::Victim(const STR name) : name(name)
{
    OUT << "Some random victim called " << this->name << " just popped !\n";

}

Victim::~Victim()
{
    OUT << "Victim " << this->name << " just died for no apparent reason !\n";
}

Victim &Victim::operator=(Victim &r)
{
    this->name = r.name;
    return *this;
}

void Victim::getPolymorphed() const
{
    OUT << this->name << " has been turned into a cute little sheep !\n";
}


std::ostream &operator<<(std::ostream &o, Victim const &r)
{
    o << "I'm " << r.name <<  "and I like otters !\n";
    return o;
}
