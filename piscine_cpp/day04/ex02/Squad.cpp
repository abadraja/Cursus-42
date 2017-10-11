//
// Created by Alen BADRAJAN on 7/25/17.
//

#include "Squad.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

int     Squad::nr_atributes = 0;

Squad::Squad()
{
    this->nr_atributes++;
}

//Squad::Squad(const STR name)
//{
//    this->nr_atributes++;
//}

//Squad::Squad(Squad const &f)
//{
//    this->nr_atributes++;
//}

Squad::~Squad() {

}

//Squad &Squad::operator=(Squad &r) {
//    return <#initializer#>;
//}

int Squad::getCount()
{
    return this->nr_atributes;
}

ISpaceMarine Squad::getUnit(int n)
{
    int i = 0;
    while (i < nr_atributes)
    {
        if (i == n)
        {
            return s[i];
            break ;
        }
        i++;
    }
    return s[i];
}

int Squad::push(ISpaceMarine *w)
{
    this->nr_atributes += 1;
    this->s[this->nr_atributes] = *w;
    return 0;
}
