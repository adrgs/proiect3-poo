//
// Created by adragos on 12/31/2019.
//

#include "Locuinta.h"

const double Locuinta::MAXDISCOUNT = 0.1;

Locuinta::Locuinta()
{
    this->suprafataUtila = 0;
    this->discount = 0;
    this->pretChirie = 0;
}


Locuinta::~Locuinta()
{
}

void Locuinta::Afisare(std::ostream & out)
{
    out << "Proprietar:" << this->numeClient << "\n";
    out << "Suprafata Utila:" << this->suprafataUtila << "\n";
    out << "Discount:" << this->discount * 100 << "%\n";
    out << "Pret chirie:" << this->calculChirie() << "\n";
}

std::istream & operator>>(std::istream & in, Locuinta & locuinta)
{
    in >> locuinta.numeClient;
    in >> locuinta.suprafataUtila;
    in >> locuinta.discount;
    in >> locuinta.pretChirie;

    if (locuinta.discount > Locuinta::MAXDISCOUNT) {
        std::string err = "Discount-ul nu poate sa fie mai mare decat ";
        err += Locuinta::MAXDISCOUNT * 100;
        err += "%\n";
        throw err.c_str();
    }

    return in;
}

std::ostream & operator<<(std::ostream & out, Locuinta & locuinta)
{
    locuinta.Afisare(out);
    return out;
}

double Locuinta::CalculeazaChirie(double suprafataUtila, double discount, double pretChirie) {
    return (suprafataUtila * pretChirie) * (1-discount);
}
