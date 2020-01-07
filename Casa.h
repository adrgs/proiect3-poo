//
// Created by adragos on 12/31/2019.
//

#ifndef PROIECT3_CASA_H
#define PROIECT3_CASA_H


#include "Locuinta.h"
#include <vector>
class Casa :
        public Locuinta
{
private:
    double suprafataCurte;
    unsigned int nrEtaje;
    std::vector<double> suprafataEtaje;
public:
    Casa();
    Casa& operator=(const Casa& c)
    {
        if (&c == this)
            return *this;

        Locuinta::operator=(c);
        this->suprafataCurte = c.suprafataCurte;
        this->nrEtaje = c.nrEtaje;
        this->suprafataEtaje = c.suprafataEtaje;

        return *this;
    }
    Casa(const Casa& c)
    {
        *this = c;
    }
    ~Casa();

    void Afisare(std::ostream& out = std::cout) override;
    double calculChirie() const override;

    friend std::istream& operator>>(std::istream& in, Casa& casa);
    friend std::ostream& operator<<(std::ostream& out, Casa& casa);
};


#endif //PROIECT3_CASA_H
