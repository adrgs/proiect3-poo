//
// Created by adragos on 12/31/2019.
//

#ifndef PROIECT3_APARTAMENT_H
#define PROIECT3_APARTAMENT_H


#include "Locuinta.h"
class Apartament :
        public Locuinta
{
private:
    int etaj;
public:
    Apartament();
    Apartament& operator=(const Apartament& a)
    {
        if (&a == this)
            return *this;

        Locuinta::operator=(a);
        this->etaj = a.etaj;

        return *this;
    }
    Apartament(const Apartament& a)
    {
        *this = a;
    }
    ~Apartament();

    void Afisare(std::ostream& out = std::cout) override;
    double calculChirie() const override;

    friend std::istream& operator>>(std::istream& in, Apartament& apartament);
    friend std::ostream& operator<<(std::ostream& out, Apartament& apartament);
};


#endif //PROIECT3_APARTAMENT_H
