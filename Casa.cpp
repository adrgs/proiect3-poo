//
// Created by adragos on 12/31/2019.
//

#include "Casa.h"

Casa::Casa()
{
    this->nrEtaje = 0;
    this->suprafataCurte = 0;
    this->suprafataCurte = 0;
}

Casa::~Casa()
{
}

void Casa::Afisare(std::ostream & out)
{
    out << "----Casa----\n";
    Locuinta::Afisare(out);
    out << "Suprafata curte:" << this->suprafataCurte << "\n";
    out << "Numar etaje:" << this->nrEtaje << "\n";
    for (int i = 0; i < this->nrEtaje; i++)
    {
        out << "Etajul " << i << " suprafata:" << this->suprafataEtaje[i] << "\n";
    }
}

double Casa::calculChirie() const
{
    return ((this->suprafataUtila - this->suprafataCurte) * (1-discount) + this->suprafataCurte) * this->pretChirie;
}

std::istream & operator>>(std::istream & in, Casa & casa)
{
    Locuinta *l = static_cast<Locuinta*>(&casa);
    in >> *l;
    in >> casa.suprafataCurte;
    in >> casa.nrEtaje;
    double suprafataUtila = casa.suprafataCurte;
    for (int i = 0; i < casa.nrEtaje; i++)
    {
        double input;
        in >> input;
        casa.suprafataEtaje.push_back(input);
        suprafataUtila += input;
    }

    if (suprafataUtila != casa.suprafataUtila)
    {
        throw "Eroare! Suprafata Utila introdusa nu este egala cu Suprafata Utila calculata.";
    }

    return in;
}

std::ostream & operator<<(std::ostream & out, Casa & casa)
{
    casa.Afisare(out);
    return out;
}