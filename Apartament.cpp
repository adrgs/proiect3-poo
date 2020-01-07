//
// Created by adragos on 12/31/2019.
//

#include "Apartament.h"

Apartament::Apartament()
{
    this->etaj = 0;
}

Apartament::~Apartament()
{
}

void Apartament::Afisare(std::ostream & out)
{
    out << "----Apartament----\n";
    Locuinta::Afisare(out);
    out << "Etaj:" << this->etaj << "\n";
}

double Apartament::calculChirie() const
{
    return (this->suprafataUtila * this->pretChirie) * (1-discount);
}

std::istream & operator>>(std::istream & in, Apartament & apartament)
{
    Locuinta *l = static_cast<Locuinta *>(&apartament);
    in >> *l;
    in >> apartament.etaj;

    return in;
}

std::ostream & operator<<(std::ostream & out, Apartament & apartament)
{
    apartament.Afisare(out);
    return out;
}