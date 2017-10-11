//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : name("Sorcerer"), title("Jorcer")
{
    OUT << this->name << ", " << this->title << ", is born !\n";
}

Sorcerer::Sorcerer(STR const n, STR const t) : name(n), title(t)
{
    OUT << this->name << ", " << this->title << ", is born !\n";

}

Sorcerer::Sorcerer(Sorcerer const &f)
{
    this->name = f.name;
    this->title = f.title;
    OUT << this->name << ", " << this->title << ", is born !\n";
}

Sorcerer::~Sorcerer()
{
    OUT << this->name << ", " << this->title << " is dead. Consequences will never be the same !\n";
}

Sorcerer &Sorcerer::operator=(Sorcerer &r)
{
    this->name = r.name;
    this->title = r.title;

    OUT << this->name << ", " << this->title << ", is born !\n";

    return *this;
}

void Sorcerer::polymorph(Victim const &v) const
{
    v.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & r)
{
    o << "I am " << r.name << ", " << r.title << ", and I like ponies !" << std::endl;
    return o;
}
